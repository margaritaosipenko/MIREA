#include<stdio.h>
#include<stdlib.h>

int isVis(int);
int main(int argc, char *argv[])

{
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int DD, MM, YY, i, sum, dw;
    dw = 1;
    if(argc < 4)
    {
     printf("argc < 4\n");
     exit(-1);
    }
     DD = atoi(argv[1]);
     MM = atoi(argv[2]);
     YY = atoi(argv[3]);
     for(i = 1; i < YY; i++)
    {
    if(i % 400 == 0)
       dw += 2;

		else if(i % 100 == 0)
            dw ++;

		else if(i % 4 == 0)
            dw += 2;
        else
            dw ++;

			if(dw > 7) dw -= 7;
    }

	dw --;
    if(dw == 0) dw = 7;
    for(i = 0; i < MM - 1; i ++)
    {
    if(i == 1 && (isVis(YY) & 1))

		{
        dw++;
        continue;

		}

		else if(i == 1)
           continue;
        dw += months[i] - (months[i] / 7) * 7;

		if(dw > 7) dw -= 7;

	}
    dw += DD - (DD / 7) * 7;
    if(dw > 7) dw -= 7;
    switch(dw)

	{

		case 1: printf("monday\n");
		break;

		case 2: printf("tuesday\n");
		break;

		case 3: printf("wednesday\n");
		break;

		case 4: printf("thursday\n");
		break;

		case 5: printf("friday\n");
		break;

		case 6: printf("saturday\n");
		break;

		case 7: printf("sunday\n");
		break;
    }
        return 0;

}
int isVis(int year)

{
     if(year % 400 == 0)
       return 1;

	else if(year % 100 == 0)
        return 0;

	else if(year % 4 == 0)
        return 1;

	else
        return 0;

}
