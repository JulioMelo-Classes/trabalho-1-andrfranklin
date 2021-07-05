#include <vector>
#include <random>
#include <fstream>

#include "../include/Util.hpp"

using namespace std;

/*! 
 * Sorteia 20 números aleatórios únicos em um range de 1 à 80.
 *
 * @return Um vetor de inteiros com os números sorteados.
 */
vector<int> sorteio(){
	vector<int> values;
	for(int i = 0; i < 20; i++){
		while(true){
			int n = rand() % 80 + 1;
			bool isEqual = false;
			for(int j = 0; j < i; j++){
				if(n == values[j]){
					isEqual = true;
					break;
				}
			}
			if(!isEqual){
				values.push_back(n);
				break;
			}
		}	
	}

	values = sortArray(values);
	return values;
}

/*! 
 * Recebe dois vetores sendo o primeiro os spots da aposta, e o segundo os números
 * sorteados pelo jogo, e retorna um vetor de inteiros com os números acertados pelo
 * jogador.
 *
 * @param vector<int> values e um vetor de inteiros.
 * @param vector<int> sorteio e um vetor de inteiros.
 * 
 * @return Um vetor de inteiros com os números que estão presente em ambos os vetores.
 */
vector<int> acertos(vector<int> values, vector<int> sorteio){
	vector<int> acertos;

	for(int i = 0; i < values.size(); i++){
		for(int j = 0; j < 20; j++){
			if(values[i] == sorteio[j]){
				acertos.push_back(values[i]);
			}
		}
	}

	return acertos;
}

/*! 
 * Recebe a quantidade de spots apostados pelo jogador, e a quantidade de hits obtidos e
 * retorna a taxa de retorno obtida.
 *
 * @param int Spots, quantidade de spots apostados pelo jogador.
 * @param int hits, quantidade de acertos obtidos pelo jogador.
 * 
 * @return Um double com a taxa de retorno obtida.
 */

double calculaPontos(int spots, int hits){
	ifstream matriz("table.dat");

	string line;
	for(int i = 1; i <= spots; i++){
		getline(matriz, line);
	}

	vector<string> valores = splitString(line);
	string taxaRetorno = valores[hits];

	return std::stod(taxaRetorno);

}