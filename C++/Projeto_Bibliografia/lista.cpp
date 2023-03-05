/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include <iostream>
#include "lista.hpp"
#include "utilidades.hpp"


Lista::Lista(){ // Construtor
	this->head = nullptr;
	this->tail = nullptr;
	this->column = nullptr;
	this->length = 0;
}

No *Lista::getHead(){ // Retorna o endereï¿½o do primeiro nï¿½
	return this->head;
}

void Lista::setHead(No *head){ // Define o endereï¿½o do primeiro nï¿½
	this->head = head;
}

No *Lista::getTail(){ // Retorna o endereï¿½o do ï¿½ltimo nï¿½
	return this->tail; 
}

void Lista::setTail(No *tail){ // Define o endereï¿½o do ï¿½ltimo nï¿½
	this->tail = tail;
}

Coluna *Lista::getColumn(){ // Retorna o endereï¿½o do nï¿½ onde armazena o valor das colunas
	return this->column;
}

int Lista::getlength(){ // Retorna o tamanho da lista
	return this->length;
}

bool Lista::empty(){ // Verifica se a lista estï¿½ vazia
	if(length == 0){
		return true;
	}else{
		return false;
	}
}

bool Lista::full(){ // Verifica se a lista estï¿½ cheia
	No *aux = new No();
	
	if(aux == 0){
		return true;
	}else{
		return false;
	}
	
	aux = nullptr;
	
}

void Lista::clear(){ // Limpa a lista
	
	No *pAnda = this->head, *pAnt = nullptr;
	
	while(pAnda != nullptr){
		
		pAnt = pAnda;
		pAnda = pAnda->getProx();
		delete pAnt->getItem();
		pAnt->setItem(nullptr);
		pAnt->setAnterior(nullptr);
		pAnt->setProx(nullptr);
		delete pAnt;
		pAnt = nullptr;
		
	}
	delete this->column;
	this->column = nullptr;
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
	pAnt = nullptr;
	
}

bool Lista::insert(string *values){ // Insere um nï¿½ na lista


	if(full()){ // Se nï¿½o for possï¿½vel inserir mais itens na lista
		return false; // Retorna false
	}else if(empty()){ // Se a lista estiver vazia
		if(this->column == nullptr){ // Se as colunas ainda nï¿½o tiverem valores
			Coluna *colAux = new Coluna(); // Insere os valores padrï¿½o da coluna
			this->column = colAux; // Atribui ï¿½ lista
			colAux = nullptr;
		}
		No *aux = new No(values, nullptr, nullptr); // Cria um nï¿½ com os valores passados por parï¿½metro e sem atribuir prox e ant
		setHead(aux); // head recebe o nï¿½
		setTail(aux); // tail recebe o nï¿½ (Como ï¿½ o ï¿½nico, ele ï¿½ o primeiro e ï¿½ltimo)
		length++; // Incrementa o tamanho
		aux = nullptr; // Limpa aux
		return true; // Retorna true
	}else{ // Se a lista nï¿½o estiver vazia
		
		No *aux = new No(values, nullptr, tail); // Cria um nï¿½ com os valores passados por parï¿½metro e atribui o ï¿½ltimo item da lista como o anterior
		tail->setProx(aux); // Define o prï¿½ximo do ultimo item da lista com o endereï¿½o do nï¿½ criado agora
		tail = aux; // Atualiza o ï¿½ltimo item da lista
		length++; // Incrementa o tamanho
		aux = nullptr; // Limpa aux
		return true; // Retorna true
		
	}
	
	values = nullptr;
	
}

bool Lista::update(string *values, No *linhaAlterada){ // Altera um nï¿½ da lista
	
	Bibliografia *aux = new Bibliografia(values); // Cria uma bibliografia com os novos valores
	delete linhaAlterada->getItem(); // Apaga a bibliografia desatualizada
	linhaAlterada->setItem(aux); // Atualiza a linha
	aux = nullptr; // Limpa aux
	values = nullptr;
	linhaAlterada = nullptr;
	return true; // Retorna true
}

