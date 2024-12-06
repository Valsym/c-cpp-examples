/*
Программу, в которой реализована структура данных под названием стек.

Данные (объекты) в стек добавляются сверху и удаляются тоже сверху. 
Класс Object служит для описания отдельных объектов, а класс Stack для работы со стеком в целом. 
Пример использования класса Stack:

Stack s;
s.push(1); // добавление 1-го элемента (объекта) в стек
s.push(2); // добавление 2-го элемента
s.push(3); // добавление 3-го элемента
s.push(4); // добавление 4-го элемента
s.pop(); // удаление верхнего объекта (4-го)
В результате структура стека будет следующей:

3 -> 2 -> 1

Пример вывода стека в консоль:

shared_obj_ptr p {s.get_top()};
while(p) {
    std::cout << p->get_data() << " ";
    p = p->get_next();
}

В класс Stack добавлены метод(ы) которые позволяют выполнять следующие команды с объектами этого класса:

Stack s1, s2;
s1.push(10); s1.push(-5);

s2 = s1; // копирование стека s1 в стек s2 (стеки должны быть независимы, полная копия)
s2 += 7; // добавление наверх стека нового элемента со значением 7 (поле data)
s2--; // удаление верхнего объекта из стека (аналог метода pop)
--s2; // удаление верхнего объекта из стека (аналог метода pop)

*/

#include <iostream>
#include <memory>

class Object {
    int data {0};
    std::shared_ptr<Object> next {nullptr};
public:
    Object(int d) : data(d), next(nullptr)
        { }

    int get_data() const { return data; }
    std::shared_ptr<Object>& get_next() { return next; }
};

using shared_obj_ptr = std::shared_ptr<Object>;

class Stack {
    shared_obj_ptr top {nullptr};
public:
    shared_obj_ptr get_top() { return top; }
    
    void copy_reverse(Stack& source, Stack& dest)
    {
        shared_obj_ptr p {source.top};
        while(p){
            dest.push(p->get_data());
            p = p->get_next();
        }
    }

    Stack operator = (Stack & src)
    {
        if(this != &src){
            Stack tmp;
            copy_reverse(src, tmp);
            copy_reverse(tmp, *this);
        }
        return *this;
    }
    Stack operator += (int rigth)
    {
        push(rigth);
        return *this;
    }
    Stack operator -- ()
    {
        pop();
        return *this;
    }
    Stack operator -- (int rigth)
    {
        Stack tmp = *this;
        pop();
        return tmp;
    }

    void push(int data)
    {
        shared_obj_ptr node = std::make_shared<Object>(data);
        node->get_next() = top;
        top = node;
    }

    shared_obj_ptr pop() {
        if (!top) return nullptr;
        shared_obj_ptr ptr = top;
        top = top->get_next();
        return ptr;
    }
};

int main()
{
    Stack s;
    s.push(1); // добавление 1-го элемента (объекта) в стек
    s.push(2); // добавление 2-го элемента
    s.push(3); // добавление 3-го элемента
    s.push(4); // добавление 4-го элемента
    s.pop(); // удаление верхнего объекта (4-го)

    shared_obj_ptr p {s.get_top()};
    while(p) {
        std::cout << p->get_data() << " ";
        p = p->get_next();
    } // 3 -> 2 -> 1

    Stack s1, s2;
    s1.push(10); s1.push(-5);

     s2 = s1; // копирование стека s1 в стек s2 (стеки должны быть независимы, полная копия)
     s2 += 7; // добавление наверх стека нового элемента со значением 7 (поле data)
     s2--; // удаление верхнего объекта из стека (аналог метода pop)
     --s2; // удаление верхнего объекта из стека (аналог метода pop)

    shared_obj_ptr p1 = s2.get_top();
    while(p1) {
        std::cout << p1->get_data() << " ";
        p1 = p1->get_next();
    }

    return 0;
}
