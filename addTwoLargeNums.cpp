#include <bits/stdc++.h>
using namespace std;

// Function to add two large numbers represented as strings
string addLargeNumbers(const string &num1, const string &num2) {
    string result;
    int carry = 0;
    
    // Make sure num1 is the longer number
    string n1 = num1;
    string n2 = num2;
    
    if (n1.size() < n2.size()) {
        swap(n1, n2);
    }
    
    // Pad the shorter number with leading zeros
    n2.insert(n2.begin(), n1.size() - n2.size(), '0');
    
    // Add digits from right to left
    for (int i = n1.size() - 1; i >= 0; --i) {
        int digit1 = n1[i] - '0';  // converting string digit to integer digit
        int digit2 = n2[i] - '0';
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');  // again converting added digits to string digit
    }
    
    // If there is a carry left, add it to the result  since we are pushing back
    if (carry > 0) {
        result.push_back(carry + '0');
    }
    
    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T

    while (T--) {
        string num1, num2;
        getline(cin, num1);
        getline(cin, num2);
        cout << addLargeNumbers(num1, num2) << endl;
    }

    return 0;
}
