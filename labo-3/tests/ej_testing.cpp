#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>


using namespace std;

// Ejercicio 4
/*TEST(Aritmetica, suma) {
    EXPECT_EQ(suma(15, 7), 22);
}*/

TEST(Aritmetica, suma) {
    int valor_calculado = 15 + 7;
    int valor_esperado = 22;
    EXPECT_EQ (valor_calculado, valor_esperado);
}

// Ejercicio 5
/*TEST(Aritmetica, potencia) {
    EXPECT_EQ(potencia(10, 2), 100);
}*/
TEST(Aritmetica, potencia) {
    int valor_calculado = pow(10,2);
    int valor_esperado = 100;
    EXPECT_EQ (valor_calculado, valor_esperado);
}

// Ejercicios 6: Escribir un test en la test suit Aritmética y de nombre potencia_general que evalúe que 
//elevar todos los números entre -5 y 5 es equivalente a multiplicar el número por sí mismo.
TEST(Aritmetica, potencia_general) {
    for(int i=-5; i<6; i++) {
        int valor_calculado= pow(i,2);
        int valor_esperado= i*i;
        EXPECT_EQ (valor_calculado, valor_esperado);
    }
}

// Ejercicios 7: Escribir un test en la test suit Diccionario y de nombre obtener que defina un diccionario 
//de enteros a enteros (map<int, int>), defina un valor con un significado y revise que al obtener la
//clave se obtiene el significado definido.
TEST(Diccionario, obtener) {
    map<int, int> m;
    

}

// Ejercicios 8: Escribir un test en la test suit Diccionario y de nombre definir que defina un diccionario 
//de enteros a enteros (map<int, int>), verifique que una clave no está definida, luego la defina y
//verifique que ahora sí está definida (usando la operación count).
TEST(Diccionario, definir) {
    map<int, int> m;

}

// Ejercicios 9: Considerando la clase Truco vista anteriormente (y presente en src/Truco.h), escribir un test 
//en la test suit Truco y de nombre inicio que cree una instancia de Truco y verifique que el puntaje de
//ambos jugadores es 0.
TEST(Truco, inicio) {
    
}
