#include <iostream>

int main(void) {
    std :: cout << std :: endl << "Bool pesa: " << sizeof(bool) << " byte" << std :: endl;
    std :: cout << "Char pesa: " << sizeof(char) << " byte" << std :: endl;
    std :: cout << "Unsigned char pesa: " << sizeof(unsigned char) << " byte" << std :: endl;
    std :: cout << "Signed char pesa: " << sizeof(signed char) << " bytes" << std :: endl;
    std :: cout << "Int pesa: " << sizeof(int) << " bytes" << std :: endl;
    std :: cout << "Unsigned int pesa: " << sizeof(unsigned int) << " bytes" << std :: endl;
    std :: cout << "Signed int pesa: " << sizeof(signed int) << " bytes" << std :: endl;
    std :: cout << "Short int pesa: " << sizeof(short int) << " bytes" << std :: endl;
    std :: cout << "Unsigned short int pesa: " << sizeof(unsigned short int) << " bytes" << std :: endl;
    std :: cout << "Signed short int pesa: " << sizeof(signed short int) << " bytes" << std :: endl;
    std :: cout << "Long int pesa: " << sizeof(long int) << " bytes" << std :: endl;
    std :: cout << "Unsigned long int pesa: " << sizeof(unsigned long int) << " bytes" << std :: endl;
    std :: cout << "Signed long int pesa: " << sizeof(signed long int) << " bytes" << std :: endl;
    std :: cout << "Float pesa: " << sizeof(float) << " bytes" << std :: endl;
    std :: cout << "Double pesa: " << sizeof(double) << " bytes" << std :: endl;
    std :: cout << "Long double pesa: " << sizeof(long double) << " bytes" << std :: endl;
    std :: cout << "Wchar_t pesa: " << sizeof(wchar_t) << " bytes" << std :: endl << std :: endl;

    std :: cout << "Puntero a Bool pesa: " << sizeof(bool*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Char pesa: " << sizeof(char*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Unsigned char pesa: " << sizeof(unsigned char*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Signed char pesa: " << sizeof(signed char*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Int pesa: " << sizeof(int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Unsigned int pesa: " << sizeof(unsigned int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Signed int pesa: " << sizeof(signed int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Short int pesa: " << sizeof(short int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Unsigned short int pesa: " << sizeof(unsigned short int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Signed short int pesa: " << sizeof(signed short int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Long int pesa: " << sizeof(long int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Unsigned long int pesa: " << sizeof(unsigned long int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Signed long int pesa: " << sizeof(signed long int*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Float pesa: " << sizeof(float*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Double pesa: " << sizeof(double*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Long double pesa: " << sizeof(long double*) << " bytes" << std :: endl;
    std :: cout << "Puntero a Wchar_t pesa: " << sizeof(wchar_t*) << " bytes" << std :: endl << std :: endl;

    std :: cout << "Notar que en sistemas de 64 Bits = 8 Bytes los punteros pesan 8 y en 32 bits pesan 4." << std :: endl << std :: endl;
}