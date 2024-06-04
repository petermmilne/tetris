#pragma once
#include "grid.h"
#include "blocks.cpp"


class Game {
    public:
        Game();
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void RotateBlock();
        bool IsBlockOutside();
        bool BlockFits();
        void LockBlock();
        void UpdateScore(int linesCleared, int moveDownPoints);
        void Reset();
        Grid grid;
        bool gameOver;
        int score;
        Music music;

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Sound rotateSound;
        Sound clearSound;

};
