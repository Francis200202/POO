#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <fstream>
#include <string>
#include <ctime>
#include "ruleta.h"
#include "crupier.h"

bool Ruleta::addJugador(const Jugador &j){
	string dni=j.getDNI();
	for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); ++i){
        if(dni==i->getDNI()){
            return false;
        }
    }
        jugadores_.push_back(j);
    	ifstream f;
		f.open(dni+".txt");
		if(!f){
			f.close();
			ofstream f(dni+".txt"); 
			f.close();
			return true;
		}else{
			return true;
    }
}

int Ruleta::deleteJugador(string dni){
	int cont=0;
	for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); ++i){
        if(dni==i->getDNI()){
        	i=jugadores_.erase(i);
            return 1;
        }
        cont++;
    }
    if(cont==0){
    	return -1;
    }else{
    	return -2;
    }
}

int Ruleta::deleteJugador(const Jugador &j){
	string dni=j.getDNI();
	for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); ++i){
        if(dni==i->getDNI()){
        	i=jugadores_.erase(i);
            return 1;
        }
    }
    if(jugadores_.size()==0){
    	return -1;
    }else{
    	return -2;
    }
}

void Ruleta::escribeJugadores(){
	string dinero, edad, escribir;
	ofstream f("jugadores.txt");
    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); ++i){
        dinero=to_string(i->getDinero());
        edad=to_string(i->getEdad());
        escribir=i->getDNI()+","+i->getCodigo()+","+i->getNombre()+","+i->getApellidos()+","+edad+","+i->getDireccion()+","+i->getLocalidad()+","+i->getProvincia()+","+i->getPais()+","+dinero+"\n";
        f.write(escribir.data(), escribir.size());
    }
    f.close();
}

void Ruleta::leeJugadores(){
	string DNI, cod, nom, ap, dir, loc, prov, pais;
    char din[255];
	int dinero;
	jugadores_.empty();
    ifstream entrada("jugadores.txt"); 
	list<Jugador>::iterator it;
        it = jugadores_.begin();
        while(getline(entrada, DNI,',')){
            getline(entrada, cod,',');
            getline(entrada, nom,',');
            getline(entrada, ap,',');
            getline(entrada, dir,',');
            getline(entrada, loc,',');
            getline(entrada, prov,',');
            getline(entrada, pais,',');
            entrada.getline(din, 255,'\n');
            dinero=atoi(din);

            Jugador j(DNI, cod, nom, ap, 0, dir, loc, prov, pais);
            j.setDinero(dinero);
            jugadores_.push_back(j);
        }
}

void Ruleta::giraRuleta(){
    int num;
    num = (rand()%37);
    if(setBola(num)==true){
        //cout<<"La ruleta ha girado correctamente, Num= "<<num<<endl;
    }else{
        cout<<"Error al girar la ruleta"<<endl;
    }
}



void Ruleta::getPremios(){
    for(list<Jugador>::iterator i = jugadores_.begin(); i != jugadores_.end(); ++i){
        i->setApuestas();
        list<Apuesta> apuestas = i->getApuestas();
        for(list<Apuesta>::iterator it = apuestas.begin(); it != apuestas.end(); ++it){
            switch(it->tipo){
                case 1:
                    if(stoi(it->valor)==getBola()){
                        i->setDinero(i->getDinero() + 35 * it->cantidad);
                        setBanca(getBanca() - 35 * it->cantidad);
                    }else{
                        i->setDinero(i->getDinero() - it->cantidad);
                        setBanca(getBanca() + it->cantidad);
                    }
                    break;
                case 2:
                    if(it->valor=="rojo"){
                        if(getBola()==(1|3|5|7|9|12|14|16|18|19|21|23|25|27|30|32|34|36)){//Numeros en rojo de una ruleta
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(getBanca() + it->cantidad);
                        }
                    }else if(it->valor=="negro"){
                        if(getBola()!=(0|1|3|5|7|9|12|14|16|18|19|21|23|25|27|30|32|34|36)){
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(banca_ + it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }
                    }
                    break;
                case 3:
                    if(it->valor=="par"){
                        if(getBola()%2==0 && getBola()!=0){
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(getBanca() + it->cantidad);
                        }
                    }else if(it->valor=="impar"){
                        if(getBola()%2!=0){
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(getBanca() + it->cantidad);
                        }
                    }
                    break;
                case 4:
                    if(it->valor=="alto"){
                        if(getBola()>=19 && getBola()<=36){
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(getBanca() + it->cantidad);
                        }
                    }else if(it->valor=="bajo"){
                        if(getBola()>=1 && getBola()<=18){
                            i->setDinero(i->getDinero() + it->cantidad);
                            setBanca(getBanca() - it->cantidad);
                        }else{
                            i->setDinero(i->getDinero() - it->cantidad);
                            setBanca(getBanca() + it->cantidad);
                        }
                    }
                    break;
            }
        }
    }
}