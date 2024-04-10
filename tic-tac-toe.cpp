#include <iostream> // for input/output operations
using namespace std;

void board();
void player_choose(int player);
bool check_winner(int player);
void show_game(int player_winner);
char get_value(char mark);

char game_matrix[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int main() {
    int player = 1;
    int old_player;
    int turns = 1;

    do {
        board();
        player_choose(player);
        old_player = player;
        player = (player == 1) ? 2 : 1;
        turns++;
        if (turns == 10) {
            old_player = 0;
        }
    } while (!check_winner(old_player) && turns < 10);

    show_game(old_player);
    return 0;
}

void board() {
    system("clear"); // Assuming you're working on a Unix-like system
    cout << " | | " << endl;
    for (size_t r = 0; r < 3; r++) {
        cout << " " << game_matrix[r][0] << " | " << game_matrix[r][1] << " | " << game_matrix[r][2] << endl;
        cout << "||_____" << endl;
        cout << " | | " << endl;
    }
}

void player_choose(int player) {
    char choose;
    char mark = (player == 1) ? 'X' : 'O';
    cout << "Inserisci " << mark << ": ";
    cin >> choose;

    for (size_t r = 0; r < 3; r++) {
        for (size_t c = 0; c < 3; c++) {
            if (game_matrix[r][c] == choose) {
                game_matrix[r][c] = mark;
            }
        }
    }
}

bool check_winner(int player) {
    bool winner = false;
    char mark = (player == 1) ? 'X' : 'O';

    // Check rows
    for (size_t r = 0; r < 3; r++) {
        int count = 0;
        for (size_t c = 0; c < 3; c++) {
            if (game_matrix[r][c] == mark) {
                count++;
            }
        }

        if (count == 3) {
            winner = true;
            break;
        }
    }

    // Check columns
    if (!winner) {
        for (size_t r = 0; r < 3; r++) {
            int count = 0;
            for (size_t c = 0; c < 3; c++) {
                if (game_matrix[c][r] == mark) {
                    count++;
                }
            }

            if (count == 3) {
                winner = true;
                break;
            }
        }
    }

    // Check diagonals
    if (!winner) {
        int count = 0;
        for (size_t i = 0; i < 3; i++) {
            if (game_matrix[i][i] == mark) {
                count++;
            }
            if (count == 3) {
                winner = true;
                break;
            }
        }
    }

    if (!winner) {
        int count = 0;
        for (size_t c = 2, r = 0; c > 0, r < 3; c--, r++) {
            if (game_matrix[r][c] == mark) {
                count++;
            }
            if (count == 3) {
                winner = true;
                break;
            }
        }
    }
    return winner;
}

void show_game(int winner) {
    system("clear");

    if (winner == 0) {
        cout << "TIE!!!!" << endl;
    } else {
        cout << "Winner player " << winner << endl;
    }

    cout << "     |     |     " << endl;
    for (size_t r = 0; r < 3; r++) {
        char cell1 = get_value(game_matrix[r][0]);
        char cell2 = get_value(game_matrix[r][1]);
        char cell3 = get_value(game_matrix[r][2]);

        cout << "  " << cell1 << "  |  " << cell2 << "  |  " << cell3 << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
    }
}

char get_value(char mark) {
    if (mark == 'X' || mark == 'O') {
        return mark;
    } else {
        return ' ';
    }
}
