#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"


Dados::Dados(){
	d1_=1;
	d2_=1;
	l1_=0;
	l2_=0;
	s1_=0;
	s2_=0;
	for(int i=0;i<5;i++){ v1[i]=0; v2[i]=0;}
}

int Dados::getDado1(){

	return d1_;
}

int Dados::getDado2(){

	return d2_; 

}

bool Dados::setDado1(int num){

	if(num>0 && num <7){

		d1_=num;
		l1_++;
		s1_=s1_+d1_;

		for(int i=4;i>0;i--){

			v1[i]=v1[i-1];

		}
		v1[0]=d1_;

		return true;

	}else{

		std::cout<<"\n-ERROR en la asignacion al dado 1\n";
		return false;

	}


}

bool Dados::setDado2(int num){

	if(num>0 && num <7){

		d2_=num;
		l2_++;
		s2_=s2_+d2_;

		for(int i=4;i>0;i--){

			v2[i]=v2[i-1];

		}
		v2[0]=d2_;

		return true;
	}else{

		std::cout<<"\n-ERROR en la asignacion al dado 2\n";
		return false;

	}

}

void Dados::lanzamiento(){
	int n1, n2;

	srand(time(NULL));
	n1 = (rand()%6)+1;

	n2 = (rand()%6)+1;

	if(setDado1(n1)==true && setDado2(n2)==true){

		std::cout<<"\nDados lanzados con exito\n";

	}else{

		std::cout<<"\n-Fallo en el lanzamiento-\n";

	}
	

}

int Dados::getSuma(){

	return d1_+d2_;

}


int Dados::getDiferencia(){

 if(d1_>=d2_){

 	return d1_-d2_;

 }else{

 	return d2_-d1_;

 }

}


int Dados::getLanzamientos1(){

	return l1_;

}

int Dados::getLanzamientos2(){

	return l2_;

}

float Dados::getMedia1(){

	float media=0;

	if(l1_!=0){
		media=s1_/l1_;
	}

	return media;
}

float Dados::getMedia2(){

	float media=0;

	if(l2_!=0){
		media=s2_/l2_;
	}

	return media;
}


int Dados::getUltimos1(int *v){

	for(int i=0;i<5;i++){

		v[i]=v1[i];

	}

	return *v;
}


int Dados::getUltimos2(int *v){

	for(int i=0;i<5;i++){

		v[i]=v2[i];

	}

	return *v;
}
