#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>

#define TAM_1000 1000
#define TAM_10000 10000
#define TAM_100000 100000

using namespace std;
using namespace chrono;

// Escopo das Funções

void MainMenu(); // Menu principal do programa para a escolha do metodo de ordenação

void InstancesMenu(); // Menu do programa para a escolha das instancias

void ChoiceMenu(int option); // Menu para exibir o algoritmo que foi escolhido para a ordenação

int ChooseInstance(); // Função para escolher qual instância abrir

void ReadFile(string fileName, int size); // Função que abre o arquivo da instância escolhida e preenche o vetor

void ReadInstances(int choice, int option); // Função que define a instância escolhida e usando ela no algoritmo

void CalculateTime(int List[], int size, int option);
/* Função que calcula o tempo de execução do algoritmo escolhido e exibe o vetor ordenado,
o número de comparações, o número de trocas e o tempo de execução.*/

void ImprimirVetor(int List[], int size); // Função para imprimir o vetor

void BubbleSort(int List[], int size); // Função do algoritmo Bubble Sort

void ShellSort(int List[], int size); // Função do algoritmo Shell Sort

// Funções

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

void ChoiceMenu(int option)
{
    system("cls");
    if (option == 1)
    {
        cout << "*******************************************\n";
        cout << "*              BUBBLE SORT                *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
    else if (option == 2)
    {
        cout << "*******************************************\n";
        cout << "*              SHELL SORT                 *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
    else if (option == 3)
    {
        cout << "*******************************************\n";
        cout << "*              SELECTION SORT             *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
    else if (option == 4)
    {
        cout << "*******************************************\n";
        cout << "*              INSERTION SORT             *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
    else if (option == 5)
    {
        cout << "*******************************************\n";
        cout << "*              QUICK SORT                 *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
    else
    {
        cout << "*******************************************\n";
        cout << "*              MERGE SORT                 *\n";
        cout << "*******************************************\n\n";
        Sleep(1500);
    }
}

int ChooseInstance()
{
    int option = 0;

    do
    {
        system("cls");

        InstancesMenu();

        cout << "Escolha uma opção: ";
        cin >> option;

        if (option < 1 || option > 13)
        {
            system("cls");
            cout << "Opção inválida!" << endl;
            Sleep(1500);
        }

    } while (option < 1 || option > 13);

    return option;
}

void ReadFile(int vet[], int size, string fileName)
{
    ifstream arqInput; // variável para ler o arquivo

    arqInput.open(fileName); // recebe a variavel com o nome da instância e abre ela

    if (!arqInput.is_open())
    {
        cerr << "ERRO! Não foi possivel abrir o arquivo.\n";
        arqInput.clear();
    }

    for (int i = 0; i < size; i++) // preenchendo o vetor com os dados lidos do arquivo
    {
        arqInput >> vet[i];
    }

    arqInput.close();
}

void ReadInstances(int choice, int option)
{
    system("cls");

    string fileName = ""; // variável para guardar o nome da instância

    int List1k[TAM_1000];     // criando vetor de tamanho 1000 (mil)
    int List10k[TAM_10000];   // criando vetor de tamanho 10000 (dez mil)
    int List100k[TAM_100000]; // criando vetor de tamanho 100000 (cem mil)

    if (choice == 1)
    {
        fileName = "ListaAleatoria-1000.txt"; // guardando o nome da instância que ser vai utilizada

        ReadFile(List1k, TAM_1000, fileName); // passando os dados para a função ReadFile

        CalculateTime(List1k, TAM_1000, option); // passando os dados para a função CalculateTime

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 2) // mesma ideia do primeiro IF, so altera o tamanho do vetor e o nome da instância
    {
        fileName = "ListaAleatoria-10000.txt";

        ReadFile(List10k, TAM_10000, fileName);

        CalculateTime(List10k, TAM_10000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 3)
    {
        fileName = "ListaAleatoria-100000.txt";

        ReadFile(List100k, TAM_100000, fileName);

        CalculateTime(List100k, TAM_100000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 4)
    {
        fileName = "ListaInversamenteOrdenada-1000.txt";

        ReadFile(List1k, TAM_1000, fileName);

        CalculateTime(List1k, TAM_1000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 5)
    {
        fileName = "ListaInversamenteOrdenada-10000.txt";

        ReadFile(List10k, TAM_10000, fileName);

        CalculateTime(List10k, TAM_10000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 6)
    {
        fileName = "ListaInversamenteOrdenada-100000.txt";

        ReadFile(List100k, TAM_100000, fileName);

        CalculateTime(List100k, TAM_100000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 7)
    {
        fileName = "ListaOrdenada-1000.txt";

        ReadFile(List1k, TAM_1000, fileName);

        CalculateTime(List1k, TAM_1000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 8)
    {
        fileName = "ListaOrdenada-10000.txt";

        ReadFile(List10k, TAM_10000, fileName);

        CalculateTime(List10k, TAM_10000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 9)
    {
        fileName = "ListaOrdenada-100000.txt";

        ReadFile(List100k, TAM_100000, fileName);

        CalculateTime(List100k, TAM_100000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 10)
    {
        fileName = "ListaQuaseOrdenada-1000.txt";

        ReadFile(List1k, TAM_1000, fileName);

        CalculateTime(List1k, TAM_1000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 11)
    {
        fileName = "ListaQuaseOrdenada-10000.txt";

        ReadFile(List10k, TAM_10000, fileName);

        CalculateTime(List10k, TAM_10000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 12)
    {
        fileName = "ListaQuaseOrdenada-100000.txt";

        ReadFile(List100k, TAM_100000, fileName);

        CalculateTime(List100k, TAM_100000, option);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }
}

void CalculateTime(int List[], int size, int option)
{
    // int comparisons = 0; precisar ser ponteiro e ser paramentro nos metodos de ordenar

    if (option == 1)
    {
        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        BubbleSort(List, size); // executa a ordenação do vetor com o BubbleSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        ImprimirVetor(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução
    }

    if(option == 2)
    {
        steady_clock::time_point initialTime = steady_clock::now();

        ShellSort(List, size); // executa a ordenação do vetor com o ShellSort

        steady_clock::time_point finalTime = steady_clock::now();

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime);

        ImprimirVetor(List, size);

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; 
        
    }
}

void ImprimirVetor(int List[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << List[i] << " ";
    }
}

// Funções dos Algoritmos

void BubbleSort(int List[], int size)
{
    int aux, chance, numExchanges = 0;
    for (int i = 0; i < size - 1; i++)
    {
        chance = 0;
        for (int j = 1; j < size - i; j++)
        {
            if (List[j] < List[j - 1])
            {
                aux = List[j];
                List[j] = List[j - 1];
                List[j - 1] = aux;
                chance = 1;
                // numExchanges++;
            }
        }
        if (chance == 0)
        {
            break;
        }
    }
    // return numExchanges;
}

void ShellSort(int List[], int size)
{
    int h, x, i, j;

    for (h = 1; h < size; h = 3 * h + 1)
        ;

    while (h > 1)
    {
        h = h / 3;

        for (i = h; i < size; i++)
        {
            x = List[i];
            j = i;

            while (j >= h && List[j - h] > x)
            {
                List[j] = List[j - h];
                j = j - h;
            }
            List[j] = x;
        }
    }
}