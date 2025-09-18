add_library(projectmanager-core)
add_library(projectmanager::core ALIAS projectmanager-core)

target_sources(projectmanager-core
  PRIVATE
    src/project.cpp
    src/task.cpp
    src/storage.cpp
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/core/project.h
      include/core/task.h
      include/core/storage.h
)

target_include_directories(projectmanager-core
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>  # future-proof if you install
)

target_link_libraries(projectmanager-core
  PUBLIC
    nlohmann_json::nlohmann_json
  PRIVATE
    spdlog::spdlog
    fmt::fmt
)

# Optional features advertised to dependents via compile defs
if (PM_WITH_SQLITE)
  target_compile_definitions(projectmanager-core PUBLIC PM_HAS_SQLITE=1)
  target_link_libraries(projectmanager-core PRIVATE sqlite3::sqlite3)
endif()

if (PM_WITH_BOOST)
  target_compile_definitions(projectmanager-core PUBLIC PM_HAS_BOOST=1)
  target_link_libraries(projectmanager-core PRIVATE boost::filesystem boost::system)
endif()

pm_apply_warnings(projectmanager-core)
