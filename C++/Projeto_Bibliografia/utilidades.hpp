/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

#include <iostream>

using namespace std;

int tamanho(string texto); // Retorna o tamanho da string

int stringToInt(string texto); // Converte de string para inteiro

string intToString(int texto); // Converte de inteiro para string

string *strsplit(string texto, char delimitador, int *tamanhoVetor); // Transforma uma string em um vetor de strings separado por um delimitador

string strTrim(string texto); // Remove espa�os no come�o e final da string (Utilizado para padroniza��o de checagem)

string toLower(string texto); // Converte os caracteres mai�sculos para min�sculos (Utilizado para padroniza��o de checagem)

int stringCompare(string a, string b); // Compara qual string vem primeiro em ordem lexicogr�fica

void transformaMatrizOrdenada(string *vetor_a, string *vetor_b, int tamanho_linhas); // Ordena os arrays em ordem crescente

bool checaNumero(string texto); // Verifica se uma string corresponde a um valor num�rico

string removeAcentos(string texto); // Remove acentos da string (Utilizado para padroniza��o de checagem)

string preparaTexto(string texto); // Transforma o texto em um texto padr�o (Utilizado para manter o c�digo limpo)

#endif
