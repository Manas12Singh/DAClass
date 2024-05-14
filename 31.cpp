//
// Created by Manas Singh on 14-05-2024.
//
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

bool compare(const string &text, const string &pattern, int startIndex) {
    for (int i = 0; i < pattern.length(); i++)
        if (pattern[i] != text[i + startIndex])
            return false;
    return true;
}

bool rabinKarp(const string &text, const string &pattern) {
    int patternLength = pattern.length(), textLength = text.length();
    if (patternLength > textLength)
        return false;
    unsigned long long patternHash = 0, textHash = 0, power = pow(33, patternLength - 1);
    for (int i = 0; i < patternLength; i++) {
        patternHash = patternHash * 33 + pattern[i];
        textHash = textHash * 33 + text[i];
    }
    if (patternHash == textHash && compare(text, pattern, 0))
        return true;
    for (int i = patternLength; i < textLength; i++) {
        textHash -= (text[i - patternLength] * power);
        textHash = textHash * 33 + text[i];
        if (patternHash == textHash && compare(text, pattern, i - patternLength + 1))
            return true;
    }
    return false;
}

int main() {
    string text = "aabaacaabaab", pattern = "aadaab";
    cout << rabinKarp(text, pattern);
}