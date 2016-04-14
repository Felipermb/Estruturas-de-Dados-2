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

    void limpaEspecifica(Pessoa *apagar){
      if(apagar->direita == NULL && apagar->esquerda == NULL){
          if(apagar->pai->direita == apagar){
              apagar->pai->direita = NULL;
              delete apagar;
          }else{
            apagar->pai->esquerda = NULL;
            delete apagar;
          }
      }else{
        if(apagar->esquerda == NULL || apagar->direita == NULL){
          if(apagar->esquerda == NULL){
            apagar->direita->pai->pai->direita = apagar->direita;
            delete apagar;
          }else{
            apagar->esquerda->pai->pai->esquerda = apagar->esquerda;
            delete apagar;
          }
        }else{
          if(apagar->direita->esquerda == NULL){
            apagar->direita->pai = apagar->pai;
            apagar->direita->esquerda = apagar->esquerda;
            if(apagar->pai->esquerda == apagar){
                apagar->pai->esquerda = apagar->direita;
            }else{
              apagar->pai->direita = apagar->direita;
            }
            delete apagar;
          }else{
            Pessoa *caminhar = apagar->direita;
            while(caminhar->esquerda != NULL){
              caminhar = caminhar->esquerda;
            }
            if(caminhar->direita == NULL){
              caminhar->pai->esquerda = NULL;
              caminhar->pai = apagar->pai;
              caminhar->esquerda = apagar->esquerda;
              apagar->esquerda->pai = caminhar;
              caminhar->direita = apagar->direita;
              apagar->direita->pai = caminhar;
              delete apagar;

            }else{
              // caminhar->direita->pai = caminhar->pai;
              // caminhar->pai->esquerda = caminhar->direita;
              // caminhar->esquerda = apagar->esquerda;
              // apagar->esquerda->pai = caminhar;
              // caminhar->direita = apagar->direita;
              // apagar->direita->pai = caminhar;
              // delete apagar;
            }
          }
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
