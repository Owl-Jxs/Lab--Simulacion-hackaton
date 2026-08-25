#include "Menu.h"
#include "ControladorColas.h"

#include <iostream>
#include <limits>

using namespace std;

Menu::Menu()
{
    cantidadBoletosTotal = 500;
    controladorColas = new ControladorColas();
}

Menu::~Menu()
{
    delete controladorColas;
}

int Menu::leerOpcion()
{
    int opcion;

    while (true)
    {
        cin >> opcion;

        if (!cin.fail())
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return opcion;
        }

        cout << "Entrada invalida. Debe ingresar un numero: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Menu::MenuPrincipal()
{
    int opcion;

    do
    {
        cout << "\n========================================\n";
        cout << "        TICKET UNA - BOLETAJE\n";
        cout << "========================================\n";
        cout << "Entradas disponibles: "
             << cantidadBoletosTotal << "\n";
        cout << "----------------------------------------\n";
        cout << "1. Registrar comprador en fila\n";
        cout << "2. Atender siguiente comprador\n";
        cout << "3. Mostrar estado de las filas\n";
        cout << "4. Simulacion masiva\n";
        cout << "5. Salir\n";
        cout << "----------------------------------------\n";
        cout << "Seleccione una opcion: ";

        opcion = leerOpcion();

        switch (opcion)
        {
        case 1:
            MenuAdministrador();
            break;

        case 2:
            MenuProcesarCompra();
            break;

        case 3:
            MenuMostrarInfoColas();
            break;

        case 4:
            MenuSimularPruebas();
            break;

        case 5:
            cout << "\nGracias por utilizar Ticket UNA.\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 5);
}

void Menu::MenuAdministrador()
{
    cout << "\n========================================\n";
    cout << "       REGISTRAR COMPRADOR\n";
    cout << "========================================\n";

    controladorColas->registrarComprador();

    cout << "\nComprador registrado correctamente.\n";
}

void Menu::MenuProcesarCompra()
{
    cout << "\n========================================\n";
    cout << "        PROCESAR COMPRA\n";
    cout << "========================================\n";

    if (cantidadBoletosTotal <= 0)
    {
        cout << "\n*** SOLD OUT ***\n";
        cout << "No quedan entradas disponibles.\n";
        return;
    }

    bool ventaRealizada = controladorColas->atenderSiguiente();

    if (ventaRealizada)
    {
        cantidadBoletosTotal--;

        cout << "\nEntrada vendida correctamente.\n";
        cout << "Entradas restantes: "
             << cantidadBoletosTotal << "\n";

        if (cantidadBoletosTotal == 0)
        {
            cout << "\n*** SOLD OUT ***\n";
            cout << "Se han agotado todas las entradas.\n";
        }
    }
    else
    {
        cout << "\nNo hay compradores esperando en las filas.\n";
    }
}

void Menu::MenuMostrarInfoColas()
{
    cout << "\n========================================\n";
    cout << "          ESTADO DE LAS FILAS\n";
    cout << "========================================\n";

    controladorColas->mostrarEstado();
}

void Menu::MenuSimularPruebas()
{
    cout << "\n========================================\n";
    cout << "          SIMULACION MASIVA\n";
    cout << "========================================\n";

    controladorColas->simularCola();

    cout << "\nSimulacion finalizada.\n";
}

