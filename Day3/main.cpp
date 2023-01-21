#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part_1();

int main()
{
    vector<string> triple;
    string buffer;
    ifstream file;
    char CL;

    file.open("C:/Users/xxxx/Desktop/input.txt");
    if(!file) {
        cout << "File does not exists" << endl;
    } else {
        while(file) {
            getline(file, buffer);
            triple.push_back(buffer);
            cout << buffer << endl;
        }
        int sum = 0, value = 0;
        for(int m = 0; m < triple.size() - 2; m++, m++, m++) {

            string top = triple.at(0 + m);
            string mid = triple.at(1 + m);
            string bottom = triple.at(2 + m);

            for(int i = 0; i < top.length(); i++) {
                for(int j = 0; j < mid.length(); j++) {
                    for(int k = 0; k < bottom.length(); k++) {
                        if(top[i] == mid[j] && top[i] == bottom[k] && mid[j] == bottom[k]) {
                            CL = top[i];

                            if(isupper(CL)) {
                                value = int(CL) - 38;
                            } else {
                                value = int(CL) - 96;
                            }
                            sum = sum + value;
                            goto outer;
                        }
                    }
                }
            }
        outer:;
        }
        cout << sum << endl;
    }

    //        for (auto x : triple) {
    //        cout << x <<endl;
}

int part_1()
{
    string buffer;
    char CL;
    ifstream file;
    int sum = 0, value = 0, flag = 0;
    file.open("C:/Users/xxxx/Desktop/input.txt");

    // char LCL[27] = "abcdefghijklmnopqrstuvwxyz";
    // char UCL[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //     for(int i = 0; i < 28; i++) {
    //     }

    if(!file) {
        cout << "File does not exists" << endl;
    } else {
        while(file) {
            getline(file, buffer);
            if(buffer == "") {
                break;
            }
            cout << buffer << endl;

            int mid = (buffer.length() + 1) / 2;
            string first = buffer.substr(0, mid);
            string second = buffer.substr(mid);
            cout << "First half: " << first << endl;
            cout << "Second half: " << second << endl << endl;

            for(int i = 0; i < first.length(); i++) {

                for(int j = 0; j < second.length(); j++) {
                    if(first.at(i) == second.at(j)) {
                        cout << first.at(i) << endl;
                        CL = first.at(i);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) {
                    flag = 0;
                    break;
                }
            }
            if(isupper(CL)) {
                value = int(CL) - 38;
            } else {
                value = int(CL) - 96;
            }
            sum = sum + value;
            cout << sum << endl;
        }
    }
}