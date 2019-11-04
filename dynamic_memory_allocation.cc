#include <iostream>
#include <exception>
#include <new>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char *p1 = new (nothrow) char;
    if (p1 == nullptr) {
      // error allocating memory
    }
    *p1 = 'c';
    delete p1;

    int *p2 = new (nothrow) int;
    if (p2 == nullptr) {
      // error allocating memory
    }
    *p2 = 32;
    delete p2;

    try {
      long *p3 = new long;
      *p3 = 3828283;
      delete p3;
    }
    catch (bad_alloc &e) {

    }

    try {
      float *p4 = new float(2.3f);
      if (*p4 == 2.3f) {
        *p4 = 1.41f;
      }
      cout << *p4 << endl;
      delete p4;
    }
    catch (bad_alloc &e) {

    }

    try {
      double *p5 = new double(1.4872333);
      (*p5)++;
      cout << *p5 << endl;
      delete p5;
    }
    catch (bad_alloc &e) {

    }

    const int kMaxStringLength = 32;

    char *c_string = new (nothrow) char[kMaxStringLength];
    if (c_string == nullptr) {
      // error allocating memory.
    }
    strcpy(c_string, "this is a c-string.");
    cout << c_string << endl;
    delete []c_string;

    try {
      int *array = new int[32];

      srand(time(0));
      for (int i = 0; i < 32; i++) {
        *(array + i) = rand() % 100; // generate a random number between 0 and 99
      }

      for (int i = 0; i < 32; i++) {
        cout << *(array + i) << " ";
      }
      cout << endl;
      delete []array;
    }
    catch (bad_alloc &e) {

    }

    return 0;
}