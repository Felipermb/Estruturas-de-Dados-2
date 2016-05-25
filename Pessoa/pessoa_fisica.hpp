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

    void inserirPessoa(Pessoa *nova, Pessoa **raiz){
        if(nova->idade <= this->idade){
          if(filhoEsquerda == NULL){
              this->filhoEsquerda = nova;
              nova->papai = this;
              (*raiz)->profundidadeNos();
              (*raiz)->verifica(raiz);
          }else{
              filhoEsquerda->inserirPessoa(nova,raiz);
          }
        }else{
          if(filhoDireita == NULL){
              this->filhoDireita = nova;
              nova->papai = this;
              (*raiz)->profundidadeNos();
              (*raiz)->verifica(raiz);
          }else{
              filhoDireita->inserirPessoa(nova,raiz);
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
        (*raiz)->profundidadeNos();
        (*raiz)->verifica(raiz);
      }else{
        //pessoa não encontrada
        cout << "Pessoa Não Encontrada" << endl;
      }

    };

    Pessoa* buscar(int chave){
      if(chave != this->idade){
        if(chave < this->idade){
          if(filhoEsquerda!=NULL){
            this->filhoEsquerda->buscar(chave);
          }else{
            return NULL;
          }
        }else{
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
        cout << this->nome << ": " << this->idade << "  Desbalanceamento:  " << this->direita - this->esquerda << endl;
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

  int profundidadeNos(){
        esquerda = 0;
        direita = 0;
        //cout<< "profundidadeNos " << endl;
        if (filhoEsquerda != NULL) {
            esquerda = filhoEsquerda->profundidadeNos()+1;
        }

        if (filhoDireita != NULL) {
            direita = filhoDireita->profundidadeNos()+1;
        }

        return (esquerda > direita) ? esquerda : direita;
    }

  void verifica(Pessoa** raiz){
        int teste = this->direita - this->esquerda;
        if(teste < -1 || teste > 1){
          cout << "Árvore Desbalanceada em: " << this->idade << endl;
          Balancear(teste, this, raiz);
          return;
        }
        if(filhoEsquerda != NULL){
          this->filhoEsquerda->verifica(raiz);
        }
        if(filhoDireita != NULL){
          this->filhoDireita->verifica(raiz);
        }
    }

  void Balancear(int teste, Pessoa *pessoa, Pessoa** raiz){
      int teste_no;
      if(teste < 0){
        teste_no = pessoa->filhoEsquerda->direita - pessoa->filhoEsquerda->esquerda;
        if(teste_no <= 0){
          cout << "Rotação direita" << endl;
          rotacaoDireita(pessoa, raiz);
        }else{
          cout << "Dupla direita" << endl;
          rotacaoEsquerda(pessoa->filhoEsquerda, raiz);
          rotacaoDireita(pessoa, raiz);
        }
      }else{
        teste_no = pessoa->filhoDireita->direita - pessoa->filhoDireita->esquerda;
        if(teste_no >= 0){
          cout << "Rotação esquerda" << endl;
          rotacaoEsquerda(pessoa, raiz);
        }else{
          cout << "Dupla esquerda" << endl;
          rotacaoDireita(pessoa->filhoDireita, raiz);
          rotacaoEsquerda(pessoa, raiz);
        }
      }
      (*raiz)->profundidadeNos();
    }

  void rotacaoDireita(Pessoa* pessoa, Pessoa** raiz){
      if(pessoa->papai == NULL){
        (*raiz) = pessoa->filhoEsquerda;
        pessoa->filhoEsquerda = (*raiz)->filhoDireita;
        (*raiz)->filhoDireita = pessoa;
        (*raiz)->papai = NULL;
        pessoa->papai = (*raiz);
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->papai = pessoa;
        }
      }else{
        Pessoa* pai = pessoa->papai;
        Pessoa* aux = pessoa->filhoEsquerda;
        if(pai->filhoEsquerda == pessoa){
          pai->filhoEsquerda = aux;
        }else{
          pai->filhoDireita = aux;
        }
        aux->papai = pai;
        pessoa->filhoEsquerda = aux->filhoDireita;
        aux->filhoDireita = pessoa;
        pessoa->papai = aux;
        if(pessoa->filhoEsquerda != NULL){
          pessoa->filhoEsquerda->papai = pessoa;
        }

      }
    }

  void rotacaoEsquerda(Pessoa* pessoa, Pessoa** raiz){
      if(pessoa->papai == NULL){
        (*raiz) = pessoa->filhoDireita;
        pessoa->filhoDireita = (*raiz)->filhoEsquerda;
        (*raiz)->filhoEsquerda = pessoa;
        (*raiz)->papai = NULL;
        pessoa->papai = (*raiz);
        if(pessoa->filhoDireita != NULL){
          pessoa->filhoDireita->papai = pessoa;
        }
      }else{
        Pessoa* pai = pessoa->papai;
        Pessoa* aux = pessoa->filhoDireita;;
        if(pai->filhoEsquerda == pessoa){
          pai->filhoEsquerda = aux;
        }else{
          pai->filhoDireita = aux;
        }
        aux->papai = pai;
        pessoa->filhoDireita = aux->filhoEsquerda;
        aux->filhoEsquerda = pessoa;
        pessoa->papai = aux;
        if(pessoa->filhoDireita != NULL){
          pessoa->filhoDireita->papai = pessoa;
        }
      }
    }

};
