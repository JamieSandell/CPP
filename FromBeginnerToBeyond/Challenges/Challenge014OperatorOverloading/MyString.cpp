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

void MyString::operator-() {
    std::cout << "Unary operator- for " << str << std::endl;
    size_t length = strlen(str);
    for (size_t i = 0; i < length; ++i) {
        str[i] = std::tolower(str[i]);
    }
    std::cout << str << std::endl;
}

bool MyString::operator==(const MyString &other) const {
    return strcmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString &other) const {
    return strcmp(str, other.str) != 0;
}

bool MyString::operator<(const MyString &rhs) const {
    return strcmp(str, rhs.str) < 0;
}

bool MyString::operator>(const MyString &rhs) const {
    return strcmp(str, rhs.str) > 0;
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

