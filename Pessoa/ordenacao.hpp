#include <iostream>
#define MAX 5
using namespace std;

class Ordenacao {
  private:
    int vetor[MAX];

  public:
    Ordenacao(){
      int i;
      for(i=0; i<MAX; i++){
        vetor[i] = rand() % 100 + 1;
      }
    }
    ~Ordenacao(){}

    void bubbleSort(){
      int i,j;
      int count = MAX;
      for(i=0;i<MAX;i++){
        int g = 0;
        for(j=1; j<count; j++){
          if(vetor[g] > vetor[j] ){
            int  aux = vetor[g];
            vetor[g] = vetor[j];
            vetor[j] = aux;
          }
          g++;
        }
        count--;
      }
    }

    void selectionSort(){
      int i,j,menor;
      for(i=0; i<MAX; i++){
        menor = vetor[i];
        for(j=i+1; j<MAX; j++ ){
          if(menor > vetor[j]){
            int aux = menor;
            menor = vetor[j];
            vetor[j] = aux;
          }
        }
        vetor[i] = menor;
      }
    }

    void insertionSort(){
      int i, aux, cont;
      for(i = 0; i < MAX; i++){
          if(vetor[i] > vetor[i+1]){
              aux = vetor[i+1];
              vetor[i+1] = vetor[i];
              vetor[i] = aux;
              cont = i;
              while(cont > 0){
                  if(vetor[cont] < vetor[cont-1]){
                      aux = vetor[cont-1];
                      vetor[cont-1] = vetor[cont];
                      vetor[cont] = aux;
                  }else{
                      break;
                  }
                  cont--;
              }
          }
      }
    }

    void shellSort(){
      int j, aux;
      int metade = MAX/2 + 1;
      while(metade > 0){
        for(j = 0; j < MAX-metade; j++){

          if(vetor[j] > vetor[j+metade]){
            aux = vetor[j];
            vetor[j] = vetor[j+metade];
            vetor[j+metade] = aux;
          }
        }
        metade--;
      }
    }

    void margeSort(int inicio, int fim){

      if(inicio != fim){
        int metade = (inicio+fim)/2;
        margeSort(inicio, metade);
        margeSort(metade+1, fim);

        int i = inicio;
        int j = fim+1;

        while(j>inicio){
          
        }
      }
    }

    void mostrar(){
      int i;
      for (i = 0; i < MAX; i++) {
        cout << vetor[i] << " : ";
      }
    }
};
