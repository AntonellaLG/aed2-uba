#ifndef ALGO2_LABO_DICCIONARIO_HPP // esta bien esto??
#define ALGO2_LABO_DICCIONARIO_HPP

// EJERCICIO 5
/*Los archivos Diccionario.h y Diccionario.cpp proveen una implementación básica de diccionario 
representado sobre un arreglo de asociaciones. Sus claves y valores son ambos de tipo int.
Adaptar la implementación de la clase Diccionario para que sea genérica y dependa de dos parámetros
class Clave y class Valor. Para esto, crear un nuevo archivo Diccionario.hpp en la carpeta src/.
*/

template<class Clave, class Valor>
class Diccionario {
public:
	Diccionario();
	void definir(Clave k, Valor v);
	bool def(Clave k) const;
	Valor obtener(Clave k) const;

private:

	struct Asociacion {
		Asociacion(Clave k, Valor v);
		Clave clave;
		Valor valor;
	};
	std::vector<Asociacion> _asociaciones;
};


template<class Clave, class Valor> //asi o template<class Diccionario> ??
Diccionario<Clave,Valor>::Diccionario() {
}

template<class Clave, class Valor>
Diccionario<Clave,Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

//La definición fuera de línea de 'definir' no coincide con ninguna declaración en 'Diccionario'
template<class Clave, class Valor>
void Diccionario<Clave,Valor>::definir(Clave k, Valor v) {
	for(unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			_asociaciones[i].valor = v;
			return;
		}
	}
	_asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave,Valor>::def(Clave k) const {
	for ( unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return true;
		}
	}
	return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave,Valor>::obtener(Clave k) const {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return _asociaciones[i].valor;
		}
	}
	assert(false);
}

#endif