#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <sstream>
#include <vector>
#include <iterator>

// String splitting
template<typename Out>
void splitHelper(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    splitHelper(s, delim, std::back_inserter(elems));
    return elems;
}
#endif