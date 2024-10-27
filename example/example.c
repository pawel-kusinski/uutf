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

// Sample functions to test
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void setup(void) {
    // Initialization code, if any
}

void teardown(void) {
    // Cleanup code, if any
}

TC_BEGIN(MathSuite, test_addition)
    int result = add(2, 3);
    ASSERT_EQ(result, 5);  // Test passes if result == 5
TC_END()

TC_BEGIN(MathSuite, test_subtraction)
    int result = subtract(5, 3);
    ASSERT_EQ(result, 2);  // Test passes if result == 2
TC_END()

RUN_TEST_BEGIN()
    RUN_TC(MathSuite, test_addition);
    RUN_TC(MathSuite, test_subtraction);
RUN_TEST_END()
