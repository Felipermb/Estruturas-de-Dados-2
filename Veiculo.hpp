#include <iostream>
#include <string>

using namespace std;

class Veiculo {
  protected:
    string marca;
    string modelo;
    float preco;

  private:
    int teste;

  public:
    Veiculo(){
      marca = "";
      modelo = "";
      preco = 0.0;
    };

    Veiculo(string mc, string md, float pr){
      marca = mc;
      modelo = md;
      preco = pr;
    };

    ~Veiculo(){
      cout << "Veiculo sendo desmontado" << endl <<endl;
    };

    string getMarca(){
      return marca;
    };

    void setMarca(string mc){
      marca = mc;
    };

    string getModelo(){
      return modelo;
    };

    void setModelo(string md){
      modelo = md;
    };

    float getPreco(){
      return preco;
    };

    void setPreco(float pr){
      preco = pr;
    };

};

class Carro: public Veiculo{
  private:
    int tipoCambio;
    int numeroAssentos;

  public:
    Carro(){

    };

    Carro (string mc, string md, float pr, int tc, int na){
      marca = mc;
      modelo = md;
      preco = pr;
      tipoCambio = tc;
      numeroAssentos = na;
    };

    ~Carro(){
      cout << "Estacionando o carro na garagem" << endl <<endl;
    };

    int getTipoCambio(){
      return tipoCambio;
    };

    void setTipoCambio(float tc){
      tipoCambio = tc;
    };

    int getNumeroAssentos(){
      return numeroAssentos;
    };

    void setNumeroAssentos(float na){
      numeroAssentos = na;
    };

};

class Aviao: public Veiculo{
  private:
    int numeroPoltronas;
    string piloto;
    string combustivel;

  public:
    Aviao(){

    };

    Aviao (string mc, string md, float pr, int np, string pl, string cb){
      marca = mc;
      modelo = md;
      preco = pr;
      numeroPoltronas = np;
      piloto = pl;
      combustivel = cb;
    };

    ~Aviao(){
      cout << "Pousando Aviao" << endl << endl;
    };

    int getNumeroPoltronas(){
      return numeroPoltronas;
    };

    void setNumeroPoltronas(int np){
      numeroPoltronas = np;
    };

    string getPiloto(){
      return piloto;
    };

    void setPiloto(string pl){
      piloto = pl;
    };

    string getCombustivel(){
      return combustivel;
    };

    void setCombustivel(string cb){
      combustivel = cb;
    };

};
