#include "funcs.hpp"
#include <iostream>
#include <vector>
#include <string>

void game() {
    std::vector<std::string> names = intro();
    std::vector<char> row1 = {' ', ' ', ' '};
    std::vector<char> row2 = {' ', ' ', ' '};
    std::vector<char> row3 = {' ', ' ', ' '};
    bool continueGame = true;
    int loop_count = 0;
    int turn;
    while (continueGame) {
        loop_count++;
        turn = get_turn(loop_count);
        std::string player = names[turn];
        char x_or_o;
        if (player == names[0]) {
            x_or_o = 'x';
        } 
        if (player == names[1]) {
            x_or_o = 'o';
        }
        display_field(row1, row2, row3);
        int user_choice = get_user_input(player, row1, row2, row3);
        switch(user_choice) {
            case 1:
                row1[0] = x_or_o;
                break;
            case 2:
                row1[1] = x_or_o;
                break;
            case 3:
                row1[2] = x_or_o;
                break;
            case 4:
                row2[0] = x_or_o;
                break;
            case 5:
                row2[1] = x_or_o;
                break;
            case 6:
                row2[2] = x_or_o;
                break;
            case 7:
                row3[0] = x_or_o;
                break;
            case 8:
                row3[1] = x_or_o;
                break;
            case 9:
                row3[2] = x_or_o;
                break;
            default:
                std::cout << "Error\n";
        }
        bool win = check_if_win(row1, row2, row3);
        if (win) {
            display_field(row1, row2, row3);
            std::cout << "Winner!\n"; 
            continueGame = false;
        }
    }
}

int main() {
    game();
}