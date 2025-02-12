#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

#include "interactionFunctions.cpp"
#include "mapFunctions.cpp"
#include "playerFunctions.cpp"
#include "screenFunctions.cpp"

// using namespace interactionFunctions; // Remove the using namespace
extern string lastMessage;

int main() {
    srand(1234);

    doLoadGame('0', true);

    while (true) {
        clearScreen();
        printScreen();
        lastMessage = ""; // Corrected lastMessage scope

        char input = readCharacterInput(); // Corrected readCharacterInput scope
        if (input == KEYBOARD_QUIT) { // Corrected KEYBOARD_QUIT scope
            break;
        } else if (!playerIsAlive()) {
            lastMessage = "You have died."; // Corrected lastMessage scope
        } else {
            doCommand(input); // Corrected doCommand scope
            doWerewolfNextMove(playerX, playerY);
            doCheckForPlayerDamage(); // Corrected doCheckForPlayerDamage scope
        }
    }
    return 0;  // Added missing return statement
}