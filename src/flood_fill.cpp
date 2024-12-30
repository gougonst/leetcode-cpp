#include "flood_fill.h"

vector<vector<int>> Solution::floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image.size() == 0 || image[0].size() == 0 || image[sr][sc] == color)
        return image;

    int rows = image.size();
    int cols = image[0].size();
    int originalColor = image[sr][sc];

    image[sr][sc] = color;
    if (sc > 0 && image[sr][sc - 1] == originalColor) {
        image = floodFill(image, sr, sc - 1, color);
    }
    if (sc < cols - 1 && image[sr][sc + 1] == originalColor) {
        image = floodFill(image, sr, sc + 1, color);
    }
    if (sr > 0 && image[sr - 1][sc] == originalColor) {
        image = floodFill(image, sr - 1, sc, color);
    }
    if (sr < rows - 1 && image[sr + 1][sc] == originalColor) {
        image = floodFill(image, sr + 1, sc, color);
    }
    return image;
}
