#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<string>
#include<vector>

using namespace std;

#define COLUMNS 4
#define __STDC_WANT_LTB_EXT1__ 1

struct IC{
    string name; //インター名
    string dfm;    //三郷からの距離[km]
    string dfy;    //谷和原からの距離[km]
};

void input_file(){
    string index;                  
    string ic_name;             
    string dist_from_misato;    
    string dist_from_yawara;
    int i = 0;
    string input_str;

    struct IC ic[40]; //読み込みファイルの　index+1 以上のサイズを持つこと
    struct IC* p;

    p = ic;

    string line;

    ifstream myFileStream("testfile.csv");
    if(!myFileStream.is_open()){
        cout << "File failed to open" << endl;
    }
    while(getline(myFileStream, line)){
        stringstream ss(line);
        getline(ss, index, ',');
        getline(ss, ic[i].name, ',');
        getline(ss, ic[i].dfm, ',');
        getline(ss, ic[i].dfy, ',');
        cout << ic[i].name << endl;
    i++;
    }
    cout << "インターチェンジを入力してください" << endl;
    cin >> input_str;

    for (;;){
        if(p->name == ""){
            cout << "インターチェンジが見つかりません" << endl;
            break;
        }else if(p->name == input_str){
            cout << "三郷からの距離:　" << p->dfm << endl;
            cout << "谷田部からの距離:　" << p->dfy << endl;
            break;        
        }
        p++;
    }
}

int main(){
    input_file();
    return 0;
}
