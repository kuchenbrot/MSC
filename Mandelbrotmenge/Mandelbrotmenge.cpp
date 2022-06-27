// Mandelbrotmenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

bool is_onSet(long double a, long double b) {
    int j = 0;          //Counter variable for the amounts of calculations
    const int max_calculations = 50000; //Holds the maximal amount of calculations that are allowed
    std::vector<long double> ergebnise; //Stores the values of z to compare them with the newest
    long double z = 0; //Always the current result
    long double c = 0.0; //The comlex Number (a+b*i)

    while (z < 2.0 && j < max_calculations) {
        ergebnise.push_back(z);

        if (j < 1) {
            c = a + b * 1.0;
        }
        else {                  //Since i is the squaroot of -1 but you can't calculate it unless you square it you have to process this like this
            c = a + b * -1.0;
        }

        z = pow(z, 2) + c; //The corefunction of the Mandelbrotset

        for (int i = 0; i < ergebnise.size(); i++) {
            if (z == ergebnise.at(i)) { //Comparing the new result with the old ones
                return true;
            }
        }
        j++;
        //std::cout << z << std::endl;  //For debuging
    }
    if (j == max_calculations) { //Since it could be that the while-loop ended because it took to long to calculate this if-statement returns a true if it took to long
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    double start = -2;  //Defines the startpoint from where it should start calculating 
    double steps = 0.1; //Holds the value by which the numbers to calculate will increase
    const int ARRAY_SIZE = 4 / steps;  //Defining the ara size so it can be used in for() loops
    long double * input_a = new long double[ARRAY_SIZE];      //Array for the real numbers (the a in a+b*i)
    long double * input_b = new long double[ARRAY_SIZE];      //Array for i (the b in a+b*i)
    bool * set = new bool[ARRAY_SIZE]; //Stores the Value of the Function the size is 18 because I will go from -1.8 to 1.8 in 0.2 Steps
    char end;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        input_a[i] = start;
        input_b[i] = start;
        start += steps;
    }

    std::cout << "[";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            set[i] = is_onSet(input_a[i], input_b[j]);
            std::cout << "[" << set[i] << ", " << input_a[i] << ", " << input_b[j] << "]" << ", ";
        }
    }
    std::cout << "]";

    //The end, it waits for input so the console window stays open
    std::cin >> end;
    return 0;
}

