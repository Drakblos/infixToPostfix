/*
 * stack.h
 *
 *  Created on: 21 mar. 2021
 *      Author: Cristian
 */

#ifndef STACK_H_
#define STACK_H_
#define value(d) ((char *) d)  //regresa el valor del stack apuntando a un char

typedef void* TYPE;  //apuntador para el dato del paquete

struct STRUCT_NODE{
    TYPE data;
    struct STRUCT_NODE *tail;
};

typedef struct STRUCT_NODE *NODE;

struct STRUCT_STACK{
    struct STRUCT_NODE *top;
    int size;
};

//funciones
typedef struct STRUCT_STACK *STACK;

void stack_destroy(STACK stack);
int stack_isempty(STACK stack);
STACK create();
void push(STACK add, TYPE s);
STACK pop(STACK header);
TYPE top(STACK head);
int stack_size(STACK stack);
int precedence (char string);

#endif /* STACK_H_ */