#include<stdio.h>
#include<stdlib.h>  
#include<string.h>
/*
    int *return_int_arr(){
        int int_arr[] = {9,1,2};      
        // returning a local variable here
        //1)THIS IS A LOCAL VARIALBLE AND THIS IS ON THE STACK
        // WE would get a warning from the compiler
        return int_arr;                //2)HERE cannot return arrays in c anyway
    }

    char *return_string(){
        char buffer[] = {"this is a local variable"};
        return buffer;   //again this would give warning as the local vars are on the stack
    }

*/

// some valid ways

// using a string literal
char *f1(){
    // return string literal
    return "returned string";
    // only for strings
    // cant calculate string content
    // some compilers store string literals in ROM so 
    // caller cannot modify the literal latter
}


// using a global array
char global_arr[100];
char *f2(){
    // any operation
    global_arr[1] = 'a';
    return global_arr;
    // anyone can modify the value
    // would be overwritten everytime the function is called
}


// using a static array
char *f3(){
    static char arr[] = {"this is a static arr"};
    // this is no longer on the stack
    return arr;
    // Still any caller can modify the content
    // really large buffer 
}

// allocate the memory dynamically
char *f4(){
    char *buffer = malloc(100);
    // fill the buffer
    return buffer;
    // the array would not be overwritten now but
    // memory management issues
    // we could face memory leaks or free memory while still in use
    // the caller will have to insure the above
}

// caller allocates and clears the memory 
// this is sort of the industory standard

void f5(char *result, int size){
    // providing size for safety
    //calculate the returned string
    strncpy(result,"Returned string",size);

    // subtely here we can also return a status/error code
}
// eg
/*
int main(void){
    char *buffer = malloc(size);
    f5(buffer,size);
    // ...
    free(buffer); 
}
*/

//wrap the array in a struct and then return it
// this must be a fixed sized array
#define SIZE 100
struct Data{
    char buffer[SIZE];
};

struct Data f6(){
    struct Data d;
    // this is similar to returning an int
    strncpy(d.buffer,"this is the returned string",SIZE);
}
// caller would receive it and store it on their own stack;

int main(void){
    // int a[10];
    // a = return_int_arr();   //3)WE CANNOT DO THIS ARRAYS ARE NOT MODIFIABLE L VALUES
    // L val is the memory location and R val is the data stored in the memory
}








