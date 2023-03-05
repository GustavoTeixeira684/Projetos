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

// ***** FUNÇÃO PARA LER AS CIDADES DO BRASIL ***** //

string *lerCidades(){
	
	int contador = 0; // Inicia contador
	string *cidades = new string[TAMANHO_CIDADES]; // Inicia vetor para armazenar as cidades
	ifstream arquivo; // inicia a variável para ler o arquivo
	arquivo.open(PATH_CIDADES); // abre o arquivo das cidades
	if(!arquivo.fail()){ // Se o arquivo foi aberto com sucesso
	
		while(arquivo.peek() != EOF){ // Laço para inserir os valores no vetor
			
			getline(arquivo, cidades[contador],'\n'); // Insere cada cidade no vetor
			contador++;
				
		}
		
	}
	return cidades; // Retorna vetor
	
}

// ***** FUNÇÃO PARA LER AS BIBLIOGRAFIAS ***** //

bool readCSV(Lista *lista){
	
	ifstream arquivo; // Inicia a variável para ler o arquivo
	arquivo.open(PATH); // Abre o arquivo das bibliografias
	if(!arquivo.fail()){ // Se o arquivo foi aberto com sucesso: 
		
		string result, columns[9], values[9]; // Inicia variáveis para receber os valores da lista
		for(int i = 0; i < 8; i++){ // laço para pegar as colunas
    		getline(arquivo, result, ';');
    		columns[i] = result;
  		}
  		
  		getline(arquivo, result, '\n');
  		columns[8] = result;
  		
  		lista->insertColumns(columns); // Chama função da lista para atribuir os valores das colunas na lista
  		
  		while (arquivo.peek() != EOF) { // Laço para percorrer o restante do arquivo

		    for(int i = 0; i < 8; i++){ // Laço para percorrer cada linha do arquivo
    			getline(arquivo, result, ';');
    			values[i] = result;
  			}
		    getline(arquivo, values[8], '\n');
		   
		    lista->insert(values); // Chama o método da lista para atribuir os valores das linhas na lista
 		}
  		
  		return true; // Retorna true
		
	}else{ // Se houve erro ao ler o arquivo
		return false; // Retorna false
	}
	
}

// ***** FUNÇÃO PARA SALVAR A LISTA ***** //

bool writeCSV(Lista *lista){
	
	ofstream fout(PATH); // Inicia a variável para gravar os dados da lista em um arquivo
	No *pAnda = lista->getHead(); // Pega o primeiro item da lista
	string *values = nullptr; // Inicia ponteiro que receberá os valores das linhas
	
	values = lista->getColumn()->getColumns(); // Chama o método da lista para retornar os valores das colunas
	
	for(int i = 0; i < 8;i++){ // Laço para gravar os valores das colunas no arquivo
		fout<< values[i] << ";";
	}
	fout << values[8] << endl;
	
	delete[] values; // deleta os valores
	values = nullptr;
	
	for(int i = 0; i < lista->getlength();i++){ // Laço para gravar todas as linhas da lista no arquivo
		values = pAnda->getItem()->getValues(); // Pega a linha atual
		for(int k = 0; k < 8; k++){ // Laço para inserir todos os valores da linha no arquivo
						
			fout << values[k] << ";";
						
		}
		fout << values[8] << endl;
		pAnda = pAnda->getProx(); // Passa para o próximo item da lista. (Não é necessário atribuir nullptr a ela, pois na ultima iteração ela ja recebe nullptr)
	}
	delete[] values; // Limpa ponteiros
	values = nullptr;
	return true;
	
}

// ***** FUNÇÃO PARA CALCULAR TODAS AS BIBLIOGRAFIAS NACIONAIS ***** //
// Foi criada como uma função e não como um método da lista porque utiliza variáveis externas à mesma

