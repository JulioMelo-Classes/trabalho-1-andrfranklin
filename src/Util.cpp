#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include "../include/Aposta.hpp"

using namespace std;

/*! 
 * Recebe uma string e quebra a cada espaço.
 *
 * @param S Uma string que será "fatiada"
 * 
 * @return retorna um vetor do tipo string em que cada posição corresponde a uma "fatia"
 * da string s quebrada em espaços.
 */
vector<string> splitString(string s){
	vector<string> v;
	stringstream ss(s);
	string t;
	while(ss >> t){
		v.push_back(t);
	}
	return v;
}

/*! 
 * Recebe um ponteiro para um array de argumentos, que será utilizado para capturar o
 * arquivo passado através do argumento, e retorna um vetor de strings com cada linha como
 * uma posição do vetor.
 *
 * @param *argv um ponteiro para um array de argumentos
 * 
 * @return Um vetor do tipo string, em que cada posição corresponde a uma linha do arquivo
 * lido.
 */
vector<string> lineInPosition(char *argv[]){
	vector<string> v;
	ifstream file;
	file.open(argv[1]);

	string credit;
	getline(file, credit);
	string rounds;
	getline(file, rounds);
	string spots;
	getline(file, spots);

	v.push_back(credit);
	v.push_back(rounds);
	v.push_back(spots);

	file.close();
	return v;
}

/*! 
 * Valida um arquivo no formato especificado do trabalho, e também: 
 * - Se o arquivo possui somente 3 linha;
 * - Se a primeira linha é um double
 * - Se a segunda linha é um inteiro
 * - Se existem somente números digitados
 * - Se o usuário está apostando mais de 3 créditos, pois o mínimo para cada rodada é 1
 * crédito.
 * - Se não existe valores repetidos na aposta do usuário
 *
 *
 * @param *argv Um ponteiro para um array de argumentos, que é usado para ler o arquivo de
 * aposta.
 * 
 * @return Verdadeiro se o arquivo de aposta passar em todos os teste, caso contrário,
 * retorna falso;
 */
bool documentIsValid(char *argv[]){
	ifstream file;
	file.open(argv[1]);

	int qtdLines = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

	// verifica se o arquivo possui mais de 3 linhas
	if(qtdLines >= 3){
		cout << "Arquivo invalido" << endl;
		return false;
	}

	regex regexDouble("[0-9]+\\.[0-9]+");
	regex regexInt("[0-9]+");

	vector<string> strings = lineInPosition(argv);

	// verigica se a primeira linha do arquivo é um double
	if(!regex_match(strings[0], regexDouble)){
		cout << "O crédito para aposta precisa ser um valor com ponto flutuante" << endl;
		return false;
		//verifica se a segunda linha do arquivo é um inteiro
	}else if(std::stod(strings[0]) < 3){
		cout << "É necessário ter crédito maior ou igual a 3.0 para jogar" << endl;
		return false;
	}else if(!regex_match(strings[1], regexInt)){
		cout << "O número de apostas deve ser um número inteiro" << endl;
		return false;
	}

	vector<string> values = splitString(strings[2]);

	//verifica se a quantidade de elementos ultrapassa 15 números
	if(values.size() > 15){
		cout << "Só é possível fazer apostas com no máximo 15 números" << endl;
		return false;
	}

	//verifica se os valores são inteiros e se existe valores repetidos
	for(int i = 0; i < values.size(); i++){
		string t = values[i];

		if(!regex_match(values[i], regexInt)){
			cout << "Os números para aposta devem ser inteiros" << endl;
			return false;
		}
		int num = stoi(t);
		if(num < 1 || num > 80){
			cout << "Os números devem entrar entre 1 e 80" << endl;
			return false;
		}
		for(int j = i+1; j < values.size(); j++){
			if(t == values[j]){
				cout << "Os números para aposta não devem se repetir" << endl;
				return false;
			}
		}
	}

	return true;
}


/*! 
 * Recebe um vetor de inteiros e o ordena de modo crescente.
 *
 * @param vector<int> um vetor de inteiros.
 * 
 * @return Um vetor de inteiros ordenado de forma crescente.
 */
vector<int> sortArray(vector<int> num){
	for(int i = 0; i < num.size()-1; i++){
		for(int j = 0; j < num.size()-1; j++){
			if(num[j] > num[j+1]){
				swap(num[j], num[j+1]);
			}
		}
	}
	return num;
}

/*! 
 * Recebe arquivo de apostas através de um array de argumentos e retorna um objeto do tipo
 * Aposta.
 *
 * @param *argv Vetor de argumentos para realizar a leitura do arquivo de apostas.
 * 
 * @return Um objeto do tipo aposta preenchido com os dados lidos do aquivo de aposta.
 */
Aposta fileToValues(char *argv[]){
	vector<string> lines = lineInPosition(argv);
	double credit = std::stod(lines[0]);
	int rounds = std::stoi(lines[1]);

	vector<string> spotString = splitString(lines[2]);

	vector<int> spots;
	for(int i = 0; i < spotString.size(); i++){
		spots.push_back(std::stoi(spotString[i]));
	}

	spots = sortArray(spots);

	Aposta ap(credit, rounds, spots);

	return ap;
}