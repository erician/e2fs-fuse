#include "ctest/ctest.h"
#include "string_util.h"
#include "e2fs_type.h"

TEST(string_util, ends_with)
{
    char *str1="abc";
    char *str2="/abc";
    char *str3="/";
    ASSERT_EQ(ends_with(str1, '/'), FALSE);
    ASSERT_EQ(ends_with(str2, '/'), FALSE);
    ASSERT_EQ(ends_with(str3, '/'), TRUE);
}