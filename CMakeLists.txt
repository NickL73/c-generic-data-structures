cmake_minimum_required(VERSION 3.16)
set(PROJECT "structures")
project(${PROJECT} "C")

set(ITEM_HEADERS ${PROJECT}_headers)
set(ITEM_TESTS ${PROJECT}_test)
set(ITEM_EXEC ${PROJECT}_exe)
set(ITEM_SUBMISSION ${PROJECT}_submission)

add_library(${ITEM_SUBMISSION} SHARED "src/linked_list.c" "include/linked_list.h")

add_library(${ITEM_TESTS} SHARED "tests/linked_lists_tests.c")

add_executable(${ITEM_EXEC} tests/main_tests.c "include/linked_list.h" "src/linked_list.c")

target_link_libraries(${ITEM_EXEC} ${ITEM_SUBMISSION} ${ITEM_TESTS} cunit)
target_compile_options(${ITEM_EXEC} PUBLIC "-Wall" "-Wextra" "-g")
add_test(${PROJECT}_tests                ${ITEM_EXEC})
