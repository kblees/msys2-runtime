/* types.h

   Copyright 2001, 2002, 2003, 2005, 2006, 2010, 2011, 2012, 2015 Red Hat Inc.
   Written by Robert Collins <rbtcollins@hotmail.com>

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#ifndef _CYGWIN_TYPES_H
#define _CYGWIN_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <endian.h>
#include <bits/wordsize.h>
#include <sys/_timespec.h>

#ifndef __timespec_t_defined
#define __timespec_t_defined
typedef struct timespec timespec_t;
#endif /*__timespec_t_defined*/

#ifndef __timestruc_t_defined
#define __timestruc_t_defined
typedef struct timespec timestruc_t;
#endif /*__timestruc_t_defined*/

#ifndef __off_t_defined
#define __off_t_defined
/* Based on the newlib definitions. */
#if __WORDSIZE == 64
typedef _off_t off_t;
#else
typedef _off64_t off_t;
#endif
#endif /*__off_t_defined*/

typedef __loff_t loff_t;

#ifndef __dev_t_defined
#define __dev_t_defined
typedef __int16_t __dev16_t;
typedef __uint32_t dev_t;
#endif /*__dev_t_defined*/

#ifndef __blksize_t_defined
#define __blksize_t_defined
typedef __int32_t blksize_t;
#endif /*__blksize_t_defined*/

#ifndef __blkcnt_t_defined
#define __blkcnt_t_defined
typedef __int32_t __blkcnt32_t;
typedef __int64_t blkcnt_t;
#endif /*__blkcnt_t_defined*/

#ifndef __fsblkcnt_t_defined
#define __fsblkcnt_t_defined
/* Keep as is.  32 bit on i386, 64 bit on x86_64. */
typedef unsigned long fsblkcnt_t;
#endif /* __fsblkcnt_t_defined */

#ifndef __fsfilcnt_t_defined
#define __fsfilcnt_t_defined
/* Keep as is.  32 bit on i386, 64 bit on x86_64. */
typedef unsigned long fsfilcnt_t;
#endif /* __fsfilcnt_t_defined */

#ifndef __uid_t_defined
#define __uid_t_defined
typedef unsigned short __uid16_t;
typedef __uint32_t uid_t;
#endif /*__uid_t_defined*/

#ifndef __gid_t_defined
#define __gid_t_defined
typedef unsigned short __gid16_t;
typedef __uint32_t gid_t;
#endif /*__gid_t_defined*/

#ifndef __ino_t_defined
#define __ino_t_defined
#ifndef __x86_64__
typedef __uint32_t __ino32_t;
#endif
typedef __uint64_t ino_t;
#endif /*__ino_t_defined*/

/* Generic ID type, must match at least pid_t, uid_t and gid_t in size. */
#ifndef __id_t_defined
#define __id_t_defined
typedef __uint32_t id_t;
#endif /* __id_t_defined */

#if defined (__INSIDE_CYGWIN__) && !defined (__x86_64__)
struct __flock32 {
	short	 l_type;	/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	 l_whence;	/* flag to choose starting offset */
	_off_t	 l_start;	/* relative offset, in bytes */
	_off_t	 l_len;		/* length, in bytes; 0 means lock to EOF */
	short	 l_pid;		/* returned with F_GETLK */
	short	 l_xxx;		/* reserved for future use */
};
#endif

struct flock {
	short	 l_type;	/* F_RDLCK, F_WRLCK, or F_UNLCK */
	short	 l_whence;	/* flag to choose starting offset */
	off_t	 l_start;	/* relative offset, in bytes */
	off_t	 l_len;		/* length, in bytes; 0 means lock to EOF */
	pid_t	 l_pid;		/* returned with F_GETLK */
};

#ifndef __key_t_defined
#define __key_t_defined
typedef long long key_t;
#endif /* __key_t_defined */

#ifndef __BIT_TYPES_DEFINED
#define __BIT_TYPES_DEFINED__ 1

#ifndef __vm_offset_t_defined
#define __vm_offset_t_defined
typedef unsigned long vm_offset_t;
#endif /*__vm_offset_t_defined*/

#ifndef __vm_size_t_defined
#define __vm_size_t_defined
typedef unsigned long vm_size_t;
#endif /*__vm_size_t_defined*/

#ifndef __vm_object_t_defined
#define __vm_object_t_defined
typedef void *vm_object_t;
#endif /* __vm_object_t_defined */

#ifndef __u_int8_t_defined
#define __u_int8_t_defined
typedef unsigned char u_int8_t;
#endif
#ifndef __u_int16_t_defined
#define __u_int16_t_defined
typedef __uint16_t u_int16_t;
#endif
#ifndef __u_int32_t_defined
#define __u_int32_t_defined
typedef __uint32_t u_int32_t;
#endif
#ifndef __u_int64_t_defined
#define __u_int64_t_defined
typedef __uint64_t u_int64_t;
#endif

#ifndef __register_t_defined
#define __register_t_defined
typedef __int32_t register_t;
#endif

#ifndef __addr_t_defined
#define __addr_t_defined
typedef char *addr_t;
#endif

#ifndef __mode_t_defined
#define __mode_t_defined
typedef unsigned mode_t;
#endif
#endif /*__BIT_TYPES_DEFINED*/

#if !defined(__INSIDE_CYGWIN__) || !defined(__cplusplus)

typedef struct __pthread_t {char __dummy;} *pthread_t;
typedef struct __pthread_mutex_t {char __dummy;} *pthread_mutex_t;

typedef struct __pthread_key_t {char __dummy;} *pthread_key_t;
typedef struct __pthread_attr_t {char __dummy;} *pthread_attr_t;
typedef struct __pthread_mutexattr_t {char __dummy;} *pthread_mutexattr_t;
typedef struct __pthread_condattr_t {char __dummy;} *pthread_condattr_t;
typedef struct __pthread_cond_t {char __dummy;} *pthread_cond_t;

  /* These variables are not user alterable. This means you!. */
typedef struct
{
  pthread_mutex_t mutex;
  int state;
}
pthread_once_t;
typedef struct __pthread_spinlock_t {char __dummy;} *pthread_spinlock_t;
typedef struct __pthread_rwlock_t {char __dummy;} *pthread_rwlock_t;
typedef struct __pthread_rwlockattr_t {char __dummy;} *pthread_rwlockattr_t;

#else

/* pthreads types */

typedef class pthread *pthread_t;
typedef class pthread_mutex *pthread_mutex_t;
typedef class pthread_key *pthread_key_t;
typedef class pthread_attr *pthread_attr_t;
typedef class pthread_mutexattr *pthread_mutexattr_t;
typedef class pthread_condattr *pthread_condattr_t;
typedef class pthread_cond *pthread_cond_t;
typedef class pthread_once pthread_once_t;
typedef class pthread_spinlock *pthread_spinlock_t;
typedef class pthread_rwlock *pthread_rwlock_t;
typedef class pthread_rwlockattr *pthread_rwlockattr_t;

/* semaphores types */
typedef class semaphore *sem_t;
#endif /* __INSIDE_CYGWIN__ */

/* this header needs the dev_t typedef */
#include <sys/sysmacros.h>

#ifdef __cplusplus
}
#endif

#endif /* _CYGWIN_TYPES_H */
