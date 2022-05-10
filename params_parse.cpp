#include "params_parse.h"
#include <string>
#include <iostream>
#include "high_scores.h"
#include <stdlib.h>
using namespace std;


void arg_parse(int argc, char* argv[], int& max)  {
    bool diff_param = false;
    int lvl;
    for (int i = 1; i < argc; i++) {
        if (string{argv[i]} == "-max") {
            max = stoi(argv[i + 1]);
            if (diff_param) {
                cout << "Too much diff settings!" << endl;
                EXIT_FAILURE;
            } else {
                diff_param = true;
            }
        }
        if (string{argv[i]} == "-table") {
            print_hs();
            EXIT_SUCCESS;
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
                EXIT_FAILURE;
            } else {
                diff_param = true;
            }
        }
    }
}
