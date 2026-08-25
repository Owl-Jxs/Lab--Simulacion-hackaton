#pragma once

#include "ColaUsuarios.h"

class ControladorColas {
private:
    ColaUsuarios* regular;
    ColaUsuarios* VIP;
    ColaUsuarios* preferencial;
    int contadorProcesosPrioritarios;  // Cuenta cuántos prioritarios consecutivos se han atendido
    static const int MAX_PRIORITARIOS = 3;  // Máximo de prioritarios antes de un regular

public:
    ControladorColas();
    ~ControladorColas();
    
    void agregarCliente(Usuario* usuario);
    Usuario* procesarCompra();
    string toString() const;
    
    // Método auxiliar para reiniciar el contador (por si se necesita)
    void reiniciarContadorPrioritarios();
};
