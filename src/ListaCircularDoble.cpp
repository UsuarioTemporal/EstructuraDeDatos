#include<circledoublelist.h>
using namespace CircleDoubleList;
Nodo *ultimo=NULL;
void menu();
bool opciones(int);
int main(){
	menu();
	return 0;
}
void menu(){
	bool condition=true;
	do{
		cout<<"\n1. Insertar"<<endl;
		cout<<"2. Eliminar especifico"<<endl;
		cout<<"3. Mostrar "<<endl;
		cout<<"4. Limpiar "<<endl;
		cout<<"5. Salir "<<endl;
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
			insert(ultimo,dato);
			break;
		case 2:
			cin>>dato;
			deleteEspecific(ultimo,dato);
			break;
		case 3:
			show(ultimo);
			break;
		case 4:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}
