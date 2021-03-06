/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2005, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

/**
 * @file
 * unistd implementation
 */

#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#if defined(F_getcwd) || defined(DOXYGEN)
extern char direct_pwd_[256];

char *getcwd(char *buf, int len)
{
	strncpy(buf, direct_pwd_, len);
	return buf;
}
#endif

#if defined(F_access) || defined(DOXYGEN)
int access(const char *path, int mode)
{
	printf("access() unimplemented\n");
	return -1;
}
#endif

#if defined(F_fstat) || defined(DOXYGEN)
int fstat(int filedes, struct stat *buf)
{
	printf("fstat() unimplemented\n");
	return -1;
}
#endif

#if defined(F_sleep) || defined(DOXYGEN)
#include <kernel.h>
#include <time.h>

#define HSYNC_COUNT 600

struct sleep_data
{
    s32	 s;
    clock_t wait;
};

static void _sleep_waker(s32 alarm_id, u16 time, void *arg2)
{
    struct sleep_data *sd = (struct sleep_data *) arg2;
    if (clock() >= sd->wait)
        iSignalSema(sd->s);
    else
        iSetAlarm(HSYNC_COUNT, _sleep_waker, arg2);

    ExitHandler();
}

unsigned int sleep(unsigned int seconds)
{
    ee_sema_t sema;
    struct sleep_data sd;

	sema.init_count = 0;
	sema.max_count  = 1;
	sema.option     = 0;

    sd.wait = clock() + seconds * CLOCKS_PER_SEC;
    sd.s = CreateSema(&sema);
    SetAlarm(HSYNC_COUNT, _sleep_waker, &sd);
    WaitSema(sd.s);
    DeleteSema(sd.s);

	return 0;
}
#endif
