#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
    string buffer;
    int max, sum = 0;
    
    vector<int> idk;
    
    // creating an ifstream object named file
    ifstream file;

    // opening the file
    file.open("C:/Users/xxxx/Desktop/input.txt");

    // checking if the file opening was successful, it will only be true ie. file would have been opened, only if the
    // file exists, so indirectly we are checking if the file exists or not by opening it, if opened, then the file
    // exists, else does not exists
    if(!file) {
        // printing the success message
        cout << "File does not exists" << endl;
    } else {

        while(file) {
            getline(file, buffer);
            if(buffer.length() > 0) {
                int num = stoi(buffer);
                cout << buffer << endl;
                sum = sum + num;
                
                
            } else if(buffer.length() == 0) {

                
                idk.push_back(sum);
                cout << sum << endl;
                sum = 0;
                cout<<endl;
                
            }
        }
        
        for(int i = 0;i < idk.size();i++){
           if(max <= idk[i]){
               max = idk[i];
           }
        }
        cout<<max<<endl;
    }
    sort(idk.begin(), idk.end()); 
    for(auto x:idk){
        cout<<x<<" ";
    }

    return 0;
}
