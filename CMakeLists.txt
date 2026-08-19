cmake_minimum_required(VERSION 3.14)
project(JustUser CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

include_directories(include)

add_executable(justuser src/main.cpp)

target_link_libraries(justuser PRIVATE 
    CURL::libcurl 
    Threads::Threads
)
