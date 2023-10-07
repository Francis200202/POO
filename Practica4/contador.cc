#include <iostream>
#include <cstdio>
#include <list>
#include "contador.h"

using namespace std;

void Contador::controlLim(){
	if(valor_>max_) valor_=max_;
	else if(valor_<min_) valor_=min_;
	cambios_.push_back(valor_);
}

Contador Contador::operator=(const Contador &c){
	valor_=c.valor_;
	max_=c.max_;
	min_=c.min_;
	cambios_.push_back(valor_);
	return *this;
}

Contador Contador::operator=(const int &i){
	valor_=i;
	controlLim();
	return *this;
}

Contador Contador::operator++(void){
	valor_++;
	controlLim();
	return *this;
}

Contador Contador::operator++(int){
	Contador temp(*this);
	valor_++;
	controlLim();
	return temp;
}

Contador Contador::operator--(void){
	valor_--;
	controlLim();
	return *this;
}

Contador Contador::operator--(int){
	Contador temp(*this);
	valor_--;
	controlLim();
	return temp;
}

Contador Contador::operator+(const int &i){
	valor_+=i;
	controlLim();
	return *this;
}

Contador operator+(const int &i, const Contador &c){
	Contador temp(c);
	temp.valor_+=i;
	temp.controlLim();
	return temp;
}

Contador Contador::operator-(const int &i){
	valor_=valor_-i;
	controlLim();
	return *this;
}

Contador operator-(const int &i, const Contador &c){
	Contador temp(c);
	temp.valor_=i-temp.valor_;
	temp.controlLim();
	return temp;
}

bool Contador::undo(int n){
	if(n >= (int) cambios_.size() || n<1) return false;
	for(int i=0; i<n; i++){
		cambios_.pop_back();
	}
	valor_=cambios_.back();
	return true;
}