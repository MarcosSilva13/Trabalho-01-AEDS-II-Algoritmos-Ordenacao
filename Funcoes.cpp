#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>

#define TAM_1K 1000
#define TAM_10K 10000
#define TAM_100K 100000

using namespace std;
using namespace chrono;

// Escopo das Funções

void MainMenu(); // Menu principal do programa para a escolha do metodo de ordenação

void InstancesMenu(); // Menu do programa para a escolha das instancias

void ChoiceMenu(int option); // Menu para exibir o algoritmo que foi escolhido para a ordenação

int ChooseInstance(); // Função para escolher qual instância abrir

void ReadFile(int List[], int size, string fileName); // Função que abre o arquivo da instância escolhida e preenche o vetor

void SaveData(string methodName, string fileName, double totalTime, long long int comparisons, unsigned long long numExchanges);
// Função para salvar os dados de execução em arquivo txt para depois poder fazer a análise dos dados

void ReadInstances(int choice, int option); // Função que define a instância escolhida e usando ela no algoritmo

void CalculateTime(int List[], int size, int option, string fileName);
/* Função que calcula o tempo de execução do algoritmo escolhido e exibe o vetor ordenado,
o número de comparações, o número de trocas e o tempo de execução.*/

void PrintVector(int List[], int size); // Função para imprimir o vetor

void BubbleSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Bubble Sort

void ShellSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Shell Sort

void SelectionSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Selection Sort

void InsertionSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Insertion Sort

void QuickSort(int List[], int left, int right, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Quick Sort

void MergeSort(int List[], int start, int end, long long int *comparisons, unsigned long long *numExchanges); // Função do algoritmo Merge Sort

void Intercala(int List[], int start, int mid, int end, long long int *comparisons, unsigned long long *numExchanges); // Função que junta os vetores do Merge Sort

// Funções

void MainMenu()
{
    system("color 03");
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
    system("color 03");
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

void ReadFile(int List[], int size, string fileName)
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
        arqInput >> List[i];
    }

    arqInput.close();
}

void SaveData(string methodName, string fileName, double totalTime, long long int comparisons, unsigned long long numExchanges)
{
    ofstream arqOutput; // variável para criar o arquivo

    arqOutput.open(methodName, ios::app); // recebe a variável com o nome do metodo e o modo de abertura
                                          // ios::app grava a partir do fim do arquivo
    if (arqOutput.fail())
    {
        cerr << "ERRO! Não foi possivel criar o arquivo.\n";
        arqOutput.clear();
    }

    arqOutput << "###" << methodName << " // " << fileName << "###" << endl; // salvando nome do metodo e da instancia
    arqOutput << "Trocas: " << numExchanges << endl;                         // salvando número de trocas
    arqOutput << "Comparações: " << comparisons << endl;                     // salvando número de comparações
    arqOutput << "Tempo total: " << totalTime << endl
              << endl; // salvando tempo total

    arqOutput.close();

    cout << "Dados salvos com sucesso!" << endl;
}

