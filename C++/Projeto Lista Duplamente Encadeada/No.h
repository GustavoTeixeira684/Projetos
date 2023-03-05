#ifndef ____LDECO_NO____
#define ____LDECO_NO____

using namespace std;

// Elemento do tipo inteiro a ser inserido no n� da LDL 
typedef int Elemento;

// Classe N� da lista duplamente encadeada
class No {
	private:
		int chave;
		Elemento dado;
		No *ant, *prox;
	public:
		No() {}
		No(int chave, Elemento dado, No *ant, No *prox){
			this->chave = chave;
			this->dado = dado;
			this->ant = ant;
			this->prox = prox;
		};
		~No(){};
		Elemento getDado() { return dado;};
		No *getAnt(){ return ant;};
		No *getProx(){ return prox;};
		int getChave(){ return chave; };
		void setDado(Elemento dado) { this->dado = dado;};
		void setChave(int chave){ this->chave = chave; };
		void setAnt(No *ant){ this->ant = ant; };
		void setProx(No *prox){ this->prox = prox; };		
};

#endif
