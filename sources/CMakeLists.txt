project(daisy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_dependencies(${PROJECT_NAME} mujs loguru)

target_link_libraries(${PROJECT_NAME} mujs loguru)

