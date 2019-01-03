#include<stdio.h>
#include "caller.c"  //importing the other c file


// LINKING FILES we can also do gcc file1.c file2.c to compile and link both the files

// STATIC HAS 3 MEANINGS
// global static variables are not accesible from the external files

// Same goes for static functions

int x = 10;
// this is accesible rn but static x wont be and would give compiletime error at linking



// if i make this global function static then i cannot call it from some other file
static void print_num(void)
{
    static int y = 0;
    // this would retain the value over function calls
    printf("%d\n",y);
    y = y + 1;
}

void caller(void);

int main(void)
{
    // y would be allocated in the data segment of the memory and the value would be
    // retained over the function calls
    print_num();
    print_num();
    print_num();
    print_num();
    // 0 1 ... is the output
    caller();
}