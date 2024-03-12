#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Generate a random number between 1 and 100
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Guess a number between 1 and 100:\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess == randomNumber) {
            std::cout << "Congratulations! You guessed the correct number (" << randomNumber << ")!\n";
            break;
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    } while (true);

    std::cout << "Number of attempts: " << attempts << std::endl;

    return 0;
}
