//
// Kalil Saldanha Kaliffe
//

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Sorts.h"
using namespace std;

int main(){

    cout<< "\nEscolha um dos algoritmos de ordenação abaixo digitando seu numero:\n" <<"1. InsertionSort\n 2.QuickSort\n 3.Radixsort\n:";
    int escolha;

    cin >> escolha;
    if(escolha == 1){
        cout<< "\nEscolha um tamanho para o vetor aleatorio:\n";
        int tamanho;

        cin >>tamanho;

        int n = tamanho;
        int arr[n];


        clock_t start = clock();
        cout<< "\nArray Inicial: \n";
        for(int i = 0; i<n; i++){
            arr[i] = rand()%100;
        }

        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }


        InsertionSort(arr, n);
        cout<< "\nArray InsertionSort:\n";


        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }
        clock_t stop = clock();
        double end = (double) (stop - start) / CLOCKS_PER_SEC;
        printf("\nTempo de execucao: %.7f\n", end);
        cout<< "N elementos: "<< n;

    }
    else if(escolha == 2){
        cout<< "\nEscolha um tamanho para o vetor aleatorio:\n";
        int tamanho;

        cin >>tamanho;

        int n = tamanho;
        int arr[n];

        clock_t start = clock();
        cout<< "\nArray Inicial: \n";
        for(int i = 0; i<n; i++){
            arr[i] = rand()%100;
        }

        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }

        QuickSort(arr, n);
        cout<< "\nArray QuickSort:\n";


        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }
        clock_t stop = clock();
        double end = (double) (stop - start) / CLOCKS_PER_SEC;
        printf("\nTempo de execucao: %.7f\n", end);
        cout<< "N elementos: "<< n;

    }
    else if(escolha == 3){
        cout<< "\nEscolha um tamanho para o vetor aleatorio:\n";
        int tamanho;

        cin >>tamanho;

        int n = tamanho;
        int arr[n];

        clock_t start = clock();
        cout<< "\nArray Inicial: \n";
        for(int i = 0; i<n; i++){
            arr[i] = rand()%100;
        }

        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }

        InsertionSort(arr, n);
        cout<< "\nArray RadixSort:";


        for(int i = 0; i< n; i++){
            cout << arr[i]<<" ";
        }
        clock_t stop = clock();
        double end = (double) (stop - start) / CLOCKS_PER_SEC;
        printf("\nTempo de execucao: %.7f\n", end);
        cout<< "N elementos: "<< n;

    }
    else{
        cout<<"Escolha invalida!";
        return 0;
    }
}