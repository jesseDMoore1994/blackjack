cmake_minimum_required(VERSION 3.5.1)

project(blackjack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(BLACKJACK_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(test_blackjack tests/tests)
