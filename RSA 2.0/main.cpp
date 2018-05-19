#include <iostream>
#include "rsa.h"
#include "operaciones.h"

using namespace std;

int main()
{
    cout << "\t\t\t\t   RSA\n";
    RSA a;
    string mensaje;
    cout << "Dame tu mensaje -> ";
    cin >> mensaje;

    cout << "\nCifrado" << endl;
    int x = a.cifrado(a.clavePublica1,a.nyYa,mensaje);

    cout << "\n\nDescifrado" << a.descifrado(x);
    cout << "\nDescifrando -> " << a.descifrado2();
    return 0;
}
