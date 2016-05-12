#include <iostream>
#include <string>

using namespace std;

class Pessoa{

  public:
    string nome;
    int idade;
    Pessoa* filhoEsquerda;
    Pessoa* filhoDireita;
    Pessoa* papai;
    int contEsq;
    int contDir;

  public:

    Pessoa(){
      nome = "";
      idade = 0;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      papai = NULL;
      contDir = 0;
      contEsq = 0;

    };

    Pessoa( string n, int id){
      nome = n;
      idade = id;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      papai = NULL;
      contDir = 0;
      contEsq = 0;
    };

    ~Pessoa(){};

    void setNome(string n){
      nome = n;
    };
    string getNome(){
      return nome;
    };
    void setIdade(int id){
      idade = id;
    };
    int getIdade(){
      return idade;
    };

    void inserirPessoa(Pessoa *nova){
        if(nova->idade <= this->idade){
          if(filhoEsquerda == NULL){
              this->filhoEsquerda = nova;
              nova->papai = this;
              Pessoa *aux = this;
              this->contEsq++;
              while(aux->papai != NULL){
                if(aux == aux->papai->filhoEsquerda){
                  aux->papai->contEsq++;
                  aux = aux->papai;
                }else{
                  break;
                }
              }
          }else{
              filhoEsquerda->inserirPessoa(nova);
          }
        }else{
          if(filhoDireita == NULL){
              this->filhoDireita = nova;
              nova->papai = this;
              Pessoa *aux = this;
              this->contDir++;
              while(aux->papai != NULL){
                if(aux == aux->papai->filhoDireita){
                  aux->papai->contDir++;
                  aux = aux->papai;
                }else{
                  break;
                }
              }
          }else{
              filhoDireita->inserirPessoa(nova);
          }
        }

    };

    void deletarSemFilho(Pessoa* pessoa){
      //Teste para saber qual lado está a pessoa que será removida

      //cout << endl << pessoa->papai->filhoEsquerda->getNome() << " : " << pessoa->getNome() << endl;

      if(pessoa->papai->filhoEsquerda == pessoa){
         //remove o filho da esquerda
         cout << endl << "Removendo filho a esquerda" << endl;
         pessoa->papai->filhoEsquerda = NULL;
         delete pessoa;
       }else{
         //remove o filho da direita
         cout << endl << "Removendo filho a direita" << endl;
         pessoa->papai->filhoDireita = NULL;
         delete pessoa;
       }
    };

    void deletarUmFilho(Pessoa* pessoa){

      //Verificar qual o lado estou
      if(pessoa->papai->filhoEsquerda == pessoa){
        cout << endl << "Removendo filho a esquerda" << endl;
        //estou do lado esquerdo
        //Verificar quem é meu filho (esquedo ou direito)
        if(pessoa->filhoEsquerda != NULL){
        //filho a esquerda
          pessoa->filhoEsquerda->papai = pessoa->papai;
          pessoa->papai->filhoEsquerda = pessoa->filhoEsquerda;

          delete pessoa;
        }else{
        //filho a direita
          pessoa->filhoDireita->papai = pessoa->papai;
          pessoa->papai->filhoEsquerda = pessoa->filhoDireita;
          delete pessoa;
        }


      }else{
        cout << endl << "Removendo filho a direita" << endl;
        //estou do lado direito
        //Verificar quem é o meu filho (esquerdo ou direito)
        if(pessoa->filhoEsquerda != NULL){
          //filho a esquerda
          pessoa->filhoEsquerda->papai = pessoa->papai;
          pessoa->papai->filhoDireita = pessoa->filhoEsquerda;
          delete pessoa;
        }else{
          // filho a direita
          pessoa->filhoDireita->papai = pessoa->papai;
          pessoa->papai->filhoDireita = pessoa->filhoDireita;
          delete pessoa;
        }
      }

    };

    void deletarDoisFilhos(Pessoa* pessoa){
      //Verificar de qual lado estou
      int binario;
      if(pessoa->papai->filhoEsquerda == pessoa){
        //estou do lado esquerdo
        binario = 0;
      }else{
        //estou do lado direito
        binario = 1;
      }
      //if(pessoa->papai->filhoEsquerda == pessoa){
        //estou do lado esquerdo
        //verificar se meu filho a direita tem um filho a esquerda
        if(pessoa->filhoDireita->filhoEsquerda == NULL){
          //ele não TEM filho a esquerda
          cout << "Não possui filho a esquerda" << endl;

          if(binario == 0){
            pessoa->papai->filhoEsquerda = pessoa->filhoDireita;
          }else{
            pessoa->papai->filhoDireita = pessoa->filhoDireita;
          }

          pessoa->filhoDireita->filhoEsquerda = pessoa->filhoEsquerda;
          pessoa->filhoDireita->papai = pessoa->papai;
          pessoa->filhoEsquerda->papai = pessoa->filhoDireita;
          delete pessoa;

        }else{
          //ele TEM filho a esquerda
          //buscar a ultima folha deste galho a esquerda
          cout << "Possui filho a esquerda" << endl;

          Pessoa* aux = pessoa->filhoDireita;
          while(aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }

           //Verificar se esse cara 'aux' tem um filho a direita
           if(aux->filhoDireita != NULL){
              aux->filhoDireita->papai = aux->papai;
           }
           aux->papai->filhoEsquerda = aux->filhoDireita;

          if(binario == 0){
            pessoa->papai->filhoEsquerda = aux;
          }else{
            pessoa->papai->filhoDireita = aux;
          }

          aux->papai = pessoa->papai;
          aux->filhoEsquerda = pessoa->filhoEsquerda;
          aux->filhoDireita = pessoa->filhoDireita;
          aux->filhoEsquerda->papai = aux;
          aux->filhoDireita->papai = aux;
          delete pessoa;

        }
    };