void Lista::insertColumns(string *values){ // Insere um nï¿½ para armazenar o valor das colunas

	if(this->column != nullptr){ // Se ja tem valores atribuidos ï¿½s colunas
		delete column; // Apaga eles
	}
	Coluna *coluna = new Coluna(values); // Cria uma nova instï¿½ncia da coluna com os valores passados por parï¿½metro
	this->column = coluna; // Atribui o endereï¿½o da coluna criada na lista
	coluna = nullptr; // Limpa a variï¿½vel coluna
	values = nullptr;
	
}

void Lista::printColumns(){ // Exibe o valor das colunas
		
		Coluna *aux = column; // Pega o endereï¿½o da instï¿½ncia da coluna
		string *values = column->getColumns(); // Pega os valores das colunas
		
		for(int i = 0 ; i < 8; i++){ // Exibe os valores para o usuï¿½rio
			cout << values[i] << " | ";
		}
		cout << values[8] << endl;
		
		delete[] values; // Limpa ponteiros
		aux = nullptr;
		values = nullptr;
	
}

No *Lista::busca(string chave){ // Busca um valor baseado em uma chave (ISBN)
	
	No *pAnda = this->head; // Pega o primeiro item da lista
	
	for(int i = 0; i < this->length;i++){ // Laï¿½o para percorrer a lista
		if(pAnda->getItem()->getIsbn() == strTrim(chave)){ // Se encontrar o item
			return pAnda; // Retorna o mesmo
		}
		pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
	}
	
	return nullptr; // Se terminar o laï¿½o e nï¿½o encontrar o item, retorn nullptr
	
}

void Lista::printLine(string *values){ // Exibe uma lina especï¿½fica (Utilizaado nos dois mï¿½todos abaixo)
	
	for(int k = 0; k < 8; k++){ // Laï¿½o para exibir para o usuï¿½rio a linha atual
						
		cout << values[k] << " | ";
						
	}
	cout << values[8] << endl;
	delete[] values;
	values = nullptr;
}

void Lista::printValue(int opcao, string parametro){ // Exibe os valores da lista baseado em um filtro
	
	No *pAnda = head; // Pega o primeiro item da lista
	string *values = nullptr, *autor_split = nullptr; 
	int tamanho_split, contador = 0;
	
	printColumns(); // Exibe as colunas da lista
		
	if(opcao == 4){ // Se o ï¿½ndice passado corresponder ao campo "Autor"
			
		for(int i = 0; i < length; i++){ // Laï¿½o para percorrer toda a lista
				autor_split = strsplit(pAnda->getItem()->getAutor(),',',&tamanho_split); // Tranforma a string contendo os autores da linha atual e um vetor de string
				for(int j = 0; j < tamanho_split; j++){ // Laï¿½o para percorrer o array criado
					if(preparaTexto(autor_split[j]) == parametro){ // Se o autor atual for igual ao parï¿½metro passado pelo usuï¿½rio
						printLine(pAnda->getItem()->getValues()); // Exibe a linha
						contador++; // Incrementa variï¿½vel que armazena quantas linhas estï¿½o sendo exibidas
						break;
					}
				}
				pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
		}
		
	}else{ // Se o ï¿½ncide passado nï¿½o corresponder ao campo "Autor"
	
		for(int i = 0; i < length; i++){ // Laï¿½o para percorrer toda a lista
				if(preparaTexto(pAnda->getItem()->getValues()[opcao-1]) == parametro){ // Se o campo escolhido pelo usuï¿½rio na linha atual for igual ao parï¿½metro passado
					printLine(pAnda->getItem()->getValues()); // Exibe a linha
					contador++; // Incrementa variï¿½vel que armazena quantas linhas estï¿½o sendo exibidas
				}
				pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
				
		}
	
	}
	
	delete[] values;
	values = nullptr;
	delete[] autor_split;
	autor_split = nullptr;
		
	cout << "\nTotal: " << contador << " linha(s)!" << endl; // Exibe a quantidade de linhas exibidas pelo usuï¿½rio
		
}



