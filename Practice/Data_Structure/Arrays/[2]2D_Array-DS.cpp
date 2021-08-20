//2D Array - DS
//url: https://www.hackerrank.com/challenges/2d-array/problem
#include <bits/stdc++.h>
#define R first
#define C second
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
typedef pair<int, int> Coord;//coordinate

//calculate hour glass sum
int calcHourGlassSum(vector<vector<int>>& arr, Coord start){
    int res = 0; 
    for(int r = start.R; r < start.R + 3; r++){
        for(int c = start.C; c < start.C + 3; c++){
            if((r == start.R+1 && c == start.C) || (r == start.R+1 && c == start.C+2))
                continue;
            else
                res += arr[r][c];
        }
    }
    return res;
}

//find max of hour glass sum
int hourglassSum(vector<vector<int>> arr) {
    int max_sum = INT_MIN;//-1 -> if all elements are -9, the max is -81. so you must not initiate "max_sum" with -1 
    for(int i = 0; i <= arr.size()-3; i++){
        for(int j = 0; j <= arr[0].size()-3; j++){
            int local_res = calcHourGlassSum(arr, make_pair(i, j));
            max_sum = max(max_sum, local_res);
            //test
            cout << "local: "<< local_res << ", max: "<<max_sum <<"\n";
        }
    }
    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
