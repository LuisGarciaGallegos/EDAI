#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};
void agregarPila(struct Nodo *, int);
int main(){
    struct Nodo *pila= NULL;
    int n1,n2;
    
    p("Digite un numero ");
    s("%d",&n1);
    agregarPila(pila,n1);
    
    p("Digite otro numero ");
    s("%d",&n2);
    agregarPila(pila,n2);

}
void agregarPila(struct Nodo *pila, int n){
    struct Nodo *nuevo_nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo_nodo ->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    p("\nElemento %d agregado a la Pila correctamente \n", n);
}