void Lista::printValues(){ // Exibe todos os valores contidos na lista
	
	
	if(!empty()){ // Se a lista nï¿½o estiver vazia
		No *pAnda = head; // Pega o primeiro item da lista
		string *values = nullptr; // Inicia array que irï¿½ conter os valores da linha em especï¿½fico
		
		printColumns(); // Exibe as colunas
		
		for(int i = 0; i < length; i++){ // Laï¿½o para percorrer todas as linhas da lista
			
			printLine(pAnda->getItem()->getValues()); // Exibe a linha atual
			pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
			
		}
		
		cout << "\nTotal: " << this->length << " linhas!" << endl; // Exibe para o usuï¿½rio quantas linhas foram exibidas
		
		delete[] values;
		values = nullptr;
		
	}else{ // Se a lista estiver vazia
		
		cout << "\nA LISTA ESTï¿½ VAZIA!!!\n\n"; // Exibe uma mensagem de erro informando para o usuï¿½rio que a lista estï¿½ vazia
		
	}
}

bool Lista::remove(string chave){ // Remove um nï¿½ da lista
	
	No *pAnda = head; // Pega o primeiro item da lista
	
	if(!empty()){ // Se a lista nï¿½o estiver vazia
		
		if(length == 1){ // Se sï¿½ tiver um item na lista
			if(pAnda->getItem()->getIsbn() == strTrim(chave)){ // E for o item escolhido
				this->head = nullptr; // head recebe nullptr
				this->tail = nullptr; // tail recebe nullptr
				length--; // decrementa o tamanho (Que vai para 0)
				delete pAnda; // Deleta o nï¿½
				pAnda = nullptr; // atribui nullptr a pAnda
				return true; // Retorna true
			}
		}else{ // Se tiver mais de um item na lista
			for(int i = 0; i < length; i++){ // Laï¿½o para percorrer a lista
				if(pAnda->getItem()->getIsbn() == strTrim(chave)){ // Se o ISBN for igual ao inserido pelo usuï¿½rio
					if(pAnda == this->head){ // Se for o primeiro item da lista
						this->setHead(pAnda->getProx()); // head recebe o prï¿½ximo item
						pAnda->getProx()->setAnterior(nullptr); // seta o anterior do prï¿½ximo item como nullptr (Afinal, nï¿½o terï¿½ mais nenhum antes dele)
					}else if(pAnda == this->tail){ // Se for o ï¿½ltimo item da lista
						this->setTail(pAnda->getAnterior()); // tail recebe o anterior ao que estï¿½ apontando
						pAnda->getAnterior()->setProx(nullptr); // O prox do anterior recebe nullptr (Afinal, nï¿½o terï¿½ mais nenhum depois dele)
					}else{ // Se estiver no meio da lista
						pAnda->getAnterior()->setProx(pAnda->getProx()); // o prox do Nï¿½ anterior recebe o prox do nï¿½ que serï¿½ excluï¿½do
						pAnda->getProx()->setAnterior(pAnda->getAnterior()); // o ant do proximo nï¿½ recebe o anterior do nï¿½ que serï¿½ excluï¿½do
					}
					length--; // Decrementa o tamanho da lista
					delete pAnda; // Deleta o nï¿½ a ser exluï¿½do
					pAnda = nullptr; // atribui nullptr a pAnda
					return true; // retorna true
				}else{ // Se ainda nï¿½o encontrou o nï¿½ para ser excluï¿½do
					pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
				}
			}
			delete pAnda;
			pAnda = nullptr; // limpa pAnda
			return false; // se nï¿½o encontrou o nï¿½, retorna false
		}
		
	}
	delete pAnda; // limpa pAnda
	pAnda = nullptr;
	return false;
}

