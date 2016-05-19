#include "pessoa_fisica.hpp"

int main(int argc, char const *argv[]) {
  Pessoa* pes;
  Pessoa* raiz = NULL;
  //pes = new Pessoa("kleyson", 20);
  string nome;
  int idade;
  int insere = 0;
  int chave;

  int id[5];
  string nom[5];

  while(insere < 4){
    cout << "Informe o nome:" << endl;
    cin >> nome;
    cout << "Informe a idade" << endl;
    cin >> idade;

    pes = new Pessoa(nome, idade);

    if(raiz == NULL){
      cout << "Sou NULL" << endl;
      raiz = pes;
    }else{
      raiz->inserirPessoa(pes);
    }

    insere++;
  }

  cout << endl << "preMostrar" << endl;
  raiz->preMostrar();

  // cout << endl << "ordemMostrar" << endl;
  // raiz->ordemMostrar();
  //
  // cout << endl << "posMostrar" << endl;
  // raiz->posMostrar();

 // Pessoa* aux;
 //  insere = 0;
/*  while(insere < 5){
       cout << endl << "Informe a idade para deletar: ";
       cin >> chave;

      aux = raiz->buscar(chave);


      if(aux != NULL){
        cout << "Elemento adicionado ao Backup "<< aux->idade << " " << aux->nome << endl;

        id[insere] = aux->idade;
        nom[insere] = aux->nome;
        insere++;
      }

      raiz->deletarElemento(chave, &raiz);
      raiz->preMostrar();
  }

  cout << endl << "Valores Armazenados" << endl << endl;
  for (size_t i = 0; i < 5; i++) {

    cout << "Nome: " << nom[i] << endl;
    cout << "Idade: " << id[i] << endl << endl;
  }*/

  return 0;
}
