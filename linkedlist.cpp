#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"
#include <time.h>


void copy_string(char s1[], char s2[])
{
    if (s1 == nullptr || s2 == nullptr)
        return;
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        ++i;
    }
    s1[i] = '\0';
}


//podwojnie połączona lista cykliczna
void push_front(LIST_2*& list, char value[])
{
    LIST_2* newList = new LIST_2;
    copy_string(newList->value, value);
    if (list == nullptr)
    {
        newList->before = newList;
        newList->next = newList;
        list = newList;
        return;
    }
    LIST_2* lastElement = list->before;

    newList->next = list;
    newList->before = lastElement;
    list->before = newList;
    lastElement->next = newList;
    list = newList;
}
void delete_front(LIST_2*& list)
{
    if (list == nullptr)
    {
        return;
    }
    LIST_2* newList = list;

    if (newList->next == newList)
    {
        delete newList;
        list = nullptr;
        return;
    }
    LIST_2* nextNode = newList->next;
    LIST_2* lastNode = newList->before;
    nextNode->before = lastNode;
    lastNode->next = nextNode;
    list = nextNode;
    delete newList;
}
void delete_back(LIST_2*& list)
{
    if (list == nullptr)
    {
        return;
    }
    LIST_2* lastElement = list->before;
    if (lastElement == list)
    {
        delete lastElement;
        list = nullptr;
        return;
    }
    LIST_2* preLastElement = lastElement->before;
    preLastElement->next = list;
    list->before = preLastElement;
    delete lastElement;
}
void delete_all(LIST_2*& list)
{
    if (list == nullptr)
    {
        return;
    }
    LIST_2* messenger = list;
    LIST_2* next;

    do {
        next = messenger->next;
        delete messenger;
        messenger = next;
    } while (messenger != list);
    list = nullptr;
}
void display(LIST_2* list)
{
    if (list == nullptr)
    {
        std::cout << " " << std::endl;
        return;
    }
    LIST_2* mesenger = list;
    do
    {
        std::cout << mesenger->value << " ";
        mesenger = mesenger->next;
    } while (mesenger != list);
    std::cout << '\n';
}
void displayRevers(LIST_2* list)
{
    if (list == nullptr)
    {
        std::cout << " " << std::endl;
        return;

    }
    LIST_2* mesenger = list->before;
    do
    {
        std::cout << mesenger->value << " ";
        mesenger = mesenger->before;
    } while (mesenger->next != list);
    std::cout << '\n';
}



//pojedynczo połączona lista
void push_front(LIST_1*& list, char value[])
{
    LIST_1* newList = new LIST_1;
    copy_string(newList->value, value);
    if (list == nullptr)
    {
        newList->next = nullptr;
        list = newList;
        return;
    }

    newList->next = list;
    list = newList;
}
void delete_front(LIST_1*& list)
{
    if (list == nullptr)
    {
        return;
    }
    LIST_1* newList;
    newList = list;
    list = list->next;
    delete newList;
}
void delete_all(LIST_1*& list)
{
    if (list == nullptr)
    {
        return;
    }
    while (list->next != nullptr)
    {
        delete_front(*&list);
    }
    delete_front(*&list);

}
void display(LIST_1* list)
{
    if (list == nullptr)
    {
        std::cout << " " << std::endl;
        return;
    }
    LIST_1* mesenger = list;
    while (mesenger != nullptr)
    {
        std::cout << mesenger->value << " ";
        mesenger = mesenger->next;
    }
    std::cout << '\n';
}



//podwojnie połączona lista liczby typu int
void delete_front(LIST_DEC*& list)
{
    if (list == nullptr)
    {
        return;
    }
    LIST_DEC* newList;
    newList = list;
    list = list->next;
    if (list != nullptr)
        list->before = nullptr;
    delete newList;
}
void delete_all(LIST_DEC*& list)
{
    if (list == nullptr)
    {
        return;
    }
    while (list->next != nullptr)
    {
        delete_front(*&list);
    }
    delete_front(*&list);
}
void display(LIST_DEC* list)
{
    if (list == nullptr)
    {
        std::cout << " " << std::endl;
        return;
    }
    LIST_DEC* mesenger = list;
    while (mesenger != nullptr)
    {
        std::cout << mesenger->value << " ";
        mesenger = mesenger->next;
    }
    std::cout << '\n';
}












