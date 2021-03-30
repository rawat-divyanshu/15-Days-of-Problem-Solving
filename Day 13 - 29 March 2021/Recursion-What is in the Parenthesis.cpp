// Take as input str, a string. The string contains a single pair of parenthesis “(..)”.
// Write a recursive function which returns the contents between the parenthesis.
// E.g. for “xyz(abc)def” return “abc”. Print the value returned.

// Input Format
// Enter the string

// Constraints
// None

// Output Format
// Display the content between the parenthesis

#include<iostream>
#include<string>
using namespace std;

void printBetweenParenthesis(string str, int currentIndex, int n, bool p) {
	if(currentIndex == n) return;

	if(str[currentIndex] == '(') {
		return printBetweenParenthesis(str,currentIndex+1,n,true);
	} else if(str[currentIndex] == ')') {
		return;
	} else {
		if(p) {
			cout << str[currentIndex];
			return printBetweenParenthesis(str,currentIndex+1,n,true);
		} else {
			return printBetweenParenthesis(str,currentIndex+1,n,false);
		}
	}
}

int main() {
	string str;
	cin >> str;
	printBetweenParenthesis(str,0,str.length(),false);
	return 0;
}