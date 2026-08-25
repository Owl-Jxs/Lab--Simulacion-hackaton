#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include "../model&colas/usuario/Usuario.h"

class NodoUsuario {
private:
    Usuario* dato;
    NodoUsuario* siguiente;

public:
    NodoUsuario(Usuario* usuario);
    void anadirUsuario(Usuario* usuario);
    void eliminarUsuario(int id);
    Usuario* getUsuario(int id);
};

#endif