// Mandelbrotmenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

int main()
{
    long double z = 0; //Ergebnis, der Funktion
    long double c = 0.0; //Ist die Eingabe
    long double a;      //Eingabe der realen Zahl
    long double b;      //Eingabe für i (b x i)
    int j = 0;          //Anzahl der Durchläufe (Bis max. der Länge von ergebnise[])
    bool on_set = false;//Für die Beesndung der while Schleife
    const int zspeicher_groesse = 1000; // Groesse des Arrays
    long double ergebnise[zspeicher_groesse]; // Zwischenspeicher der Ergebnise, wichtig für die Überprüfung, ob i gleicher Punkt erreicht wurde
    char ende; //Am ende, eine beliebige Taste, um das Programm zu beenden.


    std::cout << "Dies ist ei Programm, um zu bestimmen, ob eine Komlexe Zahl Teilder Nadelbrotmenge ist.\n";
    std::cout << "Bitte gib deinen Wert für a ein.";
    std::cin >> a;
    std::cout << "Bitte gib deinen Wert für b ein.";
    std::cin >> b;

    while (z < 2.0 && !on_set) {
        ergebnise[j] = z;
        
        if (j < 1) {
            c = a + b * 1.0;
        }
        else {                  //Da i die Wurzel von -1 ist, musste das anders verarbeitet werden
            c = a + b * -1.0;
        }
           
        if (j == zspeicher_groesse) { //Neuanfang der Schleife, um den Array neu zu beschreiben
            j = 1;
        }

        z = pow(z, 2) + c; //Die eigentliche Funktion

        for (int i = 0; i < zspeicher_groesse; i++) {
            if (z == ergebnise[i]) { //Überprüfung, ob das neue Ergebnis schonmal erreicht wurde
                on_set = true;
            }
        }
        j++;
        std::cout << z << '\n';
    }

    if (on_set) {
        std::cout << "On set!";
    }
    else {
        std::cout << "Not on set!";
    }

    //Ende, Auf Eingabe warten, damit das Ergebnis sichtbar bleibt.
    std::cin >> ende;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
