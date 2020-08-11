#include<iostream>
#include "fast-cpp-csv-parser/csv.h"
#include<string.h>
#include<string>
#include<vector>

using namespace std;

#define COLUMNS 4
#define __STDC_WANT_LTB_EXT1__ 1

struct IC{
    string name; //インター名
    double dfm;    //三郷からの距離[km]
    double dfy;    //谷和原からの距離[km]
};

void input_file(){
    int index;                  
    string ic_name;             
    double dist_from_misato;    
    double dist_from_yawara;
    int i = 0;
    string input_str;

    struct IC ic[30];
    struct IC* p;

    p = ic;

    io::CSVReader<COLUMNS> in("testfile.csv");

    while(in.read_row(index,ic_name,dist_from_misato,dist_from_yawara)){  
        ic[i].name = ic_name;
        ic[i].dfm = dist_from_misato;
        ic[i].dfy = dist_from_yawara;
        i++;
    }

    cout << "インターチェンジを入力してください" << endl;
    cin >> input_str;

    for (;;){
        if(p->name == ""){
            cout << "インターチェンジが見つかりません" << endl;
            break;
        }else if(p->name == input_str){
            cout << p->dfm << endl;
            cout << p->dfy << endl;
            break;        
        }
        p++;
    }
}

int main(){
    input_file();
    return 0;
}
