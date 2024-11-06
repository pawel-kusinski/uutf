/*====================================================================================================================*\
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

#include "uutf.h"

#define UUTF_SELF_TEST_CASES_BEGIN()\
int main(void) {\
    bool uutf_self_test_passed = true;\


#define UUTF_SELF_TEST_CASES_END()\
    printf("Test passed: %s\n", uutf_self_test_passed ? "YES" : "NO");\
    return uutf_self_test_passed ? 0 : -1;\
}

#define MUST_PASS(x, ...)\
    if (!_ ## x ## _WRAPPER (__VA_ARGS__)) {\
        printf("MUST_PASS at line %d failed\n", __LINE__);\
        uutf_self_test_passed = false;\
    }

#define MUST_FAIL(x, ...)\
    if (_ ## x ## _WRAPPER (__VA_ARGS__)) {\
        printf("MUST_FAIL at line %d failed\n", __LINE__);\
        uutf_self_test_passed = false;\
    }


static bool _ASSERT_TRUE_WRAPPER(bool condition) {
    ASSERT_TRUE(condition);
    return true;
}

static bool _ASSERT_FALSE_WRAPPER(bool condition) {
    ASSERT_FALSE(condition);
    return true;
}

static bool _ASSERT_EQ_WRAPPER(int a, int b) {
    ASSERT_EQ(a, b);
    return true;
}

static bool _ASSERT_NE_WRAPPER(int a, int b) {
    ASSERT_NE(a, b);
    return true;
}
