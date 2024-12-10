project(Curves)

add_library(
    ${PROJECT_NAME} STATIC
    Circle.cpp
    Ellipse.cpp
    Helix.cpp
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
