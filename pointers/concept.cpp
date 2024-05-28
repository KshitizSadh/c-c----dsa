#include<iostream>
using namespace std;
int main(){
    int a = 3;
    int* b = &a;
    //& address of varible
    cout<<"this is address of a"<<&a<<endl;

    cout<<"this is address of a"<<b<<endl;
    cout<<"this value at address of a is "<<*b<<endl;
    // pointer to pointer 
    int** c = &b;
    cout<<"this value of address of b is "<<&b<<"\n";
    cout<<"this value at address of c is "<<*c<<"\n";
    cout<<"this value at address of Value_at(value_at (c)) is "<<**c<<"\n";
    return 0;
}