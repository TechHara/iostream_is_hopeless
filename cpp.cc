#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, const char** argv) {
    std::ios::sync_with_stdio(false);
    std::string file = argc >= 2 ? argv[1] : "/dev/stdin";
    std::ifstream ifs{file};
    std::vector<char> buf{std::istreambuf_iterator<char>{ifs}, {}};
    std::cout << buf.size() << "\n";
    return 0;
}