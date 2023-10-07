#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include "persona.h"
using namespace std;

struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador:public Persona{
	private:
		int dinero_=1000;
		string codigo_;
		list <Apuesta> apuestas_;
	public:
		Jugador(string DNI, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="", int dinero=1000):Persona(DNI, nombre, apellidos, edad, direccion, localidad, provincia, pais){
			codigo_=codigo; dinero_=dinero;
		};
		inline string getCodigo(){return codigo_;};
		inline void setCodigo(string codigo){codigo_=codigo;};
		inline int getDinero(){return dinero_;};
		inline void setDinero(int dinero){dinero_=dinero;};
		inline list<Apuesta> getApuestas(){return apuestas_;};
		void setApuestas();
};
#endif