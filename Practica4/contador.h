#ifndef _CONTADOR_H_
#define _CONTADOR_H_

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class Contador{
	private:
		int valor_;
		int min_;
		int max_;
		list<int> cambios_;
		void controlLim();
	public:
		Contador(int valor=0, int min=0, int max=1000){
			if(valor>max || valor<min || min>max){
				valor=0;
				min=0;
				max=1000;
			}
			valor_=valor;
			max_=max;
			min_=min;
			cambios_.push_back(valor_);
		}
		Contador operator=(const Contador &c);
		Contador operator=(const int &i);
		Contador operator++(void); //prefijo ++c
		Contador operator++(int); //sufijo c++
		Contador operator--(void); //prefijo --c
		Contador operator--(int); //sufijo c--
		Contador operator+(const int &i);
		Contador operator-(const int &i);

		friend Contador operator+(const int &i, const Contador &c);
		friend Contador operator-(const int &i, const Contador &c);

		bool undo(int n=1);
		inline int get() const {return valor_;};
};

#endif