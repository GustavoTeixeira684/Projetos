#include <iostream>
#include "No.h"
#include "LDL.h"

// Construtor vazio
// inicia o cabe�a da lista como null
LDL::LDL(){
	this->cabeca = nullptr;
	this->qtde = 0;
}

bool LDL::isEmpty() { // Verifica se lDL est� vazia
	if (this->cabeca == nullptr) {
		return true; 
	} else {
	    return false;	
	};  
}


bool LDL::isFull(){ // verifica se alista est� cheia
	No *aux = new No();
	
	if (aux == nullptr) return true;

	aux = nullptr;
	return false;
};

// Percorre a lDL em ordem crescente 
// e mostra os seus valores
void LDL::mostraOrdemCrescente(){
	// Percorre a lista e imprime os valores
	// em ordem Crescente
	if (cabeca == nullptr) cout << "Lista vazia!" << endl;
	else{
		cout << "Lista: [ ";
		No *pAnda = this->cabeca;
		while (pAnda->getProx() != this->cabeca){
			cout << pAnda->getDado() << " ";
			pAnda= pAnda->getProx();
		}
		cout << pAnda->getDado() << "]";
	}
}


// Percorre a lDL em ordem decrescente e mostra os seus valores
void LDL::mostraOrdemDecrescente(){
	// Percorre a lista e imprime os valores
	// em ordem decrescente
	if (cabeca == nullptr) cout << "Lista vazia!" << endl;
	else{
		cout << "Lista: [ ";
		No *pAnda = this->cabeca;
		while (pAnda->getAnt() != this->cabeca){
			pAnda= pAnda->getAnt();
			cout << pAnda->getDado() << " ";
		}
		cout << pAnda->getAnt()->getDado() << "]";
	}
}

// Insere um novo elemento na LDL na ordem
// crescente
bool LDL::insereOrdemCrescente(int chave, Elemento dado){
	// Cria um novo no
	No *novoNo = new No(chave, dado, nullptr, nullptr);
	
	if (isFull()) return false;

	// se lista vazia, insere o n� no ponteiro cabe�a
	// e faz o n� apontar para ele mesmo
	if (cabeca == nullptr) {
		this->cabeca = novoNo;
		novoNo->setProx(novoNo);
		novoNo->setAnt(novoNo);
	} else { 
	    // Caso contr�rio, procura posi�o de inser�o
	    // na ordem crescente de valores
		No *pAnda = this->cabeca, *pAnt = nullptr;
		while (pAnda->getProx() != cabeca && pAnda->getChave() < chave){
				pAnt = pAnda;
				pAnda = pAnda->getProx();
		}	
		// Se n�o andou na lista e a chave que pAnda aponta
	    // � maior que a chave a ser inserida, significa que a chave
		// a ser inserida � antes do cabe�a
		// e cabe�a precisa ser redefinido
		if (pAnt == nullptr && pAnda->getChave() > chave){
			novoNo->setAnt(this->cabeca->getAnt());
			this->cabeca->getAnt()->setProx(novoNo);
			this->cabeca->setAnt(novoNo);
			novoNo->setProx(this->cabeca);
			this->cabeca = novoNo;
		} else {
			// Caso pAnda tenha caminhado na lista e
			// a chave que o pAnda aponta � maior do que a chave a ser inserido
			// insere o n� depois do ponteiro anterior pAnt
		 	if (pAnda->getChave() > chave && pAnt != nullptr) {	 
				pAnt->getProx()->setAnt(novoNo);
				novoNo->setProx(pAnda);
				pAnt->setProx(novoNo);
				novoNo->setAnt(pAnt);
			} else {// Sen�o, insere a chave depois do pAnda
		    	pAnda->getProx()->setAnt(novoNo);
				novoNo->setProx(pAnda->getProx());
				pAnda->setProx(novoNo);
				novoNo->setAnt(pAnda);
			}
		}
	}
	this->qtde++;
	return true;
}

No* LDL::busca(int chave){
  if(!isEmpty()){
    No *pAnda = this->cabeca;
    do{
      if(pAnda->getChave() == chave){
        return pAnda;
      }
      pAnda = pAnda->getProx();
    }while(pAnda != this->cabeca);
    return nullptr;
  }else{
    return nullptr;
  }
}

bool LDL::remove(int chave){
  if(!isEmpty()){
    No *aux = this->busca(chave);
    if(aux != nullptr){
      if(this->qtde > 1){
        if(aux == this->cabeca){
          this->cabeca = aux->getProx();
        }
        aux->getAnt()->setProx(aux->getProx());
        aux->getProx()->setAnt(aux->getAnt());
        this->qtde--;
      }else{
        this->cabeca = nullptr;
        this->qtde = 0;
      }
        delete aux;
        aux = nullptr;
        return true;
    }else{
      return false;
    }
  }else{
    return false;
  }
}

bool LDL::atualiza(int chave, Elemento dado){

  if(!isEmpty()){

    No *aux = busca(chave);
    if(aux != nullptr){
      aux->setDado(dado);
      return true;
    }else{
      return false;
    }
    
  }else{
    return false;
  }
    
}


