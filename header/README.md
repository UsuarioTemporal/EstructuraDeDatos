# **ÁRBOL BINARIO**
## **CONCEPTO**
La estructura árbol es muy ultilizada para fines de matemática donde se involucra el álgebra,
tambien en inteligencia artificial y algoritmos de cifrado .
Un Árbol no es una estrutura lineal , pues consta de subnodos llamados hijos y cada hijo se representa como un subarbol , entonces esta estructura se puede definir como una estructura recursiva.
Existen varios métodos y varios algoritmos para representar un árbol.

En este caso se trabajará en el lenguaje c++ 

## **CURIOSIDADES**
Un arbol consta de un conjunto finitos de elementos denominados nodos y un conjunto finito de lineas denominados ramas , que conectan los nodos

**Cantidad totales de nodos y de ramas**
> numeroRamas = numeroNodos - 1

### **Longitud de camino**
Esto indicara el numero de ramas que se tiene que pasar para llegar al nodo indicado.
Esto se calculara de la siguiente manera :
La cantidad de nodos a recorrer hasta llegar al nodo querido menos 1 


### **Altura de un nodo**
Esto se contara la cantidad de nodos que hay o que existen desde el nodo querido hasta la raiz menos 1

### **Profundidad de un nodo o tambien denominado nivel**
Se contara el numero de nodos hasta llegar al nodo querido

### **Orden**
La máxima cantidad de hijos que puede tener un nodo

````c++
    // Tener en cuenta siempre que debes saber cual es el padre de 
    //un nodo hijo 
````

## **IMPLEMENTACIÓN**
Para crear un arbol se debe de tomar en cuenta lo siguiente :
- Cada ves que insertamos un dato es decir creamos un nodo de la misma familia de la raiz (Esto quiere decir que toma las caracteristicas de cada nodo), debemos tener en cuenta si el arbol esta o no esta vacia.
- Cuando nos damos cuenta que esta vacio entonces el primer nodo insertado a la estructura debe ser el padre de todos es decir la ***RAÍZ***
- Cuando nos damos cuenta que no esta vacio entonces debemos de tomar dos deciciones 
    - Cuando el elemento insertado es menor que la raiz entonces se ira para la izquierda 
    - cuando el elemento insertado es mayor o igual se ira para de la derecha 

Todo lo demas se resolverá con recursividad , por lo pronto esto es lo mas básico que debes saber para poder entender



````java 
    /*
    * Autor : Thom Maurick Roman Aguilar
    * Estudiante  de la carrera Ingeniería de Sistemas
    */
````