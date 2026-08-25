#include "NodoUsuario.h"

NodoUsuario::NodoUsuario(Usuario* usuario) {
    dato = usuario;
    siguiente = nullptr;
}

void NodoUsuario::anadirUsuario(Usuario* usuario) {
    if (siguiente == nullptr) {
        siguiente = new NodoUsuario(usuario);
    } else {
        siguiente->anadirUsuario(usuario);
    }
}

void NodoUsuario::eliminarUsuario(int id) {
    if (siguiente == nullptr) {
        return;
    }
    if (siguiente->dato->getId() == id) {
        NodoUsuario* temporal = siguiente;
        siguiente = siguiente->siguiente;
        delete temporal;
    } else {
        siguiente->eliminarUsuario(id);
    }
}

Usuario* NodoUsuario::getUsuario(int id) {
    if (dato != nullptr && dato->getId() == id) {
        return dato;
    }
    if (siguiente != nullptr) {
        return siguiente->getUsuario(id);
    }
    return nullptr;
}
