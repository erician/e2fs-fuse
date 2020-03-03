#ifndef E2FS_STRING_UTIL_H_
#include "string_util.h"
#endif

#ifndef E2FS_E2FS_TYPE_H_
#include "e2fs_type.h"
#endif

#include <string.h>

int ends_with(const char *str, char c)
{
    int len = strlen(str);
    if(len == 0)
        return FALSE;
    if(str[len-1] == c)
        return TRUE;
    else
        return FALSE;
}