# Tic-Tac-Toe Game

Welcome to the Tic-Tac-Toe game! This simple yet classic game allows you to enjoy different game modes and provides a platform-independent experience. Whether you want to play against the computer or challenge your friends, Tic-Tac-Toe has you covered.

** Please note that this game was created in July of 2023, and is now only being uploaded to github. **

![](https://github.com/kabirvirk51/tic-tac-toe/blob/main/src/tictactoe.gif)

## Features

- **Game Modes**: Choose from various game modes:
  - User vs Machine
  - User vs User
  - Machine vs Machine

- **No Installation Necessary**: Just use the precompiled binary to start playing right away.

- **Easy to Modify**: The codebase is designed to be easily modifiable, allowing you to customize and enhance the game according to your preferences.

- **Multi-Platform**: Compatible with multiple operating systems:
  - Windows
  - macOS
  - Linux

## Requirements

Before you get started, make sure you have the following installed:

- `g++` (GNU Compiler Collection)
- `git` (optional but recommended for easy cloning)

## Install & Run

To get the game up and running, follow these steps:

Clone the repository:

   ```bash
   git clone https://github.com/kabirvirk51/tic-tac-toe.git
   cd tic-tac-toe
```

Compile the game using g++:

  ```bash
  g++ -O2 -std=c++2a src/game.cpp src/tictactoe.cpp -o tictactoe
  ```
Run on **macOS & Linux**:

```bash

./tictactoe

```

Run on **Windows**:

```cmd

tictactoe.exe

```

## Uninstall
If you wish to remove the game, simply delete the cloned or downloaded folder from your computer.

## Contributions
Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE
