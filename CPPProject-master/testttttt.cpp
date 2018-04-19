#include<iostream>
#include<string>
using namespace std;

void thrower(){
    throw("fuck");
}



int main(){
    try{
        thrower();
    }
    catch(string e){
        cout << e;
        cout<<
    }

}