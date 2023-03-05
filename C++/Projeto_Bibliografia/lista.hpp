/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#ifndef LISTA_HPP
#define LISTA_HPP
#include "No.hpp"
#include "Coluna.hpp"

class Lista{
	
	private:
		
		No *head;
		No *tail;
		Coluna *column;
		int length;

		
	
	public:
		Lista(); // Construtor
		No *getHead(); // Retorna o endereço do primeiro nó
		void setHead(No *head); // Define o endereço do primeiro nó
		No *getTail(); // Retorna o endereço do �ltimo nó
		void setTail(No *tail); // Define o endereço do último nó
		Coluna *getColumn(); // Retorna o endereço do nó onde armazena o valor das colunas
		void insertColumns(string *values); // Insere um nó para armazenar o valor das colunas
		int getlength(); // Retorna o tamanho da lista
		bool empty(); // Verifica se a lista está vazia
		bool full(); // Verifica se a lista está cheia
		void clear(); // Limpa a lista
		No *busca(string chave); // Busca um valor baseado em uma chave (ISBN)
		bool remove(string chave); // Remove um nó da lista
		bool insert(string *values); // Insere um nó na lista
		bool update(string *values, No *linhaAlterada); // Altera um nó da lista
		void printColumns(); // Exibe o valor das colunas
		void printValues(); // Exibe todos os valores contidos na lista
		void printValue(int opcao, string parametro); // Exibe os valores da lista baseado em um filtro
		void printLine(string *values); // Exibe uma lina específica (Utilizaado nos dois métodos acima)
		string *retornaAnalise(int indice_categoria, string texto_exibicao, int *tamanho_vetor); // Retorna uma análise que contem os valores distintos e sua quantidade baseado em uma categoria (coluna)
		void printProporcoes(int indice_categoria, string texto_exibicao); // Exibe uma análise baseada em proporção de uma determinada coluna da lista
		void printMaiores(); // Exibe uma análise que contem as maiores recorrências de uma determinada coluna da lista
		
	
};

#endif
