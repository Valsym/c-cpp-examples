/*
Класс ConvertToInt выполняет конвертирование строк в целые числа типа int следующим образом:

ConvertToInt conv_int;

int res_1 = conv_int("123"); // res_1 = 123
int res_2 = conv_int("a123"); // res_2 = 0 (ошибка конвертации)
int res_3 = conv_int("-123"); // res_3 = -123
int res_4 = conv_int("13b"); // res_4 = 0 (ошибка конвертации)
int res_5 = conv_int("+17"); // res_5 = 17
int res_6 = conv_int("1.7"); // res_6 = 1
*/

#include <iostream>
#include <string>
#include <cstring>

class ConvertToInt{
    const char* str {};
    int size {0};

public:
    ConvertToInt() = default;
    
    bool is_error() const 
    {
        for(int i = 0; i < size; i++){            
            if(strchr("-+.0123456789", str[i]) == NULL)
                return true; 
        }
        
        return false;
    }     
    int operator()(const char* s)
    {
        str = s;
        size = ((std::string)s).length();
        if(is_error())
            return 0;
        
        return atoi(str);
    }
};

int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    ConvertToInt str_to_int;

    std::cout << str_to_int(str);

    return 0;
}
