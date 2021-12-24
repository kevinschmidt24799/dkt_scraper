cmake_minimum_required(VERSION 3.21)
project(scraper)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(CURL)

add_executable(scraper main.cpp fetch.cpp fetch.hpp extract.cpp extract.hpp)

target_link_libraries(scraper ${CURL_LIBRARIES})
