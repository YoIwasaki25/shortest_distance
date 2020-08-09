#include<iostream>
#include "fast-cpp-csv-parser/csv.h"
#include<string>

using namespace std;

#define COLUMNS 4

int main(){
    string ic_name;
    int index;
    double dist_from_misato;
    double dist_from_yatabe;

    io::CSVReader<COLUMNS> in("testfile.csv");
    //in.read_header(io::ignore_extra_column,
    //         "index","ic_name","dist_from_misato","dist_from_yatabe");
    
    while(in.read_row(index,ic_name,dist_from_misato,dist_from_yatabe)){
        cout << "Index Number: "<< index <<endl;
        cout << "IC_NAME: "<< ic_name <<endl;
        cout << "From Misato: "<< dist_from_misato <<endl;
        cout << "From Yatabe: "<< dist_from_yatabe <<endl;

    }
    return 0;
}
