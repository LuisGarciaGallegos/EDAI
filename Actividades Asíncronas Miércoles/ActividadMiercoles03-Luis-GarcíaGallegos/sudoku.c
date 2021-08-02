#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define p printf
#define s scanf

void asignarBloques(char [9][9]);
void dibujarArea(int[9][9]);
bool comprobar(int[9][9]);
bool buscarElemento(int[9][9],char[9][9],int,int,int,char);


int main()
{

    int area[9][9]={0, 0, 6, 0, 0, 9, 0, 0, 0, 
                    8, 3, 5, 4, 0, 1, 6, 0, 2,
	        0, 2, 7, 0, 3, 6, 1, 5, 4,
	        6, 5, 0, 7, 4, 0, 8, 0, 9,
	        2, 0, 4, 0, 0, 0, 7, 0, 0,
	        0, 0, 0, 0, 8, 3, 0, 4, 5,
	        0, 6, 2, 0, 9, 0, 0, 7, 0,
	        5, 7, 0, 0, 6, 0, 0, 3, 0,
                    4, 1, 8, 3, 5, 0, 9, 2, 6};
    int fila=0,columna=0,valor=0, op=0;
    char bloques[9][9];
    char idBloque;
    bool check = true, check1 = false;

    ///ASIGNAMOS BLOQUES
    asignarBloques(bloques);

    do{
        ///DIBUJAMOS AREA EN CONSOLA
        system("cls");
        dibujarArea(area);


        ///PEDIMOS DATOS DE INGRESO
         p("\n\tQue desea hacer?");
         p("\n\t1) Ingresar valor");
         p("\n\t2) Eliminar valor\n\t");
         s("%d", &op);
        
        switch(op){

            case 1:
                ///ASIGNAMOS LOS INDICES AL ARREGLO
                p("\n\tIngrese los datos para ingresar el elemento");
                p("\n\tFila: ");
                s("%d", &fila);
                p("\n\tColumna: ");
                s("%d", &columna);
                //ASIGNAMOS EL VALOR QUE IRA EN EL ARREGLO
                do{
                    p("\n\tIngrese el valor: ");
                    s("%d", &valor);
                    if(valor<0 || valor>9){
                    	p("\n\tEl valor no esta en el rango, favor de volverlo a ingresar");
	        }
                }while(valor<0 || valor>9);
                ///OBTENEMOS EL BLOQUE
                idBloque = bloques[fila-1][columna-1];

                ///COMPROBAMOS QUE SEA UN VALOR QUE NO SE REPITA
                check1 = buscarElemento(area,bloques,fila,columna,valor,idBloque);

                if(check1){
                    p("\n\tNo se agrego elemento. Elemento repetido");
                }else{
                    area[fila-1][columna-1]=valor;
                    p("\n\tSe agrego elemento.");
                }
                
            break;

            case 2:
                ///ELIMINAMOS VALOR
                p("\n\t¿Que elemento vas a eliminar?");
                p("\n\tFila: ");
                s("%d", &fila);
                p("\n\tColumna: ");
                s("%d", &columna);

                area[fila-1][columna-1]=0;
                p("\n\tSe ha eliminado el elemento");
            break;

            default:
                p("¡¡¡\n\tOpcion invalida!!!");
            break;

        }

        getch();


        ///COMPROBAMOS QUE EL AREA NO ESTE LLENA
        check = comprobar(area);

    }while(check);

    p("\n\tFELICIDADES!! HAS COMPLETADO EL SUDOKU!!");


    getch();
}

void asignarBloques(char bloques[9][9]){
    int i,j;

 for( i=0; i < 9;i++){

        for( j=0; j < 9; j++){

           if(i>=0 && i<=2 ){

                if(j==0 || j==1 || j==2){
                    bloques[i][j]='a';
                }else if(j==3 || j==4 || j==5){
                     bloques[i][j]='b';
                }else{
                    bloques[i][j]='c';
                }
           }

           if(i>=3 && i<=5 ){

                if(j==0 || j==1 || j==2){
                    bloques[i][j]='d';
                }else if(j==3 || j==4 || j==5){
                     bloques[i][j]='e';
                }else{
                    bloques[i][j]='f';
                }
           }

           if(i>=6 && i<=8 ){

                if(j==0 || j==1 || j==2){
                    bloques[i][j]='g';
                }else if(j==3 || j==4 || j==5){
                     bloques[i][j]='h';
                }else{
                    bloques[i][j]='i';
                }
           }
        }


    }

}


void dibujarArea(int area[9][9]){
    int i, j;

    p("\t\t\t\t  SUDOKU");
    p("\n");
    for(i=0;i<10;i++){

        for(j=0; j < 10;j++){
        	
        	if(j==4 || j==7 || j==1){
	        p("\t");
	    }
            if(i==0 && j>0)
                p("  %d", j);
            else if(j==0 && i>0)
                p("\t %d",i);
            else if(i!=0 && j!=0)
                p("  %d", area[i-1][j-1]);
            else
                p("\t");

        }
        p("\n");
        if(i==3 || i==6 || i==0){
	        p("\n");
	    }
    }

}

bool comprobar(int area[9][9]){
    int i,j;
    ///DEVULEVE TRUE SI ENCUENTRA CERO
    bool check= false;

    for( i=0;i<9;i++){

        for( j=0; j < 9;j++){

            if(area[i][j]==0){
                check= true;
            }
        }
    }

    return check;
}

bool buscarElemento(int area[9][9],char bloques[9][9],int fila,int columna,int valor,char idBloque){

    int i, j;
    bool check=false;

    ///BUSCAMOS EN FILAS
    for(i=0; i < 9;i++){

        ///DEVULEVE TRUE SI SE REPITE EN FILAS
        if(area[fila-1][i]==valor)
        {
            check = true;
            p("\n\tADVERTENCIA: el valor que desea ingresar se repite de la fila %d, columna %d" , fila, i+1);
            return check;
        }

    }

    ///BUSCAMOS EN COLUMNAS
    for(i=0; i < 9;i++){

        ///DEVULEVE TRUE SI SE REPITE EN COLUMNAS
        if(area[i][columna-1]==valor){
            check = true;
            p("\n\tADVERTENCIA: el valor que desea ingresar se repite de la fila %d, columna %d", i+1,columna);
            return check;
        }

    }

    ///BUSCAMOS EN EL BLOQUE CORRESPONDIENTE
    for(i=0; i < 9;i++){

        for(j=0; j <9;j++){
            ///DEVULEVE TRUE SI SE REPITE EN EL MISMO BLOQUE
            if(bloques[i][j]==idBloque && area[i][j]==valor ){
                    check= true;
                    p("\n\tADVERTENCIA: el valor que desea ingresar ya es parte del mismo bloque. Fila %d, columna %d ", i+1, j+1);
                    return check;
            }

        }

    }


    return check;
}
