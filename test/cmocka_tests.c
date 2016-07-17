#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "test_dummy.h"
#include "test_allocating.h"

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(test_allocating),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
