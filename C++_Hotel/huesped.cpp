#include "huesped.h"

Huesped::Huesped(string _nombre, char _sexo) {
    nombre = _nombre; sexo = _sexo;
}

string Huesped::get_nombre() {return nombre;}

char Huesped::get_sexo() {return sexo;}

void Huesped::set_nombre(string _nombre) {nombre = _nombre;}

void Huesped::set_sexo(char _sexo) {sexo = _sexo;}

