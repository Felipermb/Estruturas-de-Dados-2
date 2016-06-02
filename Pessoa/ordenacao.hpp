#include <iostream>
#define MAX 10
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

    void insertSort(){
      int i,j;
      int count = 0;
      for(i=0; i<MAX; i++){
        for(j=i+1; j<MAX; j++){
          if(vetor[i] > vetor[j]){
            int jt = j;
            int c = 0;
            for(c=0; c<=count; c++){
              if(vetor[jt] < vetor[c]){
                int aux = vetor[jt];
                
              }
            }
          }else{
            count++;
          }
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
