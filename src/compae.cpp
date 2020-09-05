#include <iostream>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<vector<int>> int_vec_2d;
typedef vector<int>:: iterator vi_it;
typedef map<int, int>::iterator mii_it;

int main()
{
    ifstream file1("C:\\Projects\\The-Hack-Assembler\\pre_translated\\Add.hack");
    ifstream file2("C:\\Projects\\The-Hack-Assembler\\self_transated\\Add.hack");
    
    if(file2.is_open() && file1.is_open())
    {
        string t1, t2;
        int i =0;
        while(getline(file1, t1) || getline(file2, t2))
        {   i++;
            if(t1 == t2)
            {
                continue;
            }
            else
            {
                cout << "comp failure at line: " << i << endl;
            }
        }
        file2.close();
        file1.close();
    }
    return 0;
}