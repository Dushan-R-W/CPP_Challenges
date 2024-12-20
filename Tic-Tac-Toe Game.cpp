#include <iostream>
#include <string>
#include <iomanip> // For std::setw
#include <cmath>

void showBoard(int boardSize, std::string board[][3]) {
    //show the board
    std::cout << "\n";
    for (int i{ 0 }; i < boardSize; ++i) {
        for (int k{ 0 }; k < boardSize; ++k) {
            std::cout << board[i][k] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

std::string switchPlayer(std::string currentPlayer) {
    
    if (currentPlayer == "O") {
        return "X";
    }
    else {
        return "O";
    }
}

void tic_Tac_Toe() {
    std::string player1Symbol{ "O" };
    std::string player2Symbol{ "X" };
    constexpr int boardSize{ 3 };
    std::string board[boardSize][boardSize]{};
    bool end{ false };
    int winner{};
    std::string currentPlayer{};
    int slotsLeft{ 9 };
    
    //setup initial board numbers 
    int count{ 1 };
    for (int i{ 0 }; i < boardSize; ++i) {
        for (int k{ 0 }; k < boardSize; ++k) {
            board[i][k] = std::to_string(count);
            ++count;
        }
    }
    
    //generate random number between 1 and 0 to set up the first random player
    std::srand(std::time(0));
    int randomNum = rand() % 2;
    if (randomNum == 1) {
        currentPlayer = "X";
    }
    else {
        currentPlayer = "O";
    }

    //game begins
    while (!end) {
        showBoard(boardSize, board);

        int userInput{};
        do {
            std::cout << "Player " << currentPlayer << "\n";
            std::cin >> userInput;
            std::cout << "\n";
        } while (std::cin.fail() || userInput > (boardSize*boardSize));

        bool breakLoop{ false };
        bool validInput{ false };
        for (int i{ 0 }; i < boardSize; ++i) {
            for (int k{ 0 }; k < boardSize; ++k) {
                if (board[i][k] == std::to_string(userInput)) {
                    if (currentPlayer == "O") {
                        board[i][k] = "O";
                        --slotsLeft;
                        validInput = true;
                    }
                    else if (currentPlayer == "X") {
                        board[i][k] = "X";
                        --slotsLeft;
                        validInput = true;
                    }
                     
                }
            }
        }

        //check winner
        std::string symbols[] { "X", "O" };
        int arraySize{(sizeof(symbols) / sizeof(symbols[0]))-1};

        for (int i{ 0 }; i <= arraySize; ++i) {
            //top-row
            if (board[0][0] == symbols[i] && board[0][1] == symbols[i] && board[0][2] == symbols[i]) {
                end = true;
            }
            //left-column
            else if (board[0][0] == symbols[i] && board[1][0] == symbols[i] && board[2][0] == symbols[i]) {
                end = true;
            }
            //bottom-row
            else if (board[2][0] == symbols[i] && board[2][1] == symbols[i] && board[2][2] == symbols[i]) {
                end = true;
            }
            //right-column
            else if (board[0][2] == symbols[i] && board[1][2] == symbols[i] && board[2][2] == symbols[i]) {
                end = true;
            }
            //cross-left-top to right-bottom
            else if (board[0][0] == symbols[i] && board[1][1] == symbols[i] && board[2][2] == symbols[i]) {
                end = true;
            }
            //cross-right-top to left-bottom
            else if (board[0][2] == symbols[i] && board[1][1] == symbols[i] && board[2][0] == symbols[i]) {
                end = true;
            }
            //middle-row
            else if (board[1][0] == symbols[i] && board[1][1] == symbols[i] && board[1][2] == symbols[i]) {
                end = true;
            }
            //middle-column
            else if (board[0][1] == symbols[i] && board[1][1] == symbols[i] && board[2][1] == symbols[i]) {
                end = true;
            }
            
            if (end == true) {
                std::cout << "\n#######################\n";
                std::cout << "Player " << currentPlayer << " won!!!!";
                std::cout << "\n#######################\n";
                showBoard(boardSize, board);
                break;
            }
        }


        //check draw
        if (slotsLeft == 0 && end == false) {
            std::cout << "\n#######################\n";
            std::cout << "          Draw!!";
            std::cout << "\n#######################\n";
            showBoard(boardSize, board);
            break;
        }
        

        //flip the player
        if (validInput == true && end == false) { currentPlayer = switchPlayer(currentPlayer);}
        
    }
}


int main() {
    
    tic_Tac_Toe();

}


