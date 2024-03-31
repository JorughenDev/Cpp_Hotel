#include "cama.h"

//constructor
Cama::Cama(string _tipo, string _ubicacion, bool _ocupada, int _numero) {
    tipo = _tipo; ubicacion = _ubicacion; ocupada = _ocupada; numero = _numero;
}
//getters
string Cama::get_tipo() {return  tipo;}

string Cama::get_ubicacion() {return ubicacion;}

bool Cama::get_ocupada() {return ocupada;}

int Cama::get_numero() {return numero;}

//setters

void Cama::set_tipo(string _tipo) {tipo = _tipo;}

void Cama::set_ubicacion(string _ubicacion) {ubicacion = _ubicacion;}

void Cama::set_ocupada(bool _ocupado) {ocupada = _ocupado;}

void Cama::set_numero(int _numero) {numero = _numero;}




