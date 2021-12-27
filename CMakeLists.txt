cmake_minimum_required(VERSION 3.21)
project(scraper)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(CURL)

add_executable(scraper main.cpp fetch.cpp fetch.hpp extract.cpp extract.hpp)
target_link_libraries(scraper ${CURL_LIBRARIES})


add_executable(interpret interpret.cpp
                name_list.cpp name_list.hpp
                adjustment.cpp adjustment.hpp
                win_loss_records.cpp win_loss_records.hpp)
