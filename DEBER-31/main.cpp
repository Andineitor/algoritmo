#include <iostream>
#include "desarrollo.h"
using namespace std;
int main()
{
    int op;
    while (op != 4)
    {
        cout << " \t \tALGORITMOS " << endl
             << endl;
        cout << "\t \t Grupo 3\n"
             << endl;
        cout << " \t SELECCIONE UNA OPCION DEL MENU" << endl;
        cout << endl
             << "1.- EJERCICIO 1" << endl;
        cout << "2.- EJERCICIO 2" << endl;
        cout << "3.- EJERCICIO 3" << endl;
        cout << "4.- SALIR\n";
        cout << "OPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            ejercicio1();
        }
        break;
        case 2:
        {
            ejercicio2();
        }
        break;
        case 3:
        {
            ejercicio3();
        }
        break;
        case 4:
        {
            cout << "\t*GRACIAS*";
        }
        break;
        default:
        {
            cout << "Opcion incorrecta.Intentelo de nuevo." << endl;
        }
        }
    }
}
