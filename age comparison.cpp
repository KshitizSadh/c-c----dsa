#include<iostream>
using namespace std;
int main(){
    int Kshitiz,ved,unnati;
    cin>>Kshitiz>>ved>>unnati;

    if(Kshitiz>ved){
        if(Kshitiz>unnati){
            cout<<"Kshitiz is older\n";
        }
        else{
            cout<<"unnati is older\n";
        }
    }
    else{
        if(ved>unnati){
            cout<<"ved is older\n";
        }
        else{
            cout<<"unnati is older\n";
        }
    }
    return 0;
}