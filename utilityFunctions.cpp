#ifndef __DEFINE_UTILITY_FUNCTIONS_CPP__
#define __DEFINE_UTILITY_FUNCTIONS_CPP__

#include <iostream>
#include <cstdio>
using namespace std;

int max(int a, int b) { return (a >= b ? a : b); }
int min(const int a, const int b) { return (a <= b ? a : b); }
int abs(const int a) { return (a < 0 ? -a : a); }
int sign(const int a) { return (a < 0 ? -1 : (a == 0 ? 0 : 1)); }

int manhattanDistance(const int firstX, const int firstY, const int secondX, const int secondY) {
    return (abs(firstX - secondX) + abs(firstY - secondY));
}

void printChar(ostream &stream, const char c, const int times) {
    for (int i = 0; i < times; i++) {
        stream << c;
    }
}

void intToString(const int value, string &output) {
    char buffer[11];
    sprintf(buffer, "%d", value);
    output = buffer;
}

#endif