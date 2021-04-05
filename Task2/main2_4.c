#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 10000
char childrens[SIZE+1];

int child1(){
    char *args[2]={"./main2_1",NULL};
    execvp(args[0],args);
    return 0;
}
int child2(){
    char *args[2]={"./main2_2",NULL};
    execvp(args[0],args);
    return 0;
}
int child3(){
    char *args[2]={"./main2_3",NULL};
    execvp(args[0],args);
    return 0;
}

int main(){

    int re1=clone(child1,childrens+SIZE,0,0);
    int re2=clone(child2,childrens+SIZE,0,0);
    int re3=clone(child3,childrens+SIZE,0,0);

    printf("main2_4 in process");
    usleep(30000000);


    return 0;
}
