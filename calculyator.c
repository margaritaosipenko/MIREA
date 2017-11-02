#include <stdio.h>
 int main()
 {
     int stack[1000];
     int sp =0;
     while ( !feof(stdin) ) {
         int a = getchar();
         int x;
         switch (a) {
             case  ' ':
             case '\n':
                 break;
             case '=':
                 printf("Result = %d\n", stack[sp - 1]);  sp--;
                 break;
             case '+':
                stack[sp-2] = stack[sp-2] + stack[sp-1];  sp--;
                break;
             case '-':
                stack[sp-2] = stack[sp-2] - stack[sp-1];  sp--;
                break;
             case '*':
                stack[sp-2] = stack[sp-1] * stack[sp-2];  sp--;
                break;
             case '/':
               stack[sp-2] = stack[sp-2] / stack[sp-1];   sp--;
                break;
             default:
                 ungetc (a, stdin);
                 if (scanf("%d", &x) != 1) {
                     fprintf(stderr, "Error\n");
                     return -1;
                 } else {
                     stack[sp] = x;                       sp++;
                 }
         }
     }
     printf("Result = %d\n",stack[sp-1]);
     return 0;
 }
