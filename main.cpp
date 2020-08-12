#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<string>
#include<vector>
#include<array>

using namespace std;

#define COLUMNS 4
#define CONSUMPTION_TAX 1.1

typedef struct IC{
    string route;       //ルート
    string nn_1;        //node name 1
    string nn_2;        //node name 2
    string distance;    //distance
    string highway;     //高速名
    string node_1;
    string node_2;
}st;

st* search_ic(string input){                  
    int i = 0;
    int num;

    struct IC ic[256]; //読み込みファイルの　index+1 以上のサイズを持つこと
    struct IC *p;

    p = ic;

    string line;

    ifstream myFileStream("ic_list.csv");
    if(!myFileStream.is_open()){
        cout << "File failed to open" << endl;
    }
    while(getline(myFileStream, line)){
        stringstream ss(line);
        getline(ss, ic[i].route, ',');
        getline(ss, ic[i].nn_1, ',');
        getline(ss, ic[i].nn_2, ',');
        getline(ss, ic[i].distance, ',');
        getline(ss, ic[i].highway, ',');
        getline(ss, ic[i].node_1, ',');
        getline(ss, ic[i].node_2, ',');
        
        i++;
    }

    for (;;){
        if(p->nn_1 == ""){
            cout << "インターチェンジが見つかりません" << endl;
            break;
        }else if(p->nn_1 == input){
            num = stoi(p->route);
            //cout << p->nn_1 << "から" << p->nn_2 << "までの距離" << p->distance << "km" << endl;
            //cout << "高速名:　" << p->highway << endl;
            //cout << "node" << p->node_1 << " to" << " node" << p->node_2 << endl;
            break;        
        }
        p++;
    }
    return p;
}

double cost(double arg){
    return (150 + 24.6 * arg) * CONSUMPTION_TAX;  
}

int main(){
    string input_start, input_end;
    double distance;
    double cst;
    st* p; st* q; st* tmp;

    cout << "出発ICを入力してください" << endl;
    cin >> input_start;
    p = search_ic(input_start);

    cout << "到着ICを入力してください" << endl;
    cin >> input_end;
    q = search_ic(input_end);

    if (stoi(q->route) - stoi(p->route) < 0){
        tmp = p;
        p = q;
        q = tmp;
    
        for (;;){
            if (stod(p->route) == stod(q->route))
                break;
            distance += stod(p->distance);
            p++;
        }
        cout << p->nn_1 << "から" << q->nn_1 << "までの距離" << endl;
        
    }else{
        for (;;){
            if (stod(p->route) == stod(q->route))
                break;

            distance += stod(p->distance);
            p++;
        }
        cout << p->nn_1 << "から" << q->nn_1 << "までの距離" << endl;
    }
    
    cout << distance << "km" << endl;

    cst = cost(distance);    

    cout << " 料金:　" << cst << "円" << endl;
    return 0;
}
