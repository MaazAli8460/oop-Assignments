#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Array {
    private:
        int *array;
        int s;
    public:
        Array();
        Array(int size);
        Array(int *arr, int size);
        Array(const Array &);
        ~Array();
	int size();
        int& operator[](int i);
        int& operator[](int i) const;
        const Array& operator=(const Array &);
        Array operator+(const Array &);
        Array operator-(const Array &);
        Array operator++();
        Array operator++(int);
        Array& operator--(int); //subtracts one from each element of array
        bool operator==(const Array &) const;
        bool operator!();
        void operator+=(const Array &);
        void operator-=(const Array &);
        int operator()(int idx, int val);
        friend ostream& operator<<(ostream &input, const Array &rhs);
        friend istream& operator>>(istream &output, Array &rhs);
};

#endif
