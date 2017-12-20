cmake_minimum_required(VERSION 3.9)
project(google_test_demo)

set(CMAKE_CXX_STANDARD 11)

#include googletest/include dir
include_directories(/home/U203872/git/googletest/googletest/include)

#include the googlemock/include dir
include_directories(/home/U203872/git/googletest/googlemock/include)

add_executable(google_test_demo main.cpp HtmlParser.cpp HtmlParser.h HttpFetch.cpp HttpFetch.h)
add_executable(google_test_demo_test HtmlParser.cpp HtmlParser.h HttpFetch.cpp HttpFetch.h HttpTest.cpp HttpTest.h HttpFetchMock.cpp HttpFetchMock.h)

#Link with GoogleTest
target_link_libraries(google_test_demo_test gtestd gtest_maind)

#Link with GoogleTest
target_link_libraries(google_test_demo_test pthread)

#Link with GoogleMock
target_link_libraries(google_test_demo_test gmockd)