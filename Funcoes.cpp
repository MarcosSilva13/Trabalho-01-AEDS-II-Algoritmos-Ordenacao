#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>

#define TAM_1000 1000
#define TAM_10000 10000
#define TAM_100000 100000

using namespace std;
using namespace chrono;


//Escopo das Funções

void MainMenu(); // Menu principal do programa para a escolha do metodo de ordenação

void InstancesMenu(); // Menu do programa para a escolha das instancias

void ChoiceMenu(int option); // Menu para exibir o algoritmo escolhido para a ordenação

int ChooseInstance(); // Função para escolher qual instância abrir

void ReadFile(string filename, int size); // Função que abre o arquivo da instância escolhida e preenche o vetor

void ReadInstances(int choice, int option); // Função que define a instância escolhida 

void CalculateTime(int Lista[], int size, int option); 
/* Função que calcula o tempo de execução do algoritmo escolhido e exibe o vetor ordenado,
o número de comparações, o número de trocas e o tempo de execução.*/

void ImprimiVetor(int Lista[], int size); // Função para imprimir o vetor

void BubbleSortMelhorado(int Lista[], int size); // Função do algoritmo Bubble Sort melhorado

//Funções

void MainMenu()
{
    system("color 0E");
    cout << "  \n        ������������������������������������������";
    cout << "  \n        �                                        �";
    cout << "  \n        �          ALGORITMOS ORDENAÇÃO          �";
    cout << "  \n        �                                        �";
    cout << "  \n        ������������������������������������������";
    cout << "  \n        �                                        �";
    cout << "  \n        � 1 - BUBBLE SORT                        �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 2 - SHELL SORT                         �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 3 - SELECTION SORT                     �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 4 - INSERTION SORT                     �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 5 - QUICK SORT                         �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 6 - MERGE SORT                         �";
    cout << "  \n        �                                        �";
    cout << "  \n        � 7 - SAIR                               �";
    cout << "  \n        �                                        �";
    cout << "  \n        ������������������������������������������\n\n";
}

void InstancesMenu()
{
    system("color 0E");
    cout << "  \n        ����������������������������������������������";
    cout << "  \n        �                                            �";
    cout << "  \n        �                 INSTÂNCIAS                 �";
    cout << "  \n        �                                            �";
    cout << "  \n        ����������������������������������������������";
    cout << "  \n        �                                            �";
    cout << "  \n        � 1  - LISTA ALEATORIA - 1000                �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 2  - LISTA ALEATORIA - 10000               �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 3  - LISTA ALEATORIA - 100000              �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 4  - LISTA INVERSAMENTE ORDENADA - 1000    �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 5  - LISTA INVERSAMENTE ORDENADA - 10000   �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 6  - LISTA INVERSAMENTE ORDENADA - 100000  �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 7  - LISTA ORDENADA - 1000                 �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 8  - LISTA ORDENADA - 10000                �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 9  - LISTA ORDENADA - 100000               �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 10 - LISTA QUASE ORDENADA - 1000           �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 11 - LISTA QUASE ORDENADA - 10000          �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 12 - LISTA QUASE ORDENADA - 100000         �";
    cout << "  \n        �                                            �";
    cout << "  \n        � 13 - SAIR                                  �";
    cout << "  \n        �                                            �";
    cout << "  \n        ����������������������������������������������\n\n";
}

void ChoiceMenu(int option){
    system("cls");
    if(option == 1){
        cout << "*******************************************\n";
        cout << "*              BUBBLE SORT                *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    } else if(option == 2){
        cout << "*******************************************\n";
        cout << "*              SHELL SORT                 *\n";
        cout << "*******************************************\n\n";
    } else if(option == 3){
        cout << "*******************************************\n";
        cout << "*              SELECTION SORT             *\n";
        cout << "*******************************************\n\n";
    }else if(option == 4){
        cout << "*******************************************\n";
        cout << "*              INSERTION SORT             *\n";
        cout << "*******************************************\n\n";
    } else if(option == 5){
        cout << "*******************************************\n";
        cout << "*              QUICK SORT                 *\n";
        cout << "*******************************************\n\n";
    } else {
        cout << "*******************************************\n";
        cout << "*              MERGE SORT                 *\n";
        cout << "*******************************************\n\n";
    }
}

int ChooseInstance()
{
    int option = 0;
        system("cls");
        InstancesMenu();
        cout << "Escolha uma opção: ";
        cin >> option;

    return option;
}

void ReadFile(int vet[], int size, string filename){
    ifstream arqInput;

    arqInput.open(filename);
        
        if(!arqInput.is_open()){
        cerr << "ERRO! Não foi possivel abrir o arquivo.\n";
        arqInput.clear();
        }

        for(int i = 0; i < size; i++){
            arqInput >> vet[i];
        }
    
        arqInput.close();

        //ImprimiVetor(vet, size);
}

void ReadInstances(int choice, int option){
    system("cls");
    
    string filename = "";

    if(choice == 1){
        int vet[TAM_1000];

        filename = "ListaAleatoria-1000.txt";

        ReadFile(vet, TAM_1000, filename);

        CalculateTime(vet, TAM_1000, option);
        
        cout << endl << endl;
        system("pause");
    }

    if(choice == 2){
        int vet[TAM_10000];

        filename = "ListaAleatoria-10000.txt";

        ReadFile(vet, TAM_10000, filename);

        CalculateTime(vet, TAM_10000, option);
        
    }
}


void CalculateTime(int Lista[], int size, int option){
    //int comparisons = 0; precisar ser ponteiro talvez

    if(option == 1){
        steady_clock::time_point initialTime = steady_clock::now();

        BubbleSortMelhorado(Lista, size);

        steady_clock::time_point finalTime = steady_clock::now();

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime);

        ImprimiVetor(Lista, size);

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl << endl;
    }  
}

void ImprimiVetor(int Lista[], int size){
    for(int i = 0; i < size; i++){
        cout << Lista[i] << " ";
    }
}

// Funções dos Algoritmos 

void BubbleSortMelhorado(int Lista[], int size)
{
    int aux, troca, numTrocas = 0;
    for (int i = 0; i < size - 1; i++)
    {
        troca = 0;
        for (int j = 1; j < size - i; j++)
        {
            if (Lista[j] < Lista[j - 1])
            {
                aux = Lista[j];
                Lista[j] = Lista[j - 1];
                Lista[j - 1] = aux;
                troca = 1;
                // numTrocas++;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
    // return numTrocas;
}

