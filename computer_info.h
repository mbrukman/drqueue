/* $Id: computer_info.h,v 1.8 2004/01/23 03:28:00 jorge Exp $ */

#ifndef _COMPUTER_INFO_H_
#define _COMPUTER_INFO_H_

#ifdef __LINUX
#include <stdint.h>
#else
# ifdef __IRIX
#include <sys/types.h>
# else
#  ifdef __OSX
#   include <stdint.h>
#  else
#   error You need to define the OS, or OS defined not supported
#  endif
# endif
#endif

#include "constants.h"

typedef enum {
  ARCH_UNKNOWN,
  ARCH_INTEL,
  ARCH_MIPS,
	ARCH_PPC
} t_arch;

typedef enum {
  OS_UNKNOWN,
  OS_IRIX,
  OS_LINUX,
  OS_WINDOWS,
	OS_OSX
} t_os;

typedef enum {
  PROCTYPE_UNKNOWN,
  PROCTYPE_PENTIUM,
  PROCTYPE_PENTIUMII,
  PROCTYPE_PENTIUMIII,
  PROCTYPE_PENTIUM4,
  PROCTYPE_ATHLON,
  PROCTYPE_MIPSR5000,
  PROCTYPE_MIPSR10000,
	PROCTYPE_PPC
} t_proctype;

struct computer_hwinfo {
  char name[MAXNAMELEN];	/* Name of the computer */
  uint32_t id;			/* Identification number */
  unsigned char arch;		/* type of architecture */
  unsigned char os;		/* type of operating system */
  unsigned char proctype;	/* type of processors */
  uint32_t procspeed;		/* speed of the processors */
  uint16_t ncpus;		/* number of processors that the computer has */
  uint32_t speedindex;		/* global speed index for making comparisons between different computers */
};

void get_hwinfo (struct computer_hwinfo *hwinfo);
t_proctype get_proctype (void);
int get_procspeed (void);
int get_numproc (void);
int get_speedindex (struct computer_hwinfo *hwinfo);

void report_hwinfo (struct computer_hwinfo *hwinfo);

char *osstring (t_os os);
char *archstring (t_arch arch);
char *proctypestring (t_proctype proctype);

#endif /* _COMPUTER_INFO_H_ */



