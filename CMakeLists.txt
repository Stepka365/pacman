cmake_minimum_required(VERSION 3.24)
project(labo_4th)
set(CMAKE_CXX_STANDARD 17)

set(SFML C:/Users/selya/programming/SFML+MinGW)

file(GLOB my_src source/*.cpp source/*/*.cpp)
add_executable(${PROJECT_NAME} ${my_src})

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML}/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${SFML}/lib)
target_compile_definitions(${PROJECT_NAME} PUBLIC SFML_STATIC)

if(${CMAKE_BUILD_TYPE} MATCHES Release)
    target_link_libraries(${PROJECT_NAME} sfml-graphics-s sfml-window-s sfml-system-s)
elseif(${CMAKE_BUILD_TYPE} MATCHES Debug)
    target_link_libraries(${PROJECT_NAME} sfml-graphics-s-d sfml-window-s-d sfml-system-s-d)
else()
    message("Can't identify build type, should be Release or Debug")
endif()

target_link_libraries(${PROJECT_NAME} opengl32 freetype winmm gdi32)
