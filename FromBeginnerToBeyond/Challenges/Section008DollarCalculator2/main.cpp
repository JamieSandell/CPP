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
    cout << "Enter the amount of change in cents: ";
    unsigned int change_amount {0}; //in cents
    cin >> change_amount;
    
    const unsigned int cents_in_a_dollar {100};
    unsigned int dollars {change_amount / cents_in_a_dollar};
    cout << "dollars: " << dollars << endl;
    unsigned int balance {0};
    balance = change_amount % cents_in_a_dollar;
    
    const unsigned int cents_in_a_quarter {25};
    unsigned int quarters = balance / cents_in_a_quarter;
    cout << "quarters: " << quarters << endl;
    
    balance %= cents_in_a_quarter;
    const unsigned int cents_in_a_dime {10};
    unsigned int dimes = balance / cents_in_a_dime;
    cout << "dimes: " << dimes << endl;    
    
    balance %= cents_in_a_dime;
    unsigned int cents_in_a_nickel {5};
    unsigned int nickels = balance / cents_in_a_nickel;
    cout << "nickels: " << nickels << endl;
    
    balance %= cents_in_a_nickel;
    unsigned int pennies = balance;
    cout << "pennies: " << pennies << endl;
    
    
    cout << "";
}
