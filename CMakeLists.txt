cmake_minimum_required (VERSION 2.8.11)
project (battle)

add_executable (${PROJECT_NAME} pokebattle.cpp Pokemon.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
