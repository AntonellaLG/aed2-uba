#include "Lista.h"

Lista::Lista() {
    // Completar
    _longitud=0;
    _primero=nullptr;
    _ultimo= nullptr;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

void Lista::destruir() {
    Nodo* temp = _primero;
    while(temp != nullptr) {
        temp = temp->siguiente;
        delete(_primero);
        _primero = temp;
    }
    _longitud = 0;
    _primero = nullptr;
    _ultimo = nullptr;
}

Lista::~Lista() {
    // Completar
    destruir();
}


/*l.agre(1)
l.agre(2)
l.agre(3)
l = {1,2,3}; (this)
Quiero que this ahora sea: l = {4,5,6};
Para eso, tengo que ir borrando los elementos de this para no perder memoria, e ir agregando los nuevos elementos */

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    //this -> longitud() = 0; quiero que longitud de aCopiar sea 0;
    //_primero = nullptr;     quiero tambien que _primero y _ultimo de aCopiar sean nullptr? Si. Pero lo inicialicé asi en el constructor de Nodo en Lista.h
    // _ultimo = nullptr;     Esto va a pasar sólo, cuando vaya borrando
    destruir();
    for(int i=0; i<aCopiar.longitud(); i++) {  
        /*this -> iesimo(i) = aCopiar.iesimo(i);  no puedo al iesimo darle un valor, porque tengo una lista vacia. No se soluciona cambiando la longitud de la lista de this
        this -> agregarAtras(iesimo(i));*/
        this -> agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem);
    //nuevo -> anterior = nullptr; // inicialicé el constructor de Nodo anterior con nullptr, asi que no hace falta
    if(_longitud>0) {
        nuevo->siguiente = _primero;
        (this->_primero)->anterior = nuevo;
        this->_primero = nuevo;
    } else {
        _primero=nuevo;
        _ultimo=nuevo;
    }
    _longitud++;
}

void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem);
    //nuevo -> siguiente = nullptr; // inicialicé el constructor de Nodo siguiente con nullprt, asi que no hace falta
    if(_longitud>0) {
        nuevo->anterior = _ultimo; // el anterior del nuevo es el ultimo actual
        (this->_ultimo)->siguiente = nuevo; // el siguiente del ultimo actual es el nuevo nodo (el anterior del ultimo sigue siendo el mismo, asi que no lo toco)
        this->_ultimo = nuevo; // actualizo el ultimo
    } else {
        _primero=nuevo;
        _ultimo=nuevo;
    }
    _longitud++; // actualizo la longitud
} // no se hace delete de Nodo* nuevo, queda en la memoria. Despues se deletea en el destructor de la clase lista

void Lista::eliminar(Nat i) {
    // Completar
    if(_longitud==1) {
        delete _primero;
        _primero=nullptr;
        _ultimo=nullptr;
        _longitud--;
    } else {
        Nodo* borro = _primero;
        for(unsigned int j=0; j<i; j++) { // itero hasta llegar al iésimo elemento, que es el que quiero borrar
        //for(int j=1; j<=i; j++) {  //deberia estar escrito asi para que no me moleste la comparacion entre j int e i nat??
            borro = borro -> siguiente;
        }
        if(borro!=_primero && borro!=_ultimo) { // casos del medio
            (borro->anterior)->siguiente = borro->siguiente;  //el siguiente del anterior al que borro, es el siguiente del que borro
            (borro->siguiente)->anterior = borro->anterior; //el anterior del siguiente al que borro es el anterior del que borro
        } else {
            if(borro==_primero) { // caso borde primero
                (borro->siguiente)->anterior = nullptr; // TENGO QUE PEDIR ESTO ANTES??
                _primero = borro->siguiente; // quiero que el siguiente del que borro sea el nuevo primero
            }
            if(borro==_ultimo) { // caso borde ultimo
                (borro->anterior)->siguiente = nullptr; // TENGO QUE PEDIR ESTO ANTES??
                _ultimo = borro->anterior; // quiero que el anterior del que borro sea el nuevo ultimo
            }
        }
        _longitud--;
        delete borro;
    }
}

int Lista::longitud() const {
    // Completar
    int lon =0;
    Nodo* temp = _primero;
    while(temp != nullptr) {
        lon++;
        temp = temp->siguiente;
    }
    return lon;
}

const int& Lista::iesimo(Nat i) const { // deberia deletear res?????????? luego de return??
    // Completar
    Nodo* res = _primero;
    for (unsigned int j=0; j<i; j++) { // poniendo unsigned adelante del int no me saltan los warnings por comparaciones entre nat e int
     //for(int j=1; j<=i; j++){  //deberia estar escrito asi para que no me moleste la comparacion entre j int e i nat??
        res = res->siguiente;
    }
    //assert(false);
    return (res->valor);
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* res = _primero;
    for (unsigned int j=0; j<i; j++) { // poniendo unsigned adelante del int no me saltan los warnings por comparaciones entre nat e int
        res = res->siguiente;
    }
    //assert(false);
    return (res->valor);
}

/*void Lista::mostrar(ostream& o) {
    // Completar
    for(int i=0; i<longitud()-1; i++) {
        cout << "[" << iesimo(i) << ", " << endl;
    }
    cout << _ultimo << "]" << endl; // o...  cout<< iesimo(i)<< "]" << endl;   ya que tengo i=longitud()-1 del for 
}*/

/*int Lista::head(const Lista& l) {
    return l.iesimo(0);
}*/
