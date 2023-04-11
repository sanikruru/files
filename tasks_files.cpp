#include <iostream>
#include <array>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

struct Student {
    string fam;
    float avmark;
    int year;
};

const int N=10;

void task1();
void task2();
void task3();

string randfam();
float randav();
int randyear();

int main(){

    int a;

    cout<<"task? ";
    cin>>a;

    switch(a){
        case (1):{task1(); break;}
        case (2):{task2(); break;}
        case (3):{task3(); break;}
        default:{cout<<"err num task\n";}
    }

    return 0;

}

void task1(){

    char buff[1024];
    fstream fin;
    int offset=117;
    int fieldsize=offset+30;

    fin.open("data_samples/1.mp3", ios::in|ios::binary);
    if (!fin.is_open()) cout<<"opening file is wrong";

    fin.read(buff, 1024);
    fin.close();

    for (int i=offset; i<fieldsize; i++) cout<<buff[i];
    cout<<endl;

}

void task2(){

    fstream fin, fout;
    float x0, x1, dx, res;
    int p=2, k=1;

    fin.open("in1.txt", ios::in);
    fin>>x0>>x1>>dx;
    fin.close();

    fout.open("out1.txt", ios::out);
    fout<<"x  |  y"<<endl;

    while (x0<x1){
        fout<<x0<<"  |  ";
        res+=pow(-1, p)*k*x0;
        fout<<res<<endl;;
        x0+=dx;
        p++;
        k++;
    }

    fout.close();

}

void task3(){

    array <Student, N> stud;
    fstream fout;
    srand(time(0));

    for (int i=0; i<N; i++){
        stud[i].fam=randfam();
        stud[i].avmark=randav();
        stud[i].year=randyear();
    }

    fout.open("out2.txt", ios::out);
    for (int i=0; i<N; i++){
        fout<<"surname: "<<stud[i].fam
            <<"; average rating: "<<stud[i].avmark
            <<"; course: "<<stud[i].year
            <<endl;
    }
    fout.close();
}

string randfam(){

    int a=rand()%3;
    string out;

    switch(a){
    case 0:{out="Ivanov"; break;}
    case 1:{out="Popkov"; break;}
    case 2:{out="Dumkin"; break;}
    case 3:{out="Dojdev"; break;}
    default:{out="err randfam";};
    }

    return out;
}

float randav(){
    float a=rand()%4;
    float r=rand()%9+1;
    a+=1/r;
    return a;
}

int randyear(){
    int a=rand()%3+1;
    return a;
}
