#include <iostream>
#include <thread>

#include "../header/header.h"

void playTicTacToeGame() {
    using namespace std::chrono_literals;
    const unsigned char user1{'X'}, user2{'O'};
    std::array<unsigned char, 10> positions{};
    std::uint16_t option;
    std::string repeat;

    CLEAN_SCREEN
    do {
        std::cout << "\nChoose the game mode\n"
                  << "0. USER VS MACHINE\n"
                  << "1. USER VS USER\n"
                  << "2. MACHINE VS MACHINE\n> ";

        // Input game mode choice
        while (!TicTacToe::input(option) || option > 2) {
            std::puts("Invalid Input. Try Again\n>>> ");
        }

        positions.fill(0);
        CLEAN_SCREEN

        switch (option) {
            case 0: {
                // User vs. Machine mode
                while (true) {
                    TicTacToe::board(positions);
                    TicTacToe::movement(positions, user1);
                    CLEAN_SCREEN

                    if (TicTacToe::diagonal(positions, user1)
                        || TicTacToe::horizontal(positions, user1)
                        || TicTacToe::vertical(positions, user1)) {
                        TicTacToe::board(positions);
                        std::puts("You won");
                        break;
                    }

                    if (TicTacToe::tie(positions)) {
                        TicTacToe::board(positions);
                        std::puts("Tie");
                        break;
                    }

                    TicTacToe::machine(positions, user2);

                    if (TicTacToe::diagonal(positions, user2)
                        || TicTacToe::horizontal(positions, user2)
                        || TicTacToe::vertical(positions, user2)) {
                        TicTacToe::board(positions);
                        std::puts("You lost");
                        break;
                    }
                }
                break;
            }

            case 1: {
                // User vs. User mode
                while (true) {
                    TicTacToe::board(positions);
                    TicTacToe::movement(positions, user1);
                    CLEAN_SCREEN

                    if (TicTacToe::diagonal(positions, user1)
                        || TicTacToe::horizontal(positions, user1)
                        || TicTacToe::vertical(positions, user1)) {
                        TicTacToe::board(positions);
                        std::puts("User 1 wins");
                        break;
                    }

                    if (TicTacToe::tie(positions)) {
                        TicTacToe::board(positions);
                        std::puts("Tie");
                        break;
                    }

                    TicTacToe::board(positions);
                    TicTacToe::movement(positions, user2);
                    CLEAN_SCREEN

                    if (TicTacToe::diagonal(positions, user2)
                        || TicTacToe::horizontal(positions, user2)
                        || TicTacToe::vertical(positions, user2)) {
                        TicTacToe::board(positions);
                        std::puts("User 2 wins");
                        break;
                    }
                }
                break;
            }

            case 2: {
                // Machine vs. Machine mode
                while (true) {
                    CLEAN_SCREEN
                    TicTacToe::machine(positions, user1);

                    if (TicTacToe::diagonal(positions, user1)
                        || TicTacToe::horizontal(positions, user1)
                        || TicTacToe::vertical(positions, user1)) {
                        TicTacToe::board(positions);
                        std::puts("Machine 1 wins");
                        break;
                    }

                    TicTacToe::board(positions);
                    std::this_thread::sleep_for(1.369s);
                    CLEAN_SCREEN

                    if (TicTacToe::tie(positions)) {
                        TicTacToe::board(positions);
                        std::puts("Tie");
                        break;
                    }

                    TicTacToe::machine(positions, user2);

                    if (TicTacToe::diagonal(positions, user2)
                        || TicTacToe::horizontal(positions, user2)
                        || TicTacToe::vertical(positions, user2)) {
                        TicTacToe::board(positions);
                        std::puts("Machine 2 wins");
                        break;
                    }
                    TicTacToe::board(positions);
                    std::this_thread::sleep_for(1.369s);
                }
                break;
            }
        }

        // Ask if the user wants to play again
        std::puts("Do you want to play again? [Y/y/S/s/n/N]");
        std::cin >> repeat;
        CLEAN_SCREEN
    } while (std::tolower(repeat[0]) == 'y' || std::tolower(repeat[0]) == 's');
}

int main() {
    playTicTacToeGame();
    return EXIT_SUCCESS;
}
