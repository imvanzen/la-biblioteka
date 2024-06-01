project(LaBiblioteka VERSION 0.1.0 LANGUAGES C CXX)

add_library(utils
    utils.cpp
)
add_library(Book
    Book.cpp
)
add_library(User
    User.cpp
)
add_library(Library
    Library.cpp
)
add_library(Storage
    Storage.cpp
)
add_library(Menu
    Menu.cpp
)

target_include_directories(Library
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)