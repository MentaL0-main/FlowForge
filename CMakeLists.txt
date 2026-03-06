cmake_minimum_required(VERSION 3.20)  # 4.0 еще не вышла!

project(FlowForge)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Sources src/main.cpp
            src/canvas.cpp)

# Создаем таргет ПЕРЕД использованием
add_executable(FlowForge ${Sources})  # убрал запятую!

find_package(SDL3 REQUIRED)

# target_link_libraries после создания таргета
target_link_libraries(FlowForge PRIVATE SDL3::SDL3)

# target_include_directories с PRIVATE и правильным путем
target_include_directories(FlowForge PRIVATE ${CMAKE_SOURCE_DIR}/include)

