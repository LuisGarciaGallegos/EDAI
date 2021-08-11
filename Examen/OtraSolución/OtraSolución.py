'''
Examen: Programar un sistema indicador de color de semáforo COVID.
'''
import os

#Variables, contadores y listas
op='0'
datos=[]

#Realizo un ciclo para que la persona pueda agregar 100 muestras o más 
while(op!='2'):
	os.system("cls")

	#Menú
	print("\n1) Agregar persona\n2) Salir\n")
	op=input("Elige una opcion: ")

	if op=='1':
		#Datos de La persona
		edad=input("\nCual es su edad?: ")
		indi=input("\nEscriba su indicador: ")

		#Concatena los datos
		reg=edad+','+indi+'\n'

		#Agrega los datos a una lista
		datos.append(reg)
		os.system("cls")

	elif op=='2':
			
			#Sale del ciclo While
			print("\nGracias por usar mi programa :)")
			input("Presiona Enter para Continuar...")
			os.system("cls")

	else:

		#Cuando no ingresa una opcion valido le advierte y lo regresa al menú		print("\nOpción no valida :(")
		input("Presiona Enter para Continuar...")
		os.system("cls")

#Contadores para la edad y personas que tienen COVID
conta_si=0
conta_edad=0

#Abre el archivo y guarda los datos que se registraron en la lista datos
a=open("bd1.csv","a")
a.writelines(datos)
a.close()

#Abro el archivo, extraigo la información y la guardo en una variable en forma de lista
a=open("bd1.csv",'r')
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
print("Con los datos obtenidos sabemos lo siguiente: ")
if conta_si==0:
	print("\nEl semforo esta en verde\n")
