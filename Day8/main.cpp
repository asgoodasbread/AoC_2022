#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int part_one(vector<vector<int>> grid);
int part_two(vector<vector<int>> grid);

int main() {
    //input vector of strings (lines of characters)
    vector<string> input;
    vector<int> int_input;
    ifstream file("C:/Users/xxxx/Desktop/input.txt");

    // buffer is a line of characters
    string buffer;

    //98 x 98 matrix
    for (int i = 0; i < 99; i++) {
        getline(file, buffer);
        input.push_back(buffer);
        cout << buffer << endl;
    }
    cout << "XXXXX" << endl;
    for (int i = 0; i < 99; i++) {
        for (char c: input[i]) {
            int_input.push_back(stoi(string(1, c)));
        }
    }
    // converting 1d vector into 2d vector
    int rows = 99, cols = 99;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = int_input[k++];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    part_one(matrix);
    part_two(matrix);
}

int part_one(vector<vector<int>> grid){
    int n = grid.size();  // number of rows/columns in the grid
    int visible_trees = (4 * n) - 4;
    for (int row = 1; row < n - 1; row++) {
        for (int col = 1; col < n - 1; col++) {
            int tree_height = grid[row][col];
            bool may_be_visible = true;
            //left
            for(int i = col-1;i>=0;i--){
                if(tree_height <= grid[row][i]) {
                    may_be_visible = false;
                    break;
                }
            }
            if(may_be_visible){
                visible_trees++;
                continue;
            }
            may_be_visible = true;
            //right
            for(int i = col+1;i<=n-1 ;i++){
                if(tree_height <= grid[row][i]){
                    may_be_visible = false;
                    break;
                }
            }
            if(may_be_visible){
                visible_trees++;
                continue;
            }
            may_be_visible =true;
            //top
            for(int i = row-1;i>=0;i--){
                if(tree_height <= grid[i][col]){
                    may_be_visible =false;
                    break;
                }
            }
            if(may_be_visible){
                visible_trees++;
                continue;
            }
            may_be_visible =true;
            //bottom
            for(int i = row+1;i<=n-1;i++){
                if(tree_height <= grid[i][col]){
                    may_be_visible = false;
                    break;
                }
            }
            if(may_be_visible){
                visible_trees++;
                continue;
            }
        }
    }
    cout<<visible_trees<<endl;
    return 0;
}

int part_two(vector<vector<int>> grid){

    vector<int> max_heights;
    vector<int> results;
    int n = grid.size();
    for (int row = 1; row < n - 1; row++) {
        for (int col = 1; col < n - 1; col++) {
            int tree_height = grid[row][col];
            int counter{};
            //left
            for (int i = col - 1; i >= 0; i--) {
                counter++;
                if ((tree_height <= grid[row][i]) || i == 0) {
                    max_heights.push_back(counter);
                    counter = 0;
                    break;
                }
            }
            //right
            for (int i = col + 1; i <= n - 1; i++) {
                counter++;
                if ((tree_height <= grid[row][i]) || i == n - 1) {
                    max_heights.push_back(counter);
                    counter = 0;
                    break;
                }
            }
            //top
            for (int i = row - 1; i >= 0; i--) {
                counter++;
                if ((tree_height <= grid[i][col]) || i == 0) {
                    max_heights.push_back(counter);
                    counter = 0;
                    break;
                }
            }
            //bottom
            for (int i = row + 1; i <= n - 1; i++) {
                counter++;
                if ((tree_height <= grid[i][col]) || i == n - 1) {
                    max_heights.push_back(counter);
                    break;
                }
            }
            int temp = 1;
            if (!max_heights.empty()) {
                for (auto x: max_heights) {
                    temp *= x;
                }
                results.push_back(temp);
            }
            max_heights.clear();


        }
    }
    int scenic_score = *max_element(results.begin(), results.end());
    cout << scenic_score << endl;
    return 0;
}

