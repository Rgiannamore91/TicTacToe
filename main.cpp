#include "funcs.hpp"
#include <iostream>
#include <vector>
#include <string>

void game() {
    std::vector<std::string> names = intro();
    std::string player_1 = names[0];
    std::string player_2 = names[1];
    std::vector<char> row1 = {' ', ' ', ' '};
    std::vector<char> row2 = {' ', ' ', ' '};
    std::vector<char> row3 = {' ', ' ', ' '};
    bool continueGame = true;

    while (continueGame) {
        
    }
}

int main() {
    game();
}