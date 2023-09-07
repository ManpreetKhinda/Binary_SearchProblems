#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
using namespace std;
int rowWithMax1s(vector<vector<int>>&grid, int n, int m) {
	int maxones=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cntones=upper_bound(grid[i].begin(),grid[i].end(),0)-grid[i].begin();
        cntones=m-cntones;
        if(cntones>maxones){
            maxones=cntones;
            index=i;
        }
    }
    return index;
}
/* grid search 1 here whole matrix is index wise sorted*/
bool searchinMatrix(vector<vector<int>>&grid, int target){
    int n=grid.size();
    int m=grid[0].size();
    int low=0,high=m*n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int r=mid/m;
        int c=mid%m;
        if(grid[r][c]==target)return true;
        else if(grid[r][c]<target)low=mid+1;
        else high=mid-1;
    }
    return false;
}
/* grid dearch 2 here each row and col is sorted*/
bool searchMatrix(vector<vector<int>>& grid, int t) {
    int n=grid.size();
    int m=grid[0].size();
    int r=0, c=m-1;
    while(r<n && c>=0){
        if(grid[r][c]==t)return 1;
        else if(grid[r][c]>t)c--;
        else r++;
    }
    return 0;
}
