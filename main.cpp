#include <iostream>
#include <vector>

using namespace std;

// Define directions for movement (up, down, left, right)
int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, -1, 1};

// Function to print the maze with the solution path
void printMaze(const vector<vector<int>> maze)
{
    for (const auto row : maze)
    {
        for (int cell : row)
        {
            cout << (cell == 2 ? "." : (cell == 1 ? "#" : " ")) << " ";
        }
        cout << endl;
    }
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<int>> maze, int x, int y)
{
    return x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0;
}

// DFS function to solve the maze
bool solveMaze(vector<vector<int>> &maze, int x, int y, int endX, int endY)
{
    if (x == endX && y == endY)
    {
        maze[x][y] = 2; // Mark the end point as part of the path
        return true;
    }

    maze[x][y] = 2; // Mark the current cell as part of the path

    for (int i = 0; i < 4; ++i)
    {
        int newX = x + dirX[i];
        int newY = y + dirY[i];

        if (isValidMove(maze, newX, newY) && solveMaze(maze, newX, newY, endX, endY))
        {
            return true;
        }
    }

    maze[x][y] = 0; // Unmark the cell if no solution found along this path
    return false;
}

int main()
{
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 0}};

    int startX = 0, startY = 0;
    int endX = 5, endY = 5;

    if (solveMaze(maze, startX, startY, endX, endY))
    {
        cout << "Path found:\n";
        printMaze(maze);
    }
    else
    {
        cout << "No path found.\n";
    }

    return 0;
}
