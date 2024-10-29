#include <iostream>

using namespace std;
using THING = struct {
   char name[50]; 
   unsigned int weight ; 
};

void swap(THING* a, THING* b)
{
    THING t = *a;
    *a = *b;
    *b = t;
}
void sort_t(THING* ar, int len)
{
    for(THING* i = ar; i < ar + len - 1; i++)   
        for(THING* j = i + 1; j < ar + len; j++)             
            if(i->weight < j->weight)
                swap(i, j);
}   

int main()
{
    THING things[] = {{"карандаш", 20}, {"зеркальце", 100}, {"зонт", 500}, {"рубашка", 300}, 
{"брюки", 1000}, {"бумага", 200}, {"молоток", 600}, {"пила", 400}, {"удочка", 1200},
{"расческа", 40}, {"котелок", 820}, {"палатка", 5240}, {"брезент", 2130}, {"спички", 10}};
    int N, sum = 0, len = sizeof(things) / sizeof(*things);

    cin >> N; // Enter max weight, kg
    N *= 1000;
    sort_t(things, len);
    for(THING* i = things; sum < N; i++)
        if(sum + i->weight <= N){
            cout << i->weight << ' ';
            sum += i->weight;
        }

    return 0;
}
