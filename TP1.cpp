#include <iostream>
#include <windows.h>
#include "Funcoes.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int option = 0; // variável para escolha do algoritmo 
    int choice = 0; // variável para escolha da instância
    do
    {
        MainMenu();
        cout << "Escolha uma opção: ";
        cin >> option;

        system("cls");

        switch (option)
        {
        case 1:
        choice = ChooseInstance();
        ChoiceMenu(option);
        ReadInstances(choice, option);
        //talvez criar uma função ler instancias para cada algoritmo 


            break;
        case 2:
        ChoiceMenu(option);
            break;
        case 3:
        ChoiceMenu(option);
            break;
        case 4:
        ChoiceMenu(option);
            break;
        case 5:
        ChoiceMenu(option);
            break;
        case 6:
        ChoiceMenu(option);
            break;
        default:
            break;
        }
        
    } while (option != 7);
    
    return 0;
}