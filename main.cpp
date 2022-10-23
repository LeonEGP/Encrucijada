//Programa que: Implementa un algoritmo que determina si dos segmentos de recta se intersectan.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fecha de entrega: Sábado 22 de Octubre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Definición de la Estructura Punto, la cual consta de dos enteros [x, y].
struct Punto {
    int x;
    int y;
};

//Definición de la Estructura Linea, la cual consta de dos Puntos [punto1, punto2].
struct Linea {
    Punto punto1;
    Punto punto2;
};

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    cout << endl;
}

//Función que verifica la multiplicidad entre dos números, recibe dos valores enteros y retorna un valor booleano.
bool multiplicidad(int numero, int multiplo) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    if (numero % multiplo == 0) {
        return true;
    }
    else {
        return false;
    }
}

//Función que encuentra el múltiplo más cercano a un número, recibe un Entero como número y un Entero como base, retorna el múltiplo entero más cercano. 
int multiploCercano(int numero, int base) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.

    numero = numero + base / 2;
    numero = numero - (numero % base);

    if (base > numero) {
        return base;
    }
    return numero;
}

//Función que verifica si un punto está sobre una linea, recibe un Punto y una Linea, retorna el valor booleano.
bool sobreLinea(Punto punto, Linea linea) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    if (punto.x <= max(linea.punto1.x, linea.punto2.x) && punto.x >= min(linea.punto1.x, linea.punto2.x) && punto.y <= max(linea.punto1.y, linea.punto2.y) && punto.y >= min(linea.punto1.y, linea.punto2.y)) {
        return true;
    }
    else {
        return false;
    }
}

//Función que determina la Orientación/Dirección dados tres puntos, recibe los Tres Puntos, retorna un 0 si es Collinear, 1 si es Dextrógiro (Al sentido del Reloj), 2 si es Levógiro ( Al sentido ContraReloj). 
int direccion(Punto puntoA, Punto puntoB, Punto puntoC) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    
    int valor;
    valor = (puntoB.y - puntoA.y) * (puntoC.x - puntoB.x) - (puntoB.x - puntoA.x) * (puntoC.y - puntoB.y);

    if (valor == 0) {
        return 0;
    }
    else if (valor > 0) {
        return 1;
    }
    else {
        return 2;
    }
}

//Función que determina si dos líneas se intersectan, recibe Dos Lineas y retorna el valor booleano.
bool intersecta(Linea linea1, Linea linea2) { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.

    int direccion1;
    int direccion2;
    int direccion3;
    int direccion4;
    direccion1 = direccion(linea1.punto1, linea1.punto2, linea2.punto1);
    direccion2 = direccion(linea1.punto1, linea1.punto2, linea1.punto2);
    direccion3 = direccion(linea2.punto1, linea1.punto2, linea1.punto1);
    direccion4 = direccion(linea2.punto1, linea1.punto2, linea2.punto2);

    if (direccion1 != direccion2 && direccion3 != direccion4){
        return true;
    }
    else if (direccion1 == 0 && sobreLinea(linea2.punto1, linea1)) {
        return true;
    }
    else if (direccion2 == 0 && sobreLinea(linea2.punto2, linea1)) {
        return true;
    }
    else if (direccion3 == 0 && sobreLinea(linea1.punto1, linea2)) {
        return true;
    }
    else if (direccion4 == 0 && sobreLinea(linea1.punto2, linea2)) {
        return true;
    }
    else {
        return false;
    }
}

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función. Dentro de este contenido lineal, suceden 3 ciclos for independientes entre si, solo dependientes de la cantidad de puntos n, siendo estos ciclos de complejidad O(n); sin embargo, es meramente auxiliar para la ejecución del código. La Complejdiad de los Algoritmos en las Funciones desarrolladas son siempre O(1).
    
    int n; //Cantidad de Puntos
    vector <Punto> puntos;
    vector <Linea> lineas;
    vector <bool> resultados;

    espacio();
    cout << "INGRESE LA CANTIDAD DE PUNTOS [MULTIPLOS DE 4]: " << endl;
    cin >> n;
    espacio();

    if (n < 3) {
        cout << "Cantidad de puntos menor a la esperada." << endl;
        n = 4;
        cout << "Valor n ajustado a 4." << endl;
        espacio();
    }
    else if (multiplicidad(n,4) == false) {
        cout << "Cantidad de puntos diferente a los valores múltiplos de 4." << endl;
        n = multiploCercano(n, 4);
        cout << "Valor n ajustado a " << n << "." << endl;
        espacio();
    }

    cout << "INGRESE LOS VALORES PARA CADA PUNTO: " << endl;
    espacio();

    for (int i = 0; i < n; i++) { //Complejidad Computacional: O(n), siendo n la cantidad de puntos.
    
        int x;
        int y;
        Punto punto;

        cout << "x" << i + 1 << ":";
        cin >> x;
        cout << "y" << i + 1 << ":";
        cin >> y;

        punto.x = x;
        punto.y = y;
        puntos.push_back(punto);
    }

    espacio();

    for (int j = 0; j < puntos.size(); j+=2) { //Complejidad Computacional: O(n), siendo n la cantidad de puntos.
        Linea linea;
        linea.punto1 = puntos[j];
        linea.punto2= puntos[j+1];
        lineas.push_back(linea);
    }

    for (int k = 0; k < lineas.size(); k+=2) { //Complejidad Computacional: O(n), siendo n la cantidad de lineas.
        bool resultado;
        resultado = (intersecta(lineas[k], lineas[k+1]));
        resultados.push_back(resultado);
    }

    cout << "RESULTADOS: " << endl;

    for (int l = 0; l < resultados.size(); l++) {
        if (resultados[l] == true) {
            cout << "True" << endl;
        }
        else if (resultados[l] == false){
            cout << "False" << endl;
        }
    }

    return 0;
}