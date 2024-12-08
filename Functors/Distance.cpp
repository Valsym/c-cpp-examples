/*
  В классе переопределяются стандартные операции, в т.ч. использ. функторы,
  а также понятия lvalue и rvalue выражений и rvalue-ссылки
*/

#include <iostream>
#include <string>

class Distance{
    int dist {0}; // дистанция
public:
    Distance(int dist = 0): dist(dist) { }
    Distance operator += (int r) { dist += r; return *this; }
    Distance operator -= (int r) { dist -= r; return *this; }
    Distance operator *= (int r) { dist *= r; return *this; }
    Distance operator /= (int r) { dist /= r; return *this; }
    Distance operator = (Distance & other) 
    { 
        dist += other.dist; 
        return *this;     
    }
    operator int() { return dist; }
    int operator ()() { return dist; }
};

int main()
{
    Distance d1 = 100;
    d1 += 50; // dist = 150
    Distance d2 = d1 += 10; // dist в d1 и d2 равны 150+10 = 160
    Distance res = d2 -= 100; // dist = 60
    Distance sp = d1 *= 5;
    Distance ep = d1 /= 7;
    int res2 = d1(); // возвращает значение поля dist

    std::cout << res2 << "\n";

    Distance d = 547, & lnk_d = d, && lnk_r_d = std::move(d);
    
    lnk_r_d += 100;
    std::cout << d;

    return 0;
}
