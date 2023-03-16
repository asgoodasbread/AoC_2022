#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int part1();
string buffer;
int counter = 0;

int main()
{
    vector<int> FP, SP;

    ifstream file;
    file.open("C:/Users/Filip/Desktop/input.txt");

    if(!file) {
        cout << " File does not exist" << endl;
    } else {
        while(file) {

            getline(file, buffer);
            cout << buffer << endl;

            int pos1, pos2;

            for(int i = 0; i < buffer.length(); i++) {
                for(int j = i + 1; j < buffer.length(); j++) {
                    if(buffer[i] == buffer[j] && buffer[i] == '-') {
                        // cout << "Positions " << i << " and " << j << endl;
                        pos1 = i;
                        pos2 = j;
                        // cout << "Positions " << pos1 << " and " << pos2 << endl;
                    }
                }
            }

            size_t pos0 = buffer.find(",");

            string s0 = buffer.substr(0, pos1);
            string s1 = buffer.substr(pos1 + 1, pos0 - pos1 - 1);
            string s2 = buffer.substr(pos0 + 1, pos2 - pos0 - 1);
            string s3 = buffer.substr(pos2 + 1, buffer.length() - 1 - pos2);

            int i0 = stoi(s0);
            int i1 = stoi(s1);
            int i2 = stoi(s2);
            int i3 = stoi(s3);
            cout << i0 << " " << i1 << " " << i2 << " " << i3 << endl;
            if((i0 == i1 || i0 == i2 || i0 == i3 || i1 == i2 || i1 == i3 || i2 == i3) || (i0 >= i2 && i3 >= i1) ||
                (i2 >= i0 && i1 >= i3)) {
                counter++;
            }
            //
            //            FP.push_back(stoi(s0));
            //            FP.push_back(stoi(s1));
            //            SP.push_back(stoi(s2));
            //            SP.push_back(stoi(s3));
            //
            //            for(int i = 0; i < 2; i++) {
            //                cout << FP[i] << " ";
            //            }
            //            for(int i = 0; i < 2; i++) {
            //                cout << SP[i] << " ";
            //            }
        }
    }
    cout << counter << endl;
}

int part1()
{
    ifstream file;
    file.open("C:/Users/Filip/Desktop/input.txt");

    if(!file) {
        cout << " File does not exist" << endl;
    } else {
        while(file) {

            getline(file, buffer);
            cout << buffer << endl;

            int pos1, pos2;

            for(int i = 0; i < buffer.length(); i++) {
                for(int j = i + 1; j < buffer.length(); j++) {
                    if(buffer[i] == buffer[j] && buffer[i] == '-') {
                        // cout << "Positions " << i << " and " << j << endl;
                        pos1 = i;
                        pos2 = j;
                        // cout << "Positions " << pos1 << " and " << pos2 << endl;
                    }
                }
            }

            size_t pos0 = buffer.find(",");
            // cout << "Position of a coma " << pos0 << endl;
            string s0 = buffer.substr(0, pos1);

            string s1 = buffer.substr(pos1 + 1, pos0 - pos1 - 1);

            string s2 = buffer.substr(pos0 + 1, pos2 - pos0 - 1);
            //  cout << s2 << endl;
            string s3 = buffer.substr(pos2 + 1, buffer.length() - 1 - pos2);
            // cout << s3 << endl;

            int i0 = stoi(s0);
            int i1 = stoi(s1);
            int i2 = stoi(s2);
            int i3 = stoi(s3);
            //     cout << i0 << " " << i1 << " " << i2 << " " << i3 << " " << endl;
            if((i0 >= i2 && i3 >= i1) || (i2 >= i0 && i1 >= i3)) {
                counter++;
            }
        }
    }
    cout << counter << endl;
}
