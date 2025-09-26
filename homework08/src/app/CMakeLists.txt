add_library(app app.cpp)

option(USEANOTHERLIB "Fake option just to try it" ON)

if(USEANOTHERLIB)
    target_compile_definitions(app PRIVATE "USEANOTHERLIB")
endif()