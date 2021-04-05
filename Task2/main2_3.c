#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/types.h>

int main(){
  pid_t p=fork();

  if(p==0){
      chdir("/");
      setsid();

      printf("DAEMONS\n");

      close(stdout);
      close(stdin);
      close(stderr);
      int i=1000;
      while(i>0){i--;}
      openlog("OurDeamon",P_PID,LOG_DAEMON);
      syslog(LOG_NOTICE, "daemon started");
      usleep(30000000);
      syslog(LOG_NOTICE, "in process");
      usleep(30000000);
      syslog(LOG_NOTICE, "done");


  }
  else
      printf("daemon PID %d\n", p);

  }
