#include <iostream>

using namespace std;

/*
 * User enters amount of dollars in cents.
 * Output is then:
 * dollars: x
 * quarters: x
 * dime: x
 * nickel: x
 * penny: x
 * 
 * 1 dollar is 100 cents
 * 1 quarter is 25 cents
 * 1 dime is 10 cents
 * 1 nickel is 5 cents
 * 1 penny is 1 cent
 */
int main()
{
    cout << "Enter the amount of dollars in cents: ";
    unsigned int cents_in {0};
    cin >> cents_in;
    
    const unsigned int cents_in_a_dollar_cents {100};
    unsigned int dollars = cents_in / cents_in_a_dollar_cents;
    cout << "dollars: " << dollars << endl;
}
