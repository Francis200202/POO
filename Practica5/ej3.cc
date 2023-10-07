#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool descendent(int i, int j){return i>j;};

int main(void){
	int op;
	vector <int> v(5);
	srand(time(NULL));

	cout<<"Se va a rellenar el vector aleatoriamente de tam= "<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		v[i]=rand()%11;
		cout<<"v["<<i<<"]= "<<v[i]<<endl;;
	}

	for(vector<int>::iterator it= v.begin();it!=v.end();++it){
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"Elige como ordenar el vector:\n  1:Ascendente\n  2:Descendiente"<<endl;
	cin>>op;

	cout<<"Vector ordenado:"<<endl;

	if(op==1){
		sort(v.begin(),v.end());
	}else if(op==2){
		sort(v.begin(), v.end(), descendent);
	}

	for(int i=0;i<v.size();i++){
		cout<<"v["<<i<<"]= "<<v[i]<<endl;
	}

}