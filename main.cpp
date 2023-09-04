#include <iostream>

using namespace std;

void merge(int* vetor, int inicio, int meio, int fim){
    int tamEsquerda = meio - inicio +1;
    int tamDireita = fim - meio;
    int* esquerda = new int[tamEsquerda];
    int* direita = new int[tamDireita];

    for(int i = 0; i < tamEsquerda; i++)
        esquerda[i] = vetor[inicio +i];
    for(int j = 0; j < tamDireita; j++)
        direita[j] = vetor[meio +1 +j];

    int i = 0, j = 0, k = inicio;

    while(i < tamEsquerda && j < tamDireita){
        if(esquerda[i] <= direita[j]){
            vetor[k] = esquerda[i];
            i++;
        }else{
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while(i < tamEsquerda){
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < tamDireita){
        vetor[k] = direita[j];
        j++;
        k++;
    }

}

void sort(int* vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = inicio + (fim - inicio) / 2;

        sort(vetor, inicio, meio);
        sort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main(){

    int tam = 9;
    int* vetor = new int[tam] {3,6,5,1,9,7,2,8,4};

    sort(vetor, 0, tam -1);

    for(int i = 0; i < tam; i++){
        cout << vetor[i] << " - ";
    }
    cout << "\n\n";


    return 0;
}