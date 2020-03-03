#ifndef EASTLAKE_H_
#define EASTLAKE_H_

#include <sys/types.h>

#define MOCK_EASTLAKE

typedef unsigned short  umode_t;

/*
 * struct po_stat
 */
struct po_stat {
    dev_t     st_dev;         	    /* ID of device containing po*/
    mode_t    st_mode;        	    /* po type and mode */
    nlink_t   st_nlink;       	    /* Number of hard links, 暂时还不用管这个 */
    uid_t     st_uid;         		/* User ID of owner */
    gid_t     st_gid;         		/* Group ID of owner */
    off_t     st_size;        		/* Total size, in bytes */
 #ifdef __USE_XOPEN2K8
    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim;		/* Time of last access.  */
    struct timespec st_mtim;		/* Time of last modification.  */
    struct timespec st_ctim;		/* Time of last status change.  */
# define st_atime st_atim.tv_sec	/* Backward compatibility.  */
# define st_mtime st_mtim.tv_sec
# define st_ctime st_ctim.tv_sec
#else
    __time_t st_atime;			/* Time of last access.  */
    __syscall_ulong_t st_atimensec;	/* Nscecs of last access.  */
    __time_t st_mtime;			/* Time of last modification.  */
    __syscall_ulong_t st_mtimensec;	/* Nsecs of last modification.  */
    __time_t st_ctime;			/* Time of last status change.  */
    __syscall_ulong_t st_ctimensec;	/* Nsecs of last status change.  */
#endif
};


/*
 * system calls in lullaby.
 * attention: we will not use these functions directly, 
 * instead we will use syscall by passing syscall number to it.
 */
long po_creat(const char *poname, umode_t mode);
long po_unlink(const char *poname);
long po_open(const char *poname, int flags, umode_t mode);
long po_close(unsigned int pod);
long po_mmap(unsigned long addr, unsigned long len, \
                 unsigned long prot, unsigned long flags, \
                 unsigned int pod, unsigned long pgoff);
long po_munmap(unsigned long addr, size_t len);
long po_extend(unsigned int pod, size_t len);
long po_shrink(unsigned int pod, unsigned long addr, size_t len);
long po_stat(const char *poname, struct po_stat * statbuf);
long po_fstat(unsigned int pod, struct po_stat * statbuf);

/*
 * user library functions in lullaby
 */

/* 
 * for a po, the return value of first call po_malloc, if success, 
 * is the with the return value of sys_po_mmap with pgoff 0, if success.  
 */
void *po_malloc(int pod, size_t size);
void po_free(int pod, void *ptr);

#endif