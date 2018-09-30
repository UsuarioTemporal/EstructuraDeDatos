#include<simplelist.h>
using namespace DoubleList;
Nodo *inicio=NULL;
Nodo *final=NULL;
void menu();
bool opciones(int);
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar al comienzo "<<endl;
		cout<<"2. Insertar al final "<<endl;
		cout<<"3. Eliminar el inicio"<<endl;
		cout<<"4. Eliminar el final"<<endl;
		cout<<"5. Eliminar especifico"<<endl;
		cout<<"6. Mostrar "<<endl;
		cout<<"7. Salir "<<endl;
		int op;
		cin>>op;
		condition=!opciones(op);
	}while(condition);
}
bool opciones(int op){
	switch(op){
		int dato;
		case 1:
			cin>>dato;
			insertToTheStart(inicio,final,dato);
			break;
		case 2:
			cin>>dato;
			insertToTheEnd(inicio,final,dato);
			break;
		case 3:
			deleteToTheStart(inicio,final);
			break;
		case 4:
			deleteToTheEnd(inicio,final);
			break;
		case 5:
			cin>>dato;
			deleteEspecific(inicio,final,dato);
			break;
		case 6:
			show(inicio);
			break;
		default : 
			return true;
	}
	return false;
}
