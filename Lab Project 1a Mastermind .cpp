#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

string set(int, bool);
bool eval(string, string, char&, char&);
void runTest(string code);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));

    string code, guess;
    char rr , rw ;
    int nGuess = 0;
    int size = 4;
    char choice;

    cout << "==== Mastermind Game (Modified) ====\n";
    cout << "1. Play Game (Random Code)\n";
    cout << "2. Test All 10,000 Guesses (Random Code)\n";
    cout << "3. Test All 10,000 Guesses (Custom Code)\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == '1') {
        code = set(size, true);
        cout << "\nGame started! Try to guess the code.\n";
        do {
            cout << "\nEnter your guess (" << size << " digits): ";
            cin >> guess;

            if (guess.length() != size) {
                cout << "Invalid guess length!\n";
                continue;
            }

            eval(code, guess, rr, rw);
            cout << "Correct position: " << (int)rr
                 << " | Wrong position: " << (int)rw << endl;
            nGuess++;

        } while (rr != size);

        cout << "\nYou cracked the code!\n";
        cout << "Code: " << code << endl;
        cout << "Total guesses: " << nGuess << endl;

    } else if (choice == '2') {
        code = set(size, true);
        runTest(code);

    } else if (choice == '3') {
        cout << "Enter custom 4-digit code (0000-9999): ";
        cin >> code;
        while (code.length() != 4) {
            cout << "Invalid code! Must be exactly 4 digits: ";
            cin >> code;
        }
        runTest(code);
    }

    return 0;
}

string set(int size, bool allowDup) {
    string code = "";
    while (code.length() < size) {
        char digit = rand() % 10 + '0';
        if (allowDup) {
            code += digit;
        } else {
            bool exists = false;
            for (int i = 0; i < code.length(); i++) {
                if (code[i] == digit) {
                    exists = true;
                    break;
                }
            }
            if (!exists) code += digit;
        }
    }
    return code;
}

bool eval(string code, string guess, char& rr, char& rw) {
    string check(code.length(), ' ');
    rr = 0;
    rw = 0;

    for (int i = 0; i < code.length(); i++) {
        if (code[i] == guess[i]) {
            rr++;
            check[i] = 'x';
            guess[i] = 'x';
        }
    }

    for (int j = 0; j < guess.length(); j++) {
        for (int i = 0; i < code.length(); i++) {
            if (guess[j] == code[i] && check[i] == ' ' && guess[j] != 'x') {
                rw++;
                check[i] = 'x';
                break;
            }
        }
    }

    return (rr == code.length());
}

void runTest(string code) {
    char rr, rw;
    int countRR[5] = {0};
    int countRW[5] = {0};
    int countSum[5] = {0};

    cout << "\n" << left << setw(8) << "Code"
         << setw(8) << "Guess"
         << setw(8) << "#right"
         << setw(25) << "#right in wrong spot"
         << "Sum" << endl;
    cout << "---------------------------------------------------------\n";

    for (int i = 0; i < 10000; i++) {
        string guess = "";
        int temp = i;
        
        for (int j = 0; j < 4; j++) {
            guess = static_cast<char>(temp % 10 + '0') + guess;
            temp /= 10;
        }

        eval(code, guess, rr, rw);
        int sum = static_cast<int>(rr) + static_cast<int>(rw);

        countRR[static_cast<int>(rr)]++;
        countRW[static_cast<int>(rw)]++;
        countSum[sum]++;

        cout << left << setw(8) << code
             << setw(8) << guess
             << setw(8) << static_cast<int>(rr)
             << setw(25) << static_cast<int>(rw)
             << sum << "\n";
    }

    cout << "\n================ VERIFICATION STATS ================\n";
    cout << "Value | # Right (RR) | # Wrong Spot (RW) | Total Sum\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i <= 4; i++) {
        cout << "  " << i << "   | "
             << setw(12) << countRR[i] << " | "
             << setw(17) << countRW[i] << " | "
             << countSum[i] << "\n";
    }
    cout << "====================================================\n";
}

