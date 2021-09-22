#include <iostream>
#include <cassert>
#include "Vector.h"

void test_Add(const Vector &a, const Vector &b, const Vector &result);
void test_Add_return(const Vector &a, const Vector &b, const Vector &result);
void test_Subtract(const Vector &a, const Vector &b, const Vector &result);
void test_Multiply(const Vector &a, double v, const Vector &result);
void test_dotProduct(const Vector &a, const Vector &b, double result);

int main() {
    Vector a1(3, {1,  2,  3 });
    Vector a2(3, {4,  5,  6 });
    Vector b1(3, {7,  8,  9 });
    Vector b2(3, {10, 11, 12});

    test_Add(a1, b1, Vector(3, {8, 10, 12}));
    test_Add(a2, b2, Vector(3, {14, 16, 18}));

    test_Add_return(a1, b1, Vector(3, {8, 10, 12}));
    test_Add_return(a2, b2, Vector(3, {14, 16, 18}));

    test_Subtract(a1, b1, Vector(3, {-6, -6, -6}));
    test_Subtract(a2, b2, Vector(3, {-6, -6, -6}));

    test_Multiply(a1, 4, Vector(3, {4, 8, 12}));
    test_Multiply(a2, 2, Vector(3, {8, 10, 12}));

    test_dotProduct(a1, b1, 50);
    test_dotProduct(a2, b2, 167);

    return 0;
}

void test_Add(const Vector &a, const Vector &b, const Vector &result) {
    Vector res(a);
    res.add(b);

    assert(res == result);
}

void test_Add_return(const Vector &a, const Vector &b, const Vector &result) {
    assert(a.addAndReturn(b) == result);
}

void test_Subtract(const Vector &a, const Vector &b, const Vector &result) {
    Vector res(a);
    res.subtract(b);

    assert(res == result);
}

void test_Multiply(const Vector &a, double v, const Vector &result) {
    Vector res(a);
    res.multiply(v);

    assert(res == result);
}

void test_dotProduct(const Vector &a, const Vector &b, double result) {
    double res = a.dotProduct(b);
    assert(res == result);
}
