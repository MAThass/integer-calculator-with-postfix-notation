#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"


struct DATA
{
    char  string[INT_LENGHT];
    LIST_2* output_stack;
    LIST_1* operators_stack;
    LIST_DEC* operand_stack;
    LIST_DEC* min_max_size;
};

void init_data(DATA* data)
{
    data->operators_stack = nullptr;
    data->output_stack = nullptr;
    data->operand_stack = nullptr;
    data->min_max_size = nullptr;
}

int convers_to_int(char* str)
{
    if (str == nullptr)
        return 0;

    int int_value = 0;
    bool is_negative = false;
    int i = 0;

    if (str[0] == '-')
    {
        is_negative = true;
        ++i; 
    }

    while (str[i] != '\0')
    {
        int digit = str[i] - '0';
        int_value = int_value * 10 + digit;
        ++i;
    }
    if (is_negative)
        return -int_value;
    return int_value;
}

bool onp_cal_clasic_operators(DATA* data ,char* pom_operator)
{
    if (pom_operator[0] == '+')
    {
        std::cout << pom_operator << " ";
        display(data->operand_stack);
        int d1 = PopStack_Dec(data->operand_stack);
        int d2 = PopStack_Dec(data->operand_stack);
        d1 = d1 + d2;
        PushStack_Dec(data->operand_stack, d1);
    }
    else if (pom_operator[0] == '-')
    {
        std::cout << pom_operator << " ";
        display(data->operand_stack);
        int d1 = PopStack_Dec(data->operand_stack);
        int d2 = PopStack_Dec(data->operand_stack);
        d1 = d2 - d1;
        PushStack_Dec(data->operand_stack, d1);
    }
    else if (pom_operator[0] == '*')
    {
        std::cout << pom_operator << " ";
        display(data->operand_stack);
        int d1 = PopStack_Dec(data->operand_stack);
        int d2 = PopStack_Dec(data->operand_stack);
        d1 = d1 * d2;
        PushStack_Dec(data->operand_stack, d1);
    }
    else if (pom_operator[0] == '/')
    {
        std::cout << pom_operator << " ";
        display(data->operand_stack);
        int d1 = PopStack_Dec(data->operand_stack);
        int d2 = PopStack_Dec(data->operand_stack);
        if (d1 != 0) {
            d1 = d2 / d1;
            PushStack_Dec(data->operand_stack, d1);
        }
        else {
            std::cout << "ERROR" << "\n \n";
            delete[] pom_operator;
            return false;
        }
    }
    return true;
}
void onp_cal_maxi(DATA* data , char* pom_operator)
{
    std::cout << pom_operator << " ";
    display(data->operand_stack);
    int num_operand = 0;
    if (pom_operator[4] == '\0')
    {
        num_operand = int(pom_operator[3] - '0');
    }
    else
    {
        num_operand = int((pom_operator[3] - '0') * 10 + (pom_operator[4] - '0'));
    }
    int maxi = PopStack_Dec(data->operand_stack);
    for (int i = 1; i < num_operand; i++)
    {
        int d = PopStack_Dec(data->operand_stack);
        if (d > maxi)
            maxi = d;
    }
    PushStack_Dec(data->operand_stack, maxi);
}
void onp_cal_min(DATA* data, char* pom_operator)
{
    std::cout << pom_operator << " ";
    display(data->operand_stack);
    int num_operand = 0;
    if (pom_operator[4] == '\0')
    {
        num_operand = int(pom_operator[3] - '0');
    }
    else
    {
        num_operand = int((pom_operator[3] - '0') * 10 + (pom_operator[4] - '0'));
    }
    int min = PopStack_Dec(data->operand_stack);
    for (int i = 1; i < num_operand; i++)
    {
        int d = PopStack_Dec(data->operand_stack);
        if (d < min)
            min = d;
    }
    PushStack_Dec(data->operand_stack, min);
}
void onp_cal_if(DATA* data, char* pom_operator)
{
    std::cout << pom_operator << " ";
    display(data->operand_stack);
    int d1 = PopStack_Dec(data->operand_stack);
    int d2 = PopStack_Dec(data->operand_stack);
    int d3 = PopStack_Dec(data->operand_stack);
    if (d3 > 0)
        PushStack_Dec(data->operand_stack, d2);
    else
        PushStack_Dec(data->operand_stack, d1);
}
void onp_cal_n(DATA* data, char* pom_operator)
{
    std::cout << pom_operator << " ";
    display(data->operand_stack);
    int d1 = PopStack_Dec(data->operand_stack);
    PushStack_Dec(data->operand_stack, -d1);
}
void onp_calculation(DATA* data)
{
    while (data->output_stack != nullptr)
    {
        char* pom_operator = PopStack_reverse(data->output_stack);
        if (pom_operator[0] >= '0' && pom_operator[0] <= '9')
        {
            int d = convers_to_int(pom_operator);
            PushStack_Dec(data->operand_stack, d);
        }
        else if(pom_operator[0] == '*' || pom_operator[0] == '/' || pom_operator[0] == '+' || pom_operator[0] == '-')
        { 
            if(!onp_cal_clasic_operators(data, pom_operator))
                return;
        }
        else if (pom_operator[0] == 'N')
        {
            onp_cal_n(data, pom_operator);
        }
        else if (pom_operator[0] == 'I') //IF
        {
            onp_cal_if(data, pom_operator);
        }
        else if (pom_operator[2] == 'N') //MIN
        {
            onp_cal_min(data, pom_operator);
        }
        else if (pom_operator[2] == 'X') //MAX
        {
            onp_cal_maxi(data, pom_operator);
        }
        delete[] pom_operator;
    }
    display(data->operand_stack);
    std::cout << "\n";
}


