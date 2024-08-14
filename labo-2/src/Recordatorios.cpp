#include <iostream>

using namespace std;

using uint = unsigned int;
using Mensaje = unsigned string;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(uint mes, uint dia); // CHEQUEAR SI NECESITO VARIABLES m Y d PARA mes Y dia RESPECTIVAMENTE
    uint mes();               // MODIFICAR SEGUN CORRESPONDA LAS OTRAS CLASES (POR LO DE ARRIBA)
    uint dia();
    void incrementar_dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha f);
    #endif
    bool operator<(Fecha f);

  private:
    uint mes_;
    uint dia_;
};

Fecha::Fecha(uint mes, uint dia) : mes_(mes), dia_(dia){
}

uint Fecha::mes() {
    return this->mes_;
}

uint Fecha::dia() {
    return this->dia_;
}

void Fecha::incrementar_dia(){
    if (dia()<dias_en_mes(mes())) {
        dia_ = dia()+1;
    } else {
        dia_ = 1;
        mes_ = mes()+1;
    }
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha f) {
    return (this->dia_ == f.dia() && this->mes_ == f.mes());
}
#endif

bool Fecha::operator<(Fecha f) {
    return (this->mes_<f.mes()) || (this->mes_==f.mes() && this->dia_<f.dia());
}

// Ejercicio 11, 12

// Clase Horario

class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator==(Horario h);
        bool operator<(Horario h);

    private:
        uint hora_;
        uint min_;
};

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {
}

uint Horario::hora(){
    return this->hora_;
}

uint Horario::min(){
    return this->min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator==(Horario h) {
    return (this->hora_ == h.hora() && this->min_ == h.min());
}

bool Horario::operator<(Horario h) {
    return (this->hora_ < h.hora()) || (this->hora_==h.hora() && this->min_==h.min());
}

// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
    public:
        Recordatorio(Fecha fecha, Horario horario, Mensaje mensaje){
        Fecha fecha();
        Horario horario();
        Mensaje mensaje();

    private:
        Fecha fecha_;
        Horario horario_;
        Mensaje mensaje_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, Mensaje mensaje) : fecha_(fecha), 
                                                            horario_(horario), mensaje_(mensaje){
}

Fecha Recordatorio:: fecha(){
    return this-> fecha_;
}

Horario Recordatorio:: horario(){
    return this-> horario_;
}

Mensaje Recordatorio:: mensaje(){
    return this-> mensaje_;
}

ostream& operator<<(osteam& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14

// Clase Agenda

class Agenda {
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();
    
    private:
        list<Recordatorio> recordatorios_de_hoy_;
        Fecha hoy_;
};  

Agenda::Agenda(Fecha fecha_inicial) : hoy_(fecha_inicial) {
}

//void Agenda::agregar_recordatorio(Recordatorio rec) {
//    recordatorios_de_hoy_.push_back(rec);
//    recordatorios_de_hoy_.sort();
//}   Aca no estoy comparando fechas, solo agrego recordatorios y creo que asi está mal

void Agenda:: agregar_recordatorio(Recordatorio rec) {
    if (this -> rec.fecha_==hoy()) {  //estoy comparando fechas, tengo el operador == en la clase Fecha
        recordatorios_de_hoy_.push_back(rec);
    }
    recordatorios_de_hoy_.sort;
}

void Agenda:: incrementar_dia() {
    hoy_ = hoy()+1; // hoy_ es Fecha, y ya tengo incrementar_dia en Fecha.
}                   // otra opcion podria ser hoy_.incrementar_dia();

list<Recordatorio> Agenda:: recordatorios_de_hoy() {
    //return this -> recordatorios_de_hoy_;
    list<Recordatorio> recordatoriosDeHoy;
    for(Recordatorio rec : recordatorios_de_hoy()) {
        if( this -> rec.fecha_==hoy() ) {
            recordatoriosDeHoy.push.back_(rec);
        }
    }
    return recordatoriosDeHoy;
}

Fecha Agenda:: hoy() {
    return this -> hoy_;
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy();
    os << "=====";
    for (Recordatorio i: a.recordatorios_de_hoy()) {
        os << i;
    }
    return os;
}
