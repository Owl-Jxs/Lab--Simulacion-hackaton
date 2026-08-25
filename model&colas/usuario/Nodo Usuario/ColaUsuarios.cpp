#include "ColaUsuarios.h"

ColaUsuarios::ColaUsuarios() : cabeza(nullptr), cola(nullptr), cantidadUsuarios(0) {}

ColaUsuarios::~ColaUsuarios() {
	while (!estaVacia()) {
		Usuario* usuario = desencolarUsuario();
		delete usuario;
	}
}

Usuario* ColaUsuarios::encolarUsuario(Usuario* usuario) {
	nodoUsuario* nuevoNodo = new nodoUsuario(usuario);

	if (estaVacia()) {
		cabeza = nuevoNodo;
		cola = nuevoNodo;
	}
	else {
		cola->siguiente = nuevoNodo;
		cola = nuevoNodo;
	}

	cantidadUsuarios++;
}

void ColaUsuarios::desencolarUsuario() {
	if (estaVacia()) { return nullprt; }

	nodoUsuario* nodoAEliminar = cabeza;
	Usuario* usuario = cabeza->datos;

	cabeza = cabeza->siguiente;

	if (cabeza == nullptr) {
		cola = nullptr;
	}

	delete nodoAEliminar;
	cantidadUsuarios--;

	return usuario;
}

int ColaUsuarios::getCantidadUsuarios() {
	return cantidadUsuarios;
}

bool ColaUsuarios::estaVacia() {
	return cantidadUsuarios == 0;
}