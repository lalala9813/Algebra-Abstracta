#include <iostream>
#include "operaciones.h"

#include <iostream>
using namespace std;

bool primo(int numero)
{
    int cont = 0;

    for(int i = 1; i <= numero; i++)
    {
        if(numero % i == 0)
        {
            cont += 1;
        }
        else
        {
            cont += 0;
        }
    }

    if(cont == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int euclides(int a, int b)
{
    int q = 0;
    int r = 0;


    while(b != 0)
    {
        q = a/b;
        r = a - (q*b);//2
        a = b;
        b = r;
    }
    return a;
}

int inversa(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1){
        return 1;
	}
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int modulo(int a, int b)
{
    int q = a/b;
    int r = a - (q*b);
    while(r < 0){
        r += b;
    }
    return r;
}

int expModular(int base, int exp, int m)
{
    int x = modulo(base,m);
    int n = 1;
    while(exp != 0){
        if(modulo(exp,2)){
            n = modulo(n*x,m);
        }
        x = modulo(x*x,m);
        exp /= 2;
    }
    return n;
}
