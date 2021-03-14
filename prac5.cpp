#include <bits/stdc++.h>
using namespace std;
int countNegatives(vector<vector<int>>& grid) {
        int count  = 0;
        for(int i=0;i<grid.size();i++){
            int j = grid[i].size()-1;
            while(grid[i][j]<0 && j>=0){
                count++;
                j--;
            }
        }
        return count;
        
    }
int main(int argc, char const *argv[])
{
    vector<vector<int> > v = {{4,3,2,-1},
                               {3,2,1,-1},
                               {1,1,-1,-2},
                               {-1,-1,-2,-3}};
    cout<<countNegatives(v)<<endl;

}