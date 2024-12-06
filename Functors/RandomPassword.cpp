/*
Класс RandomPassword для генерации случайных паролей. Объекты этого класса должны создаваться командой:
RandomPassword rnd(psw_chars, min_length, max_length);

Непосредственная генерация одного пароля должна выполняться командой:
std::string psw = rnd();
Например:
RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);
std::string psw_1 = rnd(); // psw_1: hqt5!v@gk
std::string psw_2 = rnd(); // psw_2: vmdp&wgs*#qd
*/

#include <iostream>
#include <string>
#include <stdlib.h>

class RandomPassword {
    std::string psw_chars {};
    unsigned min_length {1};
    unsigned max_length {1};
public:
    RandomPassword(std::string psw_chars, unsigned minl, unsigned maxl)
        : psw_chars(psw_chars), min_length(minl), max_length(maxl) {}
    std::string operator()()
    {
        std::string psw {};
        int psw_chars_len = psw_chars.length();
        int len = (rand() % (max_length - min_length) + min_length);

        for(int i = 0; i < len; i++)
            psw += psw_chars[rand() % (psw_chars_len - 1)];
        
        return psw;
    }
};

int main()
{
    RandomPassword rnd("qwertyuiopasdfghjklzxcvbnm0123456789!@#$%&*", 5, 15);
    std::string psw_1 = rnd(); // psw_1: hqt5!v@gk    
    std::string psw_2 = rnd(); // psw_2: vmdp&wgs*#qd

    std::cout << psw_1 << "\n" << psw_2 << "\n" << a;

  return 0;
}
