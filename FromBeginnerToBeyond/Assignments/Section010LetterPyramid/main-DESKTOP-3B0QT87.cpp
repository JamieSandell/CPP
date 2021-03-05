#include <iostream>
#include <string>

using namespace std;

/*
 * Get the user input to construct the pyramid from.
 * 
 * ABC would look like this:
 *   A
 *  ABA
 * ABCBA
 * 
 * The height (rows) of the pyramid is the number of letters entered
 * The number of letters on a row is the number of letters on the previous row + 2, with the first row starting with 1 letter.
 * After you hit the middle letter on a row, the letters are then done in reverse/mirrored for the remainder of that row,
 *  the middle letter shouldn't be repeated on the same row.
 * The spaces preceeding the first letter of the row and post-last letter of the row should be the same.
 *  This can be calculated from 
 * 
 * Variables:
 * user_input
 * rows
 * middle_letter
 */

int main() {
    cout << "Please enter input for the letter pyramid: ";
    string input {};
    getline(cin, input);
    
    cout << "\n";
    size_t number_of_rows {input.length()};
    
    return 0;
}