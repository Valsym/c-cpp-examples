#include <iostream>
#include <bits/range_access.h>

// класс PointND для представления точки в N-мерном пространстве (с N координатами):
class PointND {
    short* coords {nullptr}; // координаты точки
    size_t dims {0}; // число координат
public:
    PointND() = default;
    PointND(short* cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for(size_t i = 0; i < dims; i++)
            coords[i] = cds[i];
    }
    PointND(PointND & other)//: coords(other.coords), dims(other.dims) { } 
    : PointND(other.coords, other.dims) { }
    ~PointND() { delete[] coords; }
                                                         
    short* get_coords() const { return coords; }
    size_t get_dims() const { return dims; }
    
    class Item{
        PointND* current {nullptr};
        int index {-1};
    public:
        Item(PointND* obj, int inx): current(obj), index(inx) { }
        operator short() 
        {
            if(index < 0 || index >= current->dims)
                return 0;
            return current->coords[index];
        }
        short operator = (short right)
        {
            if(index < 0 || index >= current->dims)
                return right;
            
            current->coords[index] = right;
            
            return right;
        }
    };

    Item operator[] (int index)
    {
        return Item(this, index);
    }
    
    PointND & operator = (PointND & other)
    {
        if(this == &other)
            return *this;
            
        delete [] coords;
        dims = other.dims;
        coords = new short[dims];
        for(int i = 0; i < dims; i++)
            coords[i] = other.coords[i];                    
        
        return *this;
    }
    PointND & operator ++ () 
    { 
        for(int i = 0; i < dims; i++)
            ++coords[i];
        return *this;
    }
    PointND operator ++ (int) 
    { 
        PointND tmp = *this;
        for(int i = 0; i < dims; i++)
            ++coords[i];
        return tmp;
    }
    PointND & operator -- () 
    { 
        for(int i = 0; i < dims; i++)
            --coords[i];
        return *this;
    }
    PointND operator -- (int) 
    { 
        PointND tmp = *this;
        for(int i = 0; i < dims; i++)
            --coords[i];
        return tmp;
    }

    PointND& operator += (PointND & right) 
    { 
        if (dims == right.dims) {
            for(int i = 0; i < dims; i++)
                coords[i] += right.coords[i];
        }

        return *this;
    }
    PointND& operator -= (PointND & right) 
    { 
        if (dims == right.dims) {
            for(int i = 0; i < dims; i++)
                coords[i] -= right.coords[i];
        }
        return *this;
    }
};

int main()
{
    short coords[] = {1, 2, 3, 4, 5};
    PointND pt(coords, std::size(coords));
    int val = pt[3]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
    pt[2] = val; // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
    PointND pt2;
    pt2 = pt; // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)
    pt2++; // увеличение каждой координаты на 1
    ++pt2; // увеличение каждой координаты на 1
    pt2--; // уменьшение каждой координаты на 1
    --pt2; // уменьшение каждой координаты на 1    
    pt += pt2; // к координатам coords объекта pt прибавляются соответствующие координаты объекта pt2
    pt -= pt2; // из координат coords объекта pt вычитаются соответствующие координаты объекта pt2

    for(int i = 0; i < pt2.get_dims(); i++)
        std::cout << pt2.get_coords()[i] << " ";    
      
    return 0;
}
