#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>


// Completar con las funciones del enunciado

// EJERCICIO 1
template<class Contenedor>   
typename Contenedor::value_type minimo(const Contenedor& c) {
    auto min=c.begin();
    for(auto it = c.begin(); it!=c.end(); ++it){
        if(*it<*min) {
            min=it;
        }
    }
    return *min;
}

/*template<class Contenedor>    // OTRA FORMA, COMPARO EL PRIMERO Y EL SEGUNDO, Y DESDE AHI VOY MODIFICANDO EL MIN Y EL IT
typename Contenedor::value_type minimo(const Contenedor& c) {
    auto min=c.begin();
    auto it=++c.begin();
    while(it!=c.end()) {
        if(*it<*min) {
            min=it;
        }
        ++it;
    }
    return *min;
}*/

/*Que devuelva el elemento mínimo del contenedor, suponiendo que la colección no es vacía. Se asume que existen:
• bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
• Contenedor::const_iterator Contenedor::begin() const
• Contenedor::const_iterator Contenedor::end() const    */

// EJERCICIO 2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    double sum=0;
    double lon=0;
    auto it=c.begin();
    while (it!=c.end()) {
        sum=sum+*it;
        lon++;
        ++it;
    }
    return sum/lon;
}

/*Que devuelva el promedio de los elementos del contenedor, suponiendo que la colección no es vacía. 
Se asume que existen
• Contenedor::const_iterator Contenedor::begin() const
• Contenedor::const_iterator Contenedor::end() const
y que Contenedor::value_type es un tipo numérico, cuyos valores se pueden sumar y dividir por un entero no
nulo.     */

// EJERCICIO 3
//Implementar las funciones análogas a los ejercicios 1 y 2 pero esta vez recibiendo iteradores:
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min=desde;
    for(auto it=desde; it!=hasta; ++it) {
        if(*it<*min) {
                min=it;
        }
    }
    return *min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    double sum=0;
    double lon=0;
    for(auto it=desde; it!=hasta; ++it) {
        sum=sum+*it;
        lon++;
    }
    return sum/lon;
}

// EJERCICIO 4
template<class Contenedor> 
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    for(auto it=c.begin(); it!=c.end(); ++it) {
        if(*it == elem) {
            it=--c.erase(it); // it queda apuntando al siguiente del que borré. Si no le asigno nuevamente la posicion donde estoy, va a saltear ese elemento
        }
    }
}

/*Se aumen las siguientes funciones del contenedor y su iterador:
• Contenedor::iterator Contenedor::begin()
• Contenedor::iterator Contenedor::end()
• Contenedor::iterator Contenedor::erase(Contenedor::iterator)
• bool operator==(const Contenedor::value_type&, const Contenedor::value_type&)
El iterador resultado de erase se encuentra ubicado en la posición siguiente al elemento eliminado.  
*/

// EJERCICIO 5
/*Implementar una función que decida si los elementos —dispuestos en el orden en el que los devuelve el iterador—
están ordenados de manera estrictamente creciente.*/
template<class Contenedor>
bool ordenado(Contenedor &c){
    bool res=true;
    auto itAnterior = c.begin(); // quiero itAnterior<it siempre
    for(auto it=++c.begin(); it!=c.end() && res; ++it){ // --c.end() para que se compare tambien el ultimo lugar
        if(*it<=*itAnterior){ // el siguiente no es mayor al anterior 
            res=false;
        } else {       // voy actualizando los iteradores
            ++itAnterior;  // it aumenta en el for
        }
    }
    return res;
}

// EJERCICIO 6
/*Implementar una operación que dado un contenedor y un elemento devuelva una tupla con dos nuevos contenedores
del mismo tipo que el recibido por parámetro. El primer contenedor deberá tener todos los elementos menores al
elemento. El segundo deberá tener los elementos mayores o iguales. La aridad será la siguiente:*/
template<class Contenedor>  
std::pair<Contenedor, Contenedor> split(const Contenedor & c,
const typename Contenedor::value_type& elem){
    //std::pair<Contenedor, Contenedor> p;
    Contenedor C1;
    Contenedor C2;
    for(auto it=c.begin(); it!=c.end(); ++it){
        if(*it<elem){
            C1.insert(C1.end(),*it);
        } else{
            C2.insert(C2.end(),*it);
        }
    }
    std::pair<Contenedor, Contenedor> p = std::make_pair(C1, C2);
     return p;
}

/*Se asumen las siguientes funciones:
• bool operator<(const Contenedor::value_type&, const Contenedor::value_type&)
• Contenedor::const_iterator Contenedor::begin() const
• Contenedor::const_iterator Contenedor::end() const
• Contenedor::iterator Contenedor::insert(const Contenedor::const_iterator&,
const Contenedor::value_type&) const      */




#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
