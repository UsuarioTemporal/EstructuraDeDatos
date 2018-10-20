// ListaAb.h: Plantilla para lista abierta ordenada
// C con Clase. (C) Marzo de 2002
// Plantilla para lista abierta
// Posibles mejoras:
// * Implementar constructor copia.

#ifndef _LISTAABIERTA_
#define _LISTAABIERTA_

template<class DATO>
class Lista {
  private:
   //// Clase local de Lista para Nodo de Lista:
   template<class DATON>
   class Nodo {
     public:
      // Constructor:
      Nodo(const DATON dat, Nodo<DATON> *sig) : dato(dat), siguiente(sig) {}
      // Miembros:
      DATON dato;
      Nodo<DATON> *siguiente;
   };

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo<DATO> *primero;
   Nodo<DATO> *actual;

  public:
   // Constructor y destructor básicos:
   Lista() : primero(NULL), actual(NULL) {}
   ~Lista();
   // Funciones de inserción:
   void InsertarFinal(const DATO dat);
   void InsertarPrincipio(const DATO dat);
   bool InsertarActual(const DATO dat);
   void Insertar(const DATO dat);
   // Funciones de borrado:
   void BorrarActual();
   bool BorrarPrimerValor(const DATO dat);
   // Función de búsqueda:
   bool BuscarPrimerValor(const DATO dat);
   // Comprobar si la lista está vacía:
   bool Vacia() { return primero==NULL; }
   // Devolver referencia al dato del nodo actual:
   DATO &ValorActual() { return actual->dato; }
   // Hacer que el nodo actual sea el primero:
   void Primero() { actual = primero; }
   // Comprobar si el nodo actual es válido:
   bool Actual() { return actual != NULL; }
   // Moverse al siguiente nodo de la lista:
   void Siguiente() { if(actual) actual = actual->siguiente; }
   // Sobrecargar operator++ en forma sufija para los mismo:
   void operator++(int) { Siguiente(); }
   // Aplicar una función a cada elemento de la lista:
   void ParaCada(void (*func)(DATO&));
};

//////// Implementación:

// Destructor
template<class DATO>
Lista<DATO>::~Lista() {
   while(!Vacia()) {
      actual = primero;
      primero = primero->siguiente;
      delete actual;
   }
}

template<class DATO>
void Lista<DATO>::InsertarFinal(const DATO dat) {
   Nodo<DATO> *ultimo;

   // Si la lista está vacía, insertar al principio:
   if(Vacia()) InsertarPrincipio(dat);
   else { // Si no lo está:
      // Buscar el último nodo:
      ultimo = primero;
      while(ultimo->siguiente) ultimo = ultimo->siguiente;
      // Insertar a continuación:
      ultimo->siguiente = new Nodo<DATO>(dat, NULL);
   }
}

template<class DATO>
void Lista<DATO>::InsertarPrincipio(const DATO dat) {
   primero = new Nodo<DATO>(dat, primero);
}

template<class DATO>
bool Lista<DATO>::InsertarActual(const DATO dat) {
   // Sólo si la lista no está vacía y actual es válido:
   if(!Vacia() && actual) {
      actual->siguiente = new Nodo<DATO>(dat, actual->siguiente);
      return true;
   }
   // Si no se puede insertar, retornar con false:
   return false;
}

// Insertar ordenadamente:
template<class DATO>
void Lista<DATO>::Insertar(const DATO dat) {
   Nodo<DATO> *temp = primero;
   Nodo<DATO> *anterior = NULL;

   // Si la lista está vacía, insertar al principio:
   if(Vacia()) InsertarPrincipio(dat);
   else {
      // Buscar el nodo anterior al primer nodo con un dato mayor qur 'dat'
      while(temp && temp->dato < dat) {
         anterior = temp;
         temp = temp->siguiente;
      }
      // Si no hay anterior, insertar al principio,
      // nuestro valor es el menor de la lista:
      if(!anterior)
         InsertarPrincipio(dat);
      else // Insertar:
         anterior->siguiente = new Nodo<DATO>(dat, temp);
   }
}

template<class DATO>
void Lista<DATO>::BorrarActual() {
   Nodo<DATO> *anterior;

   // Si el nodo actual es el primero:
   if(actual && actual == primero) {
      // El primer nodo será ahora el segundo:
      // Sacar el nodo actual de la lista:
      primero = actual->siguiente;
      // Borrarlo:
      delete actual;
      actual = NULL;
   } else
   if(actual && !Vacia()) {
      // Buscar el nodo anterior al actual:
      anterior = primero;
      while(anterior && anterior->siguiente != actual)
         anterior = anterior->siguiente;
      // Sacar el nodo actual de la lista:
      anterior->siguiente = actual->siguiente;
      // Borrarlo:
      delete actual;
      actual = NULL;
   }
}

// Borrar el primer nodo cuyo dato sea igual a 'dat':
template<class DATO>
bool Lista<DATO>::BorrarPrimerValor(const DATO dat) {
   Nodo<DATO> *anterior = NULL;
   Nodo<DATO> *temp = primero;

   if(!Vacia()) {
      // Si la lista no está vacía, buscar el nodo a borrar (temp)
      // y el nodo anterior a ese (anterior):
      while(temp && temp->dato != dat) {
         anterior = temp;
         temp = temp->siguiente;
      }
      // Si el valor está en la lista:
      if(temp) {
         // Si anterior es válido, no es el primer valor de la lista
         if(anterior) // Sacar nodo temp de la lista
            anterior->siguiente = temp->siguiente;
         else         // Ahora el primero es el segundo:
           primero = temp->siguiente;  // Borrar primer elemento
         // Borrar nodo:
         delete temp;
         return true; // Se ha encontrado y borrado dat
      }
   }
   return false; // valor no encontrado
}

// Busca el primer nodo con valor 'dat':
template<class DATO>
bool Lista<DATO>::BuscarPrimerValor(const DATO dat) {
   actual = primero;

   // Si la lista no está vacía:
   if(!Vacia()) {
      while(actual && actual->dato != dat) {
         actual = actual->siguiente;
      }
   }
   // Si el nodo es válido, se ha encontrado el valor:
   return actual != NULL;
}

// Aplicar una función a cada nodo de la lista:
template<class DATO>
void Lista<DATO>::ParaCada(void (*func)(DATO&)) {
   Nodo<DATO> *temp = primero;

   // Recorrer la lista:
   while(temp) {
      // Aplicar la función:
      func(temp->dato);
      temp = temp->siguiente;
   }
}

// La función "func" debe ser una plantilla de una función
// que no retorne valor y que admita un parámetro del mismo
// tipo que la lista:
// template <class DATO>
// void <funcion>(DATO d);

#endif
