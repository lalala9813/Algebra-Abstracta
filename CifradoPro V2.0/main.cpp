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
    int j = 0;
    while(cont <= clave*cuadrados)
    {
        //Rellenando la matriz
        //Abajo
        for(int i = inicio; i <= limite; i++){
            matriz[i][limite] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[i][limite] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cont++;
        }

        //Izquierda
        for(int i = limite - 1; i >= inicio; i--){
            matriz[limite][i] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[limite][i] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cont++;
        }

        //Arriba
        for(int i = limite - 1; i >= inicio; i--){
            matriz[i][inicio] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[i][inicio] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cont++;
        }

        //Derecha
        for(int i = inicio + 1; i < limite; i++){
            matriz[inicio][i] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[inicio][i] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cont++;
        }
        inicio += 1;
        limite -= 1;
    }


    //Llenando como N
    int inicio2 = 1 , limite2 = clave - 1;
    if(j < mensaje.size()){
        //Abajo
        for(int i = inicio2; i <= limite2; i++)
        {
            matriz[i][clave] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[i][clave] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
        }

        //Diagonal
        int d = clave+1;
        for(int i = clave-2; i >= 0; i--){
            matriz[i][d] = mensaje[j];
            if(j > mensaje.size()){
                matriz[i][d] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            j++;
            d++;
        }

        //Abajo
        for(int i = inicio2; i <= clave - 1; i++){
            matriz[i][d-1] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[i][d-1] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
        }
    }

    //Llenado espiral invertido
    int cF = 0, cC = 0, cant = 1;
    //Calculando coordenas del centro de la matriz;
    if(j < mensaje.size()){
        if((clave*cuadrados) % 2 == 0){
            cF = (clave/2);
            cC = ((cuadrados/2)+(clave*2));
        }
        cF = clave/2;
        cC = (cuadrados/2)+(clave*2);
        //Derecha
        if(clave == 5){
            for(int i = cC-1; i < cC + 1; i++){
                matriz[cF][i+1] = mensaje[j];
                j++;
                if(j > mensaje.size()){
                    matriz[cF][i+1] = '@';
                }
                if(mensaje[j] == ' '){
                        mensaje[j] = '_';
                }
                cant++;
            }
            for(int i = cF; i < cF + 1; i++){
                matriz[i+1][cC+1] = mensaje[j];
                j++;
                if(j > mensaje.size()){
                    matriz[i+1][cC+1] = '@';
                }
                if(mensaje[j] == ' '){
                    mensaje[j] = '_';
                }
                cant++;
            }
            //Izquierda
            for(int i = cC; i >= cC - 1; i--){
                matriz[cF+1][i] = mensaje[j];
                j++;
                if(j > mensaje.size()){
                    matriz[cF+2][i] = '@';
                }
                if(mensaje[j] == ' '){
                    mensaje[j] = '_';
                }
                cant++;
            }
        }
        else{
            for(int i = cC-1; i < cC + 1; i++){
            matriz[cF-1][i] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[cF-1][i] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
                cant++;
            }
            //Abajo
            for(int i = cF; i < cF + 1; i++){
                matriz[i][cC] = mensaje[j];
                j++;
            if(j > mensaje.size()){
                matriz[i][cC] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cant++;
            }
        }

        //Izquierda
        for(int i = cC-1; i >= cC - 2; i--){
            matriz[cF][i] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[cF][i] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cant++;
        }

        //Arriba
        for(int i = cF-1; i >= cF - 1; i--){
            matriz[i][cC-2] = mensaje[j];
            j++;
            if(j > mensaje.size()){
                matriz[i][cC-2] = '@';
            }
            if(mensaje[j] == ' '){
                mensaje[j] = '_';
            }
            cant++;
        }
        //HOLA COMO ESTAS HERMANO PAOLO CARPIO ZUNIGA
    }

    cout << "\n";

    /*for(int i = 0; i < clave; i++){
        for(int j = 0; j < cuadrados*clave; j++){
            cout << matriz[i][j] << " ";
        }cout << "\n";
    }*/

    //Cifrado
    for(int i = 0; i < clave; i++){
        for(int j = 0; j < cuadrados*clave; j++){
            if(matriz[i][j] != '*'){
                cout << matriz[i][j];
            }
        }
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
