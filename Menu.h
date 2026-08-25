#ifndef MENU_H
#define MENU_H

class ControladorColas;

class Menu
{
private:
    int cantidadBoletosTotal;
    ControladorColas* controladorColas;

    int leerOpcion();

public:
    Menu();
    ~Menu();

    void MenuPrincipal();
    void MenuAdministrador();
    void MenuProcesarCompra();
    void MenuMostrarInfoColas();
    void MenuSimularPruebas();
};

#endif