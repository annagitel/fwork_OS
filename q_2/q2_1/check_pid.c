// Created by asandler on 7/26/20.
#include <errno.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char** argv){
	int pid;
    sscanf(argv[1], "%d", &pid);
	printf("got pid %d\n", pid);
	int errno;
	printf("sending kill signal\n");
	kill(pid, 0);

	if(errno==0) //no error
		printf("Process %d exists\n",pid);
	else if(errno==1) //EPERM
		printf("EPERM returned. %d exist, no permission to send kill\n", pid);
	else if(errno==3) //ESRCH
		printf("ESRCH returned. %d does not exist\n", pid);
	else
		printf("unknown error\n");

	return 0;
}
