#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>

using namespace std;

class BigInt {
    
    private:
        int *num;
        int size;
        int carry;
        signed int x;

    public:
        BigInt(int val = 0);
        BigInt(const string& text);
        BigInt(const BigInt& copy); // copy constructor
        
        //BigInt operator=(BigInt & b);
        // Binary Operators
        // Arithmetic Operators
        BigInt operator+(const BigInt& val) const;
        BigInt operator+(int val) const;
        BigInt operator-(const BigInt& val) const;
        BigInt operator-(int val) const;
        BigInt operator*(const BigInt& val) const;
        
        // Compound Assignment Operators
        BigInt operator+=(const BigInt& rhs);
        BigInt operator-=(const BigInt& rhs);
        BigInt operator*=(const BigInt& rhs);
        
        // Logical Operators
        bool operator==(const BigInt& val) const;
        bool operator==(const char* val) const;
        bool operator!=(const BigInt& val) const;
        bool operator<(const BigInt& val) const;
        bool operator<=(const BigInt& val) const;
        bool operator>(const BigInt& val) const;
        bool operator>=(const BigInt& val) const;
        
        // Unary Operators
        BigInt& operator++(); // Pre-increment Operator   
        BigInt operator++(int); // Post-increment Operator
        BigInt& operator--(); // Pre-decrement Operator
        BigInt operator--(int); // Post-decrement Operator
        
        // Conversion Operator
        operator string(); // return value of the BigInt as string
        operator int(); // return the number of digits in big Integer
        
        // Destructor
        ~BigInt();
        friend ostream& operator<<(ostream& output, const BigInt& val);
        friend istream& operator>>(istream& input, BigInt& val);
    
};

#endif // BIGINT_H
