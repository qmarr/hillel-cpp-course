add_library(app 
    src/app.cpp
)

target_include_directories(app
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

option(USEANOTHERLIB "Fake option just to try it" ON)

if(USEANOTHERLIB)
    target_compile_definitions(app PRIVATE "USEANOTHERLIB")
endif()

target_include_directories(app
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(app PUBLIC compiler_flags)


