/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include "no.hpp"

No::No(){ // Construtor
	this->item = nullptr;
	this->prox = nullptr;
	this->anterior = nullptr;
}

No::No(string *values, No *prox, No *anterior){ // Construtor com parâmetros
	this->prox = prox; // Define o próximo nó
	this->anterior = anterior; // Define o nó anterior
	Bibliografia *item = new Bibliografia(values); // Cria uma bibliografia com os valores passados pelo usuário
	this->item = item; // Atribui a bibliografia criada ao nó
	
	values = nullptr;
	prox = nullptr;
	anterior = nullptr;
	
}

No* No::getProx(){ // Retorna o próximo nó
	return this->prox;
}

void No::setProx(No *prox){ // Define o próximo nó
	this->prox = prox;
}

No* No::getAnterior(){ // Retorna o nó anterior
	return this->anterior;
}

Bibliografia * No::getItem(){ // Retorna ponteiro para os itens do nó
	return this->item;
}

void No::setItem(Bibliografia *item){ // Define o endereço para os itens do nó
	this->item = item;
}

void No::setAnterior(No *anterior){ // Define o nó anterior
	this->anterior = anterior;
}
