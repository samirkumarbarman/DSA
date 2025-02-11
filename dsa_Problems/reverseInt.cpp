#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    long long reversed = 0; // Use long long to handle overflow issues

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    // Check if reversed integer is within 32-bit signed integer range
    if (reversed < INT_MIN || reversed > INT_MAX) {
        return 0;
    }

    return static_cast<int>(reversed); // Cast back to int after the check
}

int main() {
    int x = 123;
    cout << "Reversed: " << reverse(x) << endl;
    
    x = -123;
    cout << "Reversed: " << reverse(x) << endl;
    
    x = 120;
    cout << "Reversed: " << reverse(x) << endl;
    
    return 0;
}
