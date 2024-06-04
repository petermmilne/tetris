#pragma once
#include <map>
#include <vector>
#include "position.h"
#include "colours.h"

class Block
{

public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colours;
    int rowOffset;
    int colOffset;
};