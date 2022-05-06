#include <iostream>
#include <fstream>

#define TAM1000 1000
#define TAM10000 10000
#define TAM100000 100000

using namespace std;

void Menu(); // Menu do programa para a escolha do metodo de ordenação

void MenuInstancias(); // Menu do programa para a escolha das instancias

void BubbleSortMelhorado(int Lista[], int tamanho); // Função do algoritmo Bubble Sort melhorado

void LerInstancias();

void LerInstancias(int escolha){
    ifstream arqEntrada;

    if(escolha == 1){
        
        int vet[TAM1000];
        arqEntrada.open("ListaAleatoria-1000.txt");
        
        if(!arqEntrada.is_open()){
        cerr << "ERRO! Não foi possivel abrir o arquivo.\n";
        arqEntrada.clear();
        }

        for(int i = 0; i < TAM1000; i++){
            arqEntrada >> vet[i];
        }
    
        arqEntrada.close();

        for(int i = 0; i < TAM1000; i++){
            cout << vet[i] << " ";
        } 
    }

    if(escolha == 2){

        int vet[TAM10000];
        arqEntrada.open("ListaAleatoria-10000.txt");
        
        if(!arqEntrada.is_open()){
        cerr << "ERRO! Não foi possivel abrir o arquivo.\n";
        arqEntrada.clear();
        }

        for(int i = 0; i < TAM10000; i++){
            arqEntrada >> vet[i];
        }
    
        arqEntrada.close();

        for(int i = 0; i < TAM10000; i++){
            cout << vet[i] << " ";
        } 
    }
}


int EscolhaInstancia();

int EscolhaInstancia()
{
    int option = 0;
        system("cls");
        MenuInstancias();
        cout << "Escolha uma opção: ";
        cin >> option;

    return option;
}

void Menu()
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
void MenuInstancias()
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

void BubbleSortMelhorado(int Lista[], int tamanho)
{
    int aux, troca, numTrocas = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        troca = 0;
        for (int j = 1; j < tamanho - i; j++)
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