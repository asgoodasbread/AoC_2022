#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Directory
{

public:
    static int entire_size;

public:
    int size {}, total_size {};
    string name;
    vector<Directory*> children;
    Directory* parent;

    Directory* cd_into(string child_name)
    {
        // if dir exists return child else create child and return child
        for(int i = 0; i < children.size(); i++) {
            if(this->children.at(i)->name == child_name) {
                return children.at(i);
            }
        }

        Directory* child = new Directory(child_name, this);
        children.push_back(child);
        return child;
    }

    int dir_size()
    {
        int sum { 0 };
        for(int i = 0; i < children.size(); i++) {
            sum += children.at(i)->dir_size();
        }

        return sum;
    }

    static void count_solve_part1(Directory* ptr_dir, int* sum)
    {
        int content_size = 0;
        ptr_dir->count_content_size(ptr_dir, &content_size);
        ptr_dir->total_size = content_size;
        if(content_size < 100000) {
            *sum += content_size;
            // cout << ptr_dir->name << " " << *sum << " " << content_size << endl; //directory name sum and size
        }
        for(int i = 0; i < ptr_dir->children.size(); i++) {
            count_solve_part1(ptr_dir->children.at(i), sum);
        }
    }

    static void count_solve_part2(Directory* ptr_dir, int* t_size)
    {
        // disk space occupied 42TB delete around 12TB root size
        if(ptr_dir->total_size >= 2476859) {
            if(ptr_dir->total_size < *t_size) {
                *t_size = ptr_dir->total_size;
            }
        }
        for(int i = 0; i < ptr_dir->children.size(); i++) {
            count_solve_part2(ptr_dir->children[i], t_size);
        }
    }

    static void count_content_size(Directory* ptr_dir, int* sum)
    {
        int check = ptr_dir->size;
        *sum += check;

        for(int i = 0; i < ptr_dir->children.size(); i++) {
            count_content_size(ptr_dir->children.at(i), sum);
        }
    }

    Directory* cd_back()
    {
        return parent;
    }

    Directory(int val, string n, Directory* p)
    {
        size = val;
        name = n;
        parent = p;
    }

    Directory(string nam, Directory* par)
    {
        name = nam;
        parent = par;
    }

    Directory()
    {
        size = 0;
    }
};

int main()
{

    Directory* current_directory;
    string buffer;
    ifstream file;
    string nums;

    file.open("C:/Users/xxxx/Desktop/input.txt");
    if(!file) {
        cout << "File does not exist";
        return 0;
    }

    Directory* root = new Directory("/", nullptr);
    current_directory = root;
    root->size = 0;
    bool isFirst = true;

    while(getline(file, buffer)) {
        cout << buffer << endl;

        if(isFirst) {
            isFirst = false;
            continue;
        }

        if(buffer[0] == '$' && buffer[2] == 'c') {
            if(buffer[5] == '.' && buffer[6] == '.') {
                current_directory = current_directory->cd_back();
            }

            else {

                string dir_name = buffer.substr(5, buffer.size() - 5);
                current_directory = current_directory->cd_into(dir_name);
            }

        } else if(isdigit(buffer[0])) {

            nums = buffer.substr(0, buffer.size() - 0);
            int file_size = stoi(nums);
            current_directory->size += file_size;
        }

        if(buffer[0] == 'd' && buffer[1] == 'i' && buffer[2] == 'r') {
            // do nothing
        }
    }

    int sum = 0;
    int* ptr_sum = &sum;
    Directory::count_solve_part1(root, ptr_sum);
    cout << endl << "Part 1: " << sum << endl;

    //////Part 2
    sum = 0;
    Directory::count_content_size(root, ptr_sum);
    int occupied_space = *ptr_sum;
    int free_space = 70000000 - occupied_space;
    int to_remove = 30000000 - free_space;
    int target_sum {};

    int target_size = 10000000;
    Directory::count_solve_part2(root, &target_size);
    cout << "Part 2: " << target_size << endl;
}
