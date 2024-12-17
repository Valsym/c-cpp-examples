/* Корзина покупок с товарами */

#include <iostream>
#include <string>
#include <iomanip>

class Thing {
protected:
    std::string name;
    int price {0};
public:
    Thing(const std::string name = "", int price = 0) : name(name), price(price)
        { }

    const std::string& get_name() const { return name; }
    int get_price() const { return price; }
    virtual void print() {}
};

class Cart {
    enum { max_total_thing = 100 };
    Thing* goods[max_total_thing] {nullptr}; // товары в корзине
    int count {0}; // текущее количество товаров
public:
    void append(Thing* th)
    {
        if(count >= max_total_thing) return;
        goods[count++] = th;
    }

    Thing** get_goods() { return goods; }
    int get_count() const { return count; }
    void show() { for(int i = 0; i < count; i++) goods[i]->print(); }
};

class Table : public Thing {
    int color {0}; double weight {0.0};
public:    
    Table(const std::string name, int price, int color, double weight)
        : Thing(name, price), color(color), weight(weight) {}
    void print() // отображает строку (без кавычек) "Table: name, price, color, weight" (поле weight с точностью до сотых)
    { 
        std::cout << "Table: " << name << ", " << price << ", " << color << ", ";
        std::cout << std::fixed << std::setprecision(2) << weight << std::endl;
    }
};

class TV : public Thing {
    int size {0};
public:    
    TV(const std::string name, int price, int size)
        : Thing(name, price), size(size) {}
    void print() // отображает строку (без кавычек) "TV: name, price, size"
    { 
        std::cout << "TV: " << name << ", " << price << ", " << size << std::endl;
    }
};

int main(void)
{
    Cart cart;
    
    cart.append(new Table {"Стол", 12000, 0, 12.70});
    cart.append(new TV {"Panasonic", 54000, 43});
    cart.append(new TV {"Samsung", 83500, 54});
    cart.append(new Table {"Стол 2", 9500, 432, 10.74});
    cart.show();

    for(int i = 0; i < cart.get_count(); i++)
        delete cart.get_goods()[i];

    return 0;
}
