#include<string>

#ifndef SHORT_DISTANCE_HPP
#define SHORT_DISTANCE_HPP

typedef struct IC{
    std::string route;       //ルート
    std::string nn_1;        //node name 1
    std::string nn_2;        //node name 2
    std::string distance;    //distance
    std::string highway;     //高速名
    std::string node_1;
    std::string node_2;
}st;

class Distance{
private:
public:
    Distance();
    ~Distance();
    double cost(double arg);
    st* search_ic(std::string args);
};

#endif