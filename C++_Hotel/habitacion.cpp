#include "habitacion.h"
#include "string"

Habitacion::Habitacion(int _numero, float _tarifa,
                       string _tipo, int _piso_ubicaion, int _capacidad, Cama* _cama) {
    numero = _numero; tarifa = _tarifa; tipo = _tipo;
    piso_ubicacion = _piso_ubicaion; capacidad = _capacidad;cama = _cama;
}

Habitacion_privada::Habitacion_privada(int numero, float tarifa, string tipo, int pisoUbicaion, int capacidad,
                                       string _tipo_bano, Cama* _cama) : Habitacion(numero, tarifa, tipo, pisoUbicaion, capacidad, _cama) {
    tipo_bano = _tipo_bano;
}

Habitacion_compartida::Habitacion_compartida(int numero, float tarifa, string tipo, int pisoUbicaion, int capacidad,
                                             string _solomujeres, Cama* _cama, bool _num_cama_igual_8) : Habitacion(numero, tarifa, tipo, pisoUbicaion, capacidad, _cama) {
    solomujeres = _solomujeres;
    num_cama_igual_8 =_num_cama_igual_8;
}



//getters

int Habitacion::get_numero() {return numero;}
float Habitacion::get_tarifa() {return tarifa;}
string Habitacion::get_tipo() {return tipo;}
int Habitacion::get_piso_ubicacion() {return piso_ubicacion;}
int Habitacion::get_capacidad() {return capacidad;}
Cama *Habitacion::get_cama() {return cama;}

void Habitacion::set_capacidad(int _capacidad) {
    capacidad = _capacidad;
}

string Habitacion_privada::get_tipo_bano() {return tipo_bano;}
string Habitacion_compartida::get_solomujeres() {return solomujeres;}
bool Habitacion_compartida::get_num_cama_igual_8() {return num_cama_igual_8;}