int priority(char* op)
{
    if (*op == '+' || *op == '-')
        return 1;
    if (*op == '*' || *op == '/')
        return 2;
    if (*op == 'I' || *op=='N')
        return 3;
    if (*op == 'M')
        return 4;
    return 0; 
}
bool is_operator(char* op)
{
    return (*op == '+' || *op == '-'
        || *op == '*' || *op == '/'
        || *op == 'N' || *op == 'I'
        || *op == 'M');
}
void pop_from_operator_stack(DATA* data, bool push) // nie dodaje operatora na stosa wyjsciowy
{
    char* pom = PopStack(data->operators_stack);
    delete[] pom;
    pom = PeekTop(data->operators_stack);  // sprawdza czy nawias zamykal operacje if max min
    if(pom!=nullptr)
    {
        if (pom[0] == 'I')
            PopStack_Dec(data->min_max_size);
        else if (pom[0] == 'M')
        {
            int size = PopStack_Dec(data->min_max_size)+1;
            if(size<10)
            {
                pom[3] = char(size + '0');
                pom[4] = '\0';
            }
            else
            {
                pom[3] = char(size/10 + '0');
                pom[4] = char(size%10 + '0');
                pom[5] = '\0';
            }
        }
    }
}
void pop_from_operator_stack(DATA* data)
{
    char* pom = PopStack(data->operators_stack);
    PushStack(data->output_stack, pom);
    delete[] pom;
}
void clear_stacks(DATA* data)
{
    delete_all(data->operators_stack);
    delete_all(data->output_stack);
    delete_all(data->operand_stack);
}

void comma_operation(DATA* data)
{
    data->min_max_size->value++;
    char top_operators_stack[INT_LENGHT] = {};
    if (PeekTop(data->operators_stack) != nullptr)
        copy_string(top_operators_stack, PeekTop(data->operators_stack));
    while (top_operators_stack[0] != '(')
    {
        if (is_operator(&top_operators_stack[0]))
        {
            pop_from_operator_stack(data);
            if (PeekTop(data->operators_stack) != nullptr)
                copy_string(top_operators_stack, PeekTop(data->operators_stack));
            else
                break;
        }
    }
}
void operators_operation(DATA* data)
{
    char top_operators_stack[12] = {};
    if (PeekTop(data->operators_stack) != nullptr)
        copy_string(top_operators_stack, PeekTop(data->operators_stack));

    while (data->operators_stack != nullptr)  // wyciąga operatory os nie mniejszym priorytecie ze stosu 
    {
        if (top_operators_stack[0] == '(')
            break;
        else if (data->string[0] == 'N')
        {
            break;
        }
        else if (data->string[0] == '*' || data->string[0] == '/')
        {
            if (priority(&top_operators_stack[0]) > 1) 
            {
                pop_from_operator_stack(data);
                if (PeekTop(data->operators_stack) != nullptr)
                    copy_string(top_operators_stack, PeekTop(data->operators_stack));
            }
            else
                break;
        }
        else // dla operatorow + oraz -
        {
            pop_from_operator_stack(data);
            if (PeekTop(data->operators_stack) != nullptr)
                copy_string(top_operators_stack, PeekTop(data->operators_stack));
        }
    }
    PushStack(data->operators_stack, data->string);
}
void convers_to_onp()
{
    DATA data;
    init_data(&data);
    std::cin >> data.string;
    while (data.string[0] != '.')
    {
        if (data.string[0] >= '0' && data.string[0] <= '9')
        {
            PushStack(data.output_stack, data.string);
        }
        else  if (data.string[0] == ',')
        {
            comma_operation(&data);
        }
        else if (data.string[0] == '(')
        {
            PushStack(data.operators_stack, data.string);
        }
        else if (data.string[0] == ')')
        {
            while (PeekTop(data.operators_stack)[0] != '(')
            {
                pop_from_operator_stack(&data);
            }
            pop_from_operator_stack(&data,false); // nawias zamykajacy
        }
        else if (data.string[0] == 'M' || data.string[0] == 'I')
        {
            PushStack_Dec(data.min_max_size, 0);
            PushStack(data.operators_stack, data.string);
        }
        else
        {
            operators_operation(&data);
        }
        std::cin >> data.string;
    }
    while (data.operators_stack != nullptr) //wyciaga pozostale operatory ze stosu
    {   
        pop_from_operator_stack(&data);
    }
    displayRevers(data.output_stack);
    onp_calculation(&data);
    clear_stacks(&data);
}



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number_formulas = 1;
    std::cin >> number_formulas;
    
    for (int i = 0; i < number_formulas; i++)
    {
        convers_to_onp();
    }
}

