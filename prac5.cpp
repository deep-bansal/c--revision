#include <bits/stdc++.h>
using namespace std;

class Car {
  int* price;
public:
  string name;
  int wheels;

  Car(string n, int p, int w) {
    cout << "This is my Constructor2" << endl;
    name = n;
    price = &p;
    wheels = w;

  }

  // void operator = (Car &X) {
  //   name = X.name;
  //   price = X.price;
  //   wheels = X.wheels;
  // }

  void print() {
    cout << name << endl;
    cout << price << endl;
    cout << wheels << endl;
    cout << "--------------------" << endl;
  }

  void setPrice(int p){
    price = &p;
  }

  int getPrice() const {
    return *price;

  }
 

};

ostream& operator << (ostream &o, Car &X){
   o << X.name << endl;
    o << X.getPrice() << endl;
    o << X.wheels << endl;
    o << "--------------------" << endl;

    return o;

}

int main(int argc, char const *argv[])
{
  int x = 2000;
  Car C("BMW",x,4);

  Car D("AUDI",x,8);
  int z = 1000;
  D.setPrice(z);

  cout<<C<<D;

  cout<<C.getPrice()<<endl;
  cout<<D.getPrice()<<endl;


 
  return 0;
}