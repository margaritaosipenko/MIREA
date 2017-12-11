#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int str=1, sto=1, l=0, k=0;
int main(int argc, char* argv[]) {
  if (argc==1)
  printf("enter array");
else{

srand(time(NULL));
int n= 5;
int m= 5;
int i, j;
int array[m][n];
    for( i = 0; i < m; i++){
    for( j = 0; j < n ; j++){
       array[i][j] = 10+rand() %91;
       }
    }
    for ( i = 0; i<m; i++) {
       for ( j = 0; j<n; j++) {
    printf("%d ", array[i][j]);
     }
    printf("\n");
printf("\n");
int a1[5]; int a2[5];

    for( i=0;i<5;i++){
    a1[i]=array[0][abs(i-4)];
    a2[i]=array[4][abs(i-4)];
      }
    for( i=0;i<5;i++ ){
    array[0][i]=a2[i];
    array[4][i]=a1[i];
      }
    for ( i = 0; i<m; i++) {
    for ( j = 0; j<n; j++) {
    printf("%d ", array[i][j]);
      }
    printf("\n");
  }

printf("\n");
int a=100, i1,j1;
    for ( i = 0; i<m; i++) {
    for ( j = 0; j<n; j++) {

            if(array[i][j]<a) {
            a=array[i][j];
            i1=i; j1=j;
            }
        }
    }
    for (i=i1;i<n;i++){
        for (j=0; j<m; j++){
        array[i][j]=array[i+1][j];
        }
    }
    for (i=0; i<n; i++ ){
    for (j=j1; j<m; j++){
        array[i][j]=array[i][j+1];
        }
    }
      printf("min el=%d ",a);
      printf("m=%d ",i1);
      printf("n=%d ",j1);
      printf("\n");
   for ( i = 0; i<m-1; i++) {
   for ( j = 0; j<n-1; j++) {
   printf("%d ", array[i][j]);
    }
   printf("\n");
    }
printf("\n");
m=4;
n=4;
int ch[100];
for ( i=1; i<argc-1; i++) {
  if (l==0)
         sto++;
 switch ( argv[i][0]) {
    case ',':
         str++;
         l++;
    break;
default:
    ch[k]=atof(argv[i]);
    k++;
 }
}
int array1[str][sto];
int arrayend[m][sto];
l=0;
if (n==str){
for( i = 0; i < str; i++){
    for( j = 0; j < sto ; j++){
       array1[i][j]=ch[l];
l++;
    }
        }
        for (i = 0; i < n; i++){
        for( j = 0; j < sto ; j++){
        arrayend[i][j] = 0;
            for(k = 0; k < m; k++)
            arrayend[i][j] += array[i][k] * array1[k][j];
        }
     }
printf("\n");
   for ( i = 0; i<m; i++) {
   for ( j = 0; j<sto; j++) {
        printf("%d ", arrayend[i][j]);
        }
    printf("\n");
    }
}
else printf("error");
    }
return 0;
}
