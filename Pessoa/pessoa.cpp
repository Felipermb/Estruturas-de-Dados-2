#include "pessoa_fisica.hpp"
#include <stdlib.h>
#include "ordenacao.hpp"

int main(int argc, char const *argv[]) {
  Pessoa* pes;
  Pessoa* raiz = NULL;

  string nome;
  int idade;
  int insere = 0;

  Ordenacao vetor;
  vetor.mostrar();
  //vetor.bubbleSort();
  //vetor.selectionSort();
  vetor.insertSort();
  cout << endl << "Ordenando..." << endl << endl;

  vetor.mostrar();
  cout << endl;
/* while(insere < 5){
    cout << "Informe o nome:" << endl;
    cin >> nome;
    cout << "Informe a idade" << endl;
    cin >> idade;

    system("clear");
    pes = new Pessoa(nome, idade);
    if(raiz == NULL){
      raiz = pes;
    }else{
      raiz->inserirPessoa(pes,&raiz);
    }
    insere++;
    cout << endl;
    raiz->preMostrar();
    cout << endl;
  }*/

//  cout << endl << "preMostrar" << endl;
//  raiz->preMostrar();

  return 0;
}
