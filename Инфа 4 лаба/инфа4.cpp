#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

vector<string> create_arr() {
	bool correct = false;
	vector<string> arr;

	while (correct == false) {
		string filename;
		cout << "Input a file name: ";
		cin >> filename;

		ifstream File(filename);
		arr.clear();
		string line;
		while (getline(File, line)) {
			if (line.size() == 8) {
				arr.push_back(line);
			}
			else {
				correct = false;
			}
		}if (arr.size() != 8) {
			correct = false;
		}
		else {
			correct = true;
		}
		File.close();

	}


	return arr;
}

void print_vector(const vector<string>& arr) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void print_vector(const vector<vector<int>>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << "(" << arr[i][0] << ", " << arr[i][1] << ")" << endl;
	}
}

int main() {
	char next;
	do {


		vector<string> arr = create_arr();
		print_vector(arr);
		vector < vector<int>> ans;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] != '.') {
					char enemy;
					if (arr[i][j] == 'w') {
						enemy = 'b';
					}
					if (arr[i][j] == 'b') {
						enemy = 'w';
					}
					if (i >= 2 and j >= 2 and arr[i - 1][j - 1] == enemy and arr[i - 2][j - 2] == '.') {
						vector<int> boi;
						boi.push_back(i + 1);
						boi.push_back(j + 1);
						ans.push_back(boi);
					}
					if (i >= 2 and j <= 5 and arr[i - 1][j + 1] == enemy and arr[i - 2][j + 2] == '.') {
						vector<int> boi;
						boi.push_back(i + 1);
						boi.push_back(j + 1);
						ans.push_back(boi);
					}
					if (i <= 5 and j >= 2 and arr[i + 1][j - 1] == enemy and arr[i + 2][j - 2] == '.') {
						vector<int> boi;
						boi.push_back(i + 1);
						boi.push_back(j + 1);
						ans.push_back(boi);
					}
					if (i <= 5 and j <= 5 and arr[i + 1][j + 1] == enemy and arr[i + 2][j + 2] == '.') {
						vector<int> boi;
						boi.push_back(i + 1);
						boi.push_back(j + 1);
						ans.push_back(boi);
					}
				}
			}
		}
		print_vector(ans);
		cout << "do you want to repeat the work of the program?- F ";
		cin >> next;
	} while (next == 'F');
}