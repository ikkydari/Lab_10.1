#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_file(string filename) {
	ifstream file(filename);
	string temp;
	while (getline(file, temp)) {
		cout << temp << endl;
	}
	file.close();
}

int count_of_rows(string filename) {
	ifstream file(filename);
	int count = 0;
	string temp;
	while (getline(file, temp)) {
		count++;
	}
	file.close();
	return count;
}

bool check_letters(string filename, int co_ro) {//co_ro - count of rows
	ifstream file(filename);
	string* arr = new string[co_ro];
	int iter = 0;
	while (getline(file, arr[iter])) {
		iter++;
	}
	for (int i = 0; i < co_ro; i++) {
		for (int j = 1; j < arr[i].length() - 1; j++) {
			if (arr[i][j - 1] == 'n' && arr[i][j + 1] == 'o') {
				return true;
			}
		}
	}

	return false;
}

int main() {
	setlocale(LC_CTYPE, "ukr");
	string file = "data.txt";
	cout << "���i � ����i:\n";
	cout << "========================\n";
	print_file(file);
	cout << "========================\n";
	int count_rows = count_of_rows(file);
	if (check_letters(file, count_rows)) {
		cout << "I��� ���� i �� ���� j, ��� ���� s[i][j-1] = 'n' �� s[i][j+1] = 's'\n";
	}
	else {
		cout << "�� i��� ����� i �� j, ��� ���� s[i][j-1] != 'n' �� s[i][j+1] = 's'\n";
	}
}