#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int color) {
    if(image[sr][sc] == color){
        image[sr][sc] = newColor;
        if(sr >= 1) dfs(image, sr-1, sc, newColor, color);
        if(sc >= 1) dfs(image, sr, sc-1, newColor, color);
        if(sr+1 < image.size()) dfs(image, sr+1, sc, newColor, color);
        if(sc+1 < image[0].size()) dfs(image, sr, sc+1, newColor, color);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int color = image[sr][sc];
    if(color != newColor)
        dfs(image, sr, sc, newColor, color);
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,1}, {1,1,0},{1,0,1}};
    int sr = 1, sc = 2, newColor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    
}