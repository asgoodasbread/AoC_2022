#include <fstream>
#include <iostream>
#include <string>

using namespace std;
#define c cout

int part_1();

int main()
{
    string buffer;
    ifstream file;
    int sum = 0;
    file.open("C:/Users/xxxx/Desktop/input.txt");

    if(!file) {
        c << "File does not exists" << endl;
    } else {
        while(file) {
            getline(file, buffer);

            if(buffer[0] == 'A' && buffer[2] == 'Y') {
                sum += 1 + 3;

            } else if(buffer[0] == 'B' && buffer[2] == 'Z') {
                sum += 3 + 6;

            } else if(buffer[0] == 'B' && buffer[2] == 'X') {
                sum += 1 + 0;

            } else if(buffer[0] == 'C' && buffer[2] == 'X') {
                sum += 2 + 0;

            } else if(buffer[0] == 'A' && buffer[2] == 'Z') {
                sum += 2 + 6;

            } else if(buffer[0] == 'C' && buffer[2] == 'Y') {
                sum += 3 + 3;

            } else if(buffer[0] == 'A' && buffer[2] == 'X') {
                sum += 3 + 0;

            } else if(buffer[0] == 'B' && buffer[2] == 'Y') {
                sum += 2 + 3;

            } else if(buffer[0] == 'C' && buffer[2] == 'Z') {
                sum += 1 + 6;
            }
        }
    }
    c << sum << endl;
}

// PART 1
//  rock 1 paper 2 scissors 3
//  win 6 draw 3 lost 0
//
//  Rock Paper
//  Paper Scissors
//  Paper Rock
//  Scissors Rock
//  Rock Scissors
//  Scissors Paper
//  SS PP RR
// PART 2
/*
 *    X - Lose
 *    Y - Draw
 *    Z - Win
 */

int part_1()
{
    string buffer;

    ifstream file;

    int sum = 0;

    file.open("C:/Users/xxxx/Desktop/input.txt");

    if(!file) {

        c << "File does not exists" << endl;
    } else {
        while(file) {
            getline(file, buffer);

            if(buffer[0] == 'A' && buffer[2] == 'Y') {
                sum += 2 + 6;

            } else if(buffer[0] == 'B' && buffer[2] == 'Z') {
                sum += 3 + 6;

            } else if(buffer[0] == 'B' && buffer[2] == 'X') {
                sum += 1 + 0;

            } else if(buffer[0] == 'C' && buffer[2] == 'X') {
                sum += 1 + 6;

            } else if(buffer[0] == 'A' && buffer[2] == 'Z') {
                sum += 0 + 3;

            } else if(buffer[0] == 'C' && buffer[2] == 'Y') {
                sum += 0 + 2;

            } else if((buffer[0] == 'A' && buffer[2] == 'X') || (buffer[0] == 'B' && buffer[2] == 'Y') ||
                (buffer[0] == 'C' && buffer[2] == 'Z')) {
                if(buffer[2] == 'X') {
                    sum += 3 + 1;

                } else if(buffer[2] == 'Y') {
                    sum += 3 + 2;

                } else if(buffer[2] == 'Z') {
                    sum += 3 + 3;
                }
            }
        }
    }
    c << sum << endl;
}
