/*
Класс ExtensionFilter для выбора файлов с указанными расширениями. Объекты этого класса должны создаваться командой:

ExtensionFilter image_flt("bmp|png|jpg");
здесь строка "bmp|png|jpg" содержит расширения bmp, png, jpg, которые следует выделять из списка файлов. 

Непосредственная фильтрация (отбор) файлов выполняется следующим образом:

enum { max_count_files = 100 };
std::string lst[] = {"jim.jpg", "net.avi", "out1.png", "rep1.gif", "text.docx", "ava.8.jpg"};
std::string flt_lst[max_count_files];
int count = image_flt(lst, size_lst, flt_lst, max_count_files);
Здесь lst - массив с файлами; size_lst - длина массива lst (число элементов); 
flt_lst - массив с результатом фильтрации; 
max_count_files - максимальный размер массива flt_lst. 
Возвращаемое значение count содержит число выделенных файлов из массива lst в массив flt_lst. 
В приведенном примере получим результат:
flt_lst: "jim.jpg", "out1.png", "ava.8.jpg"
count: 3
*/

#include <iostream>
#include <string>
#include <cstring>

class ExtensionFilter {    
    std::string exts {};
public:
    ExtensionFilter(std::string exts): exts(exts) {}
    int operator()(std::string lst[], int size_lst, std::string flt_lst[], int max_count_files)
    {
        char* ext;          
        int cnt = 0;
        for(int i = 0; i < size_lst && i < max_count_files; i++){
            ext = strrchr(lst[i].data(), '.');
            if(strstr(exts.data(), ext+1) != NULL)
                flt_lst[cnt++] = lst[i];
        }
        return cnt;
    }
};

int main()
{
    ExtensionFilter image_flt("bmp|png|jpg");
    
    std::string lst[] = {"jim.jpg", "net.avi", "out1.png", "rep1.gif", "text.docx", "ava.8.jpg"};
    std::string flt_lst[max_count_files];
    int count = image_flt(lst, 6, flt_lst, max_count_files);

    std::cout << count;
}
