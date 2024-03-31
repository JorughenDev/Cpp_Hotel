#include <string>
using namespace std;
#ifndef ELMOCHILERORESERVA_CAMA_H
#define ELMOCHILERORESERVA_CAMA_H
class Cama {
private:
    string tipo;
    string ubicacion;
    bool ocupada;
    int numero;
public:
    //constructor
    Cama(string _tipo, string _ubicacion, bool _ocupada, int _numero);
    //getters
    string get_tipo();
    string get_ubicacion();
    bool get_ocupada();
    int get_numero();
    //setters
    void set_tipo(string _tipo);
    void set_ubicacion(string _ubicacion);
    void set_ocupada(bool _ocupado);
    void set_numero(int _numero);
};
#endif //ELMOCHILERORESERVA_CAMA_H
