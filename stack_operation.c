/*
 * stack_operation.c
 *
 *  Created on: 21 mar. 2021
 *      Author: Cristian
 */
#include <stdlib.h>
#include "stack.h"
STACK create(){
    STACK packet=malloc(sizeof(struct STRUCT_STACK));
    packet->size=0;
    packet->top=NULL;
    return(packet);
}

void push(STACK add, TYPE s){
    NODE new=malloc(sizeof(struct STRUCT_NODE));
    new->tail=add->top;  //el nuevo nodo apunta a top antes de que top cambie de valor, de esta forma el nodo apuntara al nodo anterior
    new->data=s;
    add->top=new;  //ahora el top del stack apunta al nuevo nodo
    add->size++;
}

STACK pop(STACK header){
    NODE trash=header->top;
    TYPE retrieve_data=NULL;  //si solo hay un paquete, no se hace la operacion

    if(trash->tail!=NULL){  //como hay varios paquetes, si se puede expulsar uno de ellos
        retrieve_data=trash->data; // obtener el paquete
        header->top=trash->tail;  //el encabezado del stack ahora apunto al nodo anterior

        free(trash);
        header->size--;
    }
    return(retrieve_data);
}

TYPE top(STACK head){  //regresa el valor del top del stack
    return(head->top->data);
}

int stack_isempty(STACK stack){

    int flag;
    if(stack->top==NULL){  //si el top del stack no apunta a nada nos regresara 1
        flag=1;
    }else{
        flag=0;
    }
    return(flag);
}

void stack_destroy(STACK stack)
{
    while(stack_isempty(stack)!=1){  //si el stack no esta vacío se puede efectuar
        pop(stack);
    }
    free(stack);
}

int stack_size(STACK stack)
{
    return(stack->size);
}

int precedence (char string){

    int operator;
    if(string=='+' || string=='-'){
        operator=1;
    }
    if(string=='('){
        operator=0;
    }
    if(string=='*'||string=='/'){
        operator=2;
    }
    return operator;
}
