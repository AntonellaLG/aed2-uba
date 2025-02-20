#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

uint Rectangulo::area() {
    return alto_*ancho_;
}

// Ejercicio 2

float PI = 3.14;

class Elipse {
public:
    Elipse(uint a, uint b);
    uint r_a();
    uint r_b();
    float area();

private:
    uint a_;
    uint b_;
};

Elipse::Elipse(uint a, uint b) : a_(r_a), b_(r_b) {};

uint Elipse::r_a() {
    return a_;
}

uint Elipse::r_b() {
    return b_;
}

float Elipse::area() {
    return PI * a_ * b_;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    r_ancho();
}

float Cuadrado::area() {
    r_area();
}

// Ejercicio 4

class Circulo {
    public:
        Circulo(uint radio);
        uint radio();
        float area();
    
    private:
        uint radio_;
};

Circulo::Circulo(uint radio) : radio_(radio) {};

uint Circulo::radio() {
    return radio_;
}

float Circulo::area() {
    return PI * radio_ * radio_;
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.ancho() << ", " << r.alto() << ")";
    return os;
}

ostream &operator<<(ostream &os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

ostream &operator<<(ostream &os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream &operator<<(ostream &os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}