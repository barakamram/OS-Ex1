#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 10000

char childs[SIZE+1];

void print(char *text){
    for(int i=0; i<1000; i++){
        printf("Hello %s\n",text);
        usleep(1000000);
    }
}

int child(void *p){
    print("child_thread");
    return 0;
}

int main(){
    int re1=clone(child,childs+SIZE,CLONE_PARENT,0);
    int re2=clone(child,childs+SIZE,CLONE_PARENT,0);

    printf("reasult1 = %d\n", re1);
    printf("reasult2 = %d\n", re2);
    print("parent");

    return 0;
}
