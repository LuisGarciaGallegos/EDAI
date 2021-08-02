#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //char opracion [TAM]
    char operacion [50];
    int i=0,res=0;
    int op1=0, op2=0;
    
    printf("Escribe la operacion ");
    scanf("%s", &operacion);
    
    printf("La operacion es: %s\n\n", operacion);
    do{
        for(i=0;i<50;i++){
            if(operacion[i]=='*'){
        	    op1=(int)(operacion[i-1]-'0');
        	    op2=(int)(operacion[i+1]-'0');
        	    //printf("\n%c \n%c", operacion[i-1], operacion[i+1]);
        	    res =op1*op2;
        	    
            }else{
                if(operacion[i]=='/'){
        	        op1=(int)(operacion[i-1]-'0');
        	        op2=(int)(operacion[i+1]-'0');
        	        //printf("\n%c \n%c", operacion[i-1], operacion[i+1]);
        	        res +=op1/op2;
                }else{
                    if(operacion[i]=='+'){
                        op1=(int)(operacion[i-1]-'0');
        	            op2=(int)(operacion[i+1]-'0');
        	            //printf("\n%c \n%c", operacion[i-1], operacion[i+1]);
        	            res +=op1+op2;
	        }else{
	        	if(operacion[i]=='-'){
                        op1=(int)(operacion[i-1]-'0');
        	            op2=(int)(operacion[i+1]-'0');
        	            //printf("\n%c \n%c", operacion[i-1], operacion[i+1]);
        	            res +=op1-op2;
		}
	        }
                
	    }
            }
        }
    }while(operacion[i] == '*' || operacion[i] == '/' || operacion[i] == '+' || operacion[i] == '-');
    printf("\nEl resultado de la operacion es %d ", res);
    
    return 0;
}
