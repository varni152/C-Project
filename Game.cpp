#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int lowerBound, upperBound;
    cout << "Enter the lower bound of the range: ";
    cin >> lowerBound;
    cout << "Enter the upper bound of the range: ";
    cin >> upperBound;

    // Validate the range
    if (upperBound <= lowerBound) {
        cout << "Invalid range. Upper bound must be greater than lower bound.\n";
        return 1;
    }

    // Generate a random number within the specified range
    srand(time(0));
    int randomNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess a number between " << lowerBound << " and " << upperBound << ":\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess == randomNumber) {
            cout << "Congratulations! You guessed the correct number (" << randomNumber << ")!\n";
            break;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }
    } while (true);

    cout << "Number of attempts: " << attempts << endl;

    return 0;
}
