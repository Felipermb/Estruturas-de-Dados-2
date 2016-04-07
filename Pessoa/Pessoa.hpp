#include <iostream>

using namespace std;

class Pessoa{
  protected:
    string nome;
    int idade;
    Pessoa *direita;
    Pessoa *esquerda;

  public:
    Pessoa(){

    }

    Pessoa(string nm, int id){
      nome = nm;
      idade = id;
      direita = NULL;
      esquerda = NULL;
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
          }else{
            this->direita->inserirFilho(novo);
          }
      }else{
        if(this->esquerda == NULL){
          this->esquerda = novo;
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
