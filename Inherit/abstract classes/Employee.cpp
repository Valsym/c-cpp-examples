#include <iostream>
#include <string>

class Employee {
public:
    virtual const std::string& get_fname() const = 0; // для получения имени сотрудника
    virtual const std::string& get_lname() const = 0; // для получения фамилии сотрудника
    virtual short get_old() const = 0; // для получения возраста сотрудника
};

class Lector: public Employee {
    std::string first_name, last_name; short old {0}; int salary {0};
public:
    Lector(std::string first_name, std::string last_name, short old, int salary = 0)
        : first_name(first_name), last_name(last_name), old(old)
        { set_salary(salary); }
    void set_salary(int salary) { this->salary = salary > 0 ? salary : this->salary; } // задает значение поля salary с проверкой на положительность параметра salary (если не так, то поле не менять)
    int get_salary() const { return this->salary; } // возвращает значение поля salary (зарплата)
    virtual const std::string& get_fname() const override { return first_name; } // для получения имени сотрудника
    virtual const std::string& get_lname() const  override { return last_name; } // для получения фамилии сотрудника
    virtual short get_old() const override { return old; } // для получения возраста сотрудника
};

class Laborant : public Employee {
    std::string first_name, last_name; short old {0}; std::string job_title;
public:
    Laborant(std::string first_name, std::string last_name,short old, std::string job_title = "")
        : first_name(first_name), last_name(last_name), old(old) 
        { set_job_title(job_title); }
    void set_job_title(const std::string& job_title) { this->job_title = job_title; } // задает значение поля job_title (должность)
    const std::string& get_job_title() const { return job_title; } // возвращает значение поля job_title
    virtual const std::string& get_fname() const override { return first_name; } // для получения имени сотрудника
    virtual const std::string& get_lname() const  override { return last_name; } // для получения фамилии сотрудника
    virtual short get_old() const override { return old; } // для получения возраста сотрудника
};

enum {max_persons=255};

int main(void)
{
    Employee* staff[max_persons] {nullptr};
    staff[0] = new Lector {"Sergey", "Balakirev", 33, 85000};
    staff[1] = new Laborant {"Elena", "Pozdnjakova", 27, "Programmer"};
    staff[2] = new Lector {"Olga", "Levkina", 38, 120000};
    
    for(int i = 0; i < 3; i++)
        std::cout << staff[i]->get_fname() << " ";

    for(int i = 0; i < 3; i++)
        delete staff[i];

    return 0;
}
