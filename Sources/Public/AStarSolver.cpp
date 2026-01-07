#include "AStarSolver.h"
#include <algorithm>
#include "../Private/Grid.h"

int heureustics(int i, int j)
{
    return i + j;
}

std::vector<PathNode> AStarSolver::SolveGrid(const Grid& _Grid, Coord Start, Coord Target)
{
    std::vector<PathNode> ResultPath = {};
    int actual_x = Start.X;
    int actual_y = Start.Y;

    while (actual_x != Target.X && actual_y != Target.Y) {
        PathNode node;
        //if (Grid[actual_y][actual_x] == '-') { // check if the wall is detected
        //    node.GWeight = actual_x + 1;
        //    node.HWeight = actual_y;
        //    actual_x += 1;
        //}
        if (heureustics(actual_y, actual_y + 1) > heureustics(actual_x, actual_x + 1) || actual_y != Target.Y) { // for increment the y axis
            if (actual_y > Target.Y)
                node.HWeight = actual_y - 1;
            else 
                node.HWeight = actual_y + 1;
            node.GWeight = actual_x;
            actual_y += 1;
        }
        if (heureustics(actual_x, actual_x + 1) > heureustics(actual_y, actual_y + 1) || actual_x != Target.X) { // for increment the x axis
            if (actual_x > Target.X)
                node.GWeight = actual_x - 1;
            else
                node.GWeight = actual_x + 1;
            node.HWeight = actual_y;
            actual_x += 1;
        }
        if (!ResultPath.empty()) { // check if is null and adding her neighbor
            node.IsNeighbor(ResultPath.back());
        }
        ResultPath.push_back(node); // adding the new node
    }
    return ResultPath;
}
