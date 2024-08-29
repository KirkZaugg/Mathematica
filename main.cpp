#include<iostream>
#include<math.h>

int mainGame(int gamenum) {
    for(gamenum > 0; gamenum--) {
        
    }
}

void gameStart() {
    int games = 0;
    std::cout << "Welcome to Math Game! How many Games would you like to play? ";
    std::cin >> games;
    if(games < 1) {return;}
    mainGame(games);
    std::cout << "Thank you for playing Math Game! Would you like to play again? (y/n) ";
    char answer;
    std::cin >> answer;
    if(std::toupper(answer) == 'Y') {gameStart();} else {return;}
}

int main() {
    gameStart();
}