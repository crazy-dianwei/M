#include <iostream>

using std::cout;
using std::endl;

void rref(int &&a){
    std::cout<<"rref: "<<a<<std::endl;
}

void B(int &&ref_r){
    ref_r = 1;
}

void A(int &&ref_r){
    //B(ref_r);

    B(std::move(ref_r));
    B(std::forward<int>(ref_r));
}

void change2(int &&ref_r){
    ref_r = 1;
}

void change3(int &ref_l){
    ref_l = 1;
}

void change(int &&ref_r){
    //change2(ref_r);

    change2(std::move(ref_r));
    change2(std::forward<int&&>(ref_r));

    change3(ref_r);
    change3(std::forward<int &>(ref_r));
}

class Base {
public:
    Base() {
        cout << "Base()" << endl;
    }

    ~Base() {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived()" << endl;
    }

    ~Derived() {
        cout << "~Derived()" << endl;
    }
};

int main(){
    {
        std::cout<<(-1%3)<<std::endl;
        std::cout<<(-4%3)<<std::endl;

        Base *b1 = new Derived;
        delete b1;
        cout<<endl;
        Derived d;
        Base &b2 =d;
    }




    {
        int a = 5;
        A(std::move(a));
        change(std::move(a));
    }

    std::cout<<"hello:addr"<<&("hello")<<std::endl;

    int lv = 10;
    //rref(lv);
    rref(std::move(lv));
    rref(5);
    rref(std::move(5));


    return 0;
}


