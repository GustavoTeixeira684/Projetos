/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include "bibliografia.hpp"
#include <iostream>
#include "utilidades.hpp"

using namespace std;

Bibliografia::Bibliografia(){ // Construtor
	
	// Atribui valores padrão para a Bibliografia
	this->disciplina = "";
	this->isbn = "";
	this->titulo = "";
	this->autor = "";
	this->edicao = 0;
	this->cidade = "";
	this->editora = "";
	this->ano = 0;
	this->bibliografia_basica = false;
	
}

Bibliografia::Bibliografia(string *values){ // Construtor com parâmetros
	
	// Recebe vetor com os valores da bibliografia e insere nos atributos
	
	this->disciplina = values[0];
	this->isbn = values[1];
	this->titulo = values[2];
	this->autor = values[3];
	this->edicao = stringToInt(values[4]); // Converte de string para int para inserir a Edição
	this->cidade = values[5];
	this->editora = values[6];
	this->ano = stringToInt(values[7]); // Converte de string para int para inserir o Ano
	if(values[8] == "S"){ // Se o valor digitado for S
		this->bibliografia_basica =true; // bibliografia_basica recebe true
	}else{ // Se o valor digitado não for S (Significa que é N)
		this->bibliografia_basica = false; // bibliografia_basica recebe false
	}
	
	values = nullptr;
	
}

string Bibliografia::getDisciplina(){ // Retorna a Disciplina
	return this->disciplina;
}

string Bibliografia::getIsbn(){ // Retorna o ISBN
	return this->isbn;
} 

string Bibliografia::getTitulo(){ // Retorna o Título
	return this->titulo;
}

string Bibliografia::getAutor(){ // Retorna o Autor
	return this->autor;
}

int Bibliografia::getEdicao(){ // Retorna a Edição
	return this->edicao;
}

string Bibliografia::getCidade(){ // Retorna a Cidade
	return this->cidade;
}

string Bibliografia::getEditora(){ // Retorna a Editora
	return this->editora;
}

int Bibliografia::getAno(){ // Retorna o Ano
	return this->ano;
}

string Bibliografia::getBibliografia_basica(){ // Retorna a Bibliografia Básica
	if(this->bibliografia_basica){
		return "S";
	}else{
		return "N";
	}
}

string *Bibliografia::getValues(){ // Retorna um vetor com todos os valores da Bibliografia
	
	string *values = new string[9]; // Cria um vetor cujo tamanho é igual a quantidade de colunas da lista
	
	// Atribui os valores dos atributor para um vetor
	
	values[0] = this->disciplina;
	values[1] = this->isbn;
	values[2] = this->titulo;
	values[3] = this->autor;
	values[4] = intToString(this->edicao); // Converte de int para string para poder passar para o vetor
	values[5] = this->cidade;
	values[6] = this->editora;
	values[7] = intToString(this->ano); // Converte de int para string para poder passar para o vetor
	if(this->bibliografia_basica){ // Se bibliografia_basica for true
		values[8] = "S"; // Passa "S" para o vetor
	}else{ // Se bibliografia_basica for false
		values[8] = "N"; // Passa "N" para o vetor
	}
	
	
	return values; // Retorna o vetor
}


