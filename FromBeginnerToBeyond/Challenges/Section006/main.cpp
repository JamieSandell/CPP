#include <iostream>

using namespace::std;

int main() {
    
    cout << "Please enter the number of small rooms: ";
    unsigned int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    
    cout << "Please enter the number of large rooms: ";
    unsigned int number_of_large_rooms {0};
    cin >> number_of_large_rooms;
    
    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    const double cost_per_small_room {25.0};
    cout << "Cost per small room: " << cost_per_small_room << endl;
    const double cost_per_large_room {35.0};
    cout << "Cost per large room: " << cost_per_large_room << endl;
    double cost_pre_tax {cost_per_small_room * number_of_small_rooms + cost_per_large_room * number_of_large_rooms};
    cout << "Cost $: " << cost_pre_tax << endl;
    const double tax_rate {6.0};
    double tax {cost_pre_tax / 100.0 * tax_rate};
    cout << "Tax $: " << tax << endl;
    cout << "============================" << endl;
    cout << "Total estimate: $" << cost_pre_tax + tax << endl;
    const unsigned int estimate_expiry {30}; //days
    cout << "This estimate is valid for " << estimate_expiry << " days." << endl;
    
    return 0;
}