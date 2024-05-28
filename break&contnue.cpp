#include<iostream>
using namespace std;

int main()
{   
    int potion=30;
    for(int health=1;health<=100;health--){
        if(health==0){
            continue;
            cout<<"You are dead"<<endl;
        }
        if(potion==0){
            break;
        }
        cout<<"you are damaged"<<endl;
        potion=potion-10;
    }
}