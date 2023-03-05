cmake_minimum_required(VERSION 3.0.0)
project(io)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(pybind11)

add_executable(cpp cpp.cc)

add_executable(cpp_py cpp_py.cc)
target_link_libraries(cpp_py PRIVATE pybind11::embed)

execute_process(
    COMMAND bash "-c" "rustc rust.rs -O -o build/rust"
)