    void deletarRaizDoisFilhos(Pessoa* pessoa, Pessoa ** raiz){
      //Verificar de qual lado estou
        if(pessoa->filhoDireita->filhoEsquerda == NULL){
          //ele não TEM filho a esquerda
          cout << "Não possui filho a esquerda" << endl;

          pessoa->filhoDireita->filhoEsquerda = pessoa->filhoEsquerda;
          pessoa->filhoDireita->papai = NULL;
          (*raiz) = pessoa->filhoDireita;
          pessoa->filhoEsquerda->papai = (*raiz);
          delete pessoa;

        }else{
          //ele TEM filho a esquerda
          //buscar a ultima folha deste galho a esquerda
          cout << "Possui filho a esquerda" << endl;

          Pessoa* aux = pessoa->filhoDireita;
          while(aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }

           //Verificar se esse cara 'aux' tem um filho a direita
           if(aux->filhoDireita != NULL){
              aux->filhoDireita->papai = aux->papai;
           }
           aux->papai->filhoEsquerda = aux->filhoDireita;

          aux->papai = NULL;

          aux->filhoEsquerda = pessoa->filhoEsquerda;
          aux->filhoDireita = pessoa->filhoDireita;
          aux->filhoEsquerda->papai = aux;
          aux->filhoDireita->papai = aux;
          (*raiz) = aux;
          delete pessoa;

        }
    }

    void deletarElemento(int chave, Pessoa ** raiz){

      Pessoa* aux = this->buscar(chave);
      if(aux != NULL){
        cout << "Você está deletando: " << aux->getNome() << endl;
        if(aux->filhoEsquerda == NULL && aux->filhoDireita == NULL){
            cout << endl << "Deletando SEM filhos" << endl;
            if(aux->papai == NULL){
               //sou raiz
               cout << "Sou Raiz" << endl;
               //deletarRaiz(0, &aux);
               //(*raiz) = NULL;
               delete aux;
               (*raiz) = NULL;
            }else{
              deletarSemFilho(aux);
            }

        }else{
          if(aux->filhoEsquerda == NULL || aux->filhoDireita == NULL){
              cout << endl << "Deletando com UM filho" << endl;
              if(aux->papai == NULL){
                //sou raiz
                if(aux->filhoEsquerda != NULL){
                  cout << "A raiz será o filho a esquerda" << endl;
                  aux->filhoEsquerda->papai = NULL;
                  (*raiz) = aux->filhoEsquerda;
                }else{
                  cout << "A raiz será o filho a direita" << endl;
                  aux->filhoDireita->papai=NULL;
                  (*raiz) = aux->filhoDireita;
                }
                delete aux;
              }else{
                  deletarUmFilho(aux);
              }
          }else{
                  cout << endl << "Deletando com DOIS filhos" << endl;
                   if(aux->papai == NULL){
                  //   //sou raiz
                  //   cout << "Sou Raiz" << endl;
                      deletarRaizDoisFilhos(aux, raiz);
                   }else{
                      deletarDoisFilhos(aux);
                   }
          }
        }
      }else{
        //pessoa não encontrada
        cout << "Pessoa Não Encontrada" << endl;
      }

    };

    Pessoa* buscar(int chave){
      if(chave != this->idade){
        if(chave < this->idade){
          //esquerda
          if(filhoEsquerda!=NULL){
            this->filhoEsquerda->buscar(chave);
          }else{
            return NULL;
          }
        }else{
          //direita
          if(filhoDireita != NULL){
            this->filhoDireita->buscar(chave);
          }else{
            return NULL;
          }
        }
      }else{
        return this;
      }
    }

    void limparMemoria(){
     if(this->filhoEsquerda != NULL)
       this->filhoEsquerda->limparMemoria();

     if(this->filhoDireita != NULL)
       this->filhoDireita->limparMemoria();
       delete this;
    }

    void preMostrar(){
        cout << this->nome << ": " << this->idade << ": " << this->contDir << ": "<< this->contEsq << endl;
        if(filhoEsquerda != NULL){
          this->filhoEsquerda->preMostrar();
        }

        if(filhoDireita != NULL){
          this->filhoDireita->preMostrar();
        }
    }

    void ordemMostrar(){

      if(filhoEsquerda != NULL){
        this->filhoEsquerda->ordemMostrar();
      }
      cout << this->nome << ":" << this->idade << endl;
      if(filhoDireita != NULL){
        this->filhoDireita->ordemMostrar();
      }

    }

    void posMostrar(){
      if(filhoEsquerda != NULL){
          this->filhoEsquerda->posMostrar();
      }

      if(filhoDireita != NULL){
        this->filhoDireita->posMostrar();
      }

      cout << this->nome << ":" << this->idade << endl;
    }
};

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

  while(insere < 6){
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
