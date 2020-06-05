// Scott Tornquist 10/31/19
// CPSC 121
//Assignment 1: Hangman game

#include <iostream>
#include <string>

using namespace std;

// Returns true if the character c is contained anywhere in the string
// str.  Returns false only if none of the characters in str match c.
bool letterExists(string str, char c);

// Updates the "display" string based on the secret word and the user's
// guess.
//
// All indices in secret where the letter is equal to c should be set
// appropriately in the string display.  Since display is passed by
// reference, changes we make to the string (such as assigning a character)
// at an index) will also happen in main.
void updateString(string secret, char c, string& display);

int main() {
    cout << "HANGMAN: THE VIDEO GAME" << endl;

    // the user gets to set the secret word
    string s;
    cout << "What's your favorite word?(definitley unrelated to the game)"<< endl;
    cin>> s;
    const string SECRET = s;
    // I decided to add this into the code just for fun to see if I could
    

    // display represents the string that is displayed to the user.  If the
    // user hasn't guessed a spot, it'll be set to '-'
    string display;

    
    display.resize(SECRET.size(), '-');
    int guesses = 0;
    //char g;
    while (display != SECRET) {
        guesses = guesses+1; //counts the guesses you take
        cout << endl;
        cout << display << endl;
        char g; // creates character g
        cout << "Guess?"<< endl; // asks user for guess
        cin >> g; // puts user input into g
        if (letterExists(SECRET,g)){ // runs updateString if letterExists returns true
            updateString(SECRET,g, display);   
        }
        else {
            cout << "Letter isn't in the word" << endl; // otherwise
        }
        
    }
    cout << "Correct! The word was " << SECRET << endl;
    cout << "It took you " << guesses << " guesses." << endl;
}

bool letterExists(string str, char c) {
    for (int i=0; i<=str.size(); i++){ //runs the length of the given string
        if (str[i] == c){ // if the letter in the word is equal to the guess returns true
            return true;
        }  
    }
    return false; // other wise return fasle if it doesn't exit loop through true
}

void updateString(string secret, char c, string& display) {
    for (int i=0; i<=secret.size(); i++){ // runs lenght of secret
        if (secret[i] == c){ // if secret at this idex equals the guess character
            display[i] = c; // then at the same idex change the display to the guessed character
        }
    }

}
