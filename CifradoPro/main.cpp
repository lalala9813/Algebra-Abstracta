#include <iostream>

using namespace std;


string cifrado(string mensaje, int clave, int cuadrados)
{
    char matriz[clave][cuadrados*clave];

    int inicio = 0, limite = clave - 1, cont = 1;


    //Llenando la matriz
    for(int i = 0; i < clave; i++){
        for(int j = 0; j < cuadrados*clave; j++){
            matriz[i][j] = '*';
        }
    }

    //Espiral
    while(cont <= clave*cuadrados)
    {
        //Rellenando la matriz
        //Abajo
        for(int i = inicio; i <= limite; i++){
            matriz[i][limite] = '@';
            cont++;
        }

        //Izquierda
        for(int i = limite - 1; i >= inicio; i--){
            matriz[limite][i] = '7';
            cont++;
        }

        //Arriba
        for(int i = limite - 1; i >= inicio; i--){
            matriz[i][inicio] = '2';
            cont++;
        }

        //Derecha
        for(int i = inicio + 1; i < limite; i++){
            matriz[inicio][i] = '4';
            cont++;
        }
        inicio += 1;
        limite -= 1;

    }

    //Llenando como N


    cout << "\n";

    for(int i = 0; i < clave; i++){
        for(int j = 0; j < cuadrados*clave; j++){
            cout << matriz[i][j] << " ";
        }cout << "\n";
    }
}

int main()
{
    int clave, cuadrados;
    string mensaje = "";

    cout << "Inserta tu mensaje -> ";
    getline(cin, mensaje);

    cout << "Inserta clave -> ";
    cin >> clave;

    cout << "Inserta #cuadrados -> ";
    cin >> cuadrados;

    cifrado(mensaje,clave,cuadrados);

    return 0;
}
