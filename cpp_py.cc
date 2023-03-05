#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

void exec(std::string const& file) {
	auto cmd = "with open(\"" + file + "\", \"rb\") as f:\n\tprint(len(f.read()))\n";
	py::exec(cmd);
}

int main(int argc, const char** argv) {
	py::scoped_interpreter guard{}; // start the interpreter and keep it alive
	std::string file = argc >= 2 ? argv[1] : "/dev/stdin";
	exec(file);
	return 0;
}