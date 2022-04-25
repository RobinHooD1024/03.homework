#include <iostream>
#include <string>
#include <map>
#include "random_value.h"
#include "high_scores.h"

using namespace std;


int main(int argc, char* argv[]) {


    int max {100};
    bool diff_param = false;
    int lvl;

    for (int i = 1; i < argc; i++) {
        if (string{argv[i]} == "-max") {
            max = stoi(argv[i + 1]);
            if (diff_param) {
                cout << "Too much diff settings!" << endl;
                return 1;
            } else {
                diff_param = true;
            }
        }
        if (string{argv[i]} == "-table") {
            print_hs();
            return 1;
        }
        if (string{argv[i]} == "-level") {
            lvl = stoi(argv[i+1]);
            if (lvl == 3) {
                max = 100;
            } else if (lvl == 2) {
                max = 50;
            } else {
                max = 10;
            }
            if (diff_param) {
                cout << "Too much diff settings!" << endl;
                return 1;
            } else {
                diff_param = true;
            }
        }
    }


	const int target_value = getNumber(max);
	int current_value = 0;
	bool not_win = true;
    string name;
    int attempt_count = 0;

    cout << "Enter your name" << endl;
    cin >> name;
	std::cout << "Enter your guess:" << std::endl;

	do {
        std::cin >> current_value;

		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
            attempt_count++;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
            attempt_count++;
		}
		else {
            save_and_print_hs(name, ++attempt_count);
			break;
		}

	} while (not_win);

	return 0;
}
