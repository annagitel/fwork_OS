// Created by asandler on 7/27/20.
#include <signal.h>
#include <stdio.h>
int main(int argc, char** argv){
	int pid;
	int sig;
	int num;
	sscanf(argv[1], "%d", &pid);
	sscanf(argv[2], "%d", &sig);
	sscanf(argv[3], "%d", &num);

	if(sig == 2){
		for(int i=0; i<num; i++)
			kill(pid, SIGINT);
	}
	else if(sig == 10){
		kill(pid, SIGUSR1);
	}
	else{
		printf("signal number is not supported");
	}

	return 0;
}
