// DesviacionYVarianza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

#include <string>

using namespace std;
double Media(double arr[], int n, double sum) { //calcular media
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double media = sum / n;
    return media;
}

double Varianza(double arr[], double media, int n) { //calcular varianza
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

bool ValidarDecimales(string str) { //validar datos insertados
    string numIzq, numDer; //numeros antes y despues del punto
    int punto = 0; //se usa un numero para saber si hay mas de un punto
    for (int i = 0; i < str.length(); i++) { //dividir el str en dos partes, antes y despues del punto
        if (str[i] == '.') {
            punto++;
            continue;
        }
        if (punto > 1) return false;

        if (punto == 0) {
            numIzq += str[i];
        }
        else{
            numDer += str[i];
        }
    }

    if (ValidarNumero(numIzq) && ValidarNumero(numDer)) { //si ambos lados del decimal son numeros, entonces true
        return true;
    }
    return false;
}

int main()
{
    string opcion = "0"; // opcion de volver a intentar
    do {
        system("CLS");

        string n = "", dato; //datos a validar
        double media = 0,varianza, desviacion, sum = 0, datos[30]; //datos para los calculos

        cout << "Cuantos datos desea insertar?\n>>";
        cin >> n;

        if (!ValidarNumero(n)) { //validar que n es un entero
            cout << "No es un numero, intente de nuevo" << endl;
            system("PAUSE");
            continue;
        }

        if (n == "1") { //verificar que el numero de valoress no es igual a 1
            cout << "Inserte mas numeros para realizar los calculos" << endl;
            system("PAUSE");
            continue;
        }
        
        for (int i = 0; i < stoi(n); i++) { //pedirle al usuario los datos
            cout << "Inserte el dato " << i + 1 << ": ";
            cin >> dato;
            if (!ValidarDecimales(dato)) { //validar que es un numero entero o decimal
                cout << "No es un numero valido, intente de nuevo" << endl;
                system("PAUSE");
                break;
            }

            datos[i] = stod(dato); //convertir de string a double
        }
        if (!ValidarDecimales(dato)) continue;

        //calcular valores de media, varianza y desviacion
        media = Media(datos, stoi(n), sum);
        varianza = Varianza(datos,media,stoi(n));
        desviacion = sqrt(varianza);

        cout << "Media: " << media << endl;
        cout << "La varianza es igual a " << varianza << endl;
        cout << "La desviacion es igual a " << desviacion << endl;

        //menu de volver a intenter
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