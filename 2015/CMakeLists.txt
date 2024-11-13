project(AdventofCode2015)
cmake_minimum_required(VERSION 3.0)

add_executable(aoc2015 main.cpp common.cpp day01.cpp day02.cpp day03.cpp day04.cpp)
add_executable(aoc2015_test test.cpp common.cpp day01.cpp day02.cpp day03.cpp day04.cpp)

target_link_libraries(aoc2015 -lcrypto)
target_link_libraries(aoc2015_test -lcrypto)

target_compile_definitions(aoc2015 PUBLIC -DDOCTEST_CONFIG_DISABLE)
