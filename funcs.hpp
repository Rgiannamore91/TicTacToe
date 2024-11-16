#include <iostream>
#include <vector>
#include <string>

#include <cstdio>

std::vector<std::string> intro () {
    std::cout << "This is Tic-Tac-Toe.\n" << "This game requires two players. Please enter their names: \n";
    std::vector<std::string> returnValue;
    while (returnValue.size() < 2) {
        std::cout << "Enter name: ";
        std::string name;
        std::cin >> name;
        returnValue.push_back(name);
    } 
    return returnValue;
}

void display_field(std::vector<char> row1, std::vector<char> row2, std::vector<char> row3) {
    printf(" %c | %c | %c ", row1[0], row1[1], row1[2]);
    std::cout << "---+---+---";
    printf(" %c | %c | %c ", row2[0], row2[1], row2[2]);
    std::cout << "---+---+---";
    printf(" %c | %c | %c ", row3[0], row3[1], row3[2]);
}
int get_user_input(std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
    bool valid = false;
    while (!valid){
        std::cout << "Which ";
    }
}
bool validate_input(int input, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
    bool valid;
    switch (input) {
        case 1:
            if (row1[0] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 2:
            if (row1[1] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 3:
            if (row1[2] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 4: 
            if (row2[0] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 5:
            if (row2[1] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 6:
            if (row2[2] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 7:
            if (row3[0] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 8:
            if (row3[1] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        case 9:
            if (row3[3] == ' '){
                valid = true;
            } else {
                valid = false;
            }
            break;
        default:
            valid = false;
    }
    return valid;
}