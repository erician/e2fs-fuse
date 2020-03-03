#ifndef EASTLAKE_H_
#include "eastlake.h"
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef MOCK_EASTLAKE

long po_stat(const char *poname, struct po_stat * statbuf)
{
    statbuf->st_atime=statbuf->st_ctime=statbuf->st_mtime = time(NULL);
    statbuf->st_uid = getuid();
    statbuf->st_gid = getgid();
    statbuf->st_mode = S_IFDIR | 0755;
    statbuf->st_size = 0;
    statbuf->st_nlink = 1;
    return 0;
}

#else

long po_stat(const char *poname, struct po_stat * statbuf)
{
    return 0;
}

#endif