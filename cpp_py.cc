#include <iostream>
#include <vector>
#include <string_view>
#include <pybind11/embed.h>
namespace py = pybind11;

int main(int argc, const char** argv) {
    py::scoped_interpreter guard{};

    std::string input_file = argc >= 2 ? argv[1] : "/dev/stdin";

    // Define a variable in Python
    py::globals()["input_file"] = input_file;
    py::exec(R"(
        with open(input_file, "rb") as f:
            buf = f.read()
    )");

    // Access the variable from C++
    py::object buf = py::globals()["buf"];
    auto content = buf.cast<std::string_view>();
    std::cout << content.size() << "\n";
    return 0;
}