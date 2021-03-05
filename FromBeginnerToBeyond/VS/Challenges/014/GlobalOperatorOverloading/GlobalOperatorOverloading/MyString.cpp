#include <iostream>
#include <cstring>
#include <cctype>
#include "MyString.hpp"

MyString::MyString() : str{nullptr} {
    str = new char[1];
    str[0] = '\0';
    std::cout << "No-args constructor" << std::endl;
}

MyString::MyString(const char* new_str) : str{nullptr}  {
    std::cout << "Overloaded constructor for " << new_str << std::endl;
    int len = strlen(new_str);
    str = new char[len + 1];
    strcpy_s(str, len + 1, new_str);    
}

MyString::MyString(const MyString &other) : MyString{other.str} {
    std::cout << "Deep copy constructor for " << other.str << std::endl;
}

MyString::~MyString()
{
    if (str != nullptr) {
        std::cout << "Destructor freeing data for: " << str << std::endl;
    }
    else {
        std::cout << "Destructor freeing data for nullptr" << std::endl;
    }
    delete [] str;
}

MyString::MyString(MyString &&other) : str{other.str} {    
    std::cout << "Move constructor called for " << other.str << std::endl;
    other.str = nullptr;
}

MyString operator-(const MyString &obj) {
    std::cout << "Unary operator- for " << obj.str << std::endl;
	size_t len = std::strlen(obj.str) + 1;
	char *buff = new char[len];	
	strcpy_s(buff, len, obj.str);
    for (size_t i = 0; i < len; ++i) {
        buff[i] = std::tolower(buff[i]);
    }
	MyString temp{ buff };
	delete[] buff;
	std::cout << temp.str << std::endl;
	return temp;    
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) != 0;
}

bool operator<(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) > 0;
}

MyString& MyString::operator=(const MyString &rhs) {
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    else {
        delete [] str;
		int len = strlen(rhs.str);
        str = new char[len + 1];
        strcpy_s(str, len + 1, rhs.str);
        return *this;
    }
}

MyString& MyString::operator=(MyString &&rhs) {
	std::cout << "Move assignment" << std::endl;
	if (this == &rhs) {
		return *this;
	}
	else {
		this->str = rhs.str;
		rhs.str = nullptr;
	}
	return *this;
}

