#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

void display_menu();
void print_numbers(const vector<double> &numbers);
void add_a_number(vector<double> &numbers);
void display_largest_number(vector<double> &numbers);
void display_mean(const vector<double> &numbers);
void display_smallest_number(const vector<double> &numbers);
char read_user_input();

int main() {
    
    vector <double> numbers {1, 2, 3, 4, 5, 50, 100, 250, 10};
    
    char menu_choice {};
    
    do {        
        display_menu();       
        menu_choice = read_user_input();
        
        if (menu_choice == 'P') {
            print_numbers(numbers);
        }
        else if(menu_choice == 'A') {
            add_a_number(numbers);          
        }
        else if(menu_choice == 'M') {
            display_mean(numbers);
        }
        else if (menu_choice == 'S') {
            display_smallest_number(numbers);
        }
        else if(menu_choice == 'L') {
            display_largest_number(numbers);
        }
        
        
    } while (menu_choice != 'Q');
    
    cout << "Goodbye!" << endl;
    
    return 0;
}

void add_a_number(vector<double> &numbers) {
    double number_to_add {};
    cout << "Enter the number to add to the list: ";
    cin >> number_to_add;
    numbers.push_back(number_to_add);
    cout << " added." << endl;   
}

void display_largest_number(vector<double> &numbers) {
    double largestNumber {numbers.at(0)};
    for (auto number: numbers) {
        if (number > largestNumber) {
            largestNumber = number;
        }
    }
    cout << "Largest number: " << largestNumber << endl;
}

void display_mean(const vector<double> &numbers) {
    double total;
    for (auto number: numbers) {
        total += number;
    }
    double mean = total / numbers.size();
    cout << "\nMean: " << mean << endl;
}

void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

void display_smallest_number(const vector<double> &numbers) {
    double smallestNumber {numbers.at(0)};
    for (auto number: numbers) {
        if (number < smallestNumber) {
            smallestNumber = number;
        }
    }
    cout << "Smallest number: " << smallestNumber << endl;
}

void print_numbers(const vector<double> &numbers) {
    cout << "[ ";
    for (auto number: numbers) {
        cout << number << " ";
    }
    cout << "]" << endl;
}

char read_user_input() {
    char user_input {};
    cin >> user_input;
    return toupper(user_input);
}