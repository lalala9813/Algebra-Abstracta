#include "affin.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include "euclides.h"

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";

void Affin::getDatos()
{
    cout << "a -> " << a << endl;
    cout << "b -> " << b << endl;
}

Affin::Affin()
{
    srand(time(NULL));
    a = rand()%alfabeto.size();
    while(euclides(a,alfabeto.size()) != 1)
    {
        a = rand()%alfabeto.size();
    }
    b = rand()%alfabeto.size();
}

Affin::Affin(int a, int b)
{
    this->a = a;
    this->b = b;
}

string Affin::cifrado(string mensaje)
{
    string cifrado = "";
    int index;
    for(int i = 0; i < mensaje.size(); i++)
    {
        index = alfabeto.find(mensaje[i]);
        index = (a*index + b) % alfabeto.size();
        cifrado += alfabeto[index];
    }
    return cifrado;
}

string Affin::descifrado(string cifrado)
{
    string descifrado = "";
    int inv = euclidePLUS(a,alfabeto.size());
    int index;
    for(int i = 0; i < cifrado.size(); i++)
    {
        index = alfabeto.find(cifrado[i]);
        index = index - b; //Posiblemente negativo
        if(index < 0)
        {
            index += alfabeto.size();
        }
        index = (index * inv) % alfabeto.size();
        descifrado += alfabeto[index];
    }
    return descifrado;
}
