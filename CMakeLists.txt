cmake_minimum_required(VERSION 3.8)
set (CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp)	
set(CURVES_LIB source/circle.cpp
			   source/point.cpp
			   source/ellipse.cpp
			   source/helix.cpp)
set(TESTS_SRC tests/curves_tests.cpp
			  tests/circle_test.cpp
			  tests/ellipse_test.cpp
			  tests/helix_test.cpp)

project(curves C CXX)
project(main C CXX)
project(tests C CXX)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_library(curves SHARED ${CURVES_LIB})
add_executable(main ${SOURCES})
add_executable(tests ${TESTS_SRC})

target_include_directories(main PUBLIC include)		
target_include_directories(curves PUBLIC include)
target_include_directories(tests PUBLIC include)

target_link_libraries(main curves)
target_link_libraries(tests curves ${GTEST_LIBRARIES} ) 	