void ReadInstances(int choice, int option)
{
    system("cls");

    string fileName = ""; // variável para guardar o nome da instância

    int List1k[TAM_1K];     // criando vetor de tamanho 1000 (mil)
    int List10k[TAM_10K];   // criando vetor de tamanho 10000 (dez mil)
    int List100k[TAM_100K]; // criando vetor de tamanho 100000 (cem mil)

    if (choice == 1)
    {
        fileName = "ListaAleatoria-1000.txt"; // guardando o nome da instância que ser vai utilizada

        ReadFile(List1k, TAM_1K, fileName); // passando os dados para a função ReadFile

        CalculateTime(List1k, TAM_1K, option, fileName); // passando os dados para a função CalculateTime

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 2) // mesma ideia do primeiro IF, so altera o tamanho do vetor e o nome da instância
    {
        fileName = "ListaAleatoria-10000.txt";

        ReadFile(List10k, TAM_10K, fileName);

        CalculateTime(List10k, TAM_10K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 3)
    {
        fileName = "ListaAleatoria-100000.txt";

        ReadFile(List100k, TAM_100K, fileName);

        CalculateTime(List100k, TAM_100K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 4)
    {
        fileName = "ListaInversamenteOrdenada-1000.txt";

        ReadFile(List1k, TAM_1K, fileName);

        CalculateTime(List1k, TAM_1K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 5)
    {
        fileName = "ListaInversamenteOrdenada-10000.txt";

        ReadFile(List10k, TAM_10K, fileName);

        CalculateTime(List10k, TAM_10K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 6)
    {
        fileName = "ListaInversamenteOrdenada-100000.txt";

        ReadFile(List100k, TAM_100K, fileName);

        CalculateTime(List100k, TAM_100K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 7)
    {
        fileName = "ListaOrdenada-1000.txt";

        ReadFile(List1k, TAM_1K, fileName);

        CalculateTime(List1k, TAM_1K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 8)
    {
        fileName = "ListaOrdenada-10000.txt";

        ReadFile(List10k, TAM_10K, fileName);

        CalculateTime(List10k, TAM_10K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 9)
    {
        fileName = "ListaOrdenada-100000.txt";

        ReadFile(List100k, TAM_100K, fileName);

        CalculateTime(List100k, TAM_100K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 10)
    {
        fileName = "ListaQuaseOrdenada-1000.txt";

        ReadFile(List1k, TAM_1K, fileName);

        CalculateTime(List1k, TAM_1K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 11)
    {
        fileName = "ListaQuaseOrdenada-10000.txt";

        ReadFile(List10k, TAM_10K, fileName);

        CalculateTime(List10k, TAM_10K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (choice == 12)
    {
        fileName = "ListaQuaseOrdenada-100000.txt";

        ReadFile(List100k, TAM_100K, fileName);

        CalculateTime(List100k, TAM_100K, option, fileName);

        cout << endl
             << endl;
        system("pause");
        system("cls");
    }
}

void CalculateTime(int List[], int size, int option, string fileName)
{
    string methodName = "";              // variável que guarda o nome do metodo
    long long int comparisons = 0;       // variável para guardar o número de comparações
    unsigned long long numExchanges = 0; // variável para guardar o número de trocas

    if (option == 1)
    {
        methodName = "BubbleSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        BubbleSort(List, size, &comparisons, &numExchanges); // executa a ordenação do vetor com o BubbleSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }

    if (option == 2)
    {
        methodName = "ShellSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        ShellSort(List, size, &comparisons, &numExchanges); // executa a ordenação do vetor com o ShellSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }

    if (option == 3)
    {
        methodName = "SelectionSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        SelectionSort(List, size, &comparisons, &numExchanges); // executa a ordenação do vetor com o SelectionSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }

    if (option == 4)
    {
        methodName = "InsertionSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        InsertionSort(List, size, &comparisons, &numExchanges); // executa a ordenação do vetor com o InsertionSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }

    if (option == 5)
    {
        methodName = "QuickSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        QuickSort(List, 0, size - 1, &comparisons, &numExchanges); // executa a ordenação do vetor com o QuickSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }

    if (option == 6)
    {
        methodName = "MergeSort"; // guardando nome do metodo

        steady_clock::time_point initialTime = steady_clock::now(); // guarda o tempo inicial da execução

        MergeSort(List, 0, size - 1, &comparisons, &numExchanges); // executa a ordenação do vetor com o MergeSort

        steady_clock::time_point finalTime = steady_clock::now(); //  guarda o tempo final da execução

        duration<double> totalTime = duration_cast<duration<double>>(finalTime - initialTime); // calcula o tempo total da execução

        PrintVector(List, size); // imprimi o vetor ordenado

        cout << "\n\nTempo total: " << totalTime.count() << " segundos" << endl
             << endl; // exibe o tempo total da execução

        cout << "Número de trocas: " << numExchanges << endl
             << endl; // exibe o número de trocas total

        cout << "Número de comparações: " << comparisons << endl
             << endl; // exibe o número de comparações totais

        // SaveData(methodName, fileName, totalTime.count(), comparisons, numExchanges); // Salva os dados no arquivo txt
    }
}

void PrintVector(int List[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << List[i] << " ";
    }
}

// Funções dos Algoritmos

void BubbleSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges)
{
    int aux, chance;

    for (int i = 0; i < size - 1; i++)
    {
        chance = 0;
        for (int j = 1; j < size - i; j++)
        {
            if (List[j] < List[j - 1])
            {
                (*comparisons)++;

                aux = List[j];
                List[j] = List[j - 1];
                List[j - 1] = aux;
                chance = 1;

                (*numExchanges)++;
            }
            else
            {
                (*comparisons)++;
            }
        }
        if (chance == 0)
        {
            break;
        }
    }
}

void ShellSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges)
{
    int h, x, i, j;

    for (h = 1; h < size; h = 3 * h + 1)
        ;

    while (h > 1)
    {
        h = h / 3;
        (*comparisons)++;
        for (i = h; i < size; i++)
        {
            x = List[i];
            j = i;

            while (j >= h && List[j - h] > x)
            {
                (*comparisons)++;

                List[j] = List[j - h];
                j = j - h;

                (*numExchanges)++;
            }
            List[j] = x;
            (*comparisons)++;
        }
    }
}

void SelectionSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges)
{
    int min, aux, i, j;

    for (i = 0; i < size; i++)
    {
        min = i;

        for (j = i + 1; j < size; j++)
        {
            if (List[j] < List[min])
            {
                (*comparisons)++;
                min = j;
            }
            else
            {
                (*comparisons)++;
            }
        }
        aux = List[i];
        List[i] = List[min];
        List[min] = aux;

        (*numExchanges)++;
    }
}

void InsertionSort(int List[], int size, long long int *comparisons, unsigned long long *numExchanges)
{
    int key, j;

    for (int i = 1; i < size; i++)
    {
        key = List[i];
        j = i - 1;

        (*comparisons)++;

        while (j >= 0 && List[j] > key)
        {
            (*comparisons)++;

            List[j + 1] = List[j];
            j--;
        }
        List[j + 1] = key;

        (*numExchanges)++;
    }
}

void QuickSort(int List[], int left, int right, long long int *comparisons, unsigned long long *numExchanges)
{
    int temp, i = left, j = right;
    int pivot = List[(left + right) / 2];

    while (i <= j)
    {
        while (List[i] < pivot)
            i++;
        while (List[j] > pivot)
            j--;

        (*comparisons)++;
        if (i <= j)
        {
            temp = List[i];
            List[i] = List[j];
            List[j] = temp;
            i++;
            j--;

            (*numExchanges)++;
        }
    }

    (*comparisons)++;
    if (left < j)
        QuickSort(List, left, j, comparisons, numExchanges);
    if (i < right)
        QuickSort(List, i, right, comparisons, numExchanges);
}

void MergeSort(int List[], int start, int end, long long int *comparisons, unsigned long long int *numExchanges)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        MergeSort(List, start, mid, comparisons, numExchanges);
        MergeSort(List, mid + 1, end, comparisons, numExchanges);
        Intercala(List, start, mid, end, comparisons, numExchanges);
        (*comparisons)++;
    }
}

void Intercala(int List[], int start, int mid, int end, long long int *comparisons, unsigned long long *numExchanges)
{
    int *ListAux = (int *)malloc(sizeof(int) * (end + 1));
    int i, j;

    for (i = start; i <= mid; i++)
    {
        ListAux[i] = List[i];
    }

    for (j = mid + 1; j <= end; j++)
    {
        ListAux[end + mid + 1 - j] = List[j];
    }

    i = start;
    j = end;

    for (int k = start; k <= end; k++)
    {
        (*comparisons)++;
        if (ListAux[i] <= ListAux[j])
        {
            List[k] = ListAux[i];
            i++;
            (*numExchanges)++;
        }
        else
        {
            List[k] = ListAux[j];
            j--;
            (*numExchanges)++;
        }
    }
    free(ListAux);
}