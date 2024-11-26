cmake_minimum_required(VERSION 3.1)
project("GraphProject")
set(OPENGL_USE_OPENGL ON)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_C_VERSION 17)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.h ${CMAKE_CURRENT_SOURCE_DIR}/src/vertex.h ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.h)
set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.c ${CMAKE_CURRENT_SOURCE_DIR}/src/vertex.c ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.c)


add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})
add_definitions(-DGLEW_STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/glfw/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/glew/include")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} GLEW)
target_link_libraries(${PROJECT_NAME} glfw)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})






