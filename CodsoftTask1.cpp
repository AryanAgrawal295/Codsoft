#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have generated a random number between 1 and 100. Can you guess it?\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        }
    } while (userGuess != randomNumber);

    cout << "Thank you for playing! Goodbye!\n";

    return 0;
}
