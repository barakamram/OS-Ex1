#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
#include <stddef.h>

void (*hello_message)(const char*);

bool init_lib(){
    void* k = dlopen("./libHello.so", RTLD_LAZY);
    if(k == NULL)
        return false;
    hello_message = (void(*)(char*))dlsym(k,"hello_message");
    if(hello_message == NULL)
        return false;
    return true;
}

int main(){
    if(init_lib())
        hello_message("Ariel");
    else
        printf("library was not found\n");
    return 0;
}
