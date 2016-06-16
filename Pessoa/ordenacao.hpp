#include <iostream>
#define MAX 9
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

    void quickSort(int esquerda,int direita){
      if(esquerda < direita){
        int pivot = particao(esquerda,direita);
        quickSort(esquerda, pivot-1);
        quickSort(pivot+1, direita);
      }
    }

    int particao(int esquerda,int direita){
      int i;
      int pivo = vetor[esquerda];
      while(esquerda != direita){
        if(pivo == vetor[esquerda]){
          if(pivo > vetor[direita]){
            vetor[esquerda] = vetor[direita];
            vetor[direita] = pivo;
          }else{
            direita--;
          }
        }else{
          if(pivo < vetor[esquerda]){
            vetor[direita] = vetor[esquerda];
            vetor[esquerda] = pivo;
          }else{
            esquerda++;
          }
        }
      }
      return esquerda;
    }

    int mergeSort(int esquerda, int direita){
      int i,j,k,metade = (esquerda+direita)/2;

      if(esquerda == direita) return 0;

      mergeSort(esquerda, metade);
      mergeSort(metade+1,direita);

      i = esquerda;
      j = metade+1;
      k = 0;

      int *temp = new int[direita - esquerda+1];

      while(i < metade + 1 || j  < direita + 1) {
        if (i == metade + 1 ) { // i passou do final da primeira metade, pegar v[j]
            temp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == direita + 1) { // j passou do final da segunda metade, pegar v[i]
                temp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    temp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    temp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
      }
      for(i = esquerda; i <= direita; i++) {
        vetor[i] = temp[i - esquerda];
      }
      delete [] temp;

    }

    void mostrar(){
      int i;
      for (i = 0; i < MAX; i++) {
        cout << vetor[i] << " : ";
      }
    }
};
