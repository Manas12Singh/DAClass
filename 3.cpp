//
// Created by Manas Singh on 07-05-2024.
//
#include <iostream>

using namespace std;

int towerOfHanoi(int n, char s, char a, char d) {
    if (n == 0)
        return 0;
    int steps = towerOfHanoi(n - 1, s, d, a)+1;
    cout << "Move disc " << n << " from " << s << " to " << d << " ." << endl;
    steps += towerOfHanoi(n - 1, a, s, d);
    return steps;
}

int main() {
    int n;
    cout << "Enter the number of discs: ";
    cin >> n;
    int steps = towerOfHanoi(n,'S','A','D');
    cout << "Number of steps: " << steps << endl;
}