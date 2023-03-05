/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include "utilidades.hpp"

int tamanho(string texto){ // Retorna o tamanho da string
	
	int i = 0; // Inicia variável que será utilizada na contagem
	
	while(texto[i] != '\0'){ // Laço até o fim da string
		
		i++; // Incremento na variável contadora
		
	}
	
	return i; // Retorna valor correspondente ao tamanho da string
	
}

int stringToInt(string texto){ // Converte de string para inteiro
	
	int aux = 0; // Inicia variável auxiliar
	for(int i = 0 ; i < tamanho(texto); i++){ // Laço para percorrer toda a string
		
		aux = (aux*10) + ((int)texto[i] - 48); // Aplica a conversão para de cada caractere para um valor inteiro
		
	}
	return aux; // Retorna valor agora como um inteiro
	
}

string intToString(int texto){ // Converte de inteiro para string
	
	string aux = "", final = ""; // Inicializa variáveis auxiliares
	do{ // Laço para iterar até que o número tenha apenas um dígito
		aux += (texto % 10) + 48; // Realiza a conversão de um digito inteiro para um digito em formato string
		texto /= 10;
	}while(texto >= 9);
	
	if(texto > 0){ // Aplica a conversão do último dígito, desde que seja o último zero
		aux += (texto % 10) + 48;	
	}
	
	// O resultado até aqui é o valor porém em ordem invertida
	
	for(int i = tamanho(aux) - 1; i >= 0; i--){ // Laço para percorrer o valor e transformar ele na ordem correta
		final += aux[i];
	}
	
	return final; // Retorna valor agora no formato string
	
}

string *strsplit(string texto, char delimitador, int *tamanhoVetor){ // Transforma uma string em um vetor de strings separado por um delimitador
	
	// Variável "*tamanhoVetor" é um ponteiro, pois assim conseguimos retornar não só o vetor, mas também o seu tamanho
	
	int contador = 0; // Inicia variável que servirá como um contador
	*tamanhoVetor = 1; // Atribui 1 ao ponteiro que irá ter o tamanho do vetor
	
	for(int i = 0; i < tamanho(texto); i++){ // Laço para percorrer toda a string e contar quantos delimitadores existem.
		
		if(texto[i] == delimitador){
			(*tamanhoVetor)++;
		}
		
	}
	
	string *aux = new string[*tamanhoVetor]; // Inicia vetor com o tamanho exato das novas substrings

	for(int i = 0; i < *tamanhoVetor; i++){ // Laço para percorrer o vetor
		
		aux[i] = "";
		for(contador = contador; contador < tamanho(texto); contador++){ // Laço para inserir os caracteres no índice correto do vetor
			
			// Insere os caracteres no índice atual do vetor até encontrar um delimitador
			if(texto[contador] == delimitador){ 
				contador++;
				break;
			}else{
				aux[i] += texto[contador];
			}
			
		}	
		
	}
	tamanhoVetor = nullptr;
	return aux; // Retorna o vetor
}

string removeAcentos(string texto){ // Remove acentos da string (Utilizado para padronização de checagem)
	
	char comAcentos[] = "ÄÅÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛüúûùÇç"; // Vetor com os caracteres com Acentos
  	char semAcentos[] = "AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUuuuuCc"; // Vetor com os caracteres sem Acentos
  	
  	for(int i = 0; i < tamanho(texto); i++){ // Laço para percorrer a string recebida por parâmetro
  		for(int j = 0; j < 47; j++){ // Laço para percorrer os vetores que contém os caracteres com Acentos
  			if(texto[i] == comAcentos[j]){ // Se o caractere atual for um caractere com acento
  				texto[i] = semAcentos[j]; // Substitui pelo caractere sem acento
  				break; // Encerra a iteração
			  }
		  }
	  }
	
	return texto; // Retorna a string agora sem acentos
	
}

string strTrim(string texto){ // Remove espaços no começo e final da string (Utilizado para padronização de checagem)
	
	// Trabalha com recursividade para tirar todos os espaços no começo e final da string
	
	string aux = ""; // Inica variável auxiliar
	
	if(texto[0] != ' ' && texto[tamanho(texto)-1] != ' '){ // Se a string não tiver espaços no começo e no final
		return texto; // Retorna a string
	}else if(texto[0] == ' '){ // Se o primeiro caractere for um espaço
		for(int j = 1; j < tamanho(texto); j++){ // Copia a string para a variável auxiliar (Exceto o primeiro caractere)
				aux += texto[j];
			}
	}else{ // Se o último caractere for um espaço
		for(int j = 0; j < tamanho(texto) - 1; j++){ // Copia a string para a variável auxiliar (Exceto o último caractere)
			aux += texto[j];
		}
	}
	return strTrim(aux); // Chama a função novamente
	
}

