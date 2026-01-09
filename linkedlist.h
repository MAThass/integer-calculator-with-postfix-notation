#pragma once
#include <iostream>
#include <stdlib.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define INT_LENGHT 12

struct LIST_1
{
	char value[INT_LENGHT];
	LIST_1* next;
};

struct LIST_2
{
	LIST_2* before;
	char value[INT_LENGHT];
	LIST_2* next;
};

struct LIST_DEC
{
	LIST_DEC* before;
	 int value;
	LIST_DEC* next;
};

void copy_string(char s1[], char s2[]);

//podwojnie połączona lista cykliczna
void push_front(LIST_2*& list, char value[]);
void delete_front(LIST_2*& list);
void delete_back(LIST_2*& list);
void delete_all(LIST_2*& list);
void display(LIST_2* list);
void displayRevers(LIST_2* list);



//pojedynczo połączona lista
void push_front(LIST_1*& list, char value[]);
void delete_front(LIST_1*& list);
void delete_all(LIST_1*& list);
void display(LIST_1* list);



//podwójnie połączona lista liczby typu int
void delete_front(LIST_DEC*& list);
void display(LIST_DEC* list);
void delete_all(LIST_DEC*& list);


