#include "Pessoa.hpp"
#include <stdlib.h>
Pessoa *raiz = NULL;

int main(){

  int idade;
  Pessoa *novo;
  string nome;

  int i = 0;
  for(i=0; i<6; i++){
      cout << "Insira a Idade:" << endl;
      cin >> idade;

      novo = new Pessoa("nome",idade);

      if(raiz == NULL){
        raiz = novo;
      }else{
        raiz->inserirFilho(novo);
      }
  }

  system("clear");
  cout << endl;
  raiz->mostrarPreOrdem();

  cout << "Inisira a idade a apagar" << endl;
  cin >> idade;

  /*Pessoa *retorno = raiz->buscar(idade);

  if(retorno == NULL){
    cout << "Não encontrado" << endl;
  }else{
    cout << retorno->getNome() <<"--"<< retorno->getIdade() << endl;
  }*/

  Pessoa *apagar = raiz->buscar(idade);

  raiz->limpaEspecifica(apagar);

  cout << endl;
  raiz->mostrarPreOrdem();

  raiz->limpaMemoria();
  return 0;
}
