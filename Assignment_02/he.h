#include <iostream>
#include<cstring>
using namespace std;
int strcmp(const char* str1, const char* str2) {
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

void* memmove(void* dest, const void* src, size_t n) {
    char* d = static_cast<char*>(dest);
    const char* s = static_cast<const char*>(src);
    if (d == s) {
        return dest;
    } else if (d < s) {
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
}
char* strcpy(char* dest, const char* src) {
    char* ptr = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ptr;
}
size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++ != '\0') {
        ++len;
    }
    return len;
}
char* strcat(char* destination, const char* source) {
    size_t dest_len = strlen(destination);
    size_t i;
    for (i = 0; source[i] != '\0'; i++) {
        destination[dest_len + i] = source[i];
    }
    destination[dest_len + i] = '\0';
    return destination;
}
class BinaryStore {
    private:
        int length;
        char **addresses; // dynamic array of character pointers to store addresses
        char **bytes; // dynamic array of character pointers to store bytes

    public:
   
    BinaryStore(){
    length=0;
    addresses=NULL;
    bytes=NULL;
    }
        BinaryStore(int len) {
            length = len;
            addresses = new char*[len];
            bytes = new char*[len];
            for (int i = 0; i < len; i++) {
                addresses[i] = NULL; // initialize all address pointers to NULL
                bytes[i] = NULL; // initialize all byte pointers to NULL
            }
        }

        void add_Address(char* s) {
            for (int i = 0; i < length; i++) {
                if (addresses[i] == NULL) { // find first available address slot
                    addresses[i] = new char[5];
                    strcpy(addresses[i], s); // copy the address string to the slot
                    return;
                }
                else if (strcmp(addresses[i], s) == 0) { // address already exists
                    return;
                }
            }
        }

        void set_Byte(char* address, char* value) {
            for (int i = 0; i < length; i++) {
                if (addresses[i] == NULL) { // address not found, add new address and byte
                    addresses[i] = new char[5];
                    strcpy(addresses[i], address);
                    bytes[i] = new char[9];
                    strcpy(bytes[i], value);
                    return;
                }
                else if (strcmp(addresses[i], address) == 0) { // address found, override byte
                    if (bytes[i] == NULL) {
                        bytes[i] = new char[9];
                    }
                    strcpy(bytes[i], value);
                    return;
                }
            }
        }

        char* Get(char* address) {
            for (int i = 0; i < length; i++) {
                if (addresses[i] != NULL && strcmp(addresses[i], address) == 0) {
                    return bytes[i];
                }
            }
            return NULL; // address not found
        }

        char* ToString() {
            int size = 0;
            for (int i = 0; i < length; i++) {
                if (addresses[i] != NULL && bytes[i] != NULL) {
                    size += 13; // 4 for address, 1 for space, 8 for byte
                }
            }
            size++; // for terminating null character
            char* result = new char[size];
            result[0] = '\0'; // initialize the string to empty
            for (int i = 0; i < length; i++) {
                if (addresses[i] != NULL && bytes[i] != NULL) {

                    strcat(result, addresses[i]);
                    strcat(result, " ");
                    strcat(result, bytes[i]);
                }
            }
            return result;
        }
        char* Add(char* a, char* b) {
    int len = strlen(a);
    char* result = new char[len + 1];
    result[len] = '\0'; // null terminate the result string
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int bit1 = a[i] - '0';
        int bit2 = b[i] - '0';
        int sum = bit1 + bit2 + carry;
        result[i] = sum % 2 + '0';
        carry = sum / 2;
    }
    if (carry > 0) {
        memmove(result + 1, result, len + 1);
        result[0] = '1';
    }
    return result;
}


char* comp_EQUAL(char* a, char* b) {
    char* result = new char[9];
    if (strcmp(a, b) == 0) {
        strcpy(result, "11111111");
    }
    else {
        strcpy(result, "00000000");
    }
    return result;
}

char* comp_AND(char* a, char* b) {
    char* result = new char[9];
    for (int i = 0; i < 8; i++) {
        if (a[i] == '1' && b[i] == '1') {
            result[i] = '1';
        }
        else {
            result[i] = '0';
        }
    }
    result[8] = '\0';
    return result;
}

char* comp_OR(char* a, char* b) {
    char* result = new char[9];
    for (int i = 0; i < 8; i++) {
        if (a[i] == '1' || b[i] == '1') {
            result[i] = '1';
        }
        else {
            result[i] = '0';
        }
    }
    result[8] = '\0';
    return result;
}

char* comp_NOT(char* a) {
    char* result = new char[9];
    for (int i = 0; i < 8; i++) {
        if (a[i] == '1') {
            result[i] = '0';
        }
        else {
            result[i] = '1';
        }
    }
    result[8] = '\0';
    return result;
}

        ~BinaryStore() {
            for (int i = 0; i < length; i++) {
                delete[] addresses[i]; // free each address pointer
                delete[] bytes[i]; // free each byte pointer
            }
            delete[] addresses; // free the address array pointer
            delete[] bytes; // free the byte array pointer
        }
};
