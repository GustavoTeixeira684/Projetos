/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include <iostream>
#include <fstream>
#include <locale.h>
#include "lista.hpp"
#include "utilidades.hpp"

#define PATH "Archives/bibliografia.csv"
#define PATH_CIDADES "Archives/cidades.csv"
#define TAMANHO_CIDADES 5570

// ***** FUN��O PARA LER AS CIDADES DO BRASIL ***** //

string *lerCidades(){
	
	int contador = 0; // Inicia contador
	string *cidades = new string[TAMANHO_CIDADES]; // Inicia vetor para armazenar as cidades
	ifstream arquivo; // inicia a vari�vel para ler o arquivo
	arquivo.open(PATH_CIDADES); // abre o arquivo das cidades
	if(!arquivo.fail()){ // Se o arquivo foi aberto com sucesso
	
		while(arquivo.peek() != EOF){ // La�o para inserir os valores no vetor
			
			getline(arquivo, cidades[contador],'\n'); // Insere cada cidade no vetor
			contador++;
				
		}
		
	}
	return cidades; // Retorna vetor
	
}

// ***** FUN��O PARA LER AS BIBLIOGRAFIAS ***** //

bool readCSV(Lista *lista){
	
	ifstream arquivo; // Inicia a vari�vel para ler o arquivo
	arquivo.open(PATH); // Abre o arquivo das bibliografias
	if(!arquivo.fail()){ // Se o arquivo foi aberto com sucesso: 
		
		string result, columns[9], values[9]; // Inicia vari�veis para receber os valores da lista
		for(int i = 0; i < 8; i++){ // la�o para pegar as colunas
    		getline(arquivo, result, ';');
    		columns[i] = result;
  		}
  		
  		getline(arquivo, result, '\n');
  		columns[8] = result;
  		
  		lista->insertColumns(columns); // Chama fun��o da lista para atribuir os valores das colunas na lista
  		
  		while (arquivo.peek() != EOF) { // La�o para percorrer o restante do arquivo

		    for(int i = 0; i < 8; i++){ // La�o para percorrer cada linha do arquivo
    			getline(arquivo, result, ';');
    			values[i] = result;
  			}
		    getline(arquivo, values[8], '\n');
		   
		    lista->insert(values); // Chama o m�todo da lista para atribuir os valores das linhas na lista
 		}
  		
  		return true; // Retorna true
		
	}else{ // Se houve erro ao ler o arquivo
		return false; // Retorna false
	}
	
}

// ***** FUN��O PARA SALVAR A LISTA ***** //

bool writeCSV(Lista *lista){
	
	ofstream fout(PATH); // Inicia a vari�vel para gravar os dados da lista em um arquivo
	No *pAnda = lista->getHead(); // Pega o primeiro item da lista
	string *values = nullptr; // Inicia ponteiro que receber� os valores das linhas
	
	values = lista->getColumn()->getColumns(); // Chama o m�todo da lista para retornar os valores das colunas
	
	for(int i = 0; i < 8;i++){ // La�o para gravar os valores das colunas no arquivo
		fout<< values[i] << ";";
	}
	fout << values[8] << endl;
	
	delete[] values; // deleta os valores
	values = nullptr;
	
	for(int i = 0; i < lista->getlength();i++){ // La�o para gravar todas as linhas da lista no arquivo
		values = pAnda->getItem()->getValues(); // Pega a linha atual
		for(int k = 0; k < 8; k++){ // La�o para inserir todos os valores da linha no arquivo
						
			fout << values[k] << ";";
						
		}
		fout << values[8] << endl;
		pAnda = pAnda->getProx(); // Passa para o pr�ximo item da lista. (N�o � necess�rio atribuir nullptr a ela, pois na ultima itera��o ela ja recebe nullptr)
	}
	delete[] values; // Limpa ponteiros
	values = nullptr;
	return true;
	
}

// ***** FUN��O PARA CALCULAR TODAS AS BIBLIOGRAFIAS NACIONAIS ***** //
// Foi criada como uma fun��o e n�o como um m�todo da lista porque utiliza vari�veis externas � mesma

