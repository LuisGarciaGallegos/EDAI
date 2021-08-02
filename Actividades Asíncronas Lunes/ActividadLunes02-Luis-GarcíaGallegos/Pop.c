#include <stdio.h>
#include <stdlib.h>
#define p printf
#define s scanf

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};
void agregarPila(struct Nodo *, int);
void sacarPila(struct Nodo *, int);
int main(){
    struct Nodo *pila = NULL;
    int dato;
    
    p("Digite un numero: ");
    s("%d",&dato);
    agregarPila(pila,dato);
    
    p("Digite otro numero: ");
    s("%d",&dato);
    agregarPila(pila,dato);
    
    p("\nSacando los elementos de la Pila ");
    while(pila != NULL){
        sacarPila(pila,dato);
        if (pila != NULL){
            p("%d , ", dato);
        }
        else{
            p("%d.", dato);
        }
    }
    getch();
    return 0;
}
void agregarPila(struct Nodo *pila, int n){
    struct Nodo *nuevo_nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo_nodo ->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    p("\tElemento %d ha sido agregado a PIL correctamente \n", n);
}
void sacarPila(struct Nodo *pila, int n){
    struct Nodo *aux = pila;
    n = aux->dato;
    pila = aux -> siguiente;
    free(aux);
}
