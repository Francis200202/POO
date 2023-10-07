#include <iostream>
#include <cstdlib>
#include "dados.h"

int main(){

	Dados d;
	int opt=0;

	std::cout<<"\nPRUEBA DADO1 al iniciar= " <<d.getDado1();
	std::cout<<"\nPRUEBA DADO2 al iniciar= " <<d.getDado2();

	std::cout<<"\nLanzamientos d1-> "<<d.getLanzamientos1();
	std::cout<<"\nLanzamientos d2-> "<<d.getLanzamientos2()<<"\n";

	d.lanzamiento();

	while(opt!=5){

			std::cout<<"\nLanzamientos d1-> "<<d.getLanzamientos1();
			std::cout<<"\nLanzamientos d2-> "<<d.getLanzamientos2()<<"\n";

			std::cout<<"\n1.Obtener dado 1\n2.Obtener dado 2\n3. Lanzamiento de los dos dados\n4. Obtener suma de los dos dados\n5. Salir\n";
			std::cout<<"\nOpcion: ";
			std::cin>>opt;
			std::cout<<"\n";
			

			switch(opt){

				case 1:
					std::cout<<"d1= " <<d.getDado1()<<"\n\n";
					break;

				case 2:
					std::cout<<"d2= " <<d.getDado2()<<"\n\n";
					break;

				case 3:
					d.lanzamiento();
					break;

				case 4:
					std::cout<<"Suma= " <<d.getSuma();
					break;

				case 5:
					std::cout<<"\n_Cerrando programa_\n";
					break;

				default:
					std::cout<<"\n_ERROR_\n";
					break;

			}

	}

}