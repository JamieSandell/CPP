#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#pragma warning(disable: 4522) // warning C4522: multiple assignment operators specified

class MyString
{
private:
    char *str; //Pointer to a char[] that holds a C-style string

    
public:
    MyString(); //No-args constructor
    MyString(const char*); //Overloaded constructor
    MyString(const MyString &source); // Deep copy constructor
    MyString(MyString &&source); //Move constructor
    ~MyString(); //Destructor
    
    friend MyString operator-(const MyString &obj); //unary operator
    friend bool operator==(const MyString &lhs, const MyString &rhs); //equality operator
    friend bool operator!=(const MyString &lhs, const MyString &rhs); //not equal operator
    friend bool operator<(const MyString &lhs, const MyString &rhs); //less than operator
    friend bool operator>(const MyString &lhs, const MyString &rhs);    //greater than operator
    MyString& operator=(const MyString &rhs);   //copy assignment operator
	MyString& operator=(MyString &&rhs);	//move assignment operator
};

#endif // MYSTRING_HPP
