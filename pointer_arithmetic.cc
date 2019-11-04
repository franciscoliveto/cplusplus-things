/*
*p++   // same as *(p++): increment pointer, and dereference unincremented address
*++p   // same as *(++p): increment pointer, and dereference incremented address
++*p   // same as ++(*p): dereference pointer, and increment the value it points to
(*p)++ // dereference pointer, and post-increment the value it points to 
*/
#include <iostream>

using namespace std;

int main() {
    int x(2), n;
    int *p1 = &x;  // non-const pointer to non-const int
    const int *p2 = &x;  // non-const pointer to const int
    int * const p3 = &x;  // const pointer to non-const int
    const int * const p4 = &x;  // const pointer to const int 

    int *ptr = nullptr;

    if (ptr == nullptr) {
        cout << "ptr is null" << endl;
    }

    *p1 = 3; // valid
    p1 = &n; // valid

    n = *p2; // valid
    *p2 = 4; // illegal
    p2 = &n; // valid

    *p3 = 2; // valid
    p3 = &n; // illegal

    *p4 = 1; // illegal
    p4 = &n; // illegal

    return 0;
}