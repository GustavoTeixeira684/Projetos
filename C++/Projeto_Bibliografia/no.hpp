/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#ifndef NO_HPP
#define NO_HPP

#include "bibliografia.hpp"

class No{
	
	private:
		Bibliografia *item; // Ponteiro que aponta paara os valores do nó atual
		No *prox;
		No *anterior;
	
	public:
		No(); // Construtor sem parâmetros
		No(string *values, No *prox, No *anterior); // Construtor com parâmetros
		No *getProx(); // Retorna o próximo nó
		void setProx(No *prox); // Define o próximo nó
		No *getAnterior(); // Retorna o nó anterior
		Bibliografia *getItem(); // Retorna ponteiro para os itens do nó
		void setItem(Bibliografia *item); // Define o endereço para os itens do nó
		void setAnterior(No *anterior); // Define o nó anterior
	
};

#endif




