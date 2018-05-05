#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED

#include <iostream>
using namespace std;

class RSA
{
private:
    int clavePrivada1;
public:
    int clavePublica1;
    int nyYa;
    void generadorClaves();
    RSA();
    void mostrarDatos();
    int cifrado(int, int, char);
    char descifrado(int);
};

#endif // RSA_H_INCLUDED
