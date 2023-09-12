#include <iostream>
#include <fstream>
#include <string>

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

void readFromFile(string filename, int* numbers, int size){
    ifstream file(filename);
    string line;
    int i = 0;
    while(getline(file, line) && i < size){
        size_t pos = line.find(" ");
        string firstPart = line.substr(0, pos);
        numbers[i] = stoi(firstPart);
        i++;
    }
    file.close();
}



int main(){

    int tam = 20000;
    int* vetor = new int[tam];
    
    string caminhoPasta = "teste.txt";
	ifstream arquivoLido;
	arquivoLido.open(caminhoPasta);
	readFromFile("teste.txt", vetor, tam);
	arquivoLido.close();

    sort(vetor, 0, tam -1);

    for(int i = 0; i < tam; i++){
        cout << vetor[i] << " - ";
    }
    cout << "\n\n";


    return 0;
}
