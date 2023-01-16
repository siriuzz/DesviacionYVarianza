// DesviacionYVarianza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

#include <string>

using namespace std;
double Media(double arr[], int n, double sum) {
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double media = sum / n;
    return media;
}

double Varianza(double arr[], double media, int n) {
    double numerador = 0.0, varianza = 0;
    for (int i = 0; i < n; i++) {
        numerador += (arr[i] - media)*(arr[i] - media);
    }
    varianza = numerador / (n - 1);
    return varianza;
}

// Funcion para validar entrada de un numero
bool ValidarNumero(string str)
{
    int i = 0;
    while (str[i] != '\0') //'\0' es el character que marca el final del string
    {
        if (isdigit(str[i]) == false)
        {
            return false;
        }
        i++;
    }
    return true; //devuelve un str igual si no se encontraron letras
}

bool ValidarDecimales(string str) {
    string numIzq, numDer;
    int punto = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            punto++;
            continue;
        }
        if (punto == 0) {
            numIzq += str[i];
        }
        else if(punto == 1){
            numDer += str[i];
        }
        else {
            return false;
        }
        
    }
    if (ValidarNumero(numIzq) && ValidarNumero(numDer)) {
        return true;
    }
    return false;
}

int main()
{
    string opcion = "0";
    do {
        system("CLS");
        string n = "", dato;
        double datos[30];
        double media = 0,varianza, desviacion, sum = 0;
        cout << "Cuantos datos desea insertar?\n>>";
        cin >> n;

        if (!ValidarNumero(n)) {
            cout << "No es un numero, intente de nuevo" << endl;
            system("PAUSE");
            continue;
        }

        if (n == "1") {
            cout << "Inserte mas numeros para realizar los calculos" << endl;
            system("PAUSE");
            continue;
        }
        
        for (int i = 0; i < stoi(n); i++) {
            cout << "Inserte el dato " << i + 1 << ": ";
            cin >> dato;
            if (!ValidarDecimales(dato)) {
                cout << "No es un numero valido, intente de nuevo" << endl;
                system("PAUSE");
                break;
            }

            datos[i] = stod(dato);
        }
        if (!ValidarDecimales(dato)) continue;


        media = Media(datos, stoi(n), sum);
        varianza = Varianza(datos,media,stoi(n));
        desviacion = sqrt(varianza);

        cout << "Media: " << media << endl;
        cout << "La varianza es igual a " << varianza << endl;
        cout << "La desviacion es igual a " << desviacion << endl;

        do{
            cout << "Desea volverlo a intentar?\n(1)Si\n(2)No\n>>";
            cin >> opcion;
            if (!ValidarNumero(opcion)) {
                cout << "No es un numero, intente de nuevo" << endl;
                system("PAUSE");
            }

            if (opcion != "1" && opcion != "2") {
                cout << "Opcion invalida" << endl;
                system("PAUSE");
            }

            if (opcion == "2") {
                exit(1);
            }
            break;
        } while (opcion != "2");

        continue;

    } while (true);
}