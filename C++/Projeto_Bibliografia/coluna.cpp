/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include "coluna.hpp"

Coluna::Coluna(){ // Construtor

	// Insere os valores padrão para as colunas

	this->colDisciplina = "Disciplina";
	this->colIsbn = "ISBN";
	this->colTitulo = "Título";
	this->colAutor = "Autor";
	this->colEdicao = "Edição";
	this->colCidade = "Cidade";
	this->colEditora = "Editora";
	this->colAno = "Ano";
	this->colBibliografia_basica = "Bibliografia Básica";
}

Coluna::Coluna(string *values){ // Construtor com parâmetro
	
	// Recebe um vetor e insere os valores nos atributos da coluna
	
	this->colDisciplina = values[0];
	this->colIsbn = values[1];
	this->colTitulo = values[2];
	this->colAutor = values[3];
	this->colEdicao = values[4];
	this->colCidade = values[5];
	this->colEditora = values[6];
	this->colAno = values[7];
	this->colBibliografia_basica = values[8];
	
	values = nullptr;
	
}

string* Coluna::getColumns(){ // Retorna um array com todos os valores da coluna
	string *values = new string[9]; // Cria vetor cujo tamanho é igual a quantidade de colunas
	
	// Insere os atributos no vetor
	values[0] = this->colDisciplina;
	values[1] = this->colIsbn;
	values[2] = this->colTitulo;
	values[3] = this->colAutor;
	values[4] = this->colEdicao;
	values[5] = this->colCidade;
	values[6] = this->colEditora;
	values[7] = this->colAno;
	values[8] = this->colBibliografia_basica;
	
	return values; // Retorna o vetor
	
}
