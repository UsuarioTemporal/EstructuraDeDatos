#include<iostream>
using namespace std;
template <class T> class Numeros{
	T dato1,dato2;
	public :
		Numeros(T dato1,T dato2){
			this->dato1=dato1;
			this->dato2=dato2;
		}
		T mayor(){
			return dato1>dato2 ? dato1: dato2;
		}
};
int main(){
	Numeros<int> hola(8,15);
	cout<<hola.mayor();
}
