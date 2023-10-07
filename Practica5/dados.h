#ifndef _DADOS_
#define _DADOS_

class Dados{

	private:
		int d1_;
		int d2_;
		int l1_;
		int l2_;
		float s1_;
		float s2_;
		int v1[5];
		int v2[5];

	public:
		Dados();
		void lanzamiento();
		int getDado1();
		int getDado2();
		bool setDado1(int num);
		bool setDado2(int num);
		int getSuma();
		int getDiferencia();
		int getLanzamientos1();
		int getLanzamientos2();
		float getMedia1();
		float getMedia2();
		int getUltimos1(int *v);
		int getUltimos2(int *v);

		friend ostream &operator<<(ostream &stream, Dados &d);//Insertador
		friend istream &operator>>(istream &stream, Dados &d);//Extractor

};

#endif