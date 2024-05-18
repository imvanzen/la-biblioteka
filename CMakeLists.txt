cmake_minimum_required(VERSION 3.29.2)
project(LaBiblioteka VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src)

set(MAIN_SOURCES
    src/main.cpp
)

add_executable(la-biblioteka ${MAIN_SOURCES}) 

target_link_libraries(la-biblioteka PRIVATE utils)
target_link_libraries(la-biblioteka PRIVATE Book)
target_link_libraries(la-biblioteka PRIVATE Library)
target_link_libraries(la-biblioteka PRIVATE Menu)
target_link_libraries(la-biblioteka PRIVATE Storage)
