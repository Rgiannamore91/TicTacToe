#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include <cstdio>
#include <algorithm>

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
    printf(" %c | %c | %c \n", row1[0], row1[1], row1[2]);
    std::cout << "---+---+---\n";
    printf(" %c | %c | %c \n", row2[0], row2[1], row2[2]);
    std::cout << "---+---+---\n";
    printf(" %c | %c | %c \n", row3[0], row3[1], row3[2]);
}
void print_sector_choices() {
    std::cout << "1) Top Left\n";
    std::cout << "2) Top Center\n";
    std::cout << "3) Top Right\n";
    std::cout << "4) Center Left\n";
    std::cout << "5) Center\n";
    std::cout << "6) Center Right\n";
    std::cout << "7) Bottom Left\n";
    std::cout << "8) Bottom Center\n";
    std::cout << "9) Bottom Right\n";
} 
int get_turn(int loop_count){
    if (!(loop_count % 2 == 0)){
        return 0;
    } else {
        return 1;
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
            if (row3[2] == ' '){
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
int get_user_input(std::string player, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
    bool valid = false;
    int input;
    while (!valid){
        try {
            printf("Which section will %s choose? (choose By number) \n", player.c_str());
            print_sector_choices();
            std::cin >> input;
            valid = validate_input(input, row1, row2, row3);
        } catch(const std::exception e){
            std::cout << "Invalid input.";
        }
        
    }
    return input;
}


bool check_if_win(std::vector<char> row1, std::vector<char> row2, std::vector<char> row3){
    bool win = false;
    bool vertical_conition_1 = row1[0] == ' ' && row2[0] == ' ' && row3[0] == ' ';
    bool vertical_conition_2 = row1[1] == ' ' && row2[1] == ' ' && row3[1] == ' '; 
    bool vertical_conition_3 = row1[2] == ' ' && row2[2] == ' ' && row3[2] == ' ';
    bool diagonal_condition_1 = row1[0] == ' ' && row2[1] == ' ' && row3[2] == ' ';
    bool diagonal_condition_2 = row3[0] == ' ' && row2[1] == ' ' && row1[2] == ' ';
    if (row1[0] == row1[1] 
        && row1[1] == row1[2] 
        && !(std::all_of(row1.begin(), row1.end(), [](char c) { return c == ' ';}))){
        win = true;
        
    } 
    if (row2[0] == row2[1] 
        && row2[1] == row2[2]
        && !(std::all_of(row2.begin(), row2.end(), [](char c) { return c == ' ';}))) {
        win = true;
        
    } 
    if (row3[0] == row3[1] 
        && row3[1] == row3[2]
        && !(std::all_of(row3.begin(), row3.end(), [](char c) { return c == ' ';}))) {
        win = true;
        
    } 
    if (row1[0] == row2[0] && row2[0] == row3[0] && !vertical_conition_1) {
        win = true;
        
    }
    if (row1[1] == row2[1] && row2[1] == row3[1] && !vertical_conition_2) {
        win = true;
        
    }  
    if (row1[2] == row2[2] && row2[2] == row3[2] && !vertical_conition_3) {
        win = true;
        
    } 
    if (row1[0] == row2[1] && row2[1] == row3[2] && !diagonal_condition_1) {
        win = true;
        
    } 
    if (row3[0] == row2[1] && row2[1] == row1[2] && !diagonal_condition_2) {
        win = true;
        
    } 
    return win;
}