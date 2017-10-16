#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv) {
   float numb = 0;
   char scale = ' ';

   if (argc == 1) {
       printf ("error");
       return 0;
   } else if (argc == 2) {
       numb = atof(argv [1]);
       if (numb < -273.15) {
           printf ("less than absolute null");
           return -1;
      } else {
       printf ("%.2f C:\n%.2f F\n%.2f K\n\n%.2f F:\n%.2f C\n%.2f K\n\n%.2f K:\n%.2f C\n%.2f F\n", numb, numb * 9/5 + 32,
                numb + 273.15, numb, (numb - 32) / 1.8, (numb + 459.67) / 1.8, numb, numb - 273.15, numb * 1.8 - 459.67);
       return 1;
       }
   }else{
       numb = atof(argv [1]);
       if (isalpha(*argv[2])== 0){
          printf ("error");
          return 0;
       }
    scale = *argv[2];
   switch (scale) {
   case 'C':
       if (numb >= -273.15) {
        printf ("%.2f F\n%.2f K\n", numb * 1.8 +32, numb + 273.15);
    }
    break;
   case 'K':
    if (numb >= 0) {
        printf ("%.2f C\n%.2f F\n", numb - 273.15, numb * 1.8 - 459.67);
    }
    break;
   case 'F':
       if (numb > - 459.67){
        printf ("%.2f C\n%.2f K\n",(numb - 32) / 1.8, (numb + 459.67) / 1.8);
       }
       break;
   case 'c':
       if (numb >= -273.15) {
        printf ("%.2f F\n%.2f K\n", numb * 1.8 +32, numb + 273.15);
    }
    break;
   case 'k':
    if (numb >= 0) {
        printf ("%.2f C\n%.2f F\n", numb - 273.15, numb * 1.8 - 459.67);
    }
    break;
   case 'f':
       if (numb > - 459.67){
        printf ("%.2f C\n%.2f K\n",(numb - 32) / 1.8, (numb + 459.67) / 1.8);
       }
       break;
   default:
    printf ("Unknown");
    return 0;
    }
   return 1;
    }
}




