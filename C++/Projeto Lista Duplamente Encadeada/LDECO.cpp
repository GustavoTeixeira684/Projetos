#include <iostream>
#include "LDL.h"

using namespace std;

LDL *intercala(LDL *Lista1, LDL *Lista2){
  No* pAnda = Lista2->getCabeca();
  do{
    Lista1->insereOrdemCrescente(pAnda->getChave(), pAnda->getDado());
    pAnda = pAnda->getProx();
  }while(pAnda != Lista2->getCabeca());
  return Lista1;
}

// Programa Principal que testa a LDL
int main() {
  LDL *lista = new LDL();
	LDL *lista1 = new LDL();
  LDL *lista2 = new LDL();
  No* resultBusca = new No();
  
  lista1->insereOrdemCrescente(2, 2);
	lista2->insereOrdemCrescente(5, 5);
	lista1->insereOrdemCrescente(25, 25);
	lista2->insereOrdemCrescente(12, 12);
	lista1->insereOrdemCrescente(23, 23);
	lista2->insereOrdemCrescente(55, 55);
	lista1->insereOrdemCrescente(22, 22);
	lista2->insereOrdemCrescente(43, 43);
	lista1->insereOrdemCrescente(1, 1);	
  lista2->insereOrdemCrescente(3,3);



  cout << "Lista 1: " << endl;
  lista1->mostraOrdemCrescente();
  cout << "\n\nLista 2: " << endl;
  lista2->mostraOrdemCrescente();
  cout << "\n\nLista intercalada: " << endl;
  lista = intercala(lista1,lista2);
  lista->mostraOrdemCrescente();

  lista->remove(1);
  lista->remove(2);
  lista->remove(25);
  lista->atualiza(55,123);

  

  
	//cout << "\n\nDecrescente" << endl;
	//lista->mostraOrdemDecrescente();

	// Faz uma pausa antes de finalizar o programa
	cout << endl << endl;
	system("pause");
	return 0;
}
