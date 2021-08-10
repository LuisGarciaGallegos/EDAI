'''
Examen: Programar un sistema indicador de color de semáforo COVID.
'''
import os
os.system("cls")
#Genero contadores de edad y de personas que tienen COVID
conta_si=0
conta_edad=0

#Abro el archivo, extraigo la información y la guardo en una variable en forma de lista
a=open("bd.csv",'r')
contenido=a.readlines()
a.close()

#Utilizo un for para poder recorrer los 100 elementos
for i in contenido:
	b=i #Obtengo la edad y el indicador 
	c=b.split(",") #Separo la edad y el indicador por comas
	d=float(c[1])#------> Guardo al Indicador y lo convierto en un float
	e=int(c[0])#------> Guardo la Edad y lo convierto en un int
	#Comparo el indicador para saber si tiene o no COVID
	if d>=0.8:
		#Guardo las personas que tiene COVID y su edad
		conta_si+=1
		conta_edad=conta_edad+e

#Comparo cuantas personas tienen COVID para saber el semforo
if conta_si==0:
	print("\nEl semforo esta en verde\n")
elif conta_si>0:
	print("\nEl semforo esta en Amarillo\n")
elif conta_si>30:
	print("\nEl semforo esta en Naranja\n")
elif conta_si>70:
	print("\nEl semforo esta en Rojo\n")

#Compruebo por lo menos que alguien tenga covid para obtener el promedio de edad de las
#personas que tienen COVID
if conta_si!=0:
	prom=conta_edad/conta_si
	print("La edad promedio de las personas que tiene covid son: "+str(prom))
else:
	print("Nadie tiene covid")


	
