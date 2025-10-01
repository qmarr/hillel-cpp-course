add_library(project-manager 
    src/task.cpp
)

target_include_directories(project-manager 
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

find_package(nlohmann_json REQUIRED CONFIG)

target_link_libraries(project-manager
    PUBLIC nlohmann_json::nlohmann_json
)