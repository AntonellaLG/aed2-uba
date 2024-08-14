template <class T>
Conjunto<T>::Conjunto() {
    // Completar
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    // Completar
    destruir(_raiz);
}

template <class T>
void Conjunto<T>::destruir(Nodo* n) {
    if (n!=nullptr) {
        destruir(n->izq);
        destruir(n->der);
        delete n;
    }
    //delete _raiz;
    _raiz=nullptr;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const { // es temp->valor o temp ?? ES TEMP->VALOR
    Nodo* temp=_raiz;                               // es clave o clave->valor ?? USO CLAVE
    while (temp!=nullptr && (temp->valor)!=clave) {
        if((temp->valor) > clave) {
            temp=temp->izq;
        } else {
            temp=temp->der;
        }
    }
    if (temp != nullptr && (temp->valor)==clave) {
        //delete temp;
        return true;
    } else {
        //delete temp;
        return false;
    }
    //assert(false);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) { // tengo que usar clave o clave->valor ?? TENGO QUE USAR CLAVE (clave seria el valor de un nodo que tengo que ubicar)
    Nodo* n=_raiz;
    Nodo* temp=nullptr;
    while (n!=nullptr) {
        temp=n;
        if(clave < (n->valor)) {
            n=n->izq;
        } else {
            n=n->der;
        }
    }
    if (temp==nullptr) {
        _raiz= new Nodo(clave);
    } else {
        if (clave < (temp->valor)) {
            temp->izq= new Nodo(clave);
        } else {
            temp->der= new Nodo(clave);
        }
    }
    //delete n;
    //assert(false);
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (cardinal() == 1) {
        if (clave == _raiz->valor) {
            delete _raiz;
            _raiz = nullptr;
        }
    } else {
        if (pertenece(clave)) {
            Nodo* n = nullptr;
            removerAux(n, "", _raiz, clave);
        }
    }
}

template <class T>
void Conjunto<T>::removerAux(Nodo* padre, string dir, Nodo* nodo, T clave) {
    if (nodo->valor == clave) {
        if (nodo->izq==nullptr && nodo->der== nullptr) { // el nodo es hoja
            //todos menos la raiz (caso base) tienen padre
            delete nodo; //error: escriba 'struct Conjunto<int>::Nodo' argumento dado a 'delete', puntero esperado
            if (dir == "IZQ") {
                padre->izq = nullptr;
            } else {
                padre->der = nullptr;
            }
        } else {
            //por hipotesis tengo al menos una rama
            if (nodo->der!= nullptr) {  //si tengo la rama derecha
                nodo->valor = (nodo->der)->minimo();  //error: no hay función coincidente para la llamada a 'Conjunto<int>::minimo(Conjunto<int>::Nodo*&)'
                //como llamo al resto de la rama?? porque nodo.der es un nodo, no es la rama  ?????????????????????????????????

                //nodo.valor ahora esta duplicado, lo eliminamos recursivamente por HI
                removerAux(nodo, "DER", nodo->der, nodo->valor);  // *nodo.der ??????? esta bien????
            } else {  //si tengo la rama izquierda
                nodo->valor = (nodo->izq)->maximo();  //error: no hay función coincidente para la llamada a 'Conjunto<int>::maximo(Conjunto<int>::Nodo*&)'
                // idem arriba   ?????????????????????????????????

                removerAux(nodo, "IZQ", nodo->izq, nodo->valor);
            }
        }
    } else {
        if (nodo->valor > clave){
            removerAux(nodo, "IZQ", nodo->izq, clave); // "anulo" el puntero para poder tener el llamado por copia de la funcion??
        } else {
            removerAux(nodo, "DER", nodo->der, clave);
        }
    }
}

template <class T> // CORMEN
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* ubicacion = _raiz;
    while(ubicacion!=nullptr && (ubicacion->valor)!=clave) {
        if ((ubicacion->valor) > clave) {
            Nodo* aux = ubicacion;
            ubicacion = ubicacion->izq;
            ubicacion->padre = aux;
        } else {
            Nodo* aux = ubicacion;
            ubicacion = ubicacion->der;
            ubicacion->padre = aux;
        }
    }
    if ((ubicacion->der)!=nullptr) {
        return (ubicacion->der)->minimo();
    }
    Nodo* temp = ubicacion->padre;
    while (temp!=nullptr && clave==((temp->der)->valor)) {
        ubicacion->valor= temp->valor;
        temp = temp->padre;
    }
    return temp->valor;
}

template <class T>
const T& Conjunto<T>::Nodo::minimo() const { // se asume el conjunto no vacio
    const Nodo* temp = this;
    while (temp->izq !=nullptr) {
        temp=temp->izq;
    }
    return temp->valor;
    //assert(false);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    return _raiz->maximo();
}

template <class T>
const T& Conjunto<T>::Nodo::maximo() const {
    const Nodo* temp = this;
    while ((temp->der)!=nullptr) {
        temp=temp->der;
    }
    return temp->valor;
    //assert(false);
}

/*
template <class T>
unsigned int Conjunto<T>::cardinal() const {
    unsigned int i = 0;
    if (_raiz!=nullptr) {
        i++;
        if((_raiz->izq)!=nullptr) {
            i= i+1+cardinalAux(_raiz->izq);
        }
        if((_raiz->der)!=nullptr) {
            i= i+1+cardinalAux(_raiz->der);
        }
    }
    //assert(false);
    return i;
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* n) const {
    unsigned int j = 0;
    unsigned int k = 0;
    if((n->izq)!=nullptr || (n->der)!=nullptr) {
        if((n->izq)!=nullptr) {
            j++;
            j= j+cardinalAux(n->izq);
        }
        if((n->der)!=nullptr) {
            k++;
            k= k+cardinalAux(n->der);
        }
    }
    return j+k;
}
*/

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    cardinalAux(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinalAux(Nodo* n) const {
    unsigned int res = 0;
    if(n!=nullptr){
        unsigned int cardIzq = cardinalAux(n->izq);
        unsigned int medio = 1;
        unsigned int cardDer = cardinalAux(n->der);
        res = cardIzq + medio + cardDer;
    }
    return res;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}