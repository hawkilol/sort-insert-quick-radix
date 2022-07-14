//
// Kalil Saldanha Kaliffe
//
#include <iostream>
using namespace std;
#include "Sorts.h"
void InsertionSort(int valoresArr[], int n){
    int j;
    int key;
    int comp = 0;
    int trocas = 0;
    
    //Move o key até sua devida posição fazendo trocas com os valores que são maiores que ele
    for(int i = 1; i < n; i++){
        key = valoresArr[i];
        j = i - 1;
        comp++;
        trocas++;
        //Os itens são movidos como cartas de baralho
        //Ajustando sua posição para a proxima posição da lista abrindo vaga para a key
        while( j >= 0 && valoresArr[j] > key ){
            valoresArr[j + 1] = valoresArr[j];
            j = j - 1;
        }
        trocas++;
        valoresArr[j + 1] = key;
    }
    cout <<"\n/InsertionSort/\n";
    cout << "Trocas: "<<trocas;
    cout <<"\nComparacoes: "<< comp;
}
//Esse metodo sempre para selecionar o pivot que vai servir como uma raiz para uma arvore binaria
int partitionRight(int valoresArr[], int left, int right){
    int pivot = valoresArr[right];
    int i = left - 1;

    //Os valores maiores que o pivot vão para a direita do pivot
    //Os valores menores que o pivot vão para sua esquerda

    for(int k = left; k <= right - 1; k++){
        if(valoresArr[k] < pivot){
            i++;
            //Troca a posição dos valores para organizar eles a partir da esquerda 
            int* var1 = &valoresArr[i];
            int* var2 = &valoresArr[k];

            int aux = *var1;
            *var1 = *var2;
            *var2 = aux;

        }
    }
    int* var1 = &valoresArr[i + 1];
    int* var2 = &valoresArr[right];

    int aux = *var1;
    *var1 = *var2;
    *var2 = aux;

    //Metodo vai retornar os indexes de cada nó 

    return (i + 1);
}
//QuickSort que deve ser chamado na main, já que só recebe o arr e o tamanho
void QuickSort(int valoresArr[], int n){
    int right = n - 1;
    int left = 0;
    Quicksort(valoresArr, left, right);
}
//Quicksort principal, realiza recursão similar ao InOrder da arvore binaria
void Quicksort(int valoresArr[], int left, int right){
    //Se essa condição não for cumprida, é porque a arvore já foi inteiramente viajada 
    if(left < right){
        int partI = partitionRight(valoresArr, left, right);
        Quicksort(valoresArr, left, partI -1);
        Quicksort(valoresArr, partI + 1, right);
    }
}
//O CountingSort vai auxiliar o RadixSort,
void CountingSort(int valoresArr[], int n, int exp){
    int outArr[n];
    int count[10] = {0};
    //O metodo vai receber os digitos dos numeros em foram de exponecial

    //Assim usando o range de 0..9 vai ser feita a contagem dos digitos e essa contagem vai ficar salva no cout[]

    //Quando a contagem é somada ao seu vizinho é possivel saber a posição que cada valor vai ficar na ordenação
    for(int i= 0; i < n; i++){
        count[(valoresArr[i] / exp) % 10]++;
    }
    for(int i= 1; i < 10; i++){
        count[i] += count[i -1];
    }
    for(int i= n - 1; i >= 0; i--){
        outArr[count[(valoresArr[i] / exp ) % 10] - 1] = valoresArr[i];
        count[(valoresArr[i] / exp) % 10]--;
    }
    for(int i= 0; i < n; i++){
        valoresArr[i] = outArr[i];
    }
}

//O RadixSort alimenta o counting sort com os digitos em forma de exp, com base no valor max do arr
void Radixsort(int valoresArr[], int n){
    int max = valoresArr[0];
    for(int i = 0; i< n; i++){
        if(valoresArr[i]> max){
            max = valoresArr[i];
        }
    }
    for(int exp = 1; max / exp > 0; exp *= 10){
        CountingSort(valoresArr, n, exp);
    }
}

