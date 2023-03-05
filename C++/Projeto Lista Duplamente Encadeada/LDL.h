#ifndef ____LDL____
#define ____LDL____

#include "No.h"
// Classe de Lista Duplamente Encadeada
class LDL{
	private:
		No *cabeca;
		int qtde;
	public:
		LDL();
		~LDL() {};// Exerc�cio
		void setCabeca(No *cabeca){ this->cabeca = cabeca;	};
		No *getCabeca(){ return cabeca; };
		int getQtde(){ return qtde;	};
		void setQtde(int qtde) { this->qtde =  qtde; };
		bool isEmpty();	
		bool isFull();	
		bool insereOrdemCrescente(int chave, Elemento dado);
		void mostraOrdemCrescente();
		void mostraOrdemDecrescente();// Exerc�cio
		No *busca(int chave); // Exerc�cio
		bool remove(int chave); // Exerc�cio
    bool atualiza(int chave, Elemento dado);
};

#endif
