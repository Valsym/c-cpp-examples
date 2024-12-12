#include <iostream>
#include <string>

class Thing {
protected:
    std::string name;
    int price {0};
public:
    void set_base_info(const std::string& name, int& price)
    {
        this->name = name; this->price = price;
    }
    void get_base_info(std::string& name, int& price)
    {
        name = this->name; price = this->price;
    }
};

class TV : public Thing {
    int size {0}; double weight {0.0};
public:    
    TV(std::string name, int price, int size, double weight)
        : size(size), weight(weight) { set_base_info(name, price); }
    void get_data(std::string& name, int& price, int& size, double& weight)
        { get_base_info(name, price); size = this->size; weight = this->weight; }
};
    
class Book : public Thing {
    std::string author; int pages {0};
public:    
    Book(std::string name, int price, std::string author, int pages)
        : author(author), pages(pages) { set_base_info(name, price); }
    void get_data(std::string& name, int& price, std::string& author, int& pages)
        { get_base_info(name, price); author = this->author; pages = this->pages; }
};

class Store {
    enum {max_total = 100}; // максимальное количество товаров
    Thing* things[max_total] { nullptr }; // товары магазина
    int total {0}; // текущее количество товаров
public:
    ~Store() {
        if(total)
            for(int i = 0; i < total; i++){
                delete things[i];
                //std::cout << "Delete things " << i << "\n";
            }
    }
    void append(const Thing* th) // добавление товара th в конец массива things (хранится указатель на объект)
        { if(total < max_total) things[total++] = (Thing*)th; }
    Thing* operator[](int index) // возвращает указатель на товар массива things по индексу index; если index неверный, возвращается nullptr
    { 
        if(0 <= index && index < total) 
            return things[index]; 
        
        return nullptr;
    }
    int get_total() const { return total; } // возвращает значение поля total
};

int main(void)
{
    Store st;
    TV *tv = new TV{"Samsung", 54300, 43, 5.4};  
    st.append(tv);
    
    Book *pb = new Book{"C++", 2000, "Balakirev", 543};   
    st.append(pb);

    TV *tv2 = new TV{"Sony", 97000, 80, 7.5};
    st.append(tv2);

    std::cout << st.get_total() << "\n";

    std::string name;
    int price;
    int size; double weight;

    for(int i = 0; i < st.get_total(); i++){
        st[i]->get_base_info(name, price);
        std::cout << name << " " << price << "\n";
    }    

    return 0;
}
