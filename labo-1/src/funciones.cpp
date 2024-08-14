#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_s_sin_repetidos;
    for (int i=0; i < s.size(); i++) {
        set_s_sin_repetidos.insert(s[i]);
    }
    vector<int> res;
    for ( int x : set_s_sin_repetidos) {
        res.push_back(x);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    return true;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> set_a;
    set<int> set_b;
    for(int i=0; i<a.size(); i++) {
        set_a.insert(a[i]);
    }
    for(int j=0; j<b.size(); j++) {
        set_b.insert(b[j]);
    }
    for(int x: set_a) {
        if(set_b.count(x)==0) {
            res=false;
            break;
        }
    }
    return res;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    vector<int> s_sin_repetidos = quitar_repetidos(s);
    set<int> set_s;
    for(int i=0; i<s_sin_repetidos.size(); i++) {
        set_s.insert(s_sin_repetidos[i]);
    }
    for(int x : set_s) {
        for(int j=0; j<s_sin_repetidos.size(); j++) {
            if(x = s_sin_repetidos[j]) {
                int cant = 0;
                for(int i=0; i<s.size(); i++) {
                    if(s_sin_repetidos[j]==s[i]) {
                        cant = cant+1;
                    }
                }
            res[x] = cant; // S operator[](K clave); devuelve el valor asociado a la clave.
            }
        }
    }
    return res;
}

// Ejercicio 5
/*map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    vector<int> s_sin_repetidos = quitar_repetidos(s);
    set<int> set_s;
    for(int i=0; i<s_sin_repetidos.size(); i++) {
        set_s.insert(s_sin_repetidos[i]);
    }
    for(pair<int,int> p : res) {
        for(int j=0; j<s_sin_repetidos.size(); j++) {
            if(p.first = s_sin_repetidos[j]) {     // No se como tomar la clave del map
                int cant = 0;
                for(int i=0; i<s.size(); i++) {
                    if(s_sin_repetidos[j]==s[i]) {
                        cant = cant+1;
                    }
                }
            p.second = cant; // S operator[](K clave); devuelve el valor asociado a la clave.
            }
        }
    }
    return res;
}*/

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> res;
    map<int,int> conteo = contar_apariciones(s);
    vector<int> s_sin_repetidos = quitar_repetidos(s); 
    for (pair<int, int> p : conteo) {
        if(p.second == 1) {
            res.push_back(p.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int x: a){
        if(b.count(x)>0){
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) { //IDEA: Para cada mail, me fijo las libretas y agrego
    bool res=true;  // ese conjunto de libretas a un conjunto llamado "grupos", siempre que no este
    set<set<LU>> grupos; // ya en ese conjunto (esto para ignorar los mails del mismo grupo).
    set<LU> alumnos; // Luego, agrego las LU que no parecen en el conjunto alumnos, y si hay una
    for(Mail elem : s){ // que ya está en alumnos, es porque esa LU aparece en grupos distintos,
        set<LU> l=elem.libretas(); //y devuelvo false.
        if(grupos.count(l)==0){
            grupos.insert(l);
            for(LU lib : l){
                if(alumnos.count(lib)==0){
                    alumnos.insert(lib);
                } else {
                   res=false;
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
