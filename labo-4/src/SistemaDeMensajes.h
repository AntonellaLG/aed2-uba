#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include "Proxy.h"   // lo agregué para el EJC 4
#include <string>
#include <vector>   // lo agregué para el EJC 5

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    // Pre: registrado(id)
    void desregistrarJugador(int id);

    ~SistemaDeMensajes(); // para EJC 2

    Proxy* obtenerProxy(int id); // para EJC 4

  private:
    ConexionJugador* _conns[4];  // _conns[4] el arreglo con 4 lugares

    vector<Proxy*> proxys; //EJERCICIO 5

};


#endif
