#include "Pessoa.hpp"
#include <stdlib.h>
Pessoa *raiz = NULL;

int main(){

  int idade;
  Pessoa *novo;
  string nome;

  int i = 0;
  for(i=0; i<3; i++){
      cout << "Insira o Nome: " << endl;
      cin >> nome;

      cout << "Insira a Idade:" << endl;
      cin >> idade;

      novo = new Pessoa(nome,idade);

      if(raiz == NULL){
        raiz = novo;
      }else{
        raiz->inserirFilho(novo);
      }
  }

  system("clear");
  cout << endl;
  raiz->mostrarPreOrdem();
  cout << endl;
  raiz->mostrarOrdem();
  cout << endl;
  raiz->mostrarPosOrdem();

  raiz->limpaMemoria();
  return 0;
}
