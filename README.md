# uutf (micro Unit Test Framework)

## Overview
**uutf** is a simple, minimalistic unit testing framework for C projects. It provides macros for defining test cases, assertions, and running multiple tests.

## Features
- **Test Cases**: Define and manage individual test cases.
- **Setup and Teardown**: Run setup and cleanup code before and after each test case.
- **Assertions**: Built-in macros for checking conditions (e.g., `ASSERT_TRUE`, `ASSERT_EQ`).
- **Test Runner**: Run all defined test cases with a summarized result.

## Example
### Building the Example
To build the example test case provided in `example/example.c`, follow these steps:
```bash
mkdir build
cd build
cmake ..
make
```
This will generate an executable called uutf_example in the `build/`directory.
### Running the Tests
To run the test:
```bash
./uutf_example
```
You should see output similar to:
```
-----------------------------------
Running tests...
-----------------------------------
Running Test Case MathSuite.test_addition...
  Passed
Running Test Case MathSuite.test_subtraction...
  Passed
-----------------------------------
Result: SUCCESS
  Passed: 2
  Failed: 0
  Total:  2
-----------------------------------
```

## Macros Reference
### Test Case Definition
- `TC_BEGIN(SUITE, NAME)`: Start a test case named `NAME` in the `SUITE`.
- `TC_END()`: End the test case.
### Assertions
- `ASSERT_TRUE(condition)`: Fails the test if condition is false.
- `ASSERT_FALSE(condition)`: Fails the test if condition is true.
- `ASSERT_EQ(a, b)`: Fails the test if a != b.
### Running Tests
- `RUN_TC(SUITE, TESTNAME)`: Runs a test case defined in the given `SUITE`.
- `RUN_TEST_BEGIN()` / `RUN_TEST_END()`: Block to execute all test cases and summarize results.

## License
This project is licensed under the MIT License.