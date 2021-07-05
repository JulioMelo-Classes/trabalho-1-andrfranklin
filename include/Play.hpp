#ifndef Play_hpp
#define Play_hpp

#include <vector>
using std::vector;

vector<int> sorteio();

vector<int> acertos(std::vector<int> values, std::vector<int> sorteio);

double calculaPontos(int spots, int hits);

#endif