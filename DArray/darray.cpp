#include "darray.h"
 
void DArray::_resize_array(int size_new)
{
    if(size_new <= capacity)
        return;
 
    while(capacity < size_new) {
        capacity *= resize_factor;
        if(capacity >= max_length_array) {
            capacity = max_length_array;
            break;
        }
    }
 
    int* p = new int[capacity];
 
    for(int i = 0;i < length; ++i)
        p[i] = data[i];
 
    delete[] data;
    data = p;
}
 
const DArray& DArray::operator=(const DArray& other)
{
    if(this == &other) // присваивание объекта самому себе
        return other;
 
    length = other.length;
    capacity = other.capacity;
 
    delete[] data;
    data = new int[capacity];
    for(int i = 0;i < length; ++i)
        data[i] = other.data[i];
 
    return *this;
}
 
void DArray::push_back(int value)
{
    if(length >= capacity) {
        _resize_array(capacity * resize_factor);
    }
 
    if(length < capacity)
        data[length++] = value;
}
 
int DArray::pop_back()
{
    if(length > 0)
        return data[--length];
    return value_error;
}

DArray::Item::operator int() const 
{
    if(index >= current->length || index < 0)
        return value_error;
 
    return current->data[index];
}
 
int DArray::Item::operator=(int right)
{
    if(index >= max_length_array || index < 0)
        return right; // размер массива data не может превышать max_length_array элементов
 
    if(index >= current->capacity) {
        current->_resize_array(index+1);
    }
 
    for(int i = current->length; i < index; ++i)
        current->data[i] = 0;   // зануляем все новые добавленные значения
 
    if(index >= current->length)
        current->length = index + 1; // новый размер записанных данных
 
    current->data[index] = right;
    return right;
}

int DArray::Item::_assign_operator(int right, type_assign t)
{
    if(index >= current->length || index < 0)
        return right; // операции +=, -=, *=, /=, ++ и т.п. можно выполнять только с записанными элементами массива
    
    int value = current->data[index];

    switch(t) {
        case iadd_operator: 
            current->data[index] += right;
            break;
        case isub_operator: 
            current->data[index] -= right;
            break;        
        case imul_operator: 
            current->data[index] *= right;
            break;
        case idiv_operator:
            current->data[index] /= right;
            break;
        case iddiv_operator: 
            current->data[index] %= right;
            break;
        case iincpref_operator: 
            current->data[index]++;
            break;
        case idecpref_operator: 
            current->data[index]--;
            break;
        case iincpost_operator: 
            current->data[index]++;
            return value;
        case idecpost_operator:
            current->data[index]--;
            return value;
    }
    return current->data[index];
}

int DArray::Item::operator+=(int right)
{
    return _assign_operator(right, iadd_operator);
}

int DArray::Item::operator-=(int right)
{
    return _assign_operator(right, isub_operator);
}
 
int DArray::Item::operator*=(int right)
{
    return _assign_operator(right, imul_operator);
}

int DArray::Item::operator/=(int right)
{
    return _assign_operator(right, idiv_operator);
}
 
int DArray::Item::operator%=(int right)
{
    return _assign_operator(right, iddiv_operator);
}

int DArray::Item::operator++() // prefix form
{
    return _assign_operator(0, iincpref_operator);
}

int DArray::Item::operator--() // prefix form
{
    return _assign_operator(0, idecpref_operator);
}
int DArray::Item::operator++(int right) // postfix form
{
    return _assign_operator(0, iincpost_operator);
}

int DArray::Item::operator--(int right) // postfix form
{
    return _assign_operator(0, iincpost_operator);
}

const DArray& DArray::operator+=(const DArray& other)
{
    int size_new = length + other.length;
    if(size_new > max_length_array)
        size_new = max_length_array;
 
    _resize_array(size_new);
 
    for(int i = length, j = 0; i < size_new; ++i, ++j)
        data[i] = other.data[j];
 
    length = size_new;
    return *this; 
}

const DArray DArray::operator+(const DArray& other)
{
    int size_new = length + other.length;
    if(size_new > max_length_array)
        size_new = max_length_array;
 
    DArray *tmp = new DArray;
    tmp = this;
    tmp->_resize_array(size_new);
 
    for(int i = length, j = 0; i < size_new; ++i, ++j)
        tmp->data[i] = other.data[j];
 
    tmp->length = size_new;
    return *tmp; 
}
