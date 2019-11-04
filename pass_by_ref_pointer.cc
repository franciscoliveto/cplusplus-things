#include <iostream>

using namespace std;

void SwapByReference(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

void SwapByPointer(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}


int main() {
  int a{2};
  int b{5};
  int &ref = a; // a reference
  int *ptr = &b; // a pointer

  ref = 4; // it modifies a
  *ptr = 8; // it modifies b

  cout << "Before swap" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  
  SwapByPointer(&a, &b);
  //SwapByReference(a, b);

  cout << "After swap" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  return 0;
}