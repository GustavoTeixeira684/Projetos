/*
Cleverson Pereira da Silva	TIA: 32198531
Gustavo Teixeira dos Santos	TIA: 32197020
Natalia de Fatima Teixeira	TIA: 42129397
Rafael Joo Seong Yun	TIA: 32144636
Rafael Moutinho Tessaroto	TIA: 42122521
*/

#include "utilidades.hpp"

int tamanho(string texto){ // Retorna o tamanho da string
	
	int i = 0; // Inicia vari�vel que ser� utilizada na contagem
	
	while(texto[i] != '\0'){ // La�o at� o fim da string
		
		i++; // Incremento na vari�vel contadora
		
	}
	
	return i; // Retorna valor correspondente ao tamanho da string
	
}

int stringToInt(string texto){ // Converte de string para inteiro
	
	int aux = 0; // Inicia vari�vel auxiliar
	for(int i = 0 ; i < tamanho(texto); i++){ // La�o para percorrer toda a string
		
		aux = (aux*10) + ((int)texto[i] - 48); // Aplica a convers�o para de cada caractere para um valor inteiro
		
	}
	return aux; // Retorna valor agora como um inteiro
	
}

string intToString(int texto){ // Converte de inteiro para string
	
	string aux = "", final = ""; // Inicializa vari�veis auxiliares
	do{ // La�o para iterar at� que o n�mero tenha apenas um d�gito
		aux += (texto % 10) + 48; // Realiza a convers�o de um digito inteiro para um digito em formato string
		texto /= 10;
	}while(texto >= 9);
	
	if(texto > 0){ // Aplica a convers�o do �ltimo d�gito, desde que seja o �ltimo zero
		aux += (texto % 10) + 48;	
	}
	
	// O resultado at� aqui � o valor por�m em ordem invertida
	
	for(int i = tamanho(aux) - 1; i >= 0; i--){ // La�o para percorrer o valor e transformar ele na ordem correta
		final += aux[i];
	}
	
	return final; // Retorna valor agora no formato string
	
}

