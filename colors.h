#include <bits/stdc++.h>
#pragma once
using namespace std;

#define black 30
#define red 31
#define green 32
#define yellow 33
#define blue 34
#define magenta 35
#define cyan 36
#define white 37
#define grey 90
#define brightRed 91
#define brightGreen 92
#define brightYellow 93
#define brightBlue 94
#define brightMagenta 95
#define brightCyan 96
#define brightWhite 97

string setColor(int fg, int bg) {
    return "\033[" + to_string(fg) + ";" + to_string(bg + 10) + "m";
}

string resetColor() {
    return setColor(brightWhite, black);
}
