#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include "persona.h"
#include "jugador.h"
using namespace std;

/*void Jugador::getApuestas(){
	for (list<Apuesta>::iterator i = apuestas_.begin(); i != apuestas_.end(); ++i){
    	cout<<"Tipo: "<<i->tipo<<"  Valor: "<<i->valor<<"  Cantidad: "<<i->cantidad;
	}
}*/

void Jugador::setApuestas(){
    apuestas_.clear();
    Apuesta a;
	ifstream entrada(getDNI()+".txt"); 

    string tipo, valor, cantidad;
    int tip, cant;
    while(getline(entrada, tipo,',')){
        list<Apuesta>::iterator it;
        it = apuestas_.begin();
        getline(entrada, valor,',');
        getline(entrada, cantidad,'\n');
        cant=stoi(cantidad);
        tip=stoi(tipo);
        a.tipo=tip;
        a.valor=valor;
        a.cantidad=cant;
        apuestas_.push_back(a);
        it++; 
    }
    entrada.close();
}
