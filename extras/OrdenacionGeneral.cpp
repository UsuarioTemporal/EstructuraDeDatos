#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>
using namespace std;

int numero=10;
int *array;
vector< vector<int> > Vec;
void show();
void selectionSort();
void bubbleSort();
void insertionSort();
void quickSortPivotePrimero(int [],int,int);
void quickSortPivoteCentro(int [],int,int);
void quickSortParecido(int [],int ,int);
void radixSort();
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
void shellSort(int[],int);

void heapSort();
int main(){
	array=new int[numero];
	int a[]={3,0,1,8,7,2,5,4,9,6};
	srand(time(NULL));
	for(int i=0;i<numero;i++){
		array[i]=10+rand()%(1191);
//		array[i]=a[i];
	}
	show();
//	selectionSort();
//	bubbleSort();
//	insertionSort();
//	quickSortPivotePrimero(array,0,numero-1);
//	quickSortPivoteCentro(array,0,numero-1);
//	quickSortParecido(array,0,numero-1);
//	radixSort();
//	mergeSort(array,0,numero-1);
//	shellSort(array,Countof(array));
	shellSort(array,numero);
	show();
	delete array;
}
void show(){
	cout<<"\n\n";
	for(int i=0;i<numero;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n\n";
}
void selectionSort(){
	for(int i=0;i<numero-1;i++){
		 for(int j=i+1;j<numero;j++){
		 	if(array[i]>array[j]){
		 		int aux=array[i];
		 		array[i]=array[j];
		 		array[j]=aux;
			 }
		 }
	}
}

void bubbleSort(){
	for(int i=0;i<numero;i++){
		for(int j=0;j<numero-1;j++){
			if(array[j]>array[j+1]){
				int aux=array[j+1];
		 		array[j+1]=array[j];
		 		array[j]=aux;
			}
		}
	}
}

void insertionSort(){
	for(int i=0;i<numero;i++){
		int j=i;
		while(j>0 && array[j-1]>array[j]){
			int aux=array[j-1];
			array[j-1]=array[j];
			array[j]=aux;
			j--;
		}
	}
}
void quickSortPivotePrimero(int array[],int primero,int ultimo){
	int i=primero,j=ultimo,pivote=array[primero];
//	int a[]={3,0,1,8,7,2,5,4,9,6};
	while(i<j){
		while(pivote<array[j]){
			j--;
		}
		
		while(pivote>=array[i] && j>i){
			i++;
		}
		
		if(i<j){
			int aux=array[i];
			array[i]=array[j];
			array[j]=aux;
		}
	}
	array[primero]=array[i];
	array[i]=pivote;
	if(primero<j-1){
		quickSortPivotePrimero(array,primero,j-1);
	}
	if(ultimo>i+1){
		quickSortPivotePrimero(array,i+1,ultimo);
	}
}
void quickSortPivoteCentro(int array[],int primero,int ultimo){
	int centro=(primero+ultimo)/2;
	int i=primero,j=ultimo,pivote=array[centro];
	while(i<j){
		while(pivote<array[j]){
			j--;
		}
		while(pivote>=array[i] && j>i ){
			i++;
		}
		if(i<j){
			int aux=array[i];
			array[i]=array[j];
			array[j]=aux;
		}
	}
	array[centro]=array[i];
	array[i]=pivote;
	
	if(primero<j-1){
		quickSortPivotePrimero(array,primero,j-1);
	}
	if(ultimo>i+1){
		quickSortPivotePrimero(array,i+1,ultimo);
	}
}
void quickSortParecido(int Vector[], int primero, int ultimo){
    int i = primero;
    int j = ultimo;
    int medio = Vector[(primero+ultimo)/2];
    do{
        while((Vector[i]< medio) && (j <= ultimo)){
            i++;
        }
        while((medio < Vector[j]) && (j > primero)){
            j--;
        }

        if(i<=j){
            int aux = Vector[i];
            Vector[i] = Vector[j];
            Vector[j] = aux;
            i++;
            j--;
        }
    } while(i<=j);

    if(primero < j){
        quickSortParecido(Vector,primero,j);
    }
    if(i < ultimo){
        quickSortParecido(Vector,i,ultimo);
    }
}

void radixSort(){
	Vec.resize(10);
	int temporal;
	int mayor=array[0];
	for(int i=0;i<numero;i++){
		if(mayor<array[i]){
			mayor=array[i];
		}
	}
	int conteo=0;
	while(mayor!=0){
		mayor/=10;
		conteo++;
	}
//	cout<<conteo;
	for(int i=0;i<conteo;i++){ //numero de digitos 
		int m=0;
		for(int j=0;j<numero;j++){
			temporal=(int)(array[j]/pow(10,i))%10;
			Vec[temporal].push_back(array[j]);
		}
		for(int k=0;k<10;k++){
			
			for(int l=0;l<Vec[k].size();l++){
				array[m]=Vec[k][l];
				m++;
			}
			Vec[k].clear();
		}
	}
}

void mergeSort(int arr[],int inicio,int final){
	if(final-inicio>0){
		int medio=(inicio+final)/2;
		mergeSort(arr,inicio,medio);
		mergeSort(arr,medio+1,final);
		merge(arr,inicio,medio,final);
	}
}


void merge(int arr[],int inicio,int medio,int final){
	//Estas variables se usaran en otros bucles 
	int i,j,k;
	
//	Mesclando dos subarrays de arr[]
//	Primer subarray es arr[inicio - medio]
//	Segundo subarray es arr[medio+1 -- final]
	int numTerArrIzq=medio-inicio+1;
	int numTerArrDer=final-medio;
	
//	Creacion de arrays
	int izquierda[numTerArrIzq],derecha[numTerArrDer];
	
	//Copiando los datos a sus respectivos campos o arrays
	for(i=0;i<numTerArrIzq;i++)
		izquierda[i]=arr[inicio+i];
	for(j=0;j<numTerArrDer;j++)
		derecha[j]=arr[medio+1+j];	
	i=j=0;
	k=inicio;
	while(i<numTerArrIzq && j<numTerArrDer){
		if(izquierda[i]<=derecha[j]){
			arr[k]=izquierda[i];
			i++;
		}else{
			arr[k]=derecha[j];
			j++;
		}
		k++;
	}
	
	//Agregando los elemento restantes
	while(i<numTerArrIzq){
		arr[k]=izquierda[i];
		i++;
		k++;
	}
	
	while(j<numTerArrDer){
		arr[k]=derecha[j];
		j++;
		k++;
	}
}
 	
 	void shellSort(int arr[], int n) {
	    for (int gap = n/2; gap > 0; gap /= 2){
	        for (int i = gap; i < n; i += 1){
	            int temp = arr[i];
	            int j; 
	            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
	                arr[j] = arr[j - gap]; 
	            arr[j] = temp; 
	        } 
	    }
	} 
