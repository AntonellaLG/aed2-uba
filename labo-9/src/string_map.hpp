template <typename T>
string_map<T>::string_map(){  // CREO QUE BIEN
    // COMPLETAR
    _raiz = nullptr;
    _size=0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) { //REVISAR
    // COMPLETAR
    if( this != &d ) { // Aca estoy preguntando si la instancia que me pasaron es distinta que la "actual".
        destruir(_raiz); // Antes tenia d.claves() != _claves, pero podrian tener las misman claven los dos diccionarios y d con dos instancias diferentes con las mismas claves
        _raiz=nullptr;
        for(string clave: d.claves()){
            insert(make_pair(clave, d.at(clave)));
        }
    }
    return *this;
}
template <typename T>
vector<string> string_map<T>:: claves(){ // REVISAR
    Nodo* actual = _raiz;
    vector<string> v;
    if (actual!=nullptr){
        v.push_back(actual);
        for(int i=0; i<(actual->siguientes).size(); i++){
            v.push_back((actual->siguientes)[i]);
        }
    }
    return v;
}

template <typename T>
string_map<T>::~string_map(){  // REVISAR
    // COMPLETAR
    destruir(_raiz);
    _raiz=nullptr;
    _size=0;
}

template<typename  T>
void string_map<T>::destruir(Nodo* n){  // REVISAR
    if (n!=nullptr) {
        int cantHijos = 0;
        for(int i=0; i<256; i++){
            if((i->siguientes)[i] != nullptr) {
                cantHijos++;
            }
        }
        if(cantHijos>0){
            for(Nodo* hijo: (n->siguientes)) {
                destruir(hijo);
            }
        }
        if((n->definicion)!=nullptr){
            delete n->definicion;
            // tengo que borrar algo en _claves?? Algo asi como _claves.erase(...) ?
        }
    }
    delete n;
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& par){ // LISTO
    //COMPLETAR
    if(_size==0){
        Nodo* root = new Nodo();
        _raiz = root;
        Nodo* actual = root;
        int i=0;
        while(i < (par.first).size()) {
            Nodo* nuevo = new Nodo();
            (actual -> siguientes[int(par.first[i])] ) = nuevo;
            actual = nuevo;
            i++;
        }
        T* def = new T(par.second);
        actual -> definicion = def;
    } else {
        Nodo* actual=_raiz;
        int i=0;
        string clave = par.first;
        while (i < clave.size()){
            if(actual->siguientes[int(clave[i])]==nullptr){
                actual->siguientes[int(clave[i])] = new Nodo();
                actual = actual->siguientes[int(clave[i])];
            } else {
                actual = actual->siguientes[int(clave[i])];
            }
            i++;
        }
        T* def = new T(par.second);
        actual -> definicion = def;
    }
    _size++;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){ //OPCIONAL
    // COMPLETAR
}

template <typename T>
int string_map<T>::count(const string& clave) const{ // REVISAR
    // COMPLETAR
    int res=1;
    if (_raiz == nullptr) {
        res=0;
    } else {
        Nodo* actual = _raiz;
        int i = 0;
        while(i<clave.size() && res==1){
            if( actual->siguientes[int(clave[i])]==nullptr ){
                res = 0;
            } else {
                actual=actual->siguientes[int(clave[i])];
            }
            i++;
        }
        if(i==clave.size() && actual->definicion!=nullptr){
            res=1;
        } else {
            res=0;
        }
    }
    return res;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const { // LISTO
    // COMPLETAR
    Nodo* actual = _raiz;
    for(int i=0; i<clave.size(); i++){
        actual = (actual->siguientes)[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) { // LISTO
    // COMPLETAR
    Nodo* actual = _raiz;
    for(int i=0; i<clave.size(); i++){
        actual = (actual->siguientes)[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) { // PENSAR
    // COMPLETAR
    Nodo* ultimoNodo=_raiz;
    int ultimoIndice=0;
    Nodo* actual=_raiz;
    int indice=0;
    while(indice < clave.size()){
        int hijos=0;
        for(int i=0; i<(actual->siguientes).size(); i++){
            if((actual->siguientes)[i] != nullptr){
                hijos++;
            }
        }
        if(hijos > 1 || actual->definido != nullptr){
            ultimoNodo=actual;
            ultimoIndice=indice;
        }
        int posicion = int(clave[indice]);
        actual=(actual->siguientes)[posicion];
        indice++;
    }
    delete actual->definicion;
    actual->definicion = nullptr;
    _claves.erase(actual->iterador); // YO NO TENGO ITERADOR
    int hijos=0;
    for(int i=0; i<(actual->siguientes).size(); i++){
        if((actual->siguientes[i]) != nullptr){
            hijos++;
        }
    }
    if(hijos==0){
        Nodo* siguiente = ultimoNodo->siguientes[int(clave[ultimoIndice])];
        ultimoNodo->siguientes[int(clave[ultimoIndice])] = nullptr;
        ultimoNodo = siguiente;
        ultimoIndice++;

        while(ultimoIndice < clave.size()) {
            siguiente=ultimoNodo->siguientes[int(clave[ultimoIndice])];
            delete ultimoNodo->definicion;
            delete ultimoNodo;
            ultimoNodo=siguiente;
            ultimoIndice++;
        }
        delete ultimoNodo;
    }
    _size--;
}

/*template <typename T>
int string_map<T>::size() const{ // REVISAR
    // COMPLETAR
    int res=0;
    Nodo* actual=_raiz;
    while( actual != nullptr ){ //chequear actual e ir aumentando el res  while( actual != nullptr 
        res++;
        actual = (actual->siguientes)[0];
    }
    return res; // Aca solo esta contando los hijos "directos", no?
}
*/

template <typename T>
int string_map<T>::size() const{
    sizeAux(_raiz);
}

template <typename T>
int string_map<T>::sizeAux(Nodo* n) { // CREO QUE BIEN
    int res = 0;
    if(n!=nullptr){
        res++;
        for(int i=0; i<256; i++){
            if((n->siguientes)[i] != nullptr) {
                res = res+sizeAux((n->siguientes)[i]) ;
            }
        }
    }
    return res;
}

template <typename T>
bool string_map<T>::empty() const{ // CREO QUE BIEN
    // COMPLETAR
    return _raiz==nullptr; // o return _size==0;
}