string *strsplit(string texto, char delimitador, int *tamanhoVetor){ // Transforma uma string em um vetor de strings separado por um delimitador
	
	// Vari�vel "*tamanhoVetor" � um ponteiro, pois assim conseguimos retornar n�o s� o vetor, mas tamb�m o seu tamanho
	
	int contador = 0; // Inicia vari�vel que servir� como um contador
	*tamanhoVetor = 1; // Atribui 1 ao ponteiro que ir� ter o tamanho do vetor
	
	for(int i = 0; i < tamanho(texto); i++){ // La�o para percorrer toda a string e contar quantos delimitadores existem.
		
		if(texto[i] == delimitador){
			(*tamanhoVetor)++;
		}
		
	}
	
	string *aux = new string[*tamanhoVetor]; // Inicia vetor com o tamanho exato das novas substrings

	for(int i = 0; i < *tamanhoVetor; i++){ // La�o para percorrer o vetor
		
		aux[i] = "";
		for(contador = contador; contador < tamanho(texto); contador++){ // La�o para inserir os caracteres no �ndice correto do vetor
			
			// Insere os caracteres no �ndice atual do vetor at� encontrar um delimitador
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

string removeAcentos(string texto){ // Remove acentos da string (Utilizado para padroniza��o de checagem)
	
	char comAcentos[] = "����������������������������������������������"; // Vetor com os caracteres com Acentos
  	char semAcentos[] = "AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUuuuuCc"; // Vetor com os caracteres sem Acentos
  	
  	for(int i = 0; i < tamanho(texto); i++){ // La�o para percorrer a string recebida por par�metro
  		for(int j = 0; j < 47; j++){ // La�o para percorrer os vetores que cont�m os caracteres com Acentos
  			if(texto[i] == comAcentos[j]){ // Se o caractere atual for um caractere com acento
  				texto[i] = semAcentos[j]; // Substitui pelo caractere sem acento
  				break; // Encerra a itera��o
			  }
		  }
	  }
	
	return texto; // Retorna a string agora sem acentos
	
}

string strTrim(string texto){ // Remove espa�os no come�o e final da string (Utilizado para padroniza��o de checagem)
	
	// Trabalha com recursividade para tirar todos os espa�os no come�o e final da string
	
	string aux = ""; // Inica vari�vel auxiliar
	
	if(texto[0] != ' ' && texto[tamanho(texto)-1] != ' '){ // Se a string n�o tiver espa�os no come�o e no final
		return texto; // Retorna a string
	}else if(texto[0] == ' '){ // Se o primeiro caractere for um espa�o
		for(int j = 1; j < tamanho(texto); j++){ // Copia a string para a vari�vel auxiliar (Exceto o primeiro caractere)
				aux += texto[j];
			}
	}else{ // Se o �ltimo caractere for um espa�o
		for(int j = 0; j < tamanho(texto) - 1; j++){ // Copia a string para a vari�vel auxiliar (Exceto o �ltimo caractere)
			aux += texto[j];
		}
	}
	return strTrim(aux); // Chama a fun��o novamente
	
}

string toLower(string texto){ // Converte os caracteres mai�sculos para min�sculos (Utilizado para padroniza��o de checagem)
	
	for(int i = 0; i < tamanho(texto); i++){ // La�o para percorrer toda a string
		
		if(texto[i] >= 'A' && texto[i] <= 'Z'){ // Se o caractere atual for um charactere alfab�tico mai�sculo
			texto[i] = (int) texto[i] + 32; // Converte para o caractere min�sculo
		}
		
	}
	
	return texto; // Retorna a nova string
	
}

string preparaTexto(string texto){ // Transforma o texto em um texto padr�o (Utilizado para manter o c�digo limpo)

	return toLower(removeAcentos(strTrim(texto))); // Chama as fun��es utilizadas na padroniza��o e retorna o valor

}

int stringCompare(string a, string b){ // 1 Se a for menor, -1 se b for menor e 0 se forem iguais
	
	int i = 0; // Inicia vari�vel que servir� como contador
	a = toLower(a); // Transforma a string em min�scula
	b = toLower(b); // Transforma a string em min�scula
	
	while(i < tamanho(a) || i < tamanho(b)){ // La�o que itera at� chegar ao fim de uma das duas strings
		
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
	}else{ // Se o tamanho tamb�m for igual
		return 0; // Retorna 0
	}
}

bool checaNumero(string texto){ // Verifica se uma string corresponde a um valor num�rico
	
	for(int i = 0; i < tamanho(texto); i++){ // la�o para percorrer a string
		
		if(texto[i] < 48 || texto[i] > 57){ // Se o caractere n�o corresponder ao mesmo d�gito to tipo int
			return false; // Retorna false
		}
		
	}
	
	return true; // Se todos os caracteres passarem no teste, retorna true
	
}



void transformaMatrizOrdenada(string *vetor_a, string *vetor_b, int tamanho_linhas){ // Ordena os arrays em ordem crescente
	

	
	string temp[2]; // Inicia vetor auxiliar
	int i = 0, j = 0; // Inicia vari�veis que ser�o utilizadas como contadoras
	bool numero = checaNumero(vetor_a[0]); // Recebe valor que indica se a categoria analisada corresponde a um valor num�rico (Indicando que a checagem � sobre Edi��o ou Ano)
	
	while(i < (tamanho_linhas)){ // Primeiro la�o para percorrer os arrays
		j = i+1;
		while(j < (tamanho_linhas)){ // Segundo la�o para percorrer os arrays que come�a a partir de i+1
			
			// Se a string corresponder a um caractere num�rico e a categoria checada por J for menor que a checada por I OU
			// Se a string n�o corresponder a um caractere num�rico e a categoria checada por J for alfabeticamente menor que a checada por I
			if((numero == false && stringCompare(vetor_a[i],vetor_a[j]) == -1) || (numero == true && stringToInt(vetor_a[i]) > stringToInt(vetor_a[j]))){
				
				// Troca a posi��o dos vetores
				
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


