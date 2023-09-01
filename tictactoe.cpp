#include "../header/header.h
#include <iostream>
#include <random>
#include <array>
#include <vector>
#include <limits>

class TicTacToeGame {
public:
    void showHelp() noexcept;
    void displayBoard(const std::array<char, 10>& positions) noexcept;
    void playerMove(std::array<char, 10>& positions, char player) noexcept;
    void machineMove(std::array<char, 10>& positions, char machine) noexcept;
    bool checkDiagonal(const std::array<char, 10>& positions, char player) noexcept;
    bool checkHorizontal(const std::array<char, 10>& positions, char player) noexcept;
    bool checkVertical(const std::array<char, 10>& positions, char player) noexcept;
    bool checkTie(const std::array<char, 10>& positions) noexcept;
    bool getInput(std::uint16_t& option) noexcept;
};

void TicTacToeGame::showHelp() noexcept {
    std::cout << "Game format\n"
              << "---------\n"
              << "1 | 2 | 3\n"
              << "4 | 5 | 6\n"
              << "7 | 8 | 9\n"
              << "---------\n";
}

void TicTacToeGame::displayBoard(const std::array<char, 10>& positions) noexcept {
    showHelp();
    for (std::uint8_t area = 1; area < 10; ++area) {
        if (!positions[area]) {
            std::cout << "   ";
        } else {
            std::cout << " " << positions[area] << " ";
        }

        if ((area % 3) != 0) {
            std::cout << "|";
        }

        if ((area % 3) == 0) {
            std::cout << "\n\n";
        }
    }
}

void TicTacToeGame::playerMove(std::array<char, 10>& positions, char player) noexcept {
    std::uint16_t area;
    std::cout << "\nChoose an empty area (1-9):\n>>> ";

    while (!getInput(area) || (!area || area > 9) || positions[area]) {
        std::cout << "Invalid input. Try again.\nChoose an empty area (1-9):\n>>> ";
    }

    positions[area] = player;
}

void TicTacToeGame::machineMove(std::array<char, 10>& positions, char machine) noexcept {
    std::vector<std::uint8_t> availableMoves;

    for (std::uint8_t x = 1; x < 10; ++x) {
        if (!positions[x]) {
            availableMoves.push_back(x);
        }
    }

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<std::uint8_t> dist(0, static_cast<std::uint8_t>(availableMoves.size() - 1));
    positions[availableMoves[dist(engine)]] = machine;
}

bool TicTacToeGame::checkDiagonal(const std::array<char, 10>& positions, char player) noexcept {
    if ((positions[1] == player && positions[5] == player && positions[9] == player) ||
        (positions[3] == player && positions[5] == player && positions[7] == player)) {
        return true;
    }
    return false;
}

bool TicTacToeGame::checkHorizontal(const std::array<char, 10>& positions, char player) noexcept {
    for (std::uint8_t row = 1; row <= 7; row += 3) {
        if (positions[row] == player && positions[row + 1] == player && positions[row + 2] == player) {
            return true;
        }
    }
    return false;
}

bool TicTacToeGame::checkVertical(const std::array<char, 10>& positions, char player) noexcept {
    for (std::uint8_t col = 1; col <= 3; ++col) {
        if (positions[col] == player && positions[col + 3] == player && positions[col + 6] == player) {
            return true;
        }
    }
    return false;
}

bool TicTacToeGame::checkTie(const std::array<char, 10>& positions) noexcept {
    std::uint8_t occupied = 0;

    for (std::uint8_t n = 1; n < 10; n++) {
        if (positions[n]) {
            occupied++;
        }
    }

    if (occupied == 9) {
        return true;
    }
    return false;
}

bool TicTacToeGame::getInput(std::uint16_t& option) noexcept {
    std::cin >> option;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    std::array<char, 10> positions{}; // Initialize the board positions
    TicTacToeGame game; // Create an instance of the game

    char currentPlayer = 'X';
    char otherPlayer = 'O';

    while (true) {
        game.displayBoard(positions);

        if (currentPlayer == 'X') {
            game.playerMove(positions, currentPlayer);
        } else {
            game.machineMove(positions, currentPlayer);
        }

        if (game.checkDiagonal(positions, currentPlayer) ||
            game.checkHorizontal(positions, currentPlayer) ||
            game.checkVertical(positions, currentPlayer)) {
            game.displayBoard(positions);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (game.checkTie(positions)) {
            game.displayBoard(positions);
            std::cout << "It's a tie!\n";
            break;
        }

        std::swap(currentPlayer, otherPlayer); // Swap players for the next turn
    }

    return 0;
}
