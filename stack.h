#pragma once

#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"

//stos na podwojnej liscie
char* PopStack(LIST_2*& list);
void PushStack(LIST_2* &list, char value[]);
char* PeekTop(LIST_2*& list);
char* PopStack_reverse(LIST_2*& list);

//stos na pojedynczej liscie
char* PopStack(LIST_1*& list);
void PushStack(LIST_1*& list, char value[]);
char* PeekTop(LIST_1*& list);

//stos na podwojnej liscie intow
int PopStack_Dec(LIST_DEC*& list);
void PushStack_Dec(LIST_DEC*& list,  int value);
int PeekTop_Dec(LIST_DEC*& list);
