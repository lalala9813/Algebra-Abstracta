#include <iostream>
#include "rsa.h"
#include "operaciones.h"

using namespace std;

int main()
{
    RSA a;
    char mensaje;
    cout << "Dame tu mensaje -> ";
    cin >> mensaje;
    int x = a.cifrado(a.clavePublica1,a.nyYa,mensaje);
    cout << "Cifrado -> " << x << endl;
    cout << a.descifrado(x);
    return 0;
}
