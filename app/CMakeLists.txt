project(App)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

find_package(OpenMP)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE
    Curves
    OpenMP::OpenMP_CXX
)
