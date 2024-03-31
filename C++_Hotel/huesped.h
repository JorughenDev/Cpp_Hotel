//
// Created by jorge on 11/15/2023.
//
#include <string>

using namespace std;

#ifndef ELMOCHILERORESERVA_HUESPED_H
#define ELMOCHILERORESERVA_HUESPED_H

class Huesped{
private:
    string nombre;
    char sexo;
public:
    Huesped(string _nombre, char _sexo);

    string get_nombre();
    char get_sexo();

    void set_nombre(string _nombre);
    void set_sexo(char _sexo);
};


#endif //ELMOCHILERORESERVA_HUESPED_H
