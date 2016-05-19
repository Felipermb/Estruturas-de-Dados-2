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
    int esquerda;
    int direita;

  public:

    Pessoa(){
      nome = "";
      idade = 0;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      papai = NULL;
      esquerda = 0;
      direita = 0;

    };

    Pessoa( string n, int id){
      nome = n;
      idade = id;
      filhoDireita = NULL;
      filhoEsquerda = NULL;
      papai = NULL;
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
              atualizaValores(nova,true);
              verifica(nova);
          }else{
              filhoEsquerda->inserirPessoa(nova);
          }
        }else{
          if(filhoDireita == NULL){
              this->filhoDireita = nova;
              nova->papai = this;
              atualizaValores(nova,true);
              verifica(nova);
          }else{
              filhoDireita->inserirPessoa(nova);
          }
        }

    };

    void deletarSemFilho(Pessoa* pessoa){
      if(pessoa->papai->filhoEsquerda == pessoa){
         pessoa->papai->filhoEsquerda = NULL;
         delete pessoa;
       }else{
         pessoa->papai->filhoDireita = NULL;
         delete pessoa;
       }
    };

    void deletarUmFilho(Pessoa* pessoa){
      if(pessoa->papai->filhoEsquerda == pessoa){
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->papai = pessoa->papai;
          pessoa->papai->filhoEsquerda = pessoa->filhoEsquerda;

          delete pessoa;
        }else{
          pessoa->filhoDireita->papai = pessoa->papai;
          pessoa->papai->filhoEsquerda = pessoa->filhoDireita;
          delete pessoa;
        }
      }else{
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->papai = pessoa->papai;
          pessoa->papai->filhoDireita = pessoa->filhoEsquerda;
          delete pessoa;
        }else{
          pessoa->filhoDireita->papai = pessoa->papai;
          pessoa->papai->filhoDireita = pessoa->filhoDireita;
          delete pessoa;
        }
      }

    };

    void deletarDoisFilhos(Pessoa* pessoa){
      int binario;
      if(pessoa->papai->filhoEsquerda == pessoa){
        binario = 0;
      }else{
        binario = 1;
      }
        if(pessoa->filhoDireita->filhoEsquerda == NULL){
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
          Pessoa* aux = pessoa->filhoDireita;
          while(aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }
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
        if(pessoa->filhoDireita->filhoEsquerda == NULL){
          pessoa->filhoDireita->filhoEsquerda = pessoa->filhoEsquerda;
          pessoa->filhoDireita->papai = NULL;
          (*raiz) = pessoa->filhoDireita;
          pessoa->filhoEsquerda->papai = (*raiz);
          delete pessoa;
        }else{
          Pessoa* aux = pessoa->filhoDireita;
          while(aux->filhoEsquerda != NULL){
            aux = aux->filhoEsquerda;
          }
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
        cout << this->nome << ": " << this->idade << ": " << this->direita << ": "<< this->esquerda  << ": " << this->direita - this->esquerda << endl;
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

    void atualizaValores(Pessoa* pessoa, bool opcao){
       Pessoa* aux = pessoa;
       Pessoa* auxPai = pessoa->papai;
       bool segundoFilho;
       if(auxPai->filhoEsquerda!=NULL && auxPai->filhoDireita!=NULL){
         segundoFilho = true;
       }else{
         segundoFilho = false;
       }
       while(aux->papai != NULL){
           if(auxPai->filhoEsquerda == aux){
             if(opcao){
               auxPai->esquerda++;
             }else{
               auxPai->esquerda--;
             }
           }else{
             if(opcao){
               auxPai->direita++;
             }else{
               auxPai->direita--;
             }
           }
           if(segundoFilho){
             return;
           }
           aux=aux->papai;
           auxPai=aux->papai;
       }
   }

   void verifica(Pessoa *inserido){
      while(inserido->papai != NULL){
          if(inserido->papai->direita - inserido->papai->esquerda > 1 || inserido->papai->direita - inserido->papai->esquerda < -1 ){
            int teste = qualroatacao(inserido->papai);
            break;
          }else{
            inserido = inserido->papai;
          }
      }
   }

   void qualroatacao(Pessoa *rodar){
     // 1=rotacao direita  2=rotaçao esquerda   3=rotação dupla direita   4=rotação dupla esquerda
     if(roda->direita - roda->esquerda < 0 && roda->filhoEsquerda->direita - roda->filhoEsquerda->esquerda < 0){
       return 1;
     }else{
       if(roda->direita - roda->esquerda > 0 && roda->filhoEsquerda->direita - roda->filhoEsquerda->esquerda > 0){
         return 2;
       }else{
         if(roda->direita - roda->esquerda < 0 && roda->filhoEsquerda->direita - roda->filhoEsquerda->esquerda > 0){
           return 3;
         }else{
           return 4;
         }
       }
     }
   }

   void rotacaoEsquerda(Pessoa *rodar, Pessoa **raiz){
     if(rodar == (*raiz)){
       if(rodar->filhoDireita->filhoEsquerda != NULL){
        
       }else{

       }
     }else{
       if(rodar->filhoDireita->filhoEsquerda !=NULL){

       }else{

       }
     }
   }
};
