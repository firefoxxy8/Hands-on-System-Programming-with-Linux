/*
 * ch_:query_creds.c
 * 
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Hands-on System Programming with Linux"
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *
 * From:
 *  Ch 6 : Process Credentials
 ****************************************************************
 * Brief Description:
 *
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "../common.h"

/*---------------- Globals, Macros ----------------------------*/
#define SHOW_CREDS() do {		\
  printf("RUID=%d EUID=%d\n"	\
         "RGID=%d EGID=%d\n",	\
		getuid(), geteuid(),    \
		getgid(), getegid());   \
} while (0)

/*---------------- Typedef's, constants, etc ------------------*/


/*---------------- Functions ----------------------------------*/

int main(int argc, char **argv)
{
	SHOW_CREDS();
	if (geteuid() == 0) {
		printf("%s now effectively running as root! ...\n", argv[0]);
		sleep(1);
	}
	exit (EXIT_SUCCESS);
}

/* vi: ts=8 */
