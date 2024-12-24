#include <iostream>
#include <string>

enum request_method { // обрабатываемые методы
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request { // объект запроса
    request_method method {method_get};
    std::string url;
    std::string data;
};

class RetriveMixin {
    request_method method{ method_get };
public:
    RetriveMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~RetriveMixin() { }
    std::string get(const Request& request) { return "GET: " + request.url; }
};

class CreateMixin {
    request_method method{ method_post };
public:
    CreateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~CreateMixin() { }
    std::string post(const Request& request) { return "POST: " + request.url; }
};

class UpdateMixin {
    request_method method{ method_put };
public:
    UpdateMixin(request_method* ms, int index) { ms[index] = method; }
    virtual ~UpdateMixin() { }
    std::string put(const Request& request) { return "PUT: " + request.url; }
};

class GeneralView : public RetriveMixin, public CreateMixin {
    enum { max_methods = 4 }; // максимальное число разрешенных методов
    int count_methods{ 0 }; // число разрешенных методов
    request_method allowed_methods[max_methods]{ method_get, method_post }; // массив из разрешенных методов

    bool is_method_exists(request_method method) // возвращает true, если method присутствует в массиве allowed_methods, иначе false 
    { 
        for(int i = 0; i < max_methods; i++) 
            if(method == allowed_methods[i]) return true; 
        return false; 
    }
public:
    GeneralView() 
    : RetriveMixin(allowed_methods, 0), 
      CreateMixin(allowed_methods, 1), count_methods(2) { }
    
    std::string render_request(const Request& request)
    { 
        if(!is_method_exists(request.method)) return "";
        if(request.method == method_get) return RetriveMixin::get(request);
        if(request.method == method_post) return CreateMixin::post(request);
        //if(request.method == method_put) return UpdateMixin::put(request);
    }
};

int main(void)
{
    GeneralView gw;
    
    Request request {
    method_post,    
    "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov",
    "<h1>Множественное наследование</h1>"};
    std::string res = gw.render_request(request);
    std::cout << res;

    return 0;
}
