#include <iostream>
#include <windows.h>
#include "Funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int op = 0, escolha = 0;
    do
    {
        Menu();
        cout << "Escolha uma opção: ";
        cin >> op;

        system("cls");

        switch (op)
        {
        case 1:
        escolha = EscolhaInstancia();
        LerInstancias(escolha);
        //talvez criar uma função ler instancias para cada algoritmo 


            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
        }
        
    } while (op != 7);
    
    return 0;
}