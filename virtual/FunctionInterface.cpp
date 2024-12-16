/*  Виртуальные (virtual) методы (функции) */

#include <iostream>
#include <iomanip>

class FunctionInterface {
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }
};

class LinearFunction : public FunctionInterface {
    double k {0.0}; // угловой коэффициент
    double b {0.0}; // смещение
public:   
    LinearFunction(double k, double b) : k(k), b(b) {}
    virtual double func(double arg) // возвращает значение линейной функции f(arg) = k*arg+b для аргумента arg
        { return k*arg+b; }
    virtual double operator()(double arg) // то же самое, только через оператор ()
        { return k*arg+b; }
};

class ReluFunction : public FunctionInterface {
public:
    ReluFunction() {}
    virtual double func(double arg) // возвращает значение функции f(arg) = arg, arg > 0, иначе 0
        { return arg > 0 ? arg : 0 ; }
    virtual double operator()(double arg) // то же самое, только через оператор ()
        { return arg > 0 ? arg : 0 ; }
};

int main(void)
{
    FunctionInterface* funcs[3] {nullptr};

    funcs[0] = new LinearFunction {0.5, 0};
    funcs[1] = new LinearFunction {1.2, -5.4};
    funcs[2] = new ReluFunction;
    double arg;
    
    std::cin >> arg;
    for(auto i : funcs)
      std::cout << std::fixed << std::setprecision(2) << i->func(arg) << " ";

    for(auto i : funcs)
        delete i;

    return 0;
}
