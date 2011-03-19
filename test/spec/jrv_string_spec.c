#include "expectations.h"
#include "jrv_string.h"

begin_example(jrv_str_append, should_concatenate_two_empty_strings)
    char *str1 = "";
    char *str2 = "";
    char *str3 = jrv_str_append(2, str1, str2);
    should_eq_str("", str3)
    free(str3);
end_example

begin_example(jrv_str_append, should_concatenate_one_empty_and_one_non_empty)
    char *str1 = "";
    char *str2 = "foo";
    char *str3 = jrv_str_append(2, str1, str2);
    should_eq_str("foo", str3);
    free(str3);

    str1 = "bar";
    str2 = "";
    str3 = jrv_str_append(2, str1, str2);
    should_eq_str("bar", str3)
    free(str3);
end_example

begin_example(jrv_str_append, should_concatenate_two_non_empty)
    char *str1 = "foo";
    char *str2 = "bar";
    char *str3 = jrv_str_append(2, str1, str2);
    should_eq_str("foobar", str3)
    free(str3);
end_example

begin_example(jrv_str_append, should_concatenate_three_strings)
    char *str1 = "foo";
    char *str2 = "bar";
    char *str3 = "baz";
    char *str4 = jrv_str_append(3, str1, str2, str3);
    should_eq_str("foobarbaz", str4);
    free(str4);
end_example

begin_description(jrv_string)
    add_example(should_concatenate_two_empty_strings)
    add_example(should_concatenate_one_empty_and_one_non_empty)
    add_example(should_concatenate_two_non_empty)
    add_example(should_concatenate_three_strings)
end_description
