//guess.c
//Genera un numero "aleatorio", y el usuario tiene que adivinarlo

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
	
	int n, i=0;

	srand(time(NULL));

	n = (rand()%10)+1;

	while(i!=n){

		std::cout<< "Introduce un numero entre el 1 y 10 :\n";
		std::cin>> i;

		if(i>n){
			std::cout<<"\nPrueba con un numero menor\n";
		}else{
			if(i<n){
				std::cout<<"\nPrueba con un numero mayor\n";
			}
		}
	}
	
	std::cout<<"Numero correcto\n\n";

}