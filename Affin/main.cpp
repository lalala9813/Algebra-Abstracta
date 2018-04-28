#include <iostream>
#include "affin.h"

using namespace std;

int main()
{
    //Cifrado
    cout << "\t\t\t\tCifrado Affin\n";
    Affin a;
    string msm = "";
    cout << "Inserte su mensaje amo -> ";
    getline(cin,msm);
    string cif = a.cifrado(msm);
    a.getDatos();
    cout << "\n" << "Su mensaje ha sido cifrado -> " << cif << "\n\n";

    //Descifrado
    int x,y;
    cout << "Dame a -> ";
    cin >> x;

    cout << "Dame b -> ";
    cin >> y;
    Affin b(x,y);
    string mensaje = b.descifrado(cif);
    cout << "\n" << "Su mensaje ha sido descifrado -> " << mensaje << "\n\n";

    return 0;
}
