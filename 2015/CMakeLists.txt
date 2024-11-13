cmake_minimum_required(VERSION 3.0)
project(AdventofCode2015)

set(Solutions 01 02 03 04 05)
list(TRANSFORM Solutions REPLACE "(.+)" "day\\1.cpp")

add_executable(aoc2015 main.cpp common.cpp ${Solutions})
add_executable(aoc2015_test test.cpp common.cpp ${Solutions})

target_link_libraries(aoc2015 -lcrypto)
target_link_libraries(aoc2015_test -lcrypto)

target_compile_definitions(aoc2015 PUBLIC -DDOCTEST_CONFIG_DISABLE)