string *Lista::retornaAnalise(int indice_categoria, string texto_exibicao,int *tamanho_vetor){ // Retorna uma anï¿½lise que contem os valores distintos e sua quantidade baseado em uma categoria (coluna)
	
	// Esse mï¿½todo foi construï¿½do encima de listas utilizando strings
	// Todas as categorias e suas quantidades sï¿½o inseridas em strings, com os valores separados por vï¿½rgula.
	// Apï¿½s o tï¿½rmino da anï¿½lise, as strings sï¿½o transformadas em arrays para retornar
	// Dessa forma, nï¿½o ï¿½ necessï¿½rio fazer um laï¿½o para contar quantas distintas existem e outro para mapear. Da para fazer os dois com uma iteraï¿½ï¿½o
	// Dessa forma o mï¿½todo funciona independente do tamanho da lista e de quantos valores distintos exista na coluna
	// Se o usuï¿½rio selecionar o Autor, o processo de anï¿½lise ï¿½ diferente do resto, pois a contagem segue lï¿½gicas diferentes (Ja que a coluna "Autor" ï¿½ um campo multivalorado)
	
	// Inicia variï¿½veis de apoio
	int i = 0, tamanho_autor, quantidade_distintos;
	No *pAnda = head, *pAux = nullptr;
	string categorias_distintas = "", quantidades_distintas = "", quantidade_atual = "", categoria_atual, aux;
	string *vetor_linha, *vetor_categorias, *vetor_quantidades, *vetor_autor, *matriz_geral;
	bool repetida = false;
	
	
	
	if(this->getColumn()->getColumns()[3] == texto_exibicao){ // Se o usuï¿½rio estiver selecionado anï¿½lise pela coluna "Autor
		
		do{ // Laï¿½o para percorrer toda a lista
			vetor_linha = strsplit(pAnda->getItem()->getAutor(),',',&tamanho_autor); // retorna um vetor com todos os autores da bibliografia referente a linha atual
			
			for(int j = 0; j < tamanho_autor; j++){ // Laï¿½o para percorrer cada indice do vetor criado acima
				repetida = false; // repetida inicia como false
				if(tamanho(categorias_distintas) > 0){ // se ja tiver algum valor atribuï¿½do ï¿½ lista final da categoria
					vetor_categorias = strsplit(categorias_distintas,',',tamanho_vetor); // transforma a lista em um vetor com todos os autores ja mapeados
					for(int k = 0; k < *tamanho_vetor; k++){ // Laï¿½o para percorrer o vetor acima
					
						if(strTrim(vetor_linha[j]) == strTrim(vetor_categorias[k])){ // Se o autor a ser checado ja estiver sido mapeado
							repetida = true; // repetida recebe true, indicando que o autor ja foi checado
							break;
						}
							
					}
					
				}
					
				if(!repetida){ // Se o autor ainda nï¿½o foi checado
						
					if(tamanho(categorias_distintas) > 0){ // Se ja estiver algum autor a ser checado, insere uma vï¿½rgula na string para inserir o prï¿½ximo valor
					// Isso evita que a string comece com , ou termine com ,
						categorias_distintas += ",";
						quantidades_distintas += ",";
					}
						
					pAux = pAnda; 
					quantidade_atual = "0"; // Inicia quantidade como 1
					
					for(int k = i; k < this->length - 1; k++){ // Laï¿½o para percorrer a lista com k = i+1 e contar as vezes em que o autor em especï¿½fico aparece
						pAux = pAux->getProx(); // Pega o prï¿½ximo item da lista
						vetor_autor = strsplit(pAux->getItem()->getAutor(),',',tamanho_vetor); // transforma o campo autor em um array
						
						for(int l = 0; l < *tamanho_vetor; l++){ // Laï¿½o para percorrer o vetor acima
							
							if(strTrim(vetor_linha[j]) == strTrim(vetor_autor[l])){ // Se o autor a ser checado aparece em algum outro item da lista
								quantidade_atual = intToString(stringToInt(quantidade_atual) + 1); // Incrementa a quantidade
							}
							
						}
						
					}
					
					// Ao final da iteraï¿½ï¿½o, o nome do campo e a quantidade de recorrï¿½ncias sï¿½o incrementados na string
					categorias_distintas += strTrim(vetor_linha[j]);
					quantidades_distintas += quantidade_atual;
					
				}
				
			}
			
			pAnda = pAnda->getProx(); // pAnda recebe o prï¿½ximo item da lista
			i++;
			
		}while(i < this->length);
		
	}else{ // Se o usuï¿½rio nï¿½o estiver selecionado anï¿½lise pela coluna "Autor
		
		do{ // Laï¿½o para percorrer toda a lista
			
			vetor_linha = pAnda->getItem()->getValues(); // Vetor que recebe os valores da linha atual
			if(tamanho(categorias_distintas) > 0){ // Se algum valor da coluna a ser analisada ja estiver sido mapeado
							
				vetor_categorias = strsplit(categorias_distintas,',', tamanho_vetor); // Transforma a os valores ja mapeados em um array 
				repetida = false; // Repetida comeï¿½a com false
				for(int j = 0; j < *tamanho_vetor; j++){ // Laï¿½o para percorrer o array criado acima
					
					if(vetor_linha[indice_categoria] == vetor_categorias[j]){ // Se o item da coluna selecionada pelo usuï¿½rio na linha sendo checada for igual a algum ja mapeado
						repetida = true; // Repetida recebe true
					}
					
				}
				
			}
			
			if(!repetida){ // Se o item da linha atual ainda nï¿½o estiver sido checado. Inicia a contagem
				
				if(tamanho(categorias_distintas) > 0){ // Se ja estiver algum autor a ser checado, insere uma vï¿½rgula na string para inserir o prï¿½ximo valor
					// Isso evita que a string comece com , ou termine com ,
					categorias_distintas += ",";
					quantidades_distintas += ",";
				}
				
				pAux = pAnda;
				quantidade_atual = "0"; // Inicia a quantidade como 1
				for(int j = i; j < this->length; j++){
					
					if(pAux->getItem()->getValues()[indice_categoria] == vetor_linha[indice_categoria]){ // Se o valor do campo atual a ser checado aparece am alguma outra linha da lista
						
						quantidade_atual = intToString(stringToInt(quantidade_atual) + 1); // Incrementa 1 na quantidade
						
					}
					pAux = pAux->getProx(); // Pega o prï¿½ximo item da lista
				
				}
				
				// Ao final da iteraï¿½ï¿½o, o nome do campo e a quantidade de recorrï¿½ncias sï¿½o incrementados na string
				categorias_distintas += vetor_linha[indice_categoria];
				quantidades_distintas += quantidade_atual;
			}
				
			pAnda = pAnda->getProx(); // Pega o prï¿½ximo item da lista
			i++;
		}while(i < this->length);
		
	}
	
		
	vetor_categorias = strsplit(categorias_distintas,',', tamanho_vetor); // Transforma a string que tem o nome dos campos distintos da coluna selecionada em um array
	vetor_quantidades = strsplit(quantidades_distintas,',', tamanho_vetor); // Transforma a string que tem a quantidade dos campos distintos da coluna selecionada em um array

	transformaMatrizOrdenada(vetor_categorias, vetor_quantidades, *tamanho_vetor); // Chama funï¿½ï¿½o que ordena os arrays
	
	matriz_geral = new string[((*tamanho_vetor) * 2)]; // Inicia uma matriz que vai receber os valores
	
	i = 0;
	for(int j = 0; j < ((*tamanho_vetor) * 2 - 1); j+=2){ // Insere os dois arrays em um array que serï¿½ tratado como bidimensional para retornar apenas um valor
		
		matriz_geral[j] = vetor_categorias[i];
		matriz_geral[j+1] = vetor_quantidades[i];
		i++;
		
	}
	
	pAux = nullptr;
	delete[]vetor_linha;
	vetor_linha = nullptr;
	vetor_categorias = nullptr;
	vetor_quantidades = nullptr;
	vetor_autor = nullptr;
	
	return matriz_geral; // Retorna resultado da anï¿½lise
	
}

