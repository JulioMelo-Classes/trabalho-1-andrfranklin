#include <iostream>
#include <iomanip>
#include <cstdio>

#include "../include/Util.hpp"
#include "../include/Aposta.hpp"
#include "../include/Play.hpp"

/*
Avaliação
Processamento do Arquivo de Entrada: 1
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 1
Comentários:
- O arquivo play.cpp poderia ser facilmente transformado em uma classe Play ou KenoGame, algo do tipo, uma vez que logicamente
o arquivo contém funções relacionadas ao jogo.
- O arquivo util.cpp faz sentido em muitos casos porém o que ele faz no seu programa é validar o arquivo de apostas, logo faria
mais sentido nomeá-lo de forma que remetesse o que realmente é feito. Uma forma legal era emcapsular o arquivo de apostas
em uma classe e criar um método "isValid" ou "validate" que chamaria as funções/métodos que vc implementou no util.
*/

using namespace std;

int main(int argc, char *argv[]){
	cout << ">>> Lendo arquivos de apostas [" << argv[1] << "]. Por favor, aguarde." << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	//valida documento de aposta
	bool result = documentIsValid(argv);

	if(result){
		//transforma documento de aposta em um objeto Aposta
		Aposta aposta = fileToValues(argv);
		cout << ">>> Arquivo lido com sucesso!" << endl;

		cout << ">>> Você apostará um total de $" << aposta.get_credits() << endl;

		double apostaPorRodada = aposta.get_credits()/aposta.get_rounds();

		cout << ">>> Jogará um total de " << aposta.get_rounds() << " rodadas, apostando " << apostaPorRodada << " créditos por rodada" << endl;
		cout << ">>> Sua aposta tem " << aposta.get_spots().size() << " números, eles são : [ "; 
		for(int i = 0; i < aposta.get_spots().size(); i++){
			cout << aposta.get_spots()[i] <<  " ";
		}
		cout << "]" << endl;

		cout << "--------------------------------------------------------------------------------" << endl;
		cout << ">>> Daremos inicio as rodadas agora: \n" << endl;

		//executa o jogo
		for(int i = 0; i < aposta.get_rounds(); i++ ){
			cout << "Esta é a aposta de número " << i+1 << " de " << aposta.get_rounds() << ". Boa sorte!" << endl;

			aposta.set_less_credit(apostaPorRodada);
			
			vector<int> numerosSorteados = sorteio();
			cout << "Os números sorteados são: [ ";
			for(int i = 0; i < 20; i++){
				cout << numerosSorteados[i] << " ";
			}
			cout << "]\n" << endl;

			//valida número de acertos
			vector<int> numerosAcertados = acertos(aposta.get_spots(), numerosSorteados);
			if(numerosAcertados.size() < 1){
				cout << "Infelizmente você não acertou nenhum número.\n" << endl;
			}else{
				
				cout << "Você acertou os números: [ ";
				for(int i = 0; i < numerosAcertados.size(); i++){
					cout << numerosAcertados[i] << " ";
				}
				cout << "]\n" << endl;
				
				//calcula taxa de retorno
				double pontuacao = calculaPontos(aposta.get_spots().size(), numerosAcertados.size());

				//calcula premio total
				double premio = pontuacao * apostaPorRodada;

				//adiciona premio aos créditos
				aposta.set_plus_credit(premio);

				cout << "Sua taxa de retorno é de " << pontuacao << ", assim você sai com: $" << premio << endl;
				cout << "você possui um total de: $" << aposta.get_credits() << " créditos.\n" << endl;
			}
			cout << "--------------------------------------------------------------------------------" << endl;
		}
		cout << ">>> Fim das rodadas" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "======= Sumário =======" << endl;
		double inicial = apostaPorRodada * aposta.get_rounds();

		cout << "Você gastou um total de $" << inicial << " cŕeditos" << endl;
		if(inicial < aposta.get_credits()){
			cout << "Hooray! você ganhou $" << aposta.get_credits()-inicial << " créditos!" << endl;
		}else{
			cout << "Sinto muito! você perdeu $" << fixed << setprecision(2) << inicial - aposta.get_credits() << " créditos :(" << endl;
		}
		cout << "Você está saindo do jogo com um total de $" << aposta.get_credits() << " créditos!" << endl;
	}else{
		cout << "Arquivo de aposta inválido" << endl;
	}


  return 0;
}