int calculaNacionais(Lista *lista){
	
	int nacionais = 0; // Inicia variável que vai receber a quantidade de bibliografias nacionais
	string *cidade = lerCidades(); // Inicia um array ponteiro para receber todas as cidades do Brasil
	No *pAnda = lista->getHead(); // Pega o primeiro item da lista
	
	for(int i = 0; i < lista->getlength(); i++){ // Laço para percorrer todos os itens da lista
		for(int j = 0; j < TAMANHO_CIDADES; j++){ // Laço para percorrer todas as cidades do Brasil
			
			if(pAnda->getItem()->getCidade() == cidade[j]){ // Se o valor da cidade contido na linha atual for igual a alguma cidade na lista das cidades do Brasil
				nacionais++; // Incrementa a variável "nacionais"
				break; // Encerra a iteração
			}
			
		}
		pAnda = pAnda->getProx(); // Pega a próxima linha da lista
	}
	delete[] cidade;
	cidade = nullptr;
	return nacionais; // Retorna a quantidade de bibliografias nacionais da lista
	
}

// ******************** FUNÇÃO MAIN ******************** //

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Lista *lista = new Lista(); // Inicia a lista
	No *aux = nullptr; // variável auxiliar do tipo No
	string parametro, *values = nullptr, *colunas = nullptr; // inicia variáveis auxiliares do tipo string para receber os valores das linhas / colunas e inputs do tipo texto
	bool sair = false, salvo = true, leu_arquivo = false; // Inicia variáveis auxiliares do tipo booleano para controle do software
	int option, contador, nacionais, estrangeiros; // inicia variáveis auxiliares do tipo int para auxiliar no controle do software
	
	do{ // Inicia laço que se repetirá até que o usuário decida sair do software
		
		cout << "\n\n--- Biblioteca Digital ---"<< endl << endl; // Exibe as opções para o usuário
		cout << "O que deseja fazer?\n\t1 - Ler dados\n\t2 - Alterar nome das colunas\n\t3 - Exibir dados\n\t4 - Salvar dados\n\t5 - Inserir livro\n\t6 - Alterar livro" << endl;
		cout << "\t7 - Remover livro\n\t8 - Análise de dados A\n\t9 - Análise de dados B\n\t10 - Análise de dados C\n\t11 - Encerrar\nEscolha: ";
		cin >> option;
		
		switch(option){
			
			case 1: // LER DADOS
				
				if(!leu_arquivo){ // Se o usuário ainda não leu o arquivo
					
					cout << "Lendo arquivo..." << endl; // Exibe mensagem avisando que a leitura está iniciando
					
					if(readCSV(lista)){ // Se a leitura do arquivo e inserção na lista foi bem-sucedida
						cout << "Arquivo lido com sucesso!" << endl; // Exibe mensagem avisando que a leitura foi bem-sucedida
						cout << "Foram lidas " << lista->getlength() << " linhas!\n\n"; // Exibe mensagem mostrando quantas linhas foram lidas
						salvo = true; // variável que controla se a lista está atualizada com o arquivo recebe true
						leu_arquivo = true; // Variável que indica se o arquivo ja foi lido recebe true
					}else{ //Se a leitura não foi bem-sucedida
						cout << "Erro ao ler arquivo! Por favor, verifique se o arquivo estï¿½ no caminho correto (Archives/biblioteca.csv)"<< endl << endl; // Exibe mensagem informando o erro
					}
					
				}else{ // Se o arquivo ja foi lido
					
					cout << "\n\nO ARQUIVO JA FOI LIDO!\n\n"; // Exibe mensagem avisando o usuário
					
				}
					
			break;
			case 2: // ALTERAR NOME DE COLUNAS
				
				if(lista->getColumn() != nullptr){ // Se ja existem valores das colunas (Indicando que algum valor ja foi inserido na lista)
					
						colunas = lista->getColumn()->getColumns(); // Pega o valor das colunas
					
					cout << "O que você deseja alterar?"; // Exibe conjunto de mensagens mostrando o valor atual das colunas e perguntando qual valor o usuário deseja alterar
					for(int i = 0; i < 9; i++){
						cout << "\n\t" << i+1 << " - " << colunas[i];
					}
					cout << "\nEscolha: ";
					cin >> option;
					getchar();
					if(option > 0 && option <= 9){ // Condicional que garante que o usuário selecionou uma opção válida
						cout << "\nDigite o novo nome para a coluna " << colunas[option - 1] << ": ";
						getline(cin,colunas[option - 1]);
						lista->insertColumns(colunas); // Chama método da lista que atualiza / insere os valores das colunas;
						cout << "\n\n NOME DA COLUNA ALTERADO COM SUCESSO!!!\n\n";
					}else{ // Se o usuário selecionou uma opção inválida
						cout << "\n\n VALOR INCORRETO! INICIE O PROCESSO NOVAMENTE!"; // Exibe mensagem informando o erro
					}
					
					delete[] colunas;
					colunas = nullptr;
					
				}else{ // Se a lista está vazia / não foi gerada: 
					cout << "\n\nA LISTA NÃO FOI GERADA! NÃO HÁ COMO ALTERAR O NOME DAS COLUNAS\n\n"; // Exibe mensagem de erro informando ao usuário
				}
				
			break;
			case 3: // EXIBIR DADOS
				
				if(!lista->empty()){ // Se a lista não está vazia
					
					cout << "Você deseja:\n\t1 - Exibir com filtro especï¿½fico\n\t2 - Exibir tudo\nEscolha: "; // Exibe mensagem com as opções para o usuário
					cin >> option; // Lê a opção do usuário
					
					switch(option){
						case 1: // EXIBIR COM FILTRO ESPECIAL
							cout << "\n\n Deseja consultar por:\n\t1 - Disciplina\n\t2 - ISBN\n\t3 - Título\n\t4 - Autor\n\t5 - Edição\n\t6 - Cidade\n\t";
							cout << "7 - Editora\n\t8 - Ano de lançamento\n\t9 - Bibliografia básica\nEscolha:";
							cin >> option; // Le a seleção do usuário sobre qual o filtro desejado para a consulta
							cout << "Digite o valor do campo desejado para o filtro: ";
							getchar();
							getline(cin, parametro);
							lista->printValue(option,preparaTexto(parametro)); // Chama função da lista de exibe os resultados de acordo com o filtro selecionado pelo usuário
							
						break;
						case 2: // EXIBIR TUDO
							
							lista->printValues(); // Chama função da lista que exibe todos os valores contidos na lista
							
						break;
					}
					
				}else{ // Se a lista está vazia
					cout << "\n\nNÃO HÁ VALORES NA LISTA\n\n"; // Exibe mensagem de erro informando que a lista está vazia
				}
				
					
				
			break;
			case 4: // SALVAR DADOS
				
				if(!lista->empty()){ // Se a lista não está vazia
					
					if(writeCSV(lista)){ // Se á lista foi gravada no arquivo com sucesso
						cout << "\n LISTA SALVA COM SUCESSO!\n"; // Exibe mensagem informando que a operação foi bem-sucedida
					}else{ // Se a lista não foi gravada no arquivo com sucesso
						cout << "\n ERRO AO SALVAR LISTA!\n"; // Exibe mensagem de erro informando que a operação não foi bem-sucedida
					}
					
				}else{ // Se a lista está vazia
					cout << "\n\nNÃO HÁ LISTA PARA SER SALVA\n\n"; // Exibe mensagem de erro avisando ao usuário que a lista está vazia
				}
					
				
			break;
			case 5: // INSERIR LIVRO
				
				if(!lista->full()){ // Se ainda é possível inserir valores na lista
					
					values = new string[9]; // Inicia array que irá receber os valores a serem inseridos na lista
					
					// Pega os valores da linha digitados pelo usuario
					cout << "\nDigite a disciplina: ";
					getchar();
					getline(cin,values[0]);
					cout << "\nDigite o ISBN: ";
					getline(cin,values[1]);
					cout << "\nDigite o Título: ";
					getline(cin,values[2]);
					cout << "\nDigite o Autor: ";
					getline(cin,values[3]);
					cout << "\nDigite a Edição: ";
					getline(cin, values[4]);
					cout << "\nDigite a Cidade: ";
					getline(cin, values[5]);
					cout << "\nDigite a Editora: ";
					getline(cin, values[6]);
					cout << "\nDigite o Ano: ";
					getline(cin,values[7]);
					cout << "\nDigite se a obra é uma bibliografia básica (S ou N)";
					getline(cin, values[8]);
					if(values[8] != "S" && values[8] != "s" && values[8] != "N" && values[8] != "n"){ // Condicional para checar se o campo bibliografia básica foi inserido incorretamente
						cout << "\nDADOS DIGITADOS INCORRETAMENTE! POR FAVOR, INICIE O PROCESSO NOVAMENTE!\n\n"; // Exibe mensagem de erro avisando que os valores foram inseridos incorretamente
					}else{ // Se os valores foram inseridos corretamente
						lista->insert(values); // Chama método da lista para inserir os valores na lista
					}
					
				}else{ // Se não é possível inserir mais valores na lista
					cout << "\n\nNÃO É POSSÍVEL INSERIR UM VALOR NA LISTA\n\n"; // Exibe mensagem de erro informando que a lista ja está cheia
				}
					
			break;
			case 6: // ALTERAR LIVRO
				
				if(!lista->empty()){ // Se a lista não está vazia
					
					cout << "\nDigite o ISBN da Bibliografia que deseja alterar: "; // Pede para o usuário inserir o ISBN da bibliografia desejada (Chave única)
					getchar();
					getline(cin,parametro);
					aux = lista->busca(parametro); // Busca a lista em específico
					if(aux != nullptr){ // Se o item pesquisado realmente existe na lista
						values = aux->getItem()->getValues(); // Pega os valores atuais
						colunas = lista->getColumn()->getColumns(); // Pega os valores da coluna (Apenas para uma exibição mais elegante para o usuário)
					
						for(int i = 0; i < 9; i++){ // Exibe as informações da linha atual para o usuário
							cout << "\n\t" << i+1 << " - " << colunas[i] << ": " << values[i] << endl;
						}
						cout << "Digite o índice o valor que deseja alterar: ";
						cin >> option;
						if(option > 0 && option <= 9){ // Condicional que verifica se o usuário digitou uma opção válida
							cout << "Digite o novo valor: ";
							getchar();
							getline(cin,values[option-1]); // Lê o novo valor
							lista->update(values, aux); // Chama função da lista que atualiza os a linha
						}else{ // Se o usuário inseriu uma opção inválida
							cout << "\n\nPOR FAVOR, INICIE NOVAMENTE E ESCOLHA UMA COLUNA DENTRE AS DISPONÍVEIS\n\n"; // Exibe mensagem de erro
						}
					}else{ // Se o item pesquisado não existe na lista
						cout << "\n\nBIBLIOGRAFIA NÃO ENCONTRADA\n\n"; // Exibe mensagem de erro para o usuário
					}
					aux = nullptr; // Limpa os ponteiros
					delete[] values;
					delete[] colunas;
					values = nullptr;
					colunas = nullptr;
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA ESTÁ VAZIA! NÃO É POSSÍVEL SELECIONAR UMA BIBLIOGRAFIA PARA ALTERAR\n\n"; // Exibe mensagem de erro ao usuário
				}
					
				
			break;
			case 7: // REMOVER LIVRO
				
				if(!lista->empty()){ // Se a lista não estiver vazia
					
					cout << "Por favor, Digite o ISBN do livro que dejesa remover: ";
					getchar();
					getline(cin, parametro); // Lê a linha que o usuário deseja remover
					if(lista->remove(parametro)){ // Se a remoção foi bem-sucedida
						cout << "\n Bibliografia removida com sucesso!\n\n"; // Exiibe mensagem informand
					}else{ // Se a bibliografia não foi encontrada
						cout << "\n\nBIBLIOGRAFIA NÃO ENCONTRADA!\n\n"; // Exibe mensagem de erro para o usuário
					}
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA ESTÁ VAZIA!\n\n"; // Exibe mensagem de erro ao usuário
				}
				
					
				
			break;
			case 8: // ANALISE DE DADOS A
				
				if(!lista->empty()){ // Se a lista não estiver vazia
					
					nacionais = calculaNacionais(lista); // Chama função para calcular as bibliografias nacionais
					estrangeiros = lista->getlength() - nacionais; // Calcula quantas bibliografias são estrangeiras
					
					cout << "Bibliografias Nacionais: " << nacionais << " Corresponde a: " << ((float)nacionais / lista->getlength() * 100) << "%\n"; // Exibe mensagem informando a quantidade e porcentagem das bibliografias nacionais
					cout << "Bibliografias Estrangeiras: " << estrangeiros << " Corresponde a: " << ((float)estrangeiros / lista->getlength() * 100) << "%\n"; // Exibe mensagem informando a quantidade e porcentagem das bibliografias estrangeiras
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA ESTÁ VAZIA!\n\n"; // Exibe mensagem de erro ao usuário
				}
					
				
				
			break;
			case 9: // ANALISE DE DADOS B ** PROPORÇÃO **
				
				if(!lista->empty()){ // Se a lista não estiver vazia
					
					cout << "Digite a categoria em que deseja as proporções: "; // Exibe as categorias existentes para análise
					colunas = lista->getColumn()->getColumns(); // Pega os valores das colunas (Apenas para uma exibição mais elegante)
					contador = 1;
					for(int i = 0; i < 9; i++){ // Exibe as informações para o usuário
						
						if(i == 0 || i > 2){
							
							cout << "\n\t" << contador << " - " << colunas[i];
							contador++;
							
						}
						
					}
					cout << "\nEscolha: ";
					cin >> option; // Lê a opção selecionada pelo usuário
					
					cout << "\n---------- ANÁLISE DE PROPORÇÃO ----------\n\n";
					
					if(option == 0){ // Condicional que chama o método da lista para retorna a análise de acordo com a opção desejada pelo usuário (ignorando ISBN e Títutlo que são valores únicos)
						
						cout << "Proporção por " << colunas[0] << endl << endl;
						lista->printProporcoes(option-1, colunas[0]); // Chama o método da lista para retornar a análise de proporção selecionada pelo usuário
						
					}else if(option > 0 && option <= 7){
						
						cout << "Proporção por " << colunas[option+1] << endl << endl;
						lista->printProporcoes(option-1, colunas[option+1]); // Chama o método da lista para retornar a análise de proporção selecionada pelo usuário
						
					}
					
					delete[] colunas;
					colunas = nullptr;
					
				}else{ // Se a lista estiver vazia
					cout << "\n\nA LISTA ESTÁ VAZIA!\n\n"; // Exibe mensagem de erro para o usuário
				}
				
			break;
			case 10: // ANALISE DE DADOS C
				
				lista->printMaiores(); // Chama método da lista para exibir as maiores recorrências de cada categoria
				
			break;
			case 11: // ENCERRAR PROGRAMA
				
				lista->clear(); // Limpa a lista
				cout << "Obrigado por utilizar a biblioteca virtual!";
				delete lista;
				lista = nullptr;
				sair = true; // Variável que controla o laço principal do código recebe true, indicando que o usuário deseja sair.
				
			break;
			default:
				cout << "Funcionalidade em desenvolvimento!\n\n";
			break;
			
		}
		
	}while(!sair);
	
	
}
