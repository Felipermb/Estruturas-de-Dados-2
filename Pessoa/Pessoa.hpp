#include <iostream>

using namespace std;

class Pessoa{
  protected:
    string nome;
    int idade;
    Pessoa *direita;
    Pessoa *esquerda;
    Pessoa *pai;

  public:
    Pessoa(){
    }

    Pessoa(string nm, int id){
      nome = nm;
      idade = id;
      direita = NULL;
      esquerda = NULL;
      pai = NULL;
    }
    ~Pessoa(){
      cout << "Pessoa Morta" << endl;
    }


    void setNome(string n){
      nome = n;
    }
    string getNome(){
      return nome;
    }
    void setIdade(int n){
      idade = n;
    }
    int getIdade(){
      return idade;
    }

    void setDireita(Pessoa *n ){
      direita = n;
    }
    Pessoa *getDireita(){
      return direita;
    }

    void setEsquerda(Pessoa *n ){
      esquerda = n;
    }
    Pessoa *getEsquerda(){
      return esquerda;
    }

    void inserirFilho(Pessoa *novo){
      if(novo->idade > this->idade){
          if(this->direita == NULL){
            this->direita = novo;
            novo->pai = this;
          }else{
            this->direita->inserirFilho(novo);
          }
      }else{
        if(this->esquerda == NULL){
          this->esquerda = novo;
          novo->pai = this;
        }else{
          this->esquerda->inserirFilho(novo);
        }
      }
    }

    void mostrarPreOrdem(){
        cout << "Idade: " << this->getIdade() << endl;
        if(this->esquerda != NULL)
        this->esquerda->mostrarPreOrdem();

        if(this->direita != NULL)
        this->direita->mostrarPreOrdem();
    }
    void mostrarOrdem(){
        if(this->esquerda != NULL)
        this->esquerda->mostrarOrdem();

        cout << "Idade: " << this->getIdade() << endl;

        if(this->direita != NULL)
        this->direita->mostrarOrdem();
    }
    void mostrarPosOrdem(){
        if(this->esquerda != NULL)
        this->esquerda->mostrarPosOrdem();

        if(this->direita != NULL)
        this->direita->mostrarPosOrdem();

        cout << "Idade: " << this->getIdade() << endl;
    }

    void limpaMemoria(){
      if(this->esquerda != NULL)
        this->esquerda->limpaMemoria();

      if(this->direita != NULL)
        this->direita->limpaMemoria();

      delete this;
    }

    Pessoa * buscar(int idade){
      if(this->idade == idade ){
        return this;
      }else{
        if(idade > this->idade){
          if(this->direita != NULL)
            this->direita->buscar(idade);
          else
            return NULL;
        }else{
          if(this->esquerda != NULL)
            this->esquerda->buscar(idade);
          else
            return NULL;
        }
      }
    }

    void removeNoFolha(Pessoa *apagar, Pessoa **raiz){
      if(apagar == (*raiz)){
        delete apagar;
        (*raiz) = NULL;
      }else{
        if(apagar->pai->direita == apagar){
          apagar->pai->direita = NULL;
          delete apagar;
        }else{
          apagar->pai->esquerda = NULL;
          delete apagar;
        }
      }
    }

    void removerUmFilhos(Pessoa *apagar, Pessoa **raiz){
      if(apagar == (*raiz)){
        if(apagar->direita == NULL){
          (*raiz) = apagar->esquerda;
        }else{
          (*raiz) = apagar->direita;
        }
        delete apagar;
      }else{
        if(apagar->esquerda == NULL){
          apagar->direita->pai = apagar->pai;
          if(apagar->pai->direita == apagar){
            apagar->pai->direita = apagar->direita;
          }else{
            apagar->pai->esquerda = apagar->direita;
          }
          delete apagar;
        }else{
          apagar->esquerda->pai = apagar->pai;
          if(apagar->pai->esquerda == apagar){
            apagar->pai->esquerda = apagar->esquerda;
          }else{
            apagar->pai->direita = apagar->esquerda;
          }
          delete apagar;
        }
      }
    }

    void removeDoisFilhos(Pessoa *apagar, Pessoa **raiz){
      cout << "entrou 2 filhos" << endl;
        Pessoa *caminhar = apagar->direita;
        while(caminhar->esquerda != NULL){
          caminhar = caminhar->esquerda;
        }
        caminhar->pai->esquerda = caminhar->direita;
        if(caminhar->direita != NULL){
          caminhar->direita->pai = caminhar->pai;
        }
        caminhar->direita = apagar->direita;
        caminhar->esquerda = apagar->esquerda;
        caminhar->pai = apagar->pai;
        if(apagar->pai->direita == apagar){
          apagar->pai->direita = caminhar;
        }else{
          apagar->pai->esquerda = caminhar;
        }
        delete apagar;
      }

    void limpaEspecifica(Pessoa *apagar, Pessoa **raiz){
      if(apagar->direita == NULL && apagar->esquerda == NULL){
         this->removeNoFolha(apagar,raiz);
      }else{
        if(apagar->esquerda == NULL || apagar->direita == NULL){
          this->removerUmFilhos(apagar,raiz);
        }else{
            this->removeDoisFilhos(apagar,raiz);
        }
      }
    }

};

class PessoaFisica : public Pessoa{
  protected:
    int cpf;

  public:
    PessoaFisica(){

    }
    PessoaFisica(string nm, int registro){
      nome = nm;
      cpf = registro;
    }
    ~PessoaFisica(){
      cout << "Matei uma pessoa" << endl;
    }

    void setCpf(int registro){
      cpf = registro;
    }
    int getCpf(){
      return cpf;
    }
};

class PessoaJuridica: public Pessoa{
  protected:
    int cnpj;

  public:
    PessoaJuridica(){

    }
    PessoaJuridica(string nm, int registro){
      cnpj = registro;
      nome = nm;
    }
    ~PessoaJuridica(){
      cout << "Fali uma empresa" << endl;
    }

    void setCnpj(int registro){
      cnpj = registro;
    }
    int getCnpj(){
      return cnpj;
    }
};
