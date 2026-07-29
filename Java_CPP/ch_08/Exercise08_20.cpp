#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>
/**

 * ***8.20 (Game: connect four) Connect four is a two-player board game in which the

 * players alternately drop colored disks into a seven-column, six-row vertically

 * suspended grid, as shown below.

 * The objective of the game is to connect four same-colored disks in a row, a column, or a diagonal before your opponent can do likewise. The program prompts

 * two players to drop a red or yellow disk alternately. In the preceding figure, the

 * red disk is shown in a dark color and the yellow in a light color. Whenever a disk

 * is dropped, the program will redisplay the board on the console and determines the

 * status of the game (win, draw, or continue).

 * <p>

 * Here is a sample run:

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * ———————————————

 * * Drop a red disk at column (0–6): 0

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * |R| | | | | | |

 * ———————————————

 * Drop a yellow disk at column (0–6): 3

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * | | | | | | | |

 * |R| | |Y| | | |

 * . . .

 * . . .

 * . . .

 * Drop a yellow disk at column (0–6): 6

 * | | | | | | | |

 * | | | | | | | |

 * | | | |R| | | |

 * | | | |Y|R|Y| |

 * | | |R|Y|Y|Y|Y|

 * |R|Y|R|Y|R|R|R|

 * ———————————————

 * The yellow player won

 */

/**

 * Robust implementation of Exercise 08.20 (Game: Connect Four) with resource management,

 * proper draw handling, board boundary checks, and win detection.

 */

const std::string RED = "R";
const std::string YELLOW = "Y";
const std::string WIN = "win";
const std::string CONTINUE = "continue";
const std::string DRAW = "draw";
const std::string EMPTY = " ";

/** Displays the grid state onto the console */
void printBoard(const std::vector<std::vector<std::string>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << "|" << cell;
        }
        std::cout << "|\n";
    }
    std::cout << "---------------\n";
}

/** Evaluates rows, columns, and diagonals for a winning 4-in-a-row match */
std::string evaluateGame(const std::vector<std::vector<std::string>>& board) {
    int rows = static_cast<int>(board.size());
    int cols = static_cast<int>(board[0].size());


    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            std::string val = board[r][c];
            if (val != EMPTY &&
                val == board[r][c + 1] &&
                val == board[r][c + 2] &&
                val == board[r][c + 3]) {
                return WIN;
            }
        }
    }

    for (int r = 0; r <= rows - 4; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::string val = board[r][c];
            if (val != EMPTY &&
                val == board[r + 1][c] &&
                val == board[r + 2][c] &&
                val == board[r + 3][c]) {
                return WIN;
            }
        }
    }
    for (int r = 0; r <= rows - 4; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            std::string val = board[r][c];
            if (val != EMPTY &&
                val == board[r + 1][c + 1] &&
                val == board[r + 2][c + 2] &&
                val == board[r + 3][c + 3]) {
                return WIN;
            }
        }
    }
    for (int r = 3; r < rows; ++r) {
        for (int c = 0; c <= cols - 4; ++c) {
            std::string val = board[r][c];
            if (val != EMPTY &&
                val == board[r - 1][c + 1] &&
                val == board[r - 2][c + 2] &&
                val == board[r - 3][c + 3]) {
                return WIN;
            }
        }
    }

    return CONTINUE;
}
void dropDisk(int column, std::vector<std::vector<std::string>>& board, const std::string& player) {
    for (int r = static_cast<int>(board.size()) - 1; r >= 0; --r) {
        if (board[r][column] == EMPTY) {
            board[r][column] = player;
            break;
        }
    }
}
int getValidMove(const std::vector<std::vector<std::string>>& board, const std::string& colorName, std::istream& in) {
    while (true) {
        std::cout << "Drop a " << colorName << " disk at column (0–6): ";
        int col = 0;
        if (!(in >> col)) {
            std::cout << "Invalid input. Please enter a number between 0 and 6.\n";
            in.clear();
            in.ignore(32767, '\n');
            continue;
        }
        if (col < 0 || col >= static_cast<int>(board[0].size())) {
            std::cout << "Column out of bounds. Please choose between 0 and 6.\n";
        } else if (board[0][col] != EMPTY) {
            std::cout << "Column is full! Choose another column.\n";
        } else {
            return col;
        }
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<std::vector<std::string>> board(6, std::vector<std::string>(7, EMPTY));

        bool isYellowTurn = false;
        int totalMoves = 0;

        while (true) {
            isYellowTurn = !isYellowTurn;
            std::string currentPlayer = isYellowTurn ? YELLOW : RED;
            std::string colorName = isYellowTurn ? "yellow" : "red";
            printBoard(board);
            int col = getValidMove(board, colorName, std::cin);
            dropDisk(col, board, currentPlayer);
            ++totalMoves;
            std::string result = evaluateGame(board);
            if (result == WIN) {
                printBoard(board);
                std::cout << "The " << colorName << " player won.\n";
                break;
            } else if (result == DRAW || totalMoves == 42) {
                printBoard(board);
                std::cout << "The game is a draw.\n";
                break;
            }
        }

        return EXIT_SUCCESS;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Validation Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}