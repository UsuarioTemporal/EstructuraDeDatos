// ListaAb.cpp: Ejemplo de uso de plantilla para listas abiertas
// C con Clase: Marzo de 2002

#include <iostream>
#include "CCadena.h"
#include "ListaAb.h"
using namespace std;
 
// Plantilla de función que incrementa el valor del objeto
// dado como parámetro aplicando el operador ++
template<class DATO>
void Incrementar(DATO &d) {
   d++;
}

// Plantilla de función que mustra el valor del objeto
// dado como parámetro formando una lista separada con comas
template<class DATO>
void Mostrar(DATO &d) {
   cout << d << ", ";
}

int main() {
   // Declaración de una lista de enteros:
   Lista<int> ListaInt;

   // Inserción de algunos valores:
   ListaInt.InsertarFinal(43);
   ListaInt.InsertarFinal(65);
   ListaInt.InsertarFinal(33);
   ListaInt.InsertarFinal(64);
   ListaInt.InsertarFinal(22);
   ListaInt.InsertarFinal(11);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaInt.ParaCada(Mostrar); // Aplicamos la función Mostrar a cada elemento
   cout << endl << "-------------" << endl;

   // Incrementamos los valores de todos los elementos de la lista
   // aplicando a cada uno la función "Incrementar":
   cout << "---Incrementar todos---" << endl;
   ListaInt.ParaCada(Incrementar);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaInt.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;
   cin.get();

   // Borrar el primer elemento de valor 34:
   cout << "borrar 34" << endl;
   ListaInt.BorrarPrimerValor(34);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaInt.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;

   // Declaración de una lista de floats:
   Lista<float> ListaFloat;

   // Inserción de algunos valores:
   ListaFloat.InsertarFinal(43.2);
   ListaFloat.InsertarFinal(65.3);
   ListaFloat.InsertarFinal(33.1);
   ListaFloat.InsertarFinal(64.8);
   ListaFloat.InsertarFinal(22.32);
   ListaFloat.InsertarFinal(11.003);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaFloat.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;

   // Incrementamos todos:
   cout << "---Incrementar todos---" << endl;
   ListaFloat.ParaCada(Incrementar);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaFloat.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;

   cin.get();

   // Declaración de una lista de cadenas:
   Lista<Cadena> ListaCad;

   // Inserción de algunos valores, creando una lista ordenada:
   ListaCad.Insertar("alfa");
   ListaCad.Insertar("delta");
   ListaCad.Insertar("beta");
   ListaCad.Insertar("gamma");
   ListaCad.Insertar("delta");
   ListaCad.Insertar("epsilon");
   ListaCad.Insertar("sigma");
   ListaCad.Insertar("delta");

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaCad.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;
   cin.get();

   // Borramos todos los elementos de valor "delta":
   while(ListaCad.BorrarPrimerValor("delta")) {
      cout << "borrar 'delta'" << endl;
      // Mostrar lista:
      cout << "---listado---" << endl;
      ListaCad.ParaCada(Mostrar);
      cout << endl << "-------------" << endl;
      cin.get();
   }

   // Buscar el primer elemento de valor "gamma":
   cout << "buscar 'gamma'" << endl;
   if(ListaCad.BuscarPrimerValor("gamma"))
      cout << ListaCad.ValorActual() << endl;
   else
      cout << "No encontrado" << endl;

   // Declaración de una lista de enteros:
   Lista<int> ListaOrden;

   // Inserción de algunos valores, creando una lista ordenada:
   cout << "Lista ordenada de enteros" << endl;
   ListaOrden.Insertar(43);
   ListaOrden.Insertar(65);
   ListaOrden.Insertar(33);
   ListaOrden.Insertar(64);
   ListaOrden.Insertar(4);
   ListaOrden.Insertar(22);
   ListaOrden.Insertar(1);
   ListaOrden.Insertar(11);
   ListaOrden.Insertar(164);

   // Mostrar lista:
   cout << "---listado---" << endl;
   ListaOrden.ParaCada(Mostrar);
   cout << endl << "-------------" << endl;

   cin.get();
   return 0;
}
