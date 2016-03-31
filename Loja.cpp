#include "Veiculo.hpp"

using namespace std;

int main(){

  Carro *vetor;
  vetor = new Carro[10];
  int i = 0;
  for(i=0; i<10; i++){
    vetor[i].setMarca("Ford");
  }

  for(i=0; i<10; i++){
    cout << vetor[i].getMarca() << endl;
  }

  delete[] vetor;

  return 0;
}
