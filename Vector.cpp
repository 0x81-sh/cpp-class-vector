#include "Vector.h"

Vector::Vector(int maxSize, const double *elements) : size(maxSize) {
    array = new double[size];

    if (elements == nullptr) return;
    for (int i = 0; i < size; i++) {
        array[i] = elements[i];
    }
}

Vector::Vector(int maxSize, const std::initializer_list<double> &elements) : size(maxSize) {
    array = new double[size];

    for (int i = 0; i < size; i++) {
        array[i] = *(elements.begin() + i);
    }
}

Vector::Vector(const Vector &ref) : size(ref.size) {
    array = new double[size];

    for (int i = 0; i < size; i++) {
        array[i] = ref.getElement(i);
    }
}

Vector::~Vector() {
    delete[] array;
}

void Vector::add(const Vector &ref) {
    if (ref.size < size) return;

    for (int i = 0; i < size; i++) {
        array[i] += ref.getElement(i);
    }
}

void Vector::subtract(const Vector &ref) {
    if (ref.size < size) return;

    for (int i = 0; i < size; i++) {
        array[i] -= ref.getElement(i);
    }
}

void Vector::multiply(double value) {
    for (int i = 0; i < size; i++) {
        array[i] *= value;
    }
}

double Vector::getElement(int index) const {
    if (!inBounds(index)) return -1;
    return array[index];
}

void Vector::setElement(int index, double value) {
    if (!inBounds(index)) return;
    array[index] = value;
}

double Vector::dotProduct(const Vector &ref) const {
    if (ref.size < size) return -1;

    double accumulator = 0;
    for (int i = 0; i < size; i++) {
        accumulator += array[i] * ref.getElement(i);
    }

    return accumulator;
}

Vector Vector::addAndReturn(const Vector &ref) const {
    Vector cpy(*this);
    cpy.add(ref);

    return cpy;
}

bool Vector::inBounds(int v) const {
    return v < size && v >= 0;
}

std::ostream &operator<<(std::ostream &os, const Vector &vector) {
    os << "[ ";
    for (int i = 0; i < vector.size; i++) {
        os << vector.getElement(i) << "; ";
    }
    os << "]";

    return os;
}

bool Vector::operator==(const Vector &rhs) const {
    if (rhs.size != size) return false;

    for (int i = 0; i < size; i++) {
        if (array[i] != rhs.getElement(i)) return false;
    }

    return true;
}
