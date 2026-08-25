#include "System.h"
#include "Menu.h"

System::System()
{
    MenuPrincipal = new Menu();

}
System::~System()
{
    delete MenuPrincipal;
}
void System::ejecutar(){
    MenuPrincipal->MenuPrincipal();
}