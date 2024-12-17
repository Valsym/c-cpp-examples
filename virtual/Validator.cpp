#include <iostream>

class Validator {
public:
    virtual bool is_valid(int x) { return true; } 
};

class PositiveValidator : public Validator {
public:
    virtual bool is_valid(int x) { return x > 0 ? true : false; }
};

class RangeValidator : public Validator {
    int left, right;
public:
    RangeValidator(int left, int right): left(left), right(right) {}
    virtual bool is_valid(int x) { return left <= x && x <= right ? true : false; }
};

int main(void)
{
    Validator* vs[3] {nullptr};
    vs[0] = new PositiveValidator(); 
    vs[1] = new RangeValidator(-5, 5); 
    vs[2] = new RangeValidator(-15, 10);
    int num;
    
    std::cin >> num;
    for(auto i : vs)
        std::cout << i->is_valid(num) << " ";

    for(auto i : vs)
        delete i;

    return 0;
}
