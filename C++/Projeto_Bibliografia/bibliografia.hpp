/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#ifndef BIBLIOGRAFIA_HPP
#define BIBLIOGRAFIA_HPP

#include <iostream>


using namespace std;

class Bibliografia{
	
	private: // Atributos da Bibliografia
		string disciplina;
		string isbn;
		string titulo;
		string autor;
		int edicao;
		string cidade;
		string editora;
		int ano;
		bool bibliografia_basica;
		
	public:
		Bibliografia(); // Construtor
		Bibliografia(string *values); // Construtor com parâmetros
		string *getValues(); // Retorna um vetor com todos os valores da Bibliografia
		string getIsbn(); // Retorna o ISBN
		string getTitulo(); // Retorna o Título
		string getAutor(); // Retorna o Autor
		int getEdicao(); // Retorna a Edição
		string getCidade(); // Retorna a Cidade
		string getEditora(); // Retorna a Editora
		int getAno(); // Retorna o Ano
		string getBibliografia_basica(); // Retorna a Bibliográfia Básica
		string getDisciplina(); // Retorna a Disciplina

};

#endif
