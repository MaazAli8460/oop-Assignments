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
        BigInt(int val = 0);//DONE
        BigInt(const string& );//DONE
        BigInt(const BigInt& ); // copy constructor//DONE
        
        //BigInt operator=(BigInt & b);
        // Binary Operators
        // Arithmetic Operators
        BigInt operator+(const BigInt& val) const;//DONE
        BigInt operator+(int val) const;//DONE
        BigInt operator-(const BigInt& val) const;//done
        BigInt operator-(int val) const;
        BigInt operator*(const BigInt& val) const;
        
        // Compound Assignment Operators
        BigInt operator+=(const BigInt& val);//done
        BigInt operator-=(const BigInt& val);
        BigInt operator*=(const BigInt& val);
        
        // Logical Operators
        bool operator==(const BigInt& val) const;//done
        bool operator==(const char* val) const;//done
        bool operator!=(const BigInt& val) const;//done
        bool operator<(const BigInt& val) const;//done
        bool operator<=(const BigInt& val) const;//done
        bool operator>(const BigInt& val) const;//done
        bool operator>=(const BigInt& val) const;//done
        
        // Unary Operators
        BigInt& operator++(); // Pre-increment Operator   check
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
