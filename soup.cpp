/* 
 * File:   main.cpp
 * Author: Rafael Angelo
 *
 * Created on January 9, 2013, 11:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    ifstream infile("alphabet_soup.txt");
    ofstream Students("saida.txt");
    string soup;
    int T, found, count[8], res;
    infile >> T;
    getline(infile,soup);
    for (int i = 1; i <= T; i++) {
        getline(infile, soup);
        
        for(int a=0;a<8;a++) count[a] =0;
        found = soup.find_first_of("HACKERCUP");
        while (found != string::npos) {
            if (soup[found] == 'H') count[0] = count[0] + 1; 
            else if (soup[found] == 'A') count[1] = count[1] + 1;
            else if (soup[found] == 'C') count[2] = count[2] + 1;
            else if (soup[found] == 'K') count[3] = count[3] + 1;
            else if (soup[found] == 'E') count[4] = count[4] + 1;
            else if (soup[found] == 'R') count[5] = count[5] + 1;
            else if (soup[found] == 'U') count[6] = count[6] + 1;
            else if (soup[found] == 'P') count[7] = count[7] + 1;
            found = soup.find_first_of("HACKERCUP", found + 1);
        }

        res = min(count[0], count[1]);
        res = min(count[1], res);
        res = min(count[2]/2, res);
        res = min(count[3], res);
        res = min(count[4], res);
        res = min(count[5], res);
        res = min(count[6], res);
        Students << "case #" << i <<": "<< res << endl;
        res = 0;
    }

    return 0;
}

