#include<iostream>
#include<conio.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&,int); //Prototipo de función
void sacarPila(Nodo *&,int &);	

int main (){
    Nodo *pila = NULL;
    int dato;
    cout <<"Digite un numero:  ";
    cin>>dato;
    agregarPila(pila,dato);

    cout <<"Digite otro numero: ";
    cin>>dato;
    agregarPila(pila,dato);
    
    cout<<"\nSacando los elementos de la Pila ";
    
    while(pila != NULL){
        sacarPila(pila,dato);
        if(pila != NULL){
        	cout<< dato <<" , ";
        }
        else{
        	cout<< dato <<".";
        }
    }	
			
    getch();
    return 0;
}
void agregarPila(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo(); //1. Crear el espacio en memoria para almacenar un nodo.
    nuevo_nodo->dato = n; //2. Cargar el valor dentro del nodo (dato).
    nuevo_nodo->siguiente = pila; //3. Cargar el puntero pila dentro del nodo (*siguiente)
    pila = nuevo_nodo; //4. Asignar el nuevo nodo a la pila.

    cout<<"\tElemento "<<n<<" ha sido agregado a PIL correctamente" <<endl;
}

void sacarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux ->siguiente;
    delete aux;
}
