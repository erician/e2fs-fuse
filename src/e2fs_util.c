#ifndef E2FS_E2FS_UTIL_H_
#include "e2fs_util.h"
#endif

#ifndef E2FS_H_
#include "e2fs.h"
#endif

#ifndef E2FS_E2FS_TYPE_H_
#include "e2fs_type.h"
#endif

int is_file(mode_t mode) {
    if((mode & S_IFPO) == 0)
        return TRUE;
    else
        return FALSE;
}