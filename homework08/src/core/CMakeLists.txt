add_library(project-manager 
    src/task.cpp
)

target_include_directories(project-manager 
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)