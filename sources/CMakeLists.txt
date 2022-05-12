project(daisy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp jsnexus/*.cpp)
file(GLOB HEADERS *.h jsnexus/*.h)

set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_dependencies(${PROJECT_NAME} mujs loguru)

target_link_libraries(${PROJECT_NAME} mujs loguru)

