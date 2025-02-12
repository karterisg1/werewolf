#ifndef __DEFINE_WEREWOLF_FUNCTIONS_CPP__
#define __DEFINE_WEREWOLF_FUNCTIONS_CPP__

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

#include "mapFunctions.cpp"
#include "utilityFunctions.cpp"

const char WEREWOLF_SYMBOL_NORMAL = 'W';
const char WEREWOLF_SYMBOL_STUNNED = 'w';
const char WEREWOLF_SYMBOL_DEAD = 'm';
const int WEREWOLF_MAX_DAMAGE = 5;
const int WEREWOLF_POST_DAMAGE_TELEPORT_DISTANCE = 6;
const int WEREWOLF_PICTURE_WIDTH = 36;
const int WEREWOLF_PICTURE_HEIGHT = 12;
const string WEREWOLF_PICTURE[WEREWOLF_PICTURE_HEIGHT] = {
    "             /\\",
    "            ( ;`~v/~~~ ;._",
    "         ,/'\"/^) ' < o\\  '\".~'\\\\\\--,",
    "       ,/\",/W  u '`. ~  >,._..,   )'",
    "      ,/'  w  ,U^v  ;//^)/')/^\\;~)'",
    "   ,/\"'/   W` ^v  W |;         )/'",
    ";''  |  v' v`\" W }  \\\\",
    "\"    .'\\    v  `v/^W,) '\\)\\.)\\/)",
    "         `\\   ,/,)'   ''')/^\"-;'",
    "              \\",
    "               '\". _",
    "                    \\"
};

int werewolfX;
int werewolfY;
int werewolfHealth = 0;
int werewolfStunnedCount = 0;
bool skipWerewolfsTurn = false;

bool isOpenSpaceForWerewolf(const int, const int);

bool werewolfIsAlive() {
    return (werewolfHealth > 0);
}

bool werewolfIsStunned() {
    return (werewolfStunnedCount > 0);
}

char getWerewolfSymbol() {
    return(werewolfIsAlive() ? (werewolfIsStunned() ? WEREWOLF_SYMBOL_STUNNED : WEREWOLF_SYMBOL_NORMAL) : WEREWOLF_SYMBOL_DEAD);
}

int doWerewolfHit(const int hitpoints) {
    werewolfHealth -= hitpoints;
    werewolfHealth = (werewolfHealth < 0 ? 0 : werewolfHealth);
    werewolfStunnedCount += 2;
    return werewolfHealth;
}

void doWerewolfNextMove(const int playerX, const int playerY) {
    if (!werewolfIsAlive()) {
        return;
    }
    if (skipWerewolfsTurn) {
        skipWerewolfsTurn = false;
        return;
    }
    if (werewolfIsStunned()) {
        werewolfStunnedCount--;
        return;
    }

    int deltaX = playerX - werewolfX;
    int deltaY = playerY - werewolfY;

    int possibleNextX = werewolfX + sign(deltaX);
    int possibleNextY = werewolfY + sign(deltaY);

    bool xDirectionMovePossible = (deltaX != 0 && isOpenSpaceForWerewolf(possibleNextX, werewolfY));
    bool yDirectionMovePossible = (deltaY != 0 && isOpenSpaceForWerewolf(werewolfX, possibleNextY));

    if (xDirectionMovePossible && !yDirectionMovePossible) {
        werewolfX = possibleNextX;
    }
    else if (!xDirectionMovePossible && yDirectionMovePossible) {
        werewolfY = possibleNextY;
    }
    else if (xDirectionMovePossible && yDirectionMovePossible) {
        bool randomlyPickX = static_cast<bool>(rand() % 2);
        if (randomlyPickX) {
            werewolfX = possibleNextX;
        }
        else {
            werewolfY = possibleNextY;
        }
    }
}

bool isOpenSpaceForWerewolf(const int x, const int y) {
    char mapSquare = getMapSquare(x, y);
    return (   mapSquare == MAP_SQUARE_EMPTY
            || mapSquare == MAP_SQUARE_KEY
            || mapSquare == MAP_SQUARE_PEBBLE
            || mapSquare == MAP_SQUARE_PEBBLES
            || mapSquare == MAP_SQUARE_PLANK
            || mapSquare == MAP_SQUARE_PLANK_SET
            || mapSquare == MAP_SQUARE_ROPE);
}

#endif