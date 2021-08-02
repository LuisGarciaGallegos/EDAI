# El cifrado cesar.

import os # Libreria sirve para poder leer desda la consola.

#Declare una variable string de todo el Alfabeto y otra tipo entero para el menú
Alfabeto= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
opcion=0 

#Menú
while opcion !=3:
    print("¿Que desea hacer?")
    print("1. Encriptar un mensaje")
    print("2. Desencriptar un menaje")
    print("3. Salir")
    opcion = int(input("Ingrese una opción: "))
    if opcion == 1:
       
        #Lee el desplazamiento que servira para encriptar y el mensaje que se va a encriptar
        llave = int(input("Ingrese la llave (Es cuanto se recorre el alfabeto): "))
        mensaje  = input("Mensaje que se va a encriptar: ")

        # Primero es convertir todo a mayusculas o minusculas, para quedar deacuerdo a en un mismo formato.
        # Quitar tambien los espacio si es que hay
        mensaje = mensaje.replace(" ","")
        mensaje= mensaje.upper()

        # Creamos una variable vacia para el mensaje ya encriptado
        
        mensaje_encriptado = ""

        # Ciclo
        # La logica de programacion.
        #El ciclo ayuda a desplzar el mensaje para quedar encriptado
        for letra in mensaje:
          indice = Alfabeto.index(letra)+llave
          mensaje_encriptado = mensaje_encriptado+Alfabeto[indice % len(Alfabeto)]
        
        #Imprime el mensaje encriptado
        print("El mensaje Encriptado es: ", mensaje_encriptado)
        
        
    
    if opcion==2:
        
        #Lee el desplazamiento que servira para encriptar y el mensaje que se va a encriptar
        llave = int(input("Ingrese la llave (Es cuanto fue recorrido el alfabeto): "))
        mensaje_encriptado  = input("Mensaje que se va a desencriptado: ")

        # Primero es convertir todo a mayusculas o minusculas, para quedar deacuerdo a en un mismo formato.
        # Quitar tambien los espacio si es que hay
        mensaje_encriptado = mensaje_encriptado.replace(" ","")
        mensaje_encriptado= mensaje_encriptado.upper()

        # Creamos una variable vacia para el mensaje ya encriptado

        mensaje_desencriptado = ""

        # Ciclo
        # La logica de programacion.
        #El ciclo ayuda a desplzar el mensaje para quedar encriptado
        for letra in mensaje_encriptado:
          indice = Alfabeto.index(letra)-llave
          mensaje_desencriptado = mensaje_desencriptado+Alfabeto[indice % len(Alfabeto)]
        
        #Imprime el mensaje desencriptado
        print("El mensaje desencriptado es: ", mensaje_desencriptado)
print("Hasta pronto")
