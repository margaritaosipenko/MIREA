#include <iostream>
#include <sstream>
#include <string>
#define _WIN32_WINNT 0x501
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

using std::cerr;
int main()
{
    WSADATA wsaData; /* service structure for storing information about re-application of Windows Sockets */
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    /* if there was an error loading the library.*/
    if (result != 0) {
        cerr << "WSAStartup failed: " << result << "\n";
        return result;
    }
    struct addrinfo* addr = NULL; /* A structure that stores information about the IP address of the listening socket */

    /* ������ ��� ������������� ��������� ������ */
    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP; /* use the protocol TCP */
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo("127.0.0.1", "8000", &hints, &addr);

    if (result != 0) {
        cerr << "getaddrinfo failed: " << result << "\n";
        WSACleanup();
        return 1;
    }

    /* Create a socket */
    int listen_socket = socket(addr->ai_family, addr->ai_socktype,
        addr->ai_protocol);

    if (listen_socket == INVALID_SOCKET) {
        cerr << "Error at socket: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        WSACleanup();
        return 1;
    }

    /* string the socket to the IP address */
    result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);

    /* If you can not bind the address to the socket, you get an error message, freeing memory and close the open socket*/
    /* unload the DLL-library from memory and close the program..*/
    if (result == SOCKET_ERROR) {
        cerr << "bind failed with error: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    const int max_client_buffer_size = 1024;
    char buf[max_client_buffer_size];
    int client_socket = INVALID_SOCKET;

    for (;;) {
        /* accept incoming connections */
        client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == INVALID_SOCKET) {
            cerr << "accept failed: " << WSAGetLastError() << "\n";
            closesocket(listen_socket);
            WSACleanup();
            return 1;
        }
        result = recv(client_socket, buf, max_client_buffer_size, 0);

        std::stringstream response; /* here will be answer for client */
        std::stringstream response_body;

        if (result == SOCKET_ERROR) {
            /* error getting data */
            cerr << "recv failed: " << result << "\n";
            closesocket(client_socket);
        } else if (result == 0) {
            /* connection closed by client */
            cerr << "connection closed...\n";
        } else if (result > 0) {
            buf[result] = '\0';

            /* data successfully received */
            response_body << "<title>Test C++ HTTP Server</title>\n"
                << "<h1>Test page</h1>\n"
                << "<p>This is body of the test page...</p>\n"
                << "<h2>Request headers</h2>\n"
                << "<pre>" << buf << "</pre>\n"
                << "<em><small>Test C++ Http Server</small></em>\n";

            /* form the whole answer together with the headers */
            response << "HTTP/1.1 200 OK\r\n"
                << "Version: HTTP/1.1\r\n"
                << "Content-Type: text/html; charset=utf-8\r\n"
                << "Content-Length: " << response_body.str().length()
                << "\r\n\r\n"
                << response_body.str();
            /* Send answer to client with function "send" */
            result = send(client_socket, response.str().c_str(),
                response.str().length(), 0);

              if (result == SOCKET_ERROR) {
                /*error while sending data*/
                cerr << "send failed: " << WSAGetLastError() << "\n";
            }
            /* Close connection with the client */
            closesocket(client_socket);
        }
    }

    /* "screen cleaning" */
    closesocket(listen_socket);
    freeaddrinfo(addr);
    WSACleanup();
    return 0;
}
