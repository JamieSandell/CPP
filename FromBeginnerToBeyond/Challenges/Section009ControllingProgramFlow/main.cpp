#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector <double> numbers {1, 2, 3, 4, 5, 50, 100, 250, 10};
    
    char menu_choice {};
    
    do {        
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";        
        cin >> menu_choice;
        
        if (menu_choice == 'P' || menu_choice == 'p') {
            cout << "[ ";
            for (auto number: numbers) {
                cout << number << " ";
            }
            cout << "]" << endl;
        }
        else if(menu_choice == 'A' || menu_choice == 'a') {
            double number_to_add {};
            cout << "Enter the number to add to the list: ";
            cin >> number_to_add;
            numbers.push_back(number_to_add);
            cout << " added." << endl;            
        }
        else if(menu_choice == 'M' || menu_choice == 'm') {
            double total;
            for (auto number: numbers) {
                total += number;
            }
            double mean = total / numbers.size();
            cout << "\nMean: " << mean << endl;
        }
        else if (menu_choice == 'S' || menu_choice == 's') {
            double smallestNumber {numbers.at(0)};
            for (auto number: numbers) {
                if (number < smallestNumber) {
                    smallestNumber = number;
                }
            }
            cout << "Smallest number: " << smallestNumber << endl;
        }
        else if(menu_choice == 'L' || menu_choice == 'l') {
            double largestNumber {numbers.at(0)};
            for (auto number: numbers) {
                if (number > largestNumber) {
                    largestNumber = number;
                }
            }
            cout << "Largest number: " << largestNumber << endl;
        }
        
        
    } while (menu_choice != 'Q' && menu_choice != 'q');
    
    cout << "Goodbye!" << endl;
    
    return 0;
}