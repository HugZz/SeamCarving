#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

/* A test case that does nothing and succeeds. */
void null_test_success(void **state)
{
    (void) state; /* unused */
}