void Lista::printProporcoes(int indice_categoria, string texto_exibicao){ // Exibe uma anï¿½lise baseada em proporï¿½ï¿½o de uma determinada coluna da lista
	
	int tamanho_vetor;
	
	if(indice_categoria > 0){ // Condicional que controla que o usuï¿½rio nï¿½o selecionara "ISBN" e "Autor" pois sï¿½o campos de valores ï¿½nicos
		indice_categoria +=2;
	}
	
	string *matriz = retornaAnalise(indice_categoria, texto_exibicao, &tamanho_vetor); // Chama o mï¿½todo acima que faz a anï¿½lise

	
	for(int i = 0; i < (tamanho_vetor * 2 - 1); i+=2){ // Laï¿½o para exibir os resultados obtidos
		
		cout << texto_exibicao << ": " << matriz[i] << " | Quantidade: " << matriz[i+1] << " | Proporção: " << (float)stringToInt(matriz[i+1]) / this->length * 100 << "%\n";
		
		
	}
	
	cout << "\nTotal: " << tamanho_vetor << " valores distintos!";
	
	cout << endl;
	delete[] matriz;
	matriz = nullptr;
	
}

void Lista::printMaiores(){ // Exibe uma anï¿½lise que contem as maiores recorrï¿½ncias de uma determinada coluna da lista
	
	// Esse mï¿½todo exibe as maiores recorrencias para cada campo exceto "ISBN" e "Autor" que sï¿½o campos com valores ï¿½nicos
	// Da forma como foi construï¿½do, Exibe todos que estï¿½o empatados em prmeiro lugar como mais recorrentes
	
	// Inicia variï¿½veis de apoio
	int tamanho_vetor, maior_quantidade;
	string *colunas = nullptr, *matriz = nullptr, *vetor_final = nullptr;
	string maior_categoria = "";
	
	colunas = this->getColumn()->getColumns(); // Retorna todas as colunas
	
	for(int i = 0; i < 8; i++){ // Laï¿½o que percorre todas as colunas da lista
		
		if(i == 0 || i > 2){ // Condicional que garante que nï¿½o serï¿½o feitas as anï¿½lises para os campos "ISBN" e "Autor" que sï¿½o campos com valores ï¿½nicos
			matriz = retornaAnalise(i, colunas[i], &tamanho_vetor); // Chama mï¿½todo que retorna a anï¿½lise 
			maior_categoria = matriz[0]; // Atribui um valor inicial para calcular o maior
			maior_quantidade = stringToInt(matriz[1]); // Atribui um valor inicial para calcular a maior quantidade
			for(int j = 2; j < (tamanho_vetor*2 - 1); j+=2){ // Laï¿½o para percorrer o array gerado no mï¿½todo que efetua a anï¿½lise
				
				if(stringToInt(matriz[j+1]) > maior_quantidade){ // Se a quantidade da linha atual a ser checada for maior que a inserida na variï¿½vel final
					
					// Substitui os valores
					maior_categoria = matriz[j];
					maior_quantidade = stringToInt(matriz[j+1]);
					
				}else if(stringToInt(matriz[j+1]) == maior_quantidade){ // Se a quantidade da linha atual a ser checada for igual que a inserida na variï¿½vel final
					
					if(tamanho(maior_categoria) > 0){
						// Insere uma vï¿½rgula para separar elas
						maior_categoria += ",";
					}
					maior_categoria += matriz[j]; // Incrementa com a categoria
					
				}
				
			}
			
			
			vetor_final = strsplit(maior_categoria,',', &tamanho_vetor); // Transforma a string em um vetor de arrays
			
			
			// EXIBE OS RESULTADOS //
			cout << "\nMaiores da categoria: " << colunas[i] << endl; 
			
			for(int j = 0; j < tamanho_vetor; j++){
				
				cout << "\t" << vetor_final[j] << " | Quantidade: " << maior_quantidade << endl;
			}
			
		}
		
	}
	
	delete[] colunas;
	delete[] vetor_final;
	delete[] matriz;
	colunas = nullptr;
	vetor_final = nullptr;
	matriz = nullptr;
	
}

