/* Вычисление количества точек с целочисленными координатами (x, y), принадлежащих заданному четырехугольнику */
#include <iostream>
#include <cmath>

enum { corners = 4 };

struct point {
    int x, y;
};

double get_length(point& a, point& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int sq_tr(point& a, point& b, point& c)
{
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));        
} 
int sq_4(point p[])
{
    return sq_tr(p[0], p[1], p[2]) + sq_tr(p[0], p[3], p[2]);
}

bool is_into(point figure[], point& pt, int src_4)
{
    int dest4 = 0.0; 

    for(int i = 0; i < corners; i++)
        dest4 += sq_tr(figure[i], figure[(i+1) %4], pt);
    
    //return abs(src_4 - dest4) < 0.0001;
    return src_4 == dest4;
}   

int min_x(point figure[])
{
    int min = figure[0].x;
    for(int i = 1; i < corners; i++)
        min = min > figure[i].x ? figure[i].x : min;
    return min;
}

int min_y(point figure[])
{
    int min = figure[0].y;
    for(int i = 1; i < corners; i++)
        min = min > figure[i].y ? figure[i].y : min;

    return min;
}

int max_x(point figure[])
{
    int max = figure[0].x;
    for(int i = 1; i < corners; i++)
        max = max < figure[i].x ? figure[i].x : max;

    return max;
}

int max_y(point figure[])
{
    int max = figure[0].y;
    for(int i = 1; i < corners; i++)
        max = max < figure[i].y ? figure[i].y : max;
    return max;
}  

int main()
{
    point figure[corners];

    int count = 0;
    while(count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2)
        count++;

    if(count != corners) {
        puts("Неверное количество или формат входных данных.");
        return 1;
    }

    // здесь продолжайте функцию main
    int src_4 = sq_4(figure);
    int sum = 0;
    point pt;

    for(int y = min_y(figure); y <= max_y(figure); y++){        
        pt.y = y;
        for(int x = min_x(figure); x <= max_x(figure); x++){
            pt.x = x; 
            if(is_into(figure, pt, src_4))
                ++sum;
        }
    }
    std::cout << sum;
    
    return 0;
}
