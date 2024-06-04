#include <raylib.h>
#include "game.h"
#include <stdio.h>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    const int screenWidth = 500;
    const int screenHeight = 620;

    Grid grid = Grid();
    grid.Print();

    InitWindow(screenWidth, screenHeight, "Petris");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        BeginDrawing();
        ClearBackground(darkGreen);

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 28, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}