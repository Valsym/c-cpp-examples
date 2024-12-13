/*
Реализована работа фильтра для очистки воды, состоящего из трех фильров:
  Mechanical
  Aragon
  Calcium
*/

#include <iostream>

enum type_filter_water {flt_none = 0, flt_mechanical = 1, flt_aragon = 2, flt_calcium = 3};

class FilterWater {
protected:
    unsigned date {0}; // дата установки фильтра (начало работы)
    type_filter_water type {flt_none}; // тип фильтра
public:
    unsigned get_date() const { return date; } // возвращает значение поля date
    type_filter_water get_type() const { return type; }; // возвращает значение поля type
};

class Mechanical : public FilterWater {
public:
    Mechanical(unsigned date) { FilterWater::date = date; type = flt_mechanical; }
};

class Aragon : public FilterWater {
public:
    Aragon(unsigned date) { FilterWater::date = date; type = flt_aragon; }
};

class Calcium : public FilterWater {
public:
    Calcium(unsigned date) { FilterWater::date = date; type = flt_calcium; }
};

class GeyserClassic {
public:
    enum { total_slots = 3 };
private:    
    FilterWater* slots[total_slots] {nullptr}; // слоты с фильтрами для воды
public:
    GeyserClassic(FilterWater* f1 = nullptr, FilterWater* f2 = nullptr, FilterWater* f3 = nullptr)
        { 
            if(f1) add_filter(1, f1); 
            if(f2) add_filter(2, f2); 
            if(f3) add_filter(3, f3); 
        }

    const FilterWater* operator[](int index) const // получение фильтра (из массива slots) по индексу index; если index неверный, то возвращается nullptr; если фильтр в текущем слоте отсутствует, то возвращается nullptr
    {
        if(0 <= index && index <= 3 && slots[index] != nullptr)
            return slots[index];
        
        return nullptr;
    }
    void add_filter(int slot_num, FilterWater* filter)// добавление filter в слот с номером slot_num (нумерация: 1, 2, 3)
    {
        if(0 < slot_num && slot_num < 4 && slots[slot_num - 1] == nullptr 
        && filter->get_type() == slot_num)
            slots[slot_num - 1] = filter;
    }
};

int main()
{
  Mechanical filter_1(100);
  Aragon filter_2(100);
  Calcium filter_3(100);
  
  GeyserClassic gc_1;
  GeyserClassic gc_2(&filter_1); // filter_1 для 1-го слота (два остальных nullptr)
  GeyserClassic gc_3(&filter_1, &filter_2); // filter_1 для 1-го слота; filter_2 для 2-го слота
  GeyserClassic gc_4(&filter_1, &filter_2, &filter_3); // каждый фильтр в свой слот (по порядку)

  return 0;
}
