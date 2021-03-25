/*
 * main.c
 *
 *  Created on: 21 mar. 2021
 *      Author: Cristian
 */
#define SIZE 20
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"


int main(void){
    setbuf(stdout,NULL);
    STACK a =create();

    char equation[SIZE];
    char *ptr;  //este apuntador servira para movernos a lo largo de la ecuacion
    char *operator;
    puts("ingresa la operacion");
    scanf("%s",equation);
    ptr=malloc(SIZE);
    strcpy(ptr,equation);
    do{
        if(isalnum(*ptr)){   //si es un numero cualquiera no se hace ninguna operacion aun
            printf("%c",*ptr);
        }
        else if(*ptr=='('){
            push(a,ptr);
        }
        else if(*ptr==')'){  //si encuentra el parentesis que cierra, ira sacando los operandos del stack hasta llegar al primer paréntesis
            if(stack_isempty(a)==1){ //primero vemos si el stack esta vacio
                push(a,ptr);
            }
            while(*ptr!='('){
                ptr=value(pop(a));
                printf("%c",*ptr);
                ptr++;
            }pop(a); //sacar '(' //Posible error
        }
        else{ 		//si no es un numero ni un parentesis, es un operador
            if(stack_isempty(a)==1){ //primero vemos si el stack esta vacio
                push(a,ptr);
            }else{
                if (precedence(*ptr)>precedence(value(top(a)))){ //si la precedencia del operanod es mayor a la que esta en el tope, se añade
                    push(a,ptr);
                }
                else{  //si es menor o igual se saca el del tope y se agrega el signo con menor precedencia
                    operator=value(pop(a));
                    printf("%c",*operator);
                    push(a,ptr);
                }
            }
        }
        ptr++;
    }while(*ptr!='\0');

    return 0;
}
