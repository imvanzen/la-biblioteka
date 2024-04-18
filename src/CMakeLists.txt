project(LaBiblioteka VERSION 0.1.0 LANGUAGES C CXX)

add_library(Book
    Book.cpp
)

target_include_directories(Book
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)