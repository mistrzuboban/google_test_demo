cmake_minimum_required(VERSION 3.9)
project(google_test_demo)

set(CMAKE_CXX_STANDARD 11)

#include googletest/include dir
include_directories(googletest/include)

#include the googlemock/include dir
include_directories(googlemock/include)

add_executable(google_test_demo main.cpp HtmlParser.cpp HtmlParser.h HttpFetch.cpp HttpFetch.h)
add_executable(google_test_demo_test HtmlParser.cpp HtmlParser.h HttpFetch.cpp HttpFetch.h HttpTest.cpp HttpTest.h HttpFetchMock.cpp HttpFetchMock.h)

find_library(GOOGLE_TEST_MAIN_LIBRARY
        NAMES gtestd
        PATHS ${PROJECT_SOURCE_DIR}/public/libs NO_DEFAULT_PATH)

find_library(GOOGLE_TEST_LIBRARY
        NAMES gtest_maind
        PATHS ${PROJECT_SOURCE_DIR}/public/libs NO_DEFAULT_PATH)

find_library(GOOGLE_MOCK_LIBRARY
        NAMES gmockd
        PATHS ${PROJECT_SOURCE_DIR}/public/libs NO_DEFAULT_PATH)

message(" PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

#Link with GoogleTest
target_link_libraries(google_test_demo_test ${GOOGLE_TEST_LIBRARY} ${GOOGLE_TEST_MAIN_LIBRARY} ${GOOGLE_MOCK_LIBRARY})

#Link with GoogleTest
target_link_libraries(google_test_demo_test pthread)

#Link with GoogleMock
#target_link_libraries(google_test_demo_test gmockd)