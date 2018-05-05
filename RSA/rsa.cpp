#include <iostream>
#include "rsa.h"
#include "operaciones.h"
#include <time.h>

#define TOPE 700

void RSA::generadorClaves()
{
    int n, fi, d;

    srand(time(NULL));
    int p = 2 + rand()%TOPE;
    int q = 2 + rand()%TOPE;
    while(primo(p) != 1)
    {
        p = 2 + rand()%TOPE;
    }
    while(primo(q) != 1)
    {
        q = 2 + rand()%TOPE;
    }
    //cout << "p="<< p << endl;
    //cout << "q="<<q << endl;

    n = p*q;
    //cout <<"\n n = "<< n << endl;
    fi = (p-1)*(q-1);
    int e = 2 + rand()%fi;
    while(euclides(fi,e) != 1)
    {
        e = 2 + rand()%fi;
    }
    //cout << "euclides " << euclides(fi,e) << endl;
    //cout << "fi="<<fi << endl;
    //cout << "e="<<e << endl;
    d = inversa(e,fi);

    //cout << "d="<<d << endl;
    clavePublica1 = e;
    clavePrivada1 = d;
    nyYa = n;
    //cout<<"\n e*d = "<<modulo(clavePublica1*clavePrivada1,fi)<<"\n";
}

int RSA::cifrado(int e, int n, char M)
{
    int t=(int)M;
    //cout<<"\n\n m = "<<M<<" - "<<t<<"\n";
    int cif = expModular(t,e,nyYa);
    return cif;
}

char RSA::descifrado(int M)
{
    int t = expModular(M,clavePrivada1,nyYa);
    //cout<<"\n\n t = "<<t<<"\n";
    char deci = (char)t;
    return deci;
}

RSA::RSA()
{
    generadorClaves();
}



