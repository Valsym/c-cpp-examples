#include <iostream>
#include <string>

struct BankAccount {
    std::string fio; // ФИО счета
    long volume {0}; // объем средств на счете

    BankAccount() = default;
    BankAccount(const std::string& fio, long vol) : fio(fio), volume(vol)
        { }
    BankAccount& operator+=(long vol) { volume += vol; return *this; }
    BankAccount& operator-=(long vol) { volume -= vol; return *this; }
    BankAccount& operator*=(long vol) { volume *= vol; return *this; }
    BankAccount& operator/=(long vol) { volume /= vol; return *this; }
    BankAccount& operator%=(long vol) { volume %= vol; return *this; }
};

class Bank {
    enum { max_accounts = 100 }; // максимальное количество счетов
    BankAccount* acs {nullptr}; // массив из счетов
    size_t count {0}; // текущее количество счетов
public:
    Bank()
    {
        acs = new BankAccount[max_accounts];
    }
    Bank(BankAccount* lst, size_t size)
    {
        count = (size > max_accounts) ? max_accounts : size;

        acs = new BankAccount[max_accounts];
        for(int i = 0;i < count; ++i)
            acs[i] = lst[i];
    }
    ~Bank() { delete[] acs; }
    Bank(const Bank& other) : count(other.count)
    {
        acs = new BankAccount[max_accounts];
        for(int i = 0;i < count; ++i)
            acs[i] = other.acs[i];
    }
    const BankAccount* get_accounts() const {return acs; } // возвращает массив acs
    size_t get_count() const { return count; } // возвращает значение поля count
    Bank& operator+=(BankAccount right) 
    {
        if(count < max_accounts)
            acs[count++] = right;
        return *this;
    }
    Bank& operator+(BankAccount right) 
    {
        if(count < max_accounts)
            acs[count++] = right;

        return *this;
    }
    
    Bank operator=(const Bank& other) 
    {
        if(this == &other)
            return *this;

        delete [] acs;
        acs = new BankAccount[max_accounts];
        count = other.count;
        for(int i = 0;i < count; ++i)
            acs[i] = other.acs[i];
        return *this;        
    }
};

int main(void) // Tests
{
    Bank balbank;
    BankAccount ac("Sergey", 4320405);
    balbank += ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    balbank = balbank + ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts

    ac += 1000; // добавление на счет средств: volume += 1000; fio остается без изменений
    ac -= 1000; // списание со счета средств: volume -= 1000; fio остается без изменений
    ac *= 1.5; // увеличение средств на счете в 1.5 раза с отбрасыванием дробной части: volume *= 1.5; fio остается без изменений
    ac /= 2; // уменьшение средств на счете в 2 раза с отбрасыванием дробной части: volume /= 2; fio остается без изменений
    ac %= 4; // вычисление целого остатка от деления: volume %= 4; fio остается без изменений

    Bank open_b;
    open_b = balbank; // копирование счетов

    std::cout <<  open_b.get_count() << "\n";
    for(int i = 0; i < open_b.get_count(); i++)
        std::cout <<  open_b.get_accounts()[i].fio  << " " <<  
            open_b.get_accounts()[i].volume << "\n";
  //+++++++++++++++++++++++++++++
  
    Bank my_bank;
    BankAccount ac{"А. Дзюба", 43056};
    my_bank += ac;
    ac = {"П. Гагарина", 1335395};
    my_bank += ac;
    ac = {"О. Бузова", 0};
    my_bank += ac;
    ac = {"Тимати", -546};
    my_bank += ac;

    for(int i = 0; i < my_bank.get_count(); i++)
        std::cout <<  my_bank.get_accounts()[i].fio  << " " <<  
            my_bank.get_accounts()[i].volume << "\n";

  return 0;
}
