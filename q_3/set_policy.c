// Created by asandler on 7/27/20.
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv){
	pid_t pid = 0;
	int policy = atoi(argv[1]);
	int priority = atoi(argv[2]);

	struct sched_param param;
	param.sched_priority = priority;

	printf("before: %d\n",sched_getscheduler(0));
	sched_setscheduler(0,policy,&param);
	sched_setparam(0, &param);
	printf("after: %d\n",sched_getscheduler(0));

}
