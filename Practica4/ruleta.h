#ifndef _RULETA_H_
#define _RULETA_h_
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <fstream>
#include <ctime>
#include "crupier.h"
#include "jugador.h"

using namespace std;

class Ruleta{
	private:
		int banca_;
		int bola_;
		list <Jugador> jugadores_;
		Crupier crupier_;
	public:
		Ruleta(Crupier c) : crupier_(c){
			bola_=-1;
			banca_=1000000;
			srand(time(NULL));
		}
		inline int getBanca() const {return banca_;};
		inline bool setBanca(int banca){if(banca>0){banca_=banca;return true;}else{return false;}};
		inline int getBola() const {return bola_;};
		inline bool setBola(int bola){if(bola>=0 && bola<=36){bola_=bola;return true;}else{return false;}};
		inline Crupier getCrupier() const {return crupier_;};
		inline void setCrupier(const Crupier &crupier){crupier_=crupier;};
		inline list<Jugador> getJugadores() const {return jugadores_;};
		bool addJugador(const Jugador &j);
		int deleteJugador(string dni);
		int deleteJugador(const Jugador &j);
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta();
		void getPremios();
		void getEstadoRuleta(const Jugador &j);

};
#endif