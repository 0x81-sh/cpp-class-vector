#pragma once
#include <initializer_list>
#include <ostream>

class Vector {
    public:
        const int size;
        Vector(int maxSize, const double *elements);
        Vector(int maxSize, const std::initializer_list<double> &elements);
        Vector(const Vector &ref);
        ~Vector();

        void add (const Vector &ref);
        void subtract (const Vector &ref);
        void multiply (double value);

        [[nodiscard]] double getElement (int index) const;
        void setElement(int index, double value);

        [[nodiscard]] double dotProduct (const Vector &ref) const;
        [[nodiscard]] Vector addAndReturn (const Vector &ref) const;

        // for testing
        friend std::ostream &operator<<(std::ostream &os, const Vector &vector);
        bool operator==(const Vector &rhs) const;
    private:
        double *array;
        [[nodiscard]] bool inBounds (int v) const;
};



