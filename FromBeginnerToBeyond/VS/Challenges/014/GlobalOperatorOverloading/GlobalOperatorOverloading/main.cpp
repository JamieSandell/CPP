#include <iostream>
#include <vector>
#include "MyString.hpp"

int main() {
    MyString myString {"My String"};
    MyString emptyString;
    std::vector<MyString> mystring_vec;
    mystring_vec.push_back(MyString{"vec string 1"});
    -myString;
    MyString hello {"Hello"};
    MyString hello_two {"Hello two"};
    if (hello == hello_two) {
        std::cout << "hello and hello_two are equal" << std::endl;
    }
    else {
        std::cout << "hello and hello_two are not equal" << std::endl;
    }

	if (hello != hello_two) {
		std::cout << "hello and hello_two are not equal" << std::endl;
	}
	else {
		std::cout << "hello and hello_two are equal" << std::endl;
	}

	if (hello < hello_two) {
		std::cout << "hello is less than hello_two" << std::endl;
	}
	else {
		std::cout << "hello is not less than hello_two" << std::endl;
	}

	if (hello_two > hello) {
		std::cout << "hello_two is greater than hello" << std::endl;
	}
	else {
		std::cout << "hello_two is not greater than hello" << std::endl;
	}

	hello_two = hello;

	MyString move{ "move" };
	move = MyString{ "move me" };

    return 0;
}
