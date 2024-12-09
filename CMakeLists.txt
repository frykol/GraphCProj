cmake_minimum_required(VERSION 3.12)
project("GraphProject")

set(OpenGL_GL_PREFERENCE GLVND)
if(UNIX)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
endif()
find_package(OpenGL REQUIRED)

set(CMAKE_C_VERSION 17)
#set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.h ${CMAKE_CURRENT_SOURCE_DIR}/src/vertex.h ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.h ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer.h ${CMAKE_CURRENT_SOURCE_DIR}/stb/stb_image.h)
#set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.c ${CMAKE_CURRENT_SOURCE_DIR}/src/vertex.c ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.c ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer.c)

file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
file(GLOB HEADERS2 "${CMAKE_CURRENT_SOURCE_DIR}/stb/*.h")
list (APPEND HEADERS ${HEADERS2}) 
file(GLOB SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
list (APPEND HEADERS ${SOURCE2}) 
add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})
add_definitions(-DGLEW_STATIC)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/glfw/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/glew/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/freetype/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/stb")

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS})

if(WIN32)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/glew/lib/Release/Win32/libglew32.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/glfw/lib-vc2015/libglfw3.a)

else()
target_link_libraries(${PROJECT_NAME} GLEW)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} m)
endif()
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})






