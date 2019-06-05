#include <bits/stdc++.h>
using namespace std;
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

int layout[100][100];

int row,column;
bool visited[100][100];


void dfs(int r,int c, bool visited[][50000],int R,int C,int** layout)
{
    visited[r][c] = true;
    
    if( (r-1)>=0 && !visited[r-1][c] && layout[r-1][c] == 1 ){
        dfs(r-1,c,visited,R,C,layout);
    }
    
    if((c-1)>=0 && !visited[r][c-1] && layout[r][c-1] == 1){
        dfs(r,c-1,visited,R,C,layout);
    }
    
    if( (r+1)<=(R-1) && !visited[r+1][c] && layout[r+1][c] == 1){
        dfs(r+1,c,visited,R,C,layout);
    }
    
    if( (c+1)<=(C-1) && !visited[r][c] && layout[r][c+1] == 1){
        dfs(r,c+1,visited,R,C,layout);
    }
    
    return;
    
}

int isPath(int row, int column, int** layout)
{
    bool vis[row][50000];
    
    int dx,dy;
    
    for(int i=0;i<row;i++){
        
        for(int j=0;j<column;j++){
            
            if(layout[i][j] == 9){
                dx = i;
                dy = j;
            }
            
            vis[i][j] = false;
        }
    }
    
    dfs(dx,dy,vis,row,column,layout);
    
    if(vis[0][0] == true){
        return 1;
    }
    
    return 0;
    
}
// FUNCTION SIGNATURE ENDS


int main()
{   

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    
    cin >> row >> column;



    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            visited[i][j] = false;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin >> layout[i][j];
        }
    }

    isPath(row,column,visited)
}