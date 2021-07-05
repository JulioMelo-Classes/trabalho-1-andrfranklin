#include "../include/Aposta.hpp"
#include <vector>

using namespace std;

/*! 
 * Construtor para um objeto aposta vazio;
 */
Aposta::Aposta(){};

/*! 
 * Construtor para um objeto de aposta;
 *
 * @param Double credit_ com a quantidade de créditos apostado pelo jogador.
 * @param int rounds_ com a quantidade de partidas que o jogador deseja apostar;
 * @param std::vector<int> um vetor de inteiros com os números apostados pelo jogador;
 *
 */
Aposta::Aposta(double credit_, int rounds_, std::vector<int> spots_){
	credit = credit_;
	rounds = rounds_;
	for(int i = 0; i != spots_.size(); i++){
		spots.push_back(spots_[i]);
	} 
}


/*! 
 * Retorna a quantidade de créditos armazenado no objeto Aposta;
 *
 *@return Um double com a quantidade de cŕeditos armazenado no objeto Aposta;
 */
double Aposta::get_credits(){
	return credit;
};

/*! 
 * Adiciona créditos ao credit do objeto Aposta;
 *
 * @param Double value_ com o valor a ser somado aos créditos.
 *
 */
void Aposta::set_plus_credit(double value_){
	credit += value_;
};


/*! 
 * Remove créditos do credit do objeto Aposta;
 *
 * @param Double value_ com o valor a ser subtraido dos créditos.
 *
 */
void Aposta::set_less_credit(double value_){
	credit -= value_;
};

/*! 
 * Retorna a quantidade de rounds do objeto Aposta;
 */
int Aposta::get_rounds(){
	return rounds;
};

/*! 
 * Retorna um vetor com os spots armazenados no objeto Aposta;
 */
std::vector<int> Aposta::get_spots(){
	return spots;
};