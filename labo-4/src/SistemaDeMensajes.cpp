#include "SistemaDeMensajes.h"

/*EJERCICIO 1 :Dada la clase SistemaDeMensajes definida en SistemaDeMensajes.h, completar la 
definición de las funciones en SistemaDeMensajes.cpp. El sistema de mensajes empieza sin tener 
ningún jugador registrado. La función enviarMensaje requiere que esté registrado el jugador del 
identificador parámetro. Revisar la definición de la clase SistemaDeMensajes. Notar que por 
cuestiones de eficiencia, los jugadores se guardan como un arreglo de ConexionJugador*    */

SistemaDeMensajes::SistemaDeMensajes() {
    _conns[0] = nullptr;
    _conns[1] = nullptr;
    _conns[2] = nullptr;
    _conns[3] = nullptr;
}

/*void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (registrado(id)) {
        delete _conns[id];
        _conns[id] = nullptr;
    }
    _conns[id] = new ConexionJugador(ip);
}*/

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (registrado(id)) {
        desregistrarJugador(id);
    }
    _conns[id] = new ConexionJugador(ip);
}

// De este modo no me salta ningun error
void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id] -> enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr; //_conns[id] no lleva puntero, pues esto significaria que está definido
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id] -> ip();
}

/*EJERCICIO 2: Correr valgrind sobre el ejecutable ej1. Si no implementaron el destructor de la clase
SistemaDeMensajes::~SistemaDeMensajes(); es esperable que estén perdiendo memoria.
De ser necesario, implementar el destructor. Correr valgrind sobre el ejercicio 1 y asegurarse 
de que no devuelva errores.    */

SistemaDeMensajes::~SistemaDeMensajes(){
    for(int i=0; i<4; i++) {
        if (_conns[i] != nullptr) {  // borro sólo la memoria que está ocupada, no puedo borrar memoria que no es mia
            delete _conns[i];
        }
    }
    for (Proxy* p: proxys) { // EJC 5 recorro los puteros proxys en el vector de proxys, y los borro
        delete p;
    }
}

/* EJERCIIO 3: Queremos que el sistema de mensajes permita des-registrar un ip para un jugador 
existente. Esto implica eliminar la instancia de ConexionJugador. Además, queremos que se pueda 
registrar un ip nuevo para un ip ya registrado. Para ello es necesario crear una instancia nueva de 
ConexionJugador de forma de sobreescribir la original.
Implementar void SistemaDeMensajes::desregistrarJugador(int) y modificar
void SistemaDeMensajes::registrarJugador(int, string) para que si el jugador ya está registrado, 
lo actualice con el ip parámetro.
Correr los tests del ejercicio y luego correr valgrind para asegurarse de no estar perdiendo memoria
o tener otros errores.    */


void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

/* EJERCICIO 4: Agregar en SistemaDeMensajes.h el método Proxy* SistemaDeMensajes::obtenerProxy(int id);
que dado un id de jugador cree un proxy para este jugador y devuelva un puntero al mismo.  */
Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    Proxy* p = new Proxy(_conns[id]);  // Creo un puntero Proxy y le asigno el nuevo Proxy. Y este Proxy toma ConexionJugador
    proxys.push_back(p); // EJC 5, ir agregando los punteros proxys al vector de punteros
    return p;  // Devuelvo el puntero al proxy creado del jugador
}
