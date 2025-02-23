/*====================================================================================================================*\
 *
 * uUTF - micro Unit Test Framework
 *
 * MIT License
 *
 * Copyright (c) 2024 Pawel Kusinski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
\*====================================================================================================================*/

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define INDENT "  "
#define BREAK "--------------------------------------------\n"

#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RESET "\033[0m"

#define PRINT_VAL(x) _Generic((x),          \
    int:                printf("%d", x),    \
    unsigned int:       printf("%u", x),    \
    long:               printf("%ld", x),   \
    unsigned long:      printf("%lu", x),   \
    long long:          printf("%lld", x),  \
    unsigned long long: printf("%llu", x),  \
    float:              printf("%.3f", x),  \
    double:             printf("%.3f", x),  \
    default:            printf("\"%s\"", x) \
)

#define TC_BEGIN(SUITE, NAME)\
bool NAME(void){\
    bool test_passed = true;

#define TC_END()\
    return test_passed;\
}

#define RUN_TC(SUITE, TESTNAME)\
do {\
    printf("Running Test Case %s.%s...\n", #SUITE, #TESTNAME);\
    setup();\
    const bool success = TESTNAME();\
    if (success) {__uutf_global_passed_tests__++;} else {__uutf_global_failed_tests__++;}\
    teardown();\
    printf(INDENT "%s%s%s\n", success ? COLOR_GREEN : COLOR_RED, success ? "Passed" : "Failed", COLOR_RESET);\
} while (0)

static unsigned __uutf_global_passed_tests__ = 0;
static unsigned __uutf_global_failed_tests__ = 0;

#define EXPECT_TRUE(condition)\
    if (!(condition)){\
        printf("EXPECT_TRUE(%s) at line %d failed\n", #condition, __LINE__);\
        test_passed = false;\
    }

#define EXPECT EXPECT_TRUE

#define ASSERT_TRUE(condition)\
    if (!(condition)){\
        printf("ASSERT_TRUE(%s) at line %d failed\n", #condition, __LINE__);\
        return false;\
    }

#define ASSERT ASSERT_TRUE

#define ASSERT_FALSE(condition)\
    if (condition){\
        printf("ASSERT_FALSE(%s) at line %d failed\n", #condition, __LINE__);\
        return false;\
    }

#define ASSERT_EQ(a, b)\
    if ((a) != (b)){\
        printf("ASSERT_EQ(%s, %s) at line %d failed (", #a, #b, __LINE__);\
        PRINT_VAL(a); printf(" != "); PRINT_VAL(b); printf(")\n");\
        return false;\
    }

#define ASSERT_NE(a, b)\
    if ((a) == (b)){\
        printf("ASSERT_NE(%s, %s) at line %d failed (", #a, #b, __LINE__);\
        PRINT_VAL(a); printf(" == "); PRINT_VAL(b); printf(")\n");\
        return false;\
    }

#define ASSERT_GT(a, b)\
    if ((a) <= (b)){\
        printf("ASSERT_GT(%s, %s) at line %d failed (", #a, #b, __LINE__);\
        PRINT_VAL(a); printf(" == "); PRINT_VAL(b); printf(")\n");\
        return false;\
    }

#define RUN_TEST_BEGIN()\
int main() {\
	printf(BREAK);\
	printf("Running tests...\n");\
	printf(BREAK);

#define RUN_TEST_END()\
    printf(BREAK);\
    printf("Result: %s%s%s\n", __uutf_global_failed_tests__ ? COLOR_RED : COLOR_GREEN,\
                               __uutf_global_failed_tests__ ? "FAILURE" : "SUCCESS", COLOR_RESET);\
    printf(INDENT "Passed: %u\n", __uutf_global_passed_tests__);\
    printf(INDENT "Failed: %u\n", __uutf_global_failed_tests__);\
    printf(INDENT "Total:  %u\n", __uutf_global_passed_tests__ + __uutf_global_failed_tests__);\
	printf(BREAK);\
	return __uutf_global_failed_tests__;\
}
