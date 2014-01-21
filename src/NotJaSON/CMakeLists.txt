project(NotJaSON CXX)

file(GLOB NotJaSON_FILES include/*.hpp src/*.cpp)

add_library(${PROJECT_NAME} ${NotJaSON_FILES})