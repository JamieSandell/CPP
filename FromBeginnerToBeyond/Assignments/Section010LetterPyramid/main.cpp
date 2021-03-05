#include <iostream>
#include <string>

using namespace std;

/*
 * Example input ABC would output the pyramid
 *   A
 *  ABA
 * ABCBA
 * 
 * The number of rows in the pyramid = number of characters entered
 * The number of characters for a given row = row number * 2 - 1
 * The number of spaces for a row = number of characters in the last row - number of characters in the current row
 *  Then divide this by two to get the number of spaces either side of the text on that row
 * Middle letter for a row = row_number - 1
 */

int main() {
    cout << "Please enter input for the letter pyramid: ";
    string user_input {};
    getline(cin, user_input);
    
    size_t number_of_rows = user_input.length();
    size_t current_row {1};
    for (; current_row <= number_of_rows; ++current_row) { // Cycle through the rows of the pyramid then cycle through the blocks (columns) of the pyramid
        cout << "\n";
        size_t number_of_characters_in_last_row = number_of_rows * 2 - 1;
        size_t number_of_characters_in_current_row = current_row * 2 - 1;
        size_t number_of_spaces = number_of_characters_in_last_row - number_of_characters_in_current_row;
        size_t number_of_spaces_to_the_left {number_of_spaces / 2};
        size_t number_of_spaces_to_the_right {number_of_spaces_to_the_left};
        // Print the spaces before the first character
        for (size_t current_space {0}; current_space < number_of_spaces_to_the_left; ++current_space) { 
            cout << " ";
        }
        // Print the characters to the left of the middle character
        char middle_character {user_input.at(current_row-1)};
        size_t middle_block {current_row};
        for (size_t current_block {1}; current_block < middle_block; ++current_block) { 
            cout << user_input.at(current_block - 1) << flush;
        }
        cout << middle_character;
        // Print the characters to the right of the middle character
        size_t last_block {current_row * 2 - 1};
        size_t character_to_print_position {current_row - 1}; //middle character
        for (size_t current_block {middle_block + 1}; current_block <= last_block; ++current_block) {
            --character_to_print_position; //Work backwards through the user_input
            cout << user_input.at(character_to_print_position) << flush;
        }
        // Print the spaces after the last character
        for (size_t current_space {0}; current_space < number_of_spaces_to_the_right; ++current_space) { 
            cout << " " << flush;
        }
    }    
    
    return 0;
}