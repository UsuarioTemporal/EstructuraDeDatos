# **INTRODUCCIÓN A GRAFOS**
## **Definición de grafos**
Un grafo son elementos o conjuntos que se comunican para adquirir y/o enviar información.
En programación es común llamar objetos a los nodos , pues son los elementos que forman una red o en este caso un grafo , cada objeto se comunicará
con otro y este otro a uno adyacente y asi sucesivamente .
En conclusión los grafos son la mejor forma de comunicar a los objetos para la transferencia de información.

## **Teoría de grafos** 
También conocida como teroría de gráficas , es uno mas de los estudios que todo
programador amante a la programcion funcional debe dominar , son muy usados en en 
ambiente de machine learning .
Matematicamente estudiar los grafos puede ser un poco complejo por las notaciones , un grafo tiene dos elementos principales : **G = (V,E)**

**G = (V,E)** , V significa un conjunto no vacio de de vértices , E un conjunto de aristas .Donde E consta de pares no ordenados de vertices , tales como (x,y) pertenece a E entonces se concluye que x e y son adyacente 

Normalmente un grafo se represente por la union de dos objetos o vertices uniendos estas dos por una linea no direccionada , pero si esta misma lleva un dirección será denominado un grafo dirigido donde se le conocerá como digrafo y los conjuntos que forman esta arista direccionada se conocerá como par ordenado

> fuente wikipedia : https://es.wikipedia.org/wiki/Teor%C3%ADa_de_grafos

## **Elementos de un grafo**
- Aristas : lineas con o sin dirección que uniran a los nodos u objetos (vertices del grafo)
    - Aristas adyacente : 2 aristas son adyacentes si convergen en el mismo vétice , es decir parten o se dirigen al mismo vertice
    -  Aristas paralelas : dos aristas son paraletas si si su vertice final e inicial son los mismos
    -  Aristas cíclicas : --><-- sale para volver a entrar 
    -  Cruce : aristas que cruzan por el mismo vertice
- Vertices : Objetos , nodos , elementos que forman un grafo 

## **Representación de grafos**
Para representar los grafos la mejor manera es manipularlo como listas y las matrices , aunque se recomienda usar ambas.
### **Lista de adyacencia**
Es una representación de todas las aristas o arcos de un grafo mediante una lista
Si el grafo es no dirigido , cada entrada es un conjunto o multiconjunto de
dos vertices conteniendo los dos extremos de la arista correspondiente.Si el grafo es dirigido , cada entrada es una tupla
de dos nodos , uno denotado el nodo fuente y el otro denotando el nodo destino del arco correspondiente
### **Lista de grados**
Es una secuencia de numeros que corresponde a los grupos de los vertices del grafo


## **Multigrafo**
Si dice que G es un multigrafo si se permite que entre un mismo par de vertices se trace más de una arista , u un pseudografo si se permiten aristas de tipo(v,v)

## **Vecindarios**
Un vertice v es adyacente a otro vertice w en G si (v,w) pertenece a E(G) 
El vencidario de un vertice v en un grafo G es el conjunto



````python
    # Estudiante de la carrera Ingenieria de Sistemas
    # Autor : Thom Maurick Roman Aguilar
````
