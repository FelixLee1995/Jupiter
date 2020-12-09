#include <iostream>

using namespace std;


typedef void(*Fun)(void);


class Base{

    public:

    int a;
    virtual void FuncF(){printf("base func F\n");};
    virtual void FuncG(){printf("base func G\n");};
    virtual void FuncH(){printf("base func H\n");};

};


int main() {
   
    Base obj;
    Fun pFun = nullptr;

    cout <<  "虚函数表的地址： " << &obj << endl;
    cout << "虚函数表的第一个函数的地址： " <<  (void *)*(void *)(&obj) << endl;

    pFun = (Fun)* ((void *)*(void *)(&obj));

    pFun();
    return 0;
}