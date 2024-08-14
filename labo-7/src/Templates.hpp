#ifndef ALGO2_LABO_TEMPLATES_HPP  // esta bien esto??
#define ALGO2_LABO_TEMPLATES_HPP


// EJERCICIO 1
template<class T>
T cuadrado(const T& t){// typename T::value_type& t
  return t * t;
}

// EJERCICIO 2
/*Adaptar la funcion bool contiene(string s) a una función genérica con dos parámetros, 
class Contenedor y class Elem (usando template<class Contenedor, class Elem>). Asumir que se 
encuentra definido el método Elem Contenedor::operator[](int) const. Por ejemplo, si Contenedor es 
std::string, el tipo Elem es char, y si Contenedor es std::vector<int>, el tipo Elem es int.
*/

template<class Contenedor, class Elem>
bool contiene(Contenedor c, const Elem elem){
    /*
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == elem) {
            return true;
        }
    }
*/
    for (auto it = c.begin(); it != c.end(); ++it) {
       if (*it == elem) {
            return true;
        }
    }
    return false;
}

// EJERCICIO 3
/*Definir la función genérica bool esPrefijo(Contenedor a, Contenedor b) que devuelve true si y sólo 
si a tiene menos elementos que b y a es prefijo de b. La función depende de un parámetro class 
Contenedor. Asumir que se encuentran definidos los métodos:
• int Contenedor::size() const
• Elem Contenedor::operator[](int) const — para algún tipo Elem apropiado, que puede depender de
Contenedor.
*/

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    bool res = (a.size() < b.size());
    if(res) {
        for (int j = 0; j < a.size() && res; j++) {
            if (a[j] != b[j]) {
                res = false;
            }
        }
    }
    return res;
}

//EJERCICIO 4
/*Definir la función genérica Elem maximo(Contenedor c) que devuelve el elemento más grande de c. 
Se asume que c tiene al menos un elemento y que se encuentran definidos los métodos:
• int Contenedor::size() const
• Elem Contenedor::operator[](int) const
• bool operator<(Elem, Elem)
*/

template<class Contenedor, class Elem> // chequear
Elem maximo(Contenedor c){
    Elem max=c[0];
    if(c.size()>1){
        for(int i=1; i < c.size(); i++){
            if(max<c[i]) {
                max=c[i];
            }
        }
    }
    return max;
}

#endif