#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        int _rows;
        int _cols;
        map<int, map<int, double>> matMap;

    public:
        Matrix(const vector<double> v, int rows, int cols);
        ~Matrix(){};

        Matrix operator+(const Matrix &m1);
        Matrix operator-(const Matrix &m1);

        Matrix &operator+=(const Matrix &m1);
        Matrix &operator-=(const Matrix &m1);

        /*
        here is aoprators function that give as amore operate that we want to do
        */
        friend ostream &operator<<(ostream &output, const Matrix &m);
        friend istream &operator>>(istream &input, Matrix &m);

        // friend istream &operator>>(istream &output,const Matrix &m);

        Matrix operator++(int); // a++
        Matrix operator--(int); // a--
        Matrix &operator++();   // ++a
        Matrix &operator--();   // --a

        Matrix operator+(); // return copy
        Matrix operator-(); // *-1 copy

        // scalar
        friend Matrix operator*(double num, const Matrix &m1); // num*A copy
        friend Matrix operator*(const Matrix &m1, double num); // A*num copy
        Matrix &operator*=(double num);                        // A*=num this

        Matrix operator*(const Matrix &m1);   // A*B copy
        Matrix &operator*=(const Matrix &m1); // A*=B this

        // A >B -> !A<=B
        // A <B -> !A>=B
        // sum of the units
        friend bool operator>(const Matrix &m1, const Matrix &m2);
        friend bool operator<(const Matrix &m1, const Matrix &m2);

        friend bool operator>=(const Matrix &m1, const Matrix &m2);
        friend bool operator<=(const Matrix &m1, const Matrix &m2);

        // every unit equals
        //  return !(m1 > m2) -? m1<=m2
        friend bool operator==(const Matrix &m1, const Matrix &m2);
        friend bool operator!=(const Matrix &m1, const Matrix &m2);

        friend double sum_calculator(const Matrix &m1);
    };
}
