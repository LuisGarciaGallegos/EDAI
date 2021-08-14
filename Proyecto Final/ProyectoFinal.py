'''
Sistema indicador de color de semáforo COVID y Datos registrados.
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
			input("Presiona Enter para ver los datos de la muestra...")
			os.system("cls")

	else:

		#Cuando no ingresa una opcion valido le advierte y lo regresa al menú		print("\nOpción no valida :(")
		input("Presiona Enter para Continuar...")
		os.system("cls")

#Contadores para la edad y personas que tienen COVID
conta_si=0
conta_no=0
edad_no=0
conta_edad=0

#Abre el archivo y guarda los datos que se registraron en la lista datos
a=open("bd1.csv","a")
a.writelines(datos)
a.close()

#Abro el archivo, extraigo la información y la guardo en una variable en forma de lista
a=open("bd1.csv",'r')
contenido=a.readlines()
a.close()

#Almacena a las personas con mayor o menor edad con y sin COVID
mayor=0
mas=0
menor=200
menos=200

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

		#Busca a la persona con mayor edad con COVID
		if e>mayor:
			mayor=e

		#Busca a la persona con menor edad con COVID
		if e<menor:
			menor=e

	else:
		#Guardo las personas que no tiene COVID y su edad
		conta_no+=1
		edad_no=edad_no+e

		#Busca a la persona con mayor edad sin COVID
		if e>mas:
			mas=e

		#Busca a la persona con menor edad sin COVID
		if e<menos:
			menos=e

ac='0'
while(ac!='5'):
	os.system("cls")

	#Genero un menú para ver los datos de la base de datos
	print("\n1) Ver datos de la personas que no tiene covid\n2) Ver datos de la personas que tiene covid\n3) Ver datos generales de todas las personas\n4) El color del semaforo\n5) Salir\n")
	ac=input("Elige una opcion: ")

	if ac=='1':

		#Imprime cuantas personas no tienen covid y el promedio de la edad de esas personas 
		os.system("cls")
		print("\nDe las personas de la muestra "+str(conta_no)+(" no tienen covid"))
		
		print("La persona con menor edad es: "+str(menos))

		print("La persona con mayor edad es: "+str(mas))

		if conta_no!=0:
			p=edad_no/conta_no
			print("\nEl promedio de la edad de las personas es: "+str(p))
		else:
			print("\nNadie tiene covid")

		input("\nPresiona Enter para Continuar...")

	elif ac=='2':

		#Imprime cuantas personas tienen covid y el promedio de la edad de esas personas 
		os.system("cls")
		print("\nDe las personas de la muestra "+str(conta_si)+(" tienen covid"))
		
		print("La persona con menor edad es: "+str(menor))

		print("La persona con mayor edad es: "+str(mayor))

		if conta_si!=0:
			prom=conta_edad/conta_si
			print("\nEl promedio de la edad de las personas es: "+str(prom))
		else:
			print("\nNadie tiene covid")

		input("\nPresiona Enter para Continuar...")

	elif ac=='3':

		#Imprime cuantas personas se tienen en la muestra y el promedio de la edad de esas personas
		os.system("cls")
		total=conta_si+conta_no
		edad_total=edad_no+conta_edad

		print("\nLas personas totales de la muestra son: "+str(total))

		if total!=0:
			pm=edad_total/total
			print("\nEl promedio de la edad de las personas es: "+str(pm))
		else:
			print("\nNo hay elemetos en la base de datos")

		input("\nPresiona Enter para Continuar...")

	elif ac=='4':	

		os.system("cls")
		#Comparo cuantas personas tienen COVID para saber el semforo
		if conta_si==0:
			print("\nEl semforo esta en verde\n")

		elif conta_si<30:
			print("\nEl semforo esta en Amarillo\n")

		elif conta_si<70:
			print("\nEl semforo esta en Naranja\n")

		elif conta_si>70:
			print("\nEl semforo esta en Rojo\n")

		input("Presiona Enter para Continuar...")

	elif ac=='5':

		#Sale del ciclo While
		print("\nGracias por usar mi programa :)")

	else:

		#Cuando no ingresa una opcion valido le advierte y lo regresa al menú		
		print("\nOpción no valida :(")
		input("Presiona Enter para Continuar...")
		os.system("cls")
