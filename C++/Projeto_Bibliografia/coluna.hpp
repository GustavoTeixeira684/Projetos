/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/
#ifndef COLUNA_HPP
#define COLUNA_HPP
#include <iostream>
using namespace std;


class Coluna{
	
	private: // Atributos da Coluna
		string colDisciplina;
		string colIsbn;
		string colTitulo;
		string colAutor;
		string colEdicao;
		string colCidade;
		string colEditora;
		string colAno;
		string colBibliografia_basica;
		
	public:
		Coluna(); // Construtor
		Coluna(string* values); // Construtor com par�metros
		string* getColumns(); // Retorna um array com todos os valores da coluna
	
};

#endif




