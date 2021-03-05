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
    
    void operator-(); //unary operator
    bool operator==(const MyString &other) const; //equality operator
    bool operator!=(const MyString &other) const; //not equal operator
    bool operator<(const MyString &rhs) const; //less than operator
    bool operator>(const MyString &rhs) const;    //greater than operator
    MyString& operator=(const MyString &rhs);   //copy assignment operator
	MyString& operator=(MyString &&rhs);	//move assignment operator
};

#endif // MYSTRING_HPP
