// Created by asandler on 7/27/20.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int counter = 0;
void int_handler(int signum){
	if (signum == SIGINT){
		counter++;
		printf("got signal, counter is %d\n", counter);
	}
}

void usr_handler(int signum){
	if (signum == SIGUSR1){
		printf("number of SIGINT received: %d\n", counter);
		exit(0);
	}
}

int main(){
	printf("server pid is: %d\n", getpid());
	while(1) {
		signal(SIGINT, int_handler);
		signal(SIGUSR1, usr_handler);
	}
}