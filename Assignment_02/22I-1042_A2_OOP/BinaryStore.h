/*
 * BinaryStore.h
 *
 *  Created on: Mar 22, 2023
 *      Author: maaz
 */

#ifndef BINARYSTORE_H_
#define BINARYSTORE_H_
#include <cstddef>
#include<iostream>
using namespace std;

class BinaryStore {
private:
    char** addres;//array to store address
    char** byte;//array to store byte
    int olen;
    int address_count;
    int byte_count;
    char *** additional_address;//to entertain extra addresses
    int total_index;
    int current_index;
    bool flag_control;//only true when additional address is made so that it can be deleted in destructor
public:
BinaryStore (int len); // constructor which creates the store of length len.
void add_Address(char*s); // add a new address in the list of Binary store.
void set_Byte(char* address, char* value); // add the byte at newly added address
// here the first parameter is address and second is byte// Similarly the following code adds byte address and later byte // if address not found addaddress and byte both // function also overrides the data given at particular byteaddress.
char* Get(char* address); //Get function will retrieve the byte at a givenaddress ,
char* ToString(); //return the BinaryStore as character dynamic array.
char * Add(char * a, char * b);
//ADD function will take two strings as input parameters and given the binaryequivalent in form of string.
// comp_EQUAL, comp_AND, and comp_OR function will take two strings as inputparameters and given the binary equivalent in form of string.

bool comp_EQUAL(char * a, char * b);
char *comp_AND(char * a, char * b);
char *comp_OR(char * a, char * b );
char *comp_NOT(char * a);
~BinaryStore();
};

#endif /* BINARYSTORE_H_ */
