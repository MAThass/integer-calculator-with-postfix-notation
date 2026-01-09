#include <iostream>
#include <stdlib.h>
#include "stack.h"
#include "linkedlist.h"


//stos na podwojnej liscie
char* PopStack(LIST_2*& list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	char* value = new char[INT_LENGHT];
	copy_string(value, list->value);
	delete_front(list);
	return value;
}
void PushStack(LIST_2* &list, char value[])
{
	push_front(list, value);
}
char* PeekTop(LIST_2*& list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	return list->value;
}
char* PopStack_reverse(LIST_2*& list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	char* value = new char[INT_LENGHT];

	copy_string(value, list->before->value);
	
	delete_back(list);
	return value;
}



//stos na pojedynczej liscie
char* PopStack(LIST_1*& list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	char* value = new char[INT_LENGHT];
	copy_string(value, list->value);
	delete_front(list);
	return value;
}
void PushStack(LIST_1*& list, char value[])
{
	push_front(list, value);
}
char* PeekTop(LIST_1*& list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	return list->value;
}



//stos na podwojnej liscie intow
 int PopStack_Dec(LIST_DEC*& list)
{
	if (list == nullptr)
	{
		return 0;
	}
	int value = list->value;
	LIST_DEC* newList;
	newList = list;
	list = list->next;
	if (list != nullptr)
		list->before = nullptr;
	delete newList;
	return value;
}
void PushStack_Dec(LIST_DEC*& list,  int value)
{
	LIST_DEC* newList = new LIST_DEC;
	newList->value = value;

	if (list == nullptr)
	{
		newList->before = nullptr;
		newList->next = nullptr;
		list = newList;
		return;
	}

	newList->next = list;
	newList->before = nullptr;
	list->before = newList;
	list = newList;
}
 int PeekTop_Dec(LIST_DEC*& list)
{
	if (list == nullptr)
	{
		return 0;
	}
	return list->value;
}
