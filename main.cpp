#include<iostream>
#include<math.h>
#include<time.h>

std::string checkInput(double ans, int* score) {
    double input = 0;
    std::cin >> input;
    if(ans == input) {*score++;}
    std::string response = (ans == input) ? "That is correct!\n" : "That is incorrect!\n";
    return response;
}

void mainGame(int gamenum) {
    int score = 0;
    for(; gamenum > 0; gamenum--) {
        char operation = std::rand() % 5;        //0 = addition; 1 = subtraction; 2 = multiplication; 3 = division; 4 = modulus
        int a = std::rand() % 100;
        int b = std::rand() % 100;
        double c = 0;
        switch (operation) {
            case 0:
                c = a + b;
                operation = '+';
                break;
            case 1:
                c = a - b;
                operation = '-';
                break;
            case 2:
                c = a * b;
                operation = '*';
                break;
            case 3:
                while (b == 0) { b = std::rand() % 100; }
                c = a / b;
                operation = '/';
                break;
            case 4:
                c = a % b;
                operation = '%';
                break;
            default:
                std::cout << "You done messed up.\n";
        }
        std::cout << "What is " << a << " " << operation << " " << b << "? ";
        int* scoreref = &score;
        std::cout << checkInput(c, scoreref);
        std::cout << "Your score is " << score << "\n";
        std::cout << "You have " << gamenum - 1 << " games left\n";
    }
    return;
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
    std::srand(time(0));
    gameStart();
    return 0;
}