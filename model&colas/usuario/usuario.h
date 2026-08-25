#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario {
private:
    string name;
    int id;
    string categoriaCliente;

public:
    Usuario(string name, int id, string categoriaCliente);
    string getName();
    int getId();
    string getCategoria();
};

#endif