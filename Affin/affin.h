#ifndef AFFIN_H_INCLUDED
#define AFFIN_H_INCLUDED

#include <string>

using namespace std;

class Affin
{
private:
    int a;
    int b;
public:
    void getDatos();
    Affin();
    Affin(int , int);
    string cifrado(string);
    string descifrado(string);
};

#endif // AFFIN_H_INCLUDED
