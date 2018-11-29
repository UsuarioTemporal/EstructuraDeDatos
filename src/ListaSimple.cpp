#include<simplelist.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//ordenar
using namespace SimpleList;
Nodo *inicio=NULL;
Nodo *final=NULL;
void menu();
bool opciones(int);
int main(){
	system("color 0B");
	srand(time(NULL));
	for(int i=0;i<20;i++){
		insertToTheEnd(inicio,final,rand()%(101));
	}
	show(inicio);
	cout<<"\n";
//	ordenarSeleccion(inicio,final);
//	ordenarPorBurbuja(inicio,final);
//	shellSort(inicio);
	quickSort(inicio,final);
//	ordenarInsercion(inicio,final);
//	radix(inicio,final);
//	mergeSort(inicio);
//	inicio=quickSortRecur(inicio,final);
	show(inicio);
//	menu();
//	inicio=final=NULL;
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
		cout<<"6. Buscar "<<endl;
		cout<<"7. Ingresar dato en :  "<<endl;
		cout<<"8. Mostrar  "<<endl;
		cout<<"9. Cantidad de elementos  "<<endl;
		cout<<"10. Menor y mayor "<<endl;
		cout<<"11. Eliminar Nodos repetidos "<<endl;
		cout<<"12. ELIMINAR DOS PRIMEROS "<<endl;
		cout<<"13. eliminar pares "<<endl;
		cout<<"14. eliminar impares "<<endl;
		cout<<"15. Ordenar por burbuja "<<endl;
		cout<<"16. Eliminar Posicion par "<<endl;
		cout<<"17. Eliminar Posicion impar "<<endl;
		cout<<"18. Eliminar numeros primos "<<endl;
		cout<<"19. Invertir lista "<<endl;
		cout<<"20. limpiar "<<endl;
		cout<<"21. Salir "<<endl;
		int op;
		cout<<"\nOpcion : ";
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
			if(isEmpty(inicio)){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				deleteEspecific(inicio,final,dato);
			}
			break;
		case 6:
			if(isEmpty(inicio)){
				cout<<"\nVacio\n";
			}else{
				cin>>dato;
				buscar(inicio,final,dato);
			}
			break;
		case 7:
			if(!isEmpty(inicio)){
				int opcion;
				int datoSoA;
				cout<<"El valor que sera fijo : ";
				cin>>dato;
				cout<<"1.Antes"<<endl;
				cout<<"2.Despues"<<endl;
				cin>>opcion;
				cout<<"Ingrese el dato : ";
				cin>>datoSoA;
				insertarAntesODespues(inicio,final,dato,datoSoA,opcion);
			
			}else{
				cout<<"\nvacio\n";
			}
			break;
		case 8:
			show(inicio);
			break;
		case 9:
			contar(inicio);
			break;
		case 10:
			menorYMayor(inicio);
			break;
		case 11:
			eliminarRepetidos(inicio,final);
			break;
		case 12:
			eliminarDosprimeros(inicio,final);
			break;
		case 13:
			eliminarPares(inicio,final);
			break;
		case 14:
			eliminarImpares(inicio,final);
			break;
		case 15:
			ordenarPorBurbuja(inicio,final); 
			break;
		case 16:
			eliminarPosicionesPares(inicio,final);
			break;
		case 17:
			eliminarPosicionesImpares(inicio,final);
			break;
		case 18:
			eliminarNumerosPrimos(inicio,final);
			break;
		case 19:
			invertir(inicio,final);
			break;
		case 20:
			system("cls");
			break;
		default : 
			return true;
	}
	return false;
}

