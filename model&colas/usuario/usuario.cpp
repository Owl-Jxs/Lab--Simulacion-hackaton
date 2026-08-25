#include "Usuario.h"

Usuario::Usuario(string name, int id, string categoriaCliente) {
    this->name = name;
    this->id = id;
    this->categoriaCliente = categoriaCliente;
}

string Usuario::getName() {
    return name;
}

int Usuario::getId() {
    return id;
}

string Usuario::getCategoria() {
    return categoria;
}
