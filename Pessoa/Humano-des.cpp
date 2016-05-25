#include "Pessoa.hpp"
#include <stdlib.h>
Pessoa *raiz = NULL;

int main(){

  int idade;
  Pessoa *novo;
  string nome;

  int i = 0;
  for(i=0; i<3; i++){
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

  Pessoa *apagar = raiz->buscar(idade);
  if(apagar == NULL){
    std::cout << "Não encontrado" << std::endl;
  }else{
    raiz->limpaEspecifica(apagar, &raiz);
  }

  cout << endl;
  if(raiz != NULL)
    raiz->mostrarPreOrdem();


  if(raiz != NULL)
    raiz->limpaMemoria();
  return 0;
}