int calculaNacionais(Lista *lista){
	
	int nacionais = 0; // Inicia vari�vel que vai receber a quantidade de bibliografias nacionais
	string *cidade = lerCidades(); // Inicia um array ponteiro para receber todas as cidades do Brasil
	No *pAnda = lista->getHead(); // Pega o primeiro item da lista
	
	for(int i = 0; i < lista->getlength(); i++){ // La�o para percorrer todos os itens da lista
		for(int j = 0; j < TAMANHO_CIDADES; j++){ // La�o para percorrer todas as cidades do Brasil
			
			if(pAnda->getItem()->getCidade() == cidade[j]){ // Se o valor da cidade contido na linha atual for igual a alguma cidade na lista das cidades do Brasil
				nacionais++; // Incrementa a vari�vel "nacionais"
				break; // Encerra a itera��o
			}
			
		}
		pAnda = pAnda->getProx(); // Pega a pr�xima linha da lista
	}
	delete[] cidade;
	cidade = nullptr;
	return nacionais; // Retorna a quantidade de bibliografias nacionais da lista
	
}

// ******************** FUN��O MAIN ******************** //

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Lista *lista = new Lista(); // Inicia a lista
	No *aux = nullptr; // vari�vel auxiliar do tipo No
	string parametro, *values = nullptr, *colunas = nullptr; // inicia vari�veis auxiliares do tipo string para receber os valores das linhas / colunas e inputs do tipo texto
	bool sair = false, salvo = true, leu_arquivo = false; // Inicia vari�veis auxiliares do tipo booleano para controle do software
	int option, contador, nacionais, estrangeiros; // inicia vari�veis auxiliares do tipo int para auxiliar no controle do software
	
	do{ // Inicia la�o que se repetir� at� que o usu�rio decida sair do software
		
		cout << "\n\n--- Biblioteca Digital ---"<< endl << endl; // Exibe as op��es para o usu�rio
		cout << "O que deseja fazer?\n\t1 - Ler dados\n\t2 - Alterar nome das colunas\n\t3 - Exibir dados\n\t4 - Salvar dados\n\t5 - Inserir livro\n\t6 - Alterar livro" << endl;
		cout << "\t7 - Remover livro\n\t8 - An�lise de dados A\n\t9 - An�lise de dados B\n\t10 - An�lise de dados C\n\t11 - Encerrar\nEscolha: ";
		cin >> option;
		
		switch(option){
			
			case 1: // LER DADOS
				
				if(!leu_arquivo){ // Se o usu�rio ainda n�o leu o arquivo
					
					cout << "Lendo arquivo..." << endl; // Exibe mensagem avisando que a leitura est� iniciando
					
					if(readCSV(lista)){ // Se a leitura do arquivo e inser��o na lista foi bem-sucedida
						cout << "Arquivo lido com sucesso!" << endl; // Exibe mensagem avisando que a leitura foi bem-sucedida
						cout << "Foram lidas " << lista->getlength() << " linhas!\n\n"; // Exibe mensagem mostrando quantas linhas foram lidas
						salvo = true; // vari�vel que controla se a lista est� atualizada com o arquivo recebe true
						leu_arquivo = true; // Vari�vel que indica se o arquivo ja foi lido recebe true
					}else{ //Se a leitura n�o foi bem-sucedida
						cout << "Erro ao ler arquivo! Por favor, verifique se o arquivo est� no caminho correto (Archives/biblioteca.csv)"<< endl << endl; // Exibe mensagem informando o erro
					}
					
				}else{ // Se o arquivo ja foi lido
					
					cout << "\n\nO ARQUIVO JA FOI LIDO!\n\n"; // Exibe mensagem avisando o usu�rio
					
				}
					
			break;
			case 2: // ALTERAR NOME DE COLUNAS
				
				if(lista->getColumn() != nullptr){ // Se ja existem valores das colunas (Indicando que algum valor ja foi inserido na lista)
					
						colunas = lista->getColumn()->getColumns(); // Pega o valor das colunas
					
					cout << "O que voc� deseja alterar?"; // Exibe conjunto de mensagens mostrando o valor atual das colunas e perguntando qual valor o usu�rio deseja alterar
					for(int i = 0; i < 9; i++){
						cout << "\n\t" << i+1 << " - " << colunas[i];
					}
					cout << "\nEscolha: ";
					cin >> option;
					getchar();
					if(option > 0 && option <= 9){ // Condicional que garante que o usu�rio selecionou uma op��o v�lida
						cout << "\nDigite o novo nome para a coluna " << colunas[option - 1] << ": ";
						getline(cin,colunas[option - 1]);
						lista->insertColumns(colunas); // Chama m�todo da lista que atualiza / insere os valores das colunas;
						cout << "\n\n NOME DA COLUNA ALTERADO COM SUCESSO!!!\n\n";
					}else{ // Se o usu�rio selecionou uma op��o inv�lida
						cout << "\n\n VALOR INCORRETO! INICIE O PROCESSO NOVAMENTE!"; // Exibe mensagem informando o erro
					}
					
					delete[] colunas;
					colunas = nullptr;
					
				}else{ // Se a lista est� vazia / n�o foi gerada: 
					cout << "\n\nA LISTA N�O FOI GERADA! N�O H� COMO ALTERAR O NOME DAS COLUNAS\n\n"; // Exibe mensagem de erro informando ao usu�rio
				}
				
			break;
			case 3: // EXIBIR DADOS
				
				if(!lista->empty()){ // Se a lista n�o est� vazia
					
					cout << "Voc� deseja:\n\t1 - Exibir com filtro espec�fico\n\t2 - Exibir tudo\nEscolha: "; // Exibe mensagem com as op��es para o usu�rio
					cin >> option; // L� a op��o do usu�rio
					
					switch(option){
						case 1: // EXIBIR COM FILTRO ESPECIAL
							cout << "\n\n Deseja consultar por:\n\t1 - Disciplina\n\t2 - ISBN\n\t3 - T�tulo\n\t4 - Autor\n\t5 - Edi��o\n\t6 - Cidade\n\t";
							cout << "7 - Editora\n\t8 - Ano de lan�amento\n\t9 - Bibliografia b�sica\nEscolha:";
							cin >> option; // Le a sele��o do usu�rio sobre qual o filtro desejado para a consulta
							cout << "Digite o valor do campo desejado para o filtro: ";
							getchar();
							getline(cin, parametro);
							lista->printValue(option,preparaTexto(parametro)); // Chama fun��o da lista de exibe os resultados de acordo com o filtro selecionado pelo usu�rio
							
						break;
						case 2: // EXIBIR TUDO
							
							lista->printValues(); // Chama fun��o da lista que exibe todos os valores contidos na lista
							
						break;
					}
					
				}else{ // Se a lista est� vazia
					cout << "\n\nN�O H� VALORES NA LISTA\n\n"; // Exibe mensagem de erro informando que a lista est� vazia
				}
				
					
				
			break;
			case 4: // SALVAR DADOS
				
				if(!lista->empty()){ // Se a lista n�o est� vazia
					
					if(writeCSV(lista)){ // Se � lista foi gravada no arquivo com sucesso
						cout << "\n LISTA SALVA COM SUCESSO!\n"; // Exibe mensagem informando que a opera��o foi bem-sucedida
					}else{ // Se a lista n�o foi gravada no arquivo com sucesso
						cout << "\n ERRO AO SALVAR LISTA!\n"; // Exibe mensagem de erro informando que a opera��o n�o foi bem-sucedida
					}
					
				}else{ // Se a lista est� vazia
					cout << "\n\nN�O H� LISTA PARA SER SALVA\n\n"; // Exibe mensagem de erro avisando ao usu�rio que a lista est� vazia
				}
					
				
			break;
			case 5: // INSERIR LIVRO
				
				if(!lista->full()){ // Se ainda � poss�vel inserir valores na lista
					
					values = new string[9]; // Inicia array que ir� receber os valores a serem inseridos na lista
					
					// Pega os valores da linha digitados pelo usuario
					cout << "\nDigite a disciplina: ";
					getchar();
					getline(cin,values[0]);
					cout << "\nDigite o ISBN: ";
					getline(cin,values[1]);
					cout << "\nDigite o T�tulo: ";
					getline(cin,values[2]);
					cout << "\nDigite o Autor: ";
					getline(cin,values[3]);
					cout << "\nDigite a Edi��o: ";
					getline(cin, values[4]);
					cout << "\nDigite a Cidade: ";
					getline(cin, values[5]);
					cout << "\nDigite a Editora: ";
					getline(cin, values[6]);
					cout << "\nDigite o Ano: ";
					getline(cin,values[7]);
					cout << "\nDigite se a obra � uma bibliografia b�sica (S ou N)";
					getline(cin, values[8]);
					if(values[8] != "S" && values[8] != "s" && values[8] != "N" && values[8] != "n"){ // Condicional para checar se o campo bibliografia b�sica foi inserido incorretamente
						cout << "\nDADOS DIGITADOS INCORRETAMENTE! POR FAVOR, INICIE O PROCESSO NOVAMENTE!\n\n"; // Exibe mensagem de erro avisando que os valores foram inseridos incorretamente
					}else{ // Se os valores foram inseridos corretamente
						lista->insert(values); // Chama m�todo da lista para inserir os valores na lista
					}
					
				}else{ // Se n�o � poss�vel inserir mais valores na lista
					cout << "\n\nN�O � POSS�VEL INSERIR UM VALOR NA LISTA\n\n"; // Exibe mensagem de erro informando que a lista ja est� cheia
				}
					
			break;
			case 6: // ALTERAR LIVRO
				
				if(!lista->empty()){ // Se a lista n�o est� vazia
					
					cout << "\nDigite o ISBN da Bibliografia que deseja alterar: "; // Pede para o usu�rio inserir o ISBN da bibliografia desejada (Chave �nica)
					getchar();
					getline(cin,parametro);
					aux = lista->busca(parametro); // Busca a lista em espec�fico
					if(aux != nullptr){ // Se o item pesquisado realmente existe na lista
						values = aux->getItem()->getValues(); // Pega os valores atuais
						colunas = lista->getColumn()->getColumns(); // Pega os valores da coluna (Apenas para uma exibi��o mais elegante para o usu�rio)
					
						for(int i = 0; i < 9; i++){ // Exibe as informa��es da linha atual para o usu�rio
							cout << "\n\t" << i+1 << " - " << colunas[i] << ": " << values[i] << endl;
						}
						cout << "Digite o �ndice o valor que deseja alterar: ";
						cin >> option;
						if(option > 0 && option <= 9){ // Condicional que verifica se o usu�rio digitou uma op��o v�lida
							cout << "Digite o novo valor: ";
							getchar();
							getline(cin,values[option-1]); // L� o novo valor
							lista->update(values, aux); // Chama fun��o da lista que atualiza os a linha
						}else{ // Se o usu�rio inseriu uma op��o inv�lida
							cout << "\n\nPOR FAVOR, INICIE NOVAMENTE E ESCOLHA UMA COLUNA DENTRE AS DISPON�VEIS\n\n"; // Exibe mensagem de erro
						}
					}else{ // Se o item pesquisado n�o existe na lista
						cout << "\n\nBIBLIOGRAFIA N�O ENCONTRADA\n\n"; // Exibe mensagem de erro para o usu�rio
					}
					aux = nullptr; // Limpa os ponteiros
					delete[] values;
					delete[] colunas;
					values = nullptr;
					colunas = nullptr;
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA EST� VAZIA! N�O � POSS�VEL SELECIONAR UMA BIBLIOGRAFIA PARA ALTERAR\n\n"; // Exibe mensagem de erro ao usu�rio
				}
					
				
			break;
			case 7: // REMOVER LIVRO
				
				if(!lista->empty()){ // Se a lista n�o estiver vazia
					
					cout << "Por favor, Digite o ISBN do livro que dejesa remover: ";
					getchar();
					getline(cin, parametro); // L� a linha que o usu�rio deseja remover
					if(lista->remove(parametro)){ // Se a remo��o foi bem-sucedida
						cout << "\n Bibliografia removida com sucesso!\n\n"; // Exiibe mensagem informand
					}else{ // Se a bibliografia n�o foi encontrada
						cout << "\n\nBIBLIOGRAFIA N�O ENCONTRADA!\n\n"; // Exibe mensagem de erro para o usu�rio
					}
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA EST� VAZIA!\n\n"; // Exibe mensagem de erro ao usu�rio
				}
				
					
				
			break;
			case 8: // ANALISE DE DADOS A
				
				if(!lista->empty()){ // Se a lista n�o estiver vazia
					
					nacionais = calculaNacionais(lista); // Chama fun��o para calcular as bibliografias nacionais
					estrangeiros = lista->getlength() - nacionais; // Calcula quantas bibliografias s�o estrangeiras
					
					cout << "Bibliografias Nacionais: " << nacionais << " Corresponde a: " << ((float)nacionais / lista->getlength() * 100) << "%\n"; // Exibe mensagem informando a quantidade e porcentagem das bibliografias nacionais
					cout << "Bibliografias Estrangeiras: " << estrangeiros << " Corresponde a: " << ((float)estrangeiros / lista->getlength() * 100) << "%\n"; // Exibe mensagem informando a quantidade e porcentagem das bibliografias estrangeiras
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA EST� VAZIA!\n\n"; // Exibe mensagem de erro ao usu�rio
				}
					
				
				
			break;
			case 9: // ANALISE DE DADOS B ** PROPOR��O **
				
				if(!lista->empty()){ // Se a lista n�o estiver vazia
					
					cout << "Digite a categoria em que deseja as propor��es: "; // Exibe as categorias existentes para an�lise
					colunas = lista->getColumn()->getColumns(); // Pega os valores das colunas (Apenas para uma exibi��o mais elegante)
					contador = 1;
					for(int i = 0; i < 9; i++){ // Exibe as informa��es para o usu�rio
						
						if(i == 0 || i > 2){
							
							cout << "\n\t" << contador << " - " << colunas[i];
							contador++;
							
						}
						
					}
					cout << "\nEscolha: ";
					cin >> option; // L� a op��o selecionada pelo usu�rio
					
					cout << "\n---------- AN�LISE DE PROPOR��O ----------\n\n";
					
					if(option == 0){ // Condicional que chama o m�todo da lista para retorna a an�lise de acordo com a op��o desejada pelo usu�rio (ignorando ISBN e T�tutlo que s�o valores �nicos)
						
						cout << "Propor��o por " << colunas[0] << endl << endl;
						lista->printProporcoes(option-1, colunas[0]); // Chama o m�todo da lista para retornar a an�lise de propor��o selecionada pelo usu�rio
						
					}else if(option > 0 && option <= 7){
						
						cout << "Propor��o por " << colunas[option+1] << endl << endl;
						lista->printProporcoes(option-1, colunas[option+1]); // Chama o m�todo da lista para retornar a an�lise de propor��o selecionada pelo usu�rio
						
					}
					
					delete[] colunas;
					colunas = nullptr;
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA EST� VAZIA!\n\n"; // Exibe mensagem de erro para o usu�rio
				}
				
			break;
			case 10: // ANALISE DE DADOS C
				
				lista->printMaiores(); // Chama m�todo da lista para exibir as maiores recorr�ncias de cada categoria
				
			break;
			case 11: // ENCERRAR PROGRAMA
				
				lista->clear(); // Limpa a lista
				cout << "Obrigado por utilizar a biblioteca virtual!";
				delete lista;
				lista = nullptr;
				sair = true; // Vari�vel que controla o la�o principal do c�digo recebe true, indicando que o usu�rio deseja sair.
				
			break;
			default:
				cout << "Funcionalidade em desenvolvimento!\n\n";
			break;
			
		}
		
	}while(!sair);
	
	
}
