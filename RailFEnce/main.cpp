#include <iostream>

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLAMNOPQRSTUVWXYZ.,_-0123456789";

string transpuesta(string msm)
{
    string cripMessage = "";
    int alfTam = alfabeto.size() - 1;

    for(int i = 0; i < msm.size(); i++)
    {
        for(int j = 0; j <= alfTam; j++)
        {
            if(msm[i] == alfabeto[j])
            {
                cripMessage += alfabeto[alfTam - j];
            }
        }
    }
    return cripMessage;
}

string encriptado(string msm, int clave)
{
    msm = transpuesta(msm);
    string encrip = "";
    int salto1 = clave - 1;
    int salto2 = 0;

    while((msm.size()%(clave-1)) != 1)
    {
        msm += "x";
    }

    for(int i = 0; i < clave; i++){
        int pos = i;
        int par = true;
        int aux = -1;
        while(pos < msm.size())
        {
            if(pos != aux)
            {
                encrip += msm[pos];
            }
            aux = pos;
            if(par){
                pos += 2*(salto1);
                par = false;
            }
            else if(!par){
                pos += 2*(salto2);
                par = true;
            }
        }
        salto1--;
        salto2++;
    }
    return encrip;

}

string desencriptado(string msm, int clave)
{
    msm = transpuesta(msm);
    string desencrip = msm;
    int salto1 = clave - 1;
    int salto2 = 0;
    int index = 0;

    for(int i = 0; i < clave; i++){
        int pos = i;
        int par = true;
        int aux = -1;
        while(pos < msm.size())
        {
            if(pos != aux)
            {
                desencrip[pos] = msm[index];
                index++;
            }
            aux = pos;
            if(par){
                pos += 2*(salto1);
                par = false;
            }
            else if(!par){
                pos += 2*(salto2);
                par = true;
            }
        }
        salto1--;
        salto2++;
    }
    return desencrip;

}

int main()
{
    string msm;
    cout << "Deme su mensaje -> ";
    getline(cin,msm);
    msm = encriptado(msm,4);
    cout << msm << endl;
    cout << desencriptado(msm,4);
    return 0;
}
