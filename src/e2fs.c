#ifndef E2FS_H_
#include "e2fs.h"
#endif

#ifndef EASTLAKE_H_
#include "eastlake.h"
#endif

#ifndef E2FS_E2FS_TYPE_H_
#include "e2fs_type.h"
#endif

#ifndef E2FS_STRING_UTIL_H_
#include "string_util.h"
#endif

#ifndef E2FS_E2FS_UTIL_H_
#include "e2fs_util.h"
#endif

#include <fuse.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>

static int e2fs_getattr(const char *path, struct stat *stbuf);

static int e2fs_getattr(const char *path, struct stat *stbuf)
{
    if(strlen(path)==0)
        return -ENOENT;
    char poname[strlen(path) + 1];
    strcpy(poname, path);
    /* delete '/' in path that ends with '/' */
    if(strcmp(poname, ROOT_PATH) != 0 && ends_with(poname, '/') == TRUE) {
        poname[strlen(poname)-1] = '\0';
    }

    struct po_stat po_stat_buf;
    if(po_stat(poname, &po_stat_buf) != 0)
        return -errno;
    if(is_file(po_stat_buf.st_mode) == FALSE)
        return -ENOENT;
    stbuf->st_uid = po_stat_buf.st_uid;
    stbuf->st_gid = po_stat_buf.st_gid;
    stbuf->st_atime = po_stat_buf.st_atime;
    stbuf->st_mtime = po_stat_buf.st_mtime;
    stbuf->st_ctime = po_stat_buf.st_ctime;
    stbuf->st_mode = po_stat_buf.st_mode;
    stbuf->st_size = po_stat_buf.st_size;
    stbuf->st_nlink = po_stat_buf.st_nlink;
	return 0;
}

static struct fuse_operations e2fs_oper = {
	.getattr	= e2fs_getattr,
};

int main(int argc, char *argv[])
{
	return fuse_main(argc, argv, &e2fs_oper, NULL);
}
