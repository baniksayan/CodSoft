#include <iostream>
#include <string>

using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;
string player1_name, player2_name, current_player_name;

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0; // No one has won yet
}

void switchPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player_name = (current_player == 1) ? player1_name : player2_name;
}

string getFirstName(string full_name) {
    return full_name.substr(0, full_name.find(' '));
}

void game() {
    cout << "Player 1, please enter your full name: ";
    string full_name1;
    getline(cin, full_name1);
    player1_name = getFirstName(full_name1);

    cout << "Player 2, please enter your full name: ";
    string full_name2;
    getline(cin, full_name2);
    player2_name = getFirstName(full_name2);

    cout << player1_name << ", choose your marker: X or O: ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    current_player_name = player1_name;

    drawBoard();
    
    int player_won = 0;

    for (int i = 0; i < 9; i++) {
        cout << "It's " << current_player_name << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again." << endl;
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try again." << endl;
            i--;
            continue;
        }

        drawBoard();

        player_won = checkWin();

        if (player_won == 1) {
            cout << "Congratulations, Mr./Mrs. " << full_name1 << "! You won!" << endl;
            cout << "Let's give a pizza to yourself!" << endl;
            break;
        } else if (player_won == 2) {
            cout << "Congratulations, Mr./Mrs. " << full_name2 << "! You won!" << endl;
            cout << "Let's give a pizza to yourself!" << endl;
            break;
        }

        switchPlayer();
    }

    if (player_won == 0) {
        cout << "It's a draw!" << endl;
        cout << "No pizza this time, but well played!" << endl;
    }
}

int main() {
    char play_again;

    do {
        cin.ignore();
        game();
        cout << "Do you want to play again? (Y/N): ";
        cin >> play_again;

        board[0][0] = '1', board[0][1] = '2', board[0][2] = '3';
        board[1][0] = '4', board[1][1] = '5', board[1][2] = '6';
        board[2][0] = '7', board[2][1] = '8', board[2][2] = '9';

    } while (play_again == 'Y' || play_again == 'y');

    return 0;
}
