class DArray {
    enum {
        start_length_array = 8, // начальная длина массива
        resize_factor = 2,      // множитель для увеличения длины массива
        max_length_array = 30,  // максимальная длина массива
        value_error = 2123456789, // специальное значение для обозначения ошибки данных
    };

    class Item {
        enum type_assign {
            iadd_operator, isub_operator, imul_operator, idiv_operator, iddiv_operator,
            iincpref_operator, idecpref_operator, iincpost_operator, idecpost_operator
        };
        DArray* current {nullptr};
        int index {-1};

        int _assign_operator(int right, type_assign t);
 
    public:
        Item(DArray* obj, int idx) : current(obj), index(idx)
            { }
 
        operator int() const;
        int operator=(int right);
        int operator+=(int right);
        int operator-=(int right);
        int operator*=(int right);
        int operator/=(int right);
        int operator%=(int right);
        int operator++(); // prefix form
        int operator--(); // prefix form
        int operator++(int right); // postfix form
        int operator--(int right); // postfix form
    };
 
    int* data {nullptr};
    int length {0};   // число записанных в массив значений
    int capacity {0}; // физический размер массива
 
    void _resize_array(int size_new); // увеличение размера массива data но не более max_length_array элементов
public:
    DArray() : length(0), capacity(start_length_array)
    {
        data = new int[start_length_array];
        capacity = start_length_array;
    }
 
    DArray(const DArray& other) : length(other.length), capacity(other.capacity)
    {
        data = new int[capacity];
        for(int i = 0; i < length;++i)
            data[i] = other.data[i];
    }
 
    ~DArray() { delete[] data; }
 
    int size() const { return length; }
    int capacity_ar() const { return capacity; }
    const int* get_data() const { return data; }
 
    const DArray& operator=(const DArray& other);
 
    void push_back(int value);
    int pop_back();
    
    Item operator[](int index)
    {
        return Item(this, index);
    }
    const DArray& operator+=(const DArray& other);
    const DArray operator+(const DArray& other);
};
