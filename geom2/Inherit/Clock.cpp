// Насдледование классов

#include <iostream>

class Clock{
protected:    
    unsigned time_current {0}; // текущее время в секундах
public:
    Clock(unsigned time_current = 0): time_current(time_current) {}
    void set_time(unsigned tm) { this->time_current = tm; } // заносит в поле time_current значение tm
    unsigned get_hours() const 
    { return time_current / 3600; } // возвращает количество часов в time_current
    unsigned get_minutes() const 
    { return (time_current - (time_current / 3600) * 3600) / 60; }// возвращает количество минут в time_current (за вычетом часов)
    unsigned get_seconds() const 
    { return time_current - get_hours() * 3600 - get_minutes() * 60; } // возвращает количество секунд в time_current (за вычетом часов и минут)
};

class ClockShow : public Clock{
    
public:     
    enum time_format { tm_hhmmss = 1, tm_hms = 2, tm_ssmmhh = 3, tm_smh = 4};
private:
    time_format format {tm_hhmmss}; // формат отображения времени
public:    
    ClockShow(unsigned tm = 0, time_format format = tm_hhmmss)
        : Clock(tm), format(format) {}
    void show_time() const // выполняет отображение в консоль времени заданном формате
    {
        switch (format)
        {
        case tm_hhmmss:
            printf("%02u:%02u:%02u", get_hours(), get_minutes(), get_seconds()) ;
            break;
        case tm_hms:
            printf("%u:%u:%u", get_hours(), get_minutes(), get_seconds()) ;
            break;
        case tm_ssmmhh:
            printf("%02u:%02u:%02u", get_seconds(), get_minutes(), get_hours()) ;
            break;
        case tm_smh:
            printf("%u:%u:%u", get_seconds(), get_minutes(), get_hours()) ;
            break;
        
        default:
            printf("%02u:%02u:%02u", get_hours(), get_minutes(), get_seconds()) ;    
            break;
        }
    }

};

int main()
{
    unsigned tm;// = 54305;
    std::cin >> tm;
    ClockShow clock(tm, ClockShow::tm_hms);
    
    clock.show_time(); // 15:5:5

    return 0;
}
