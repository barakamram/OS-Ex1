#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>

void print_process(char *text){
    for(int i=0; i<20; i++){
        printf("Hello %s\n",text);
        usleep(1000000);
    }
}

int main(){
    pid_t p=fork();

    if(p==0){
        pid_t p=fork();

        if(p==0)
            print_process("process2");

        else
            print_process("process1");

    }
    else
        print_process("app");

}
