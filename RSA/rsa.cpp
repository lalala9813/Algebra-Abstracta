#include <iostream>
#include "rsa.h"
#include "operaciones.h"
#include <time.h>
#include <vector>

#define L 100

string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";

void RSA::generadorClaves()
{
    int n, fi, d;

    srand(time(NULL));
    int p = 2 + rand()%L;
    int q = 2 + rand()%L;
    while(primo(p) != 1)
    {
        p = 2 + rand()%L;
    }
    while(primo(q) != 1)
    {
        q = 2 + rand()%L;
    }
    cout << "p="<< p << endl;
    cout << "q="<<q << endl;

    n = p*q;
    cout <<"\nn = "<< n << endl;
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

int RSA::cifrado(int e, int n, string M)
{
    int cif;
    for(int i = 0; i < M.size(); i++)
    {
        int t = alfabeto.find(M[i]);
    //cout<<"\n\n m = "<<M<<" - "<<t<<"\n";
        cif = expModular(t,e,nyYa);
        cout << cif << " ";
    }
    return cif;
}

string RSA::descifrado(int M)
{
    string deci;
    for(int i = 0; i < M; i++)
    {
        int t = expModular(M,clavePrivada1,nyYa);
        //cout<<"\n\n t = "<<t<<"\n";
        deci += alfabeto[t];
    }
    return deci;
}

string RSA::descifrado2()
{
    //int parametros = descifrado(cifrado(clavePublica1,nyYa,mensaje));
    int n;
    cout << "\nDame n -> ";
    cin >> n;
    int num;
    string deciFINAL;
    for(int i = 0; i < n; i++)
    {
        cout << "\nDame num -> ";
        cin >> num;
        int t = expModular(num,clavePrivada1,nyYa);
        //cout<<"\n\n t = "<<t<<"\n";
        deciFINAL += alfabeto[t];
    }
    return deciFINAL;
}

RSA::RSA()
{
    generadorClaves();
    cout << "clavePublica -> " << clavePublica1 << endl;
    cout << "clavePrivada -> " << clavePrivada1 << endl;
}



