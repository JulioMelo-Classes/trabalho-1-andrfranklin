#ifndef Util_hpp
#define Util_hpp

#include <vector>
using std::vector;
#include <string>
using std::string;
#include "../include/Aposta.hpp"

vector<std::string> splitString(std::string s);

vector<std::string> lineInPosition(char *argv[]);

bool documentIsValid(char *argv[]);

Aposta fileToValues(char *argv[]);

vector<int> sortArray(std::vector<int> num);

#endif