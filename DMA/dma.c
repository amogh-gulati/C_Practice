#include<stdio.h>
// we use this library to dynamically allocate memory
#include<stdlib.h>
// malloc() - allocate memory to structures(user defined datatypes)
// calloc() - allocate memory to arrays
// realloc() - increase or decrease the size of array
// free() - release the memory



int main(void){
    // malloc
    // void* - this is a generic pointer to interger char etc/ can point to any type of data 
    // size_t - this is a positive integer value
    // size_t is an unsigned integer type of at least 16 bit
    // on success , it returns base address of memory block
    // on failure , it returns null pointer

    struct emp{
        int eno;
        char ename[20];
        float esal;
    };
    struct emp* ptr;   
    //pointer size is based on the compiler we are using 
    // 16 bit compiler 2 bytes 32 bit compiler the size is 4 bytes and so on

    ptr  = (struct emp*)malloc(sizeof(struct emp));
    // malloc returns void pointer we must typecast it to emp* type 
    if(ptr!=NULL)
    {
        printf("memory allocated succesfully \n");
        printf("enter details \n");
        // to scanf we are providing the address of ptr->eno and ptr->esal
        // we dont need to provide the address of an array because its already an address
        scanf("%d%s%f",&ptr->eno,ptr->ename,&ptr->esal);
        printf("%d\n%s\n%f\n",ptr->eno,ptr->ename,ptr->esal);
    }
    else
    {
        printf("out of memory error \n");
    }
    
}