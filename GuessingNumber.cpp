#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // rand() this function generate the random number 
    int numberToGuess = rand() % 100 + 1;
    cout<<"this is the random number we have to guess "<<numberToGuess<<endl;
    int UserGuess;
    int attempts = 0;

    cout << "Guess the number between 1 and 100!" << endl;

    cout << "Enter your guess number : ";
    cin >> UserGuess;

    while (UserGuess != numberToGuess) {
        attempts++;

        if (UserGuess > numberToGuess) {
            cout << "Too high! Please try again to guess the number: ";
        } else {
            cout << "Too low! please try again to guess the number: ";
        }

        cin >> UserGuess;
    }

    attempts++;  

    cout << "Congrats U have guessed the Number " << numberToGuess << " in " << attempts << " attempts." << endl;

    return 0;
}
