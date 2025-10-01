cmake_minimum_required(VERSION 4.1)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

project(cmaketasting VERSION 0.1)
configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(cmaketasting
    main.cpp
)

target_include_directories(cmaketasting PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src/app/include"
    "${PROJECT_SOURCE_DIR}/src/core/include"
    
)

#compiler flags like c++ version
add_library(compiler_flags INTERFACE)

target_compile_features(compiler_flags INTERFACE cxx_std_20)

target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

target_link_libraries(cmaketasting PUBLIC app project-manager compiler_flags)


add_subdirectory(src/app)
add_subdirectory(src/core)
