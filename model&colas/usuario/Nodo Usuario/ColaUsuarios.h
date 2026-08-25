#pragma once
#include "Usuario.h"
#include "nodoUsuario.h"

class ColaUsuarios {
private:
	nodoUsuario* cabeza;
	nodoUsuario* cola;
	int cantidadUsuarios;

public:
	ColaUsuarios();
	~ColaUsuarios();

	// metodos de la cola
	void encolarUsuario(Usuario* usuario);
	Usuario* desencolarUsuario();
	int getCantidadUsuarios() const;
	bool estaVacia() const;
};