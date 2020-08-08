// Created by asandler on 7/27/20.
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <sys/syscall.h>
// 1 2 can be changed, 0 3 5 must be zero, 4 ???
#define _GNU_SOURCE
#include <linux/kernel.h>
#include <time.h>
#include <linux/types.h>
#include <linux/sched.h>
#include <sys/types.h>

#define SCHED_DEADLINE  6

/* __NR_sched_setattr number */
#ifndef __NR_sched_setattr
#ifdef __x86_64__
#define __NR_sched_setattr      314
#endif

#ifdef __i386__
#define __NR_sched_setattr      351
#endif

#ifdef __arm__
#define __NR_sched_setattr      380
#endif

#ifdef __aarch64__
#define __NR_sched_setattr      274
#endif
#endif

/* __NR_sched_getattr number */
#ifndef __NR_sched_getattr
#ifdef __x86_64__
#define __NR_sched_getattr      315
#endif

#ifdef __i386__
#define __NR_sched_getattr      352
#endif

#ifdef __arm__
#define __NR_sched_getattr      381
#endif

#ifdef __aarch64__
#define __NR_sched_getattr      275
#endif
#endif

struct sched_attr {
    __u32 size;
    __u32 sched_policy;
    __u64 sched_flags;
    /* SCHED_NORMAL, SCHED_BATCH */
    __s32 sched_nice;
    /* SCHED_FIFO, SCHED_RR */
    __u32 sched_priority;
    /* SCHED_DEADLINE */
    __u64 sched_runtime;
    __u64 sched_deadline;
    __u64 sched_period;
};

int sched_setattr(pid_t pid,const struct sched_attr *attr,unsigned int flags){
    return syscall(__NR_sched_setattr, pid, attr, flags);
}

int sched_getattr(pid_t pid,struct sched_attr *attr, unsigned int size,unsigned int flags){
    return syscall(__NR_sched_getattr, pid, attr, size, flags);
}

int main(int argc, char** argv){
	int policy = atoi(argv[1]);
	int priority = atoi(argv[2]);
	printf("policy %d priority %d \n", policy, priority);

	char command[128];
	snprintf(command, sizeof(command), "chrt -p %d",getpid());

	struct sched_param param;
	struct sched_attr attr;

	if (policy == 1 || policy == 2)
		param.sched_priority = priority;
	else if( policy == 6) {
		printf("in 6\n");
		attr.size = sizeof(attr);
		attr.sched_policy = 6;
		attr.sched_runtime = 10 * 100 * 1000;
		attr.sched_period = 2 * 100 * 100 * 1000;
		attr.sched_deadline = 11 * 1000 * 1000;
		attr.sched_flags = 0;
		sched_setattr(getpid(), &attr, attr.sched_flags);
		printf("6 is now: \n");
		system(command);
		printf("%s\n", command);

	}
	else
		param.sched_priority = 0;

	printf("%d\n", getpid());
	printf("before:\n");
	system(command);
	sched_setscheduler(0,policy,&param);
	printf("after:\n");
	system(command);
	return(0);
}
