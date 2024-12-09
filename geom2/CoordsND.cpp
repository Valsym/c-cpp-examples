/*
В класс CoordsND ((координаты в N-мерном пространстве)) добавлены:
конструктор копирования, 
конструктор перемещения, 
операция присваивания копированием,
операция присваивания перемещением
*/

#include <iostream>

class CoordsND {
    enum {max_coords = 10};
    int *coords {nullptr}; // массив значений координат
    int size {0}; // количество координат (не более max_coords)
public:
    CoordsND(): coords(nullptr), size(0) { }
    CoordsND(int* lst, int sz)
    {
        size = (sz > max_coords) ? max_coords : sz;

        coords = new int[size];
        for(int i = 0;i < size; ++i)
            coords[i] = lst[i];
    }
    ~CoordsND() { delete[] coords; }
    CoordsND(const CoordsND& other): size(other.size)
    {
        coords = new int[size];
        for(int i = 0; i < size; i++)
            coords[i] = other.coords[i];
    }
    CoordsND(CoordsND&& move) noexcept : size(move.size) 
    {
        coords = move.coords;
        move.coords = nullptr;
    }
    CoordsND& operator = (CoordsND&& right) noexcept
    {
        if(this == &right) return *this;
        delete [] coords;
        size = right.size;
        coords = right.coords;
        right.coords = nullptr;
        return *this;
    }
    CoordsND& operator = (const CoordsND& other)
    {
        if(this == &other) return *this;
        delete [] coords;
        size = other.size;
        coords = new int[size];
        for(int i = 0; i < size; i++)
            coords[i] = other.coords[i];
        return *this;
    }

    int* get_coords() { return coords; }
    int get_size() const { return size; }
};

int main()
{
    int crds[]{-4, 10, 0, 77, 14};
    int size = std::size(crds);
    CoordsND coords {crds, size};

    for(int i = 0; i < size; i++)
        std::cout << coords.get_coords()[i] << " ";

    return 0;
}
