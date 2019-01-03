#include<stdio.h>
// extern means that there is a variable x exterally defined
// not in the same file
extern int x;

void caller(void){
    printf("global variable x is : %d \n",x);
}