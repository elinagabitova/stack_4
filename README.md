[![Build Status](https://travis-ci.org/elinagabitova/stack_4.svg?branch=master)](https://travis-ci.org/elinagabitova/stack_4)
```
cmake -H. -B_builds -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
_builds/example
```
