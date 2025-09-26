cmake_minimum_required(VERSION 4.1)

project(cmaketasting VERSION 0.1)
configure_file(TutorialConfig.h.in TutorialConfig.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(cmaketasting
    main.cpp
)

target_include_directories(cmaketasting PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src/app"
    
)

add_subdirectory(src/app)

target_link_libraries(cmaketasting PUBLIC app)