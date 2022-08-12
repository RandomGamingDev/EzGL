cmake_minimum_required(VERSION 3.8)

find_path(STB_INCLUDE_DIRS stb.h)

add_executable(Example Settings.cpp Main.cpp Main.h)


target_include_directories(Example PUBLIC ${STB_INCLUDE_DIRS})

target_include_directories(Example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../EzGL)
target_link_libraries(Example PRIVATE EzGL)