#include "ControladorColas.h"
#include <sstream>
using namespace std;

ControladorColas::ControladorColas() 
    : regular(new ColaUsuarios()), 
      VIP(new ColaUsuarios()), 
      preferencial(new ColaUsuarios()),
      contadorProcesosPrioritarios(0) {}

ControladorColas::~ControladorColas() {
    delete regular;
    delete VIP;
    delete preferencial;
}

void ControladorColas::agregarCliente(Usuario* usuario) {
    switch (usuario->getCategoria()) {
        case CategoriaCliente::REGULAR:
            regular->encolarUsuario(usuario);
            break;
        case CategoriaCliente::VIP:
            VIP->encolarUsuario(usuario);
            break;
        case CategoriaCliente::PREFERENCIAL:
            preferencial->encolarUsuario(usuario);
            break;
    }
}

Usuario* ControladorColas::procesarCompra() {
    Usuario* usuarioAtendido = nullptr;
    
    // Verificar si podemos atender un prioritario
    // (menos de 3 prioritarios consecutivos Y hay clientes prioritarios)
    if (contadorProcesosPrioritarios < MAX_PRIORITARIOS) {
        // Intentar atender preferencial primero (tienen prioridad sobre VIP)
        if (!preferencial->estaVacia()) {
            usuarioAtendido = preferencial->desencolarUsuario();
            contadorProcesosPrioritarios++;
        }
        // Si no hay preferenciales, intentar VIP
        else if (!VIP->estaVacia()) {
            usuarioAtendido = VIP->desencolarUsuario();
            contadorProcesosPrioritarios++;
        }
    }
    
    // Si no se atendió a nadie prioritario (o ya llevamos 3 prioritarios)
    if (usuarioAtendido == nullptr) {
        // Intentar atender un cliente regular
        if (!regular->estaVacia()) {
            usuarioAtendido = regular->desencolarUsuario();
            contadorProcesosPrioritarios = 0;  // Reiniciar contador después de un regular
        }
        // Si no hay regulares, podemos atender prioritarios aunque ya hayamos atendido 3
        else if (!preferencial->estaVacia()) {
            usuarioAtendido = preferencial->desencolarUsuario();
            contadorProcesosPrioritarios++;
        }
        else if (!VIP->estaVacia()) {
            usuarioAtendido = VIP->desencolarUsuario();
            contadorProcesosPrioritarios++;
        }
    }
    
    return usuarioAtendido;
}

string ControladorColas::toString() const {
    stringstream ss;
    ss << "=== Estado del Sistema ===" << endl;
    ss << "REGULAR: " << regular->getCantidadUsuarios() << " clientes" << endl;
    ss << "VIP: " << VIP->getCantidadUsuarios() << " clientes" << endl;
    ss << "PREFERENCIAL: " << preferencial->getCantidadUsuarios() << " clientes" << endl;
    ss << "Prioritarios atendidos consecutivos: " << contadorProcesosPrioritarios << "/" << MAX_PRIORITARIOS;
    return ss.str();
}

void ControladorColas::reiniciarContadorPrioritarios() {
    contadorProcesosPrioritarios = 0;
}
