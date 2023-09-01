# ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

# ifdef _WIN32
# define CLEAR_SCREEN system("CLS");
# elif __APPLE__
# define CLEAR_SCREEN system("clear");
# elif __linux__
# define CLEAR_SCREEN system("clear");
# endif

namespace UniqueTicTacToe {
    // Display game instructions
    void showInstructions() noexcept;

    // Display the game board
    void displayBoard(const std::array<unsigned char, 10>&) noexcept;

    // Handle player movement
    void handlePlayerMove(std::array<unsigned char, 10>&, const unsigned char&) noexcept;

    // Simulate AI's move
    void simulateAIMove(std::array<unsigned char, 10>&, const unsigned char&) noexcept;

    // Check for a diagonal win
    bool checkDiagonalWin(const std::array<unsigned char, 10>&, const unsigned char&) noexcept;

    // Check for a horizontal win
    bool checkHorizontalWin(const std::array<unsigned char, 10>&, const unsigned char&) noexcept;

    // Check for a vertical win
    bool checkVerticalWin(const std::array<unsigned char, 10>&, const unsigned char&) noexcept;

    // Check if the game is a tie
    bool isGameTied(const std::array<unsigned char, 10>&) noexcept;

    // Get player input
    bool getPlayerInput(std::uint16_t&) noexcept;
}

# endif
