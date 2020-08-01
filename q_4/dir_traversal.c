// Created by asandler on 7/26/20.
#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf){
	long inode = sb->st_ino;
	char* filetype = (tflag == FTW_D) ? "D" : (tflag == FTW_F) ? "F" :(tflag == FTW_SL) ?  "SL" : "???";
	if(filetype != "SL")
    	printf("%-3s %ld %s\n",filetype,inode,fpath + ftwbuf->base);
    return 0;
}

int main(int argc, char *argv[]){
	int flags = 0;
	flags |= FTW_PHYS;
   if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags)== -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
   }
   exit(EXIT_SUCCESS);
}
//https://pubs.opengroup.org/onlinepubs/9699919799/functions/nftw.html

