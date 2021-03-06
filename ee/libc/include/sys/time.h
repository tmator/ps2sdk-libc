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
 * POSIX declarations for time
 */

#ifndef __SYS_TIME_H__
#define __SYS_TIME_H__


#ifndef __time_t_defined
typedef unsigned long time_t;
#define __time_t_defined
#endif

struct timeval {
	time_t tv_sec;
	time_t tv_usec;
};

#endif /* __SYS_TIME_H__ */
