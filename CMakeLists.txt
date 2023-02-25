cmake_minimum_required(VERSION 3.24)
project(ieeentu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(ieeentu main.cpp Database.cpp Sql.cpp User.cpp Tiktok.cpp Types.h)

TARGET_LINK_LIBRARIES(ieeentu  ${PQXX_LIB} ${PQ_LIB})