string toLower(string texto){ // Converte os caracteres maiúsculos para minúsculos (Utilizado para padronização de checagem)
	
	for(int i = 0; i < tamanho(texto); i++){ // Laço para percorrer toda a string
		
		if(texto[i] >= 'A' && texto[i] <= 'Z'){ // Se o caractere atual for um charactere alfabético maiúsculo
			texto[i] = (int) texto[i] + 32; // Converte para o caractere minúsculo
		}
		
	}
	
	return texto; // Retorna a nova string
	
}

string preparaTexto(string texto){ // Transforma o texto em um texto padrão (Utilizado para manter o código limpo)

	return toLower(removeAcentos(strTrim(texto))); // Chama as funções utilizadas na padronização e retorna o valor

}

int stringCompare(string a, string b){ // 1 Se a for menor, -1 se b for menor e 0 se forem iguais
	
	int i = 0; // Inicia variável que servirá como contador
	a = toLower(a); // Transforma a string em minúscula
	b = toLower(b); // Transforma a string em minúscula
	
	while(i < tamanho(a) || i < tamanho(b)){ // Laço que itera até chegar ao fim de uma das duas strings
		
		if(a[i] < b[i]){ // Se o caractere da primeira string for alfabeticamente menor que o da segunda
			return 1; // Retorna 1
		}else if(a[i] > b[i]){ // Se o caractere da primeira string for alfabeticamente maior que o da segunda
			return -1; // Retorna -1
		}
		i++; // Incrementa contador
	}
	if(tamanho(a) < tamanho(b)){ // Se chegar ao fim de uma das strings e o tamanho de a for menor que o de b
		return 1; // Retorna 1
	}else if(tamanho(a) > tamanho(b)){ // Se o tamanho de a for maior que o de b
		return -1; // Retorna -1
	}else{ // Se o tamanho também for igual
		return 0; // Retorna 0
	}
}

bool checaNumero(string texto){ // Verifica se uma string corresponde a um valor numérico
	
	for(int i = 0; i < tamanho(texto); i++){ // laço para percorrer a string
		
		if(texto[i] < 48 || texto[i] > 57){ // Se o caractere não corresponder ao mesmo dígito to tipo int
			return false; // Retorna false
		}
		
	}
	
	return true; // Se todos os caracteres passarem no teste, retorna true
	
}



void transformaMatrizOrdenada(string *vetor_a, string *vetor_b, int tamanho_linhas){ // Ordena os arrays em ordem crescente
	

	
	string temp[2]; // Inicia vetor auxiliar
	int i = 0, j = 0; // Inicia variáveis que serão utilizadas como contadoras
	bool numero = checaNumero(vetor_a[0]); // Recebe valor que indica se a categoria analisada corresponde a um valor numérico (Indicando que a checagem é sobre Edição ou Ano)
	
	while(i < (tamanho_linhas)){ // Primeiro laço para percorrer os arrays
		j = i+1;
		while(j < (tamanho_linhas)){ // Segundo laço para percorrer os arrays que começa a partir de i+1
			
			// Se a string corresponder a um caractere numérico e a categoria checada por J for menor que a checada por I OU
			// Se a string não corresponder a um caractere numérico e a categoria checada por J for alfabeticamente menor que a checada por I
			if((numero == false && stringCompare(vetor_a[i],vetor_a[j]) == -1) || (numero == true && stringToInt(vetor_a[i]) > stringToInt(vetor_a[j]))){
				
				// Troca a posição dos vetores
				
				temp[0] = vetor_a[i];
				temp[1] = vetor_b[i];
				
				vetor_a[i] = vetor_a[j];
				vetor_b[i] = vetor_b[j];
				
				vetor_a[j] = temp[0];
				vetor_b[j] = temp[1];
				
				
			}
			j++;
		}
		i++;
	}
	
	vetor_a = nullptr;
	vetor_b = nullptr;
	
}


