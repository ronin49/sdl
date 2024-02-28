#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>

SDL_Renderer* renderer;
std::map<const char*, SDL_Texture*> map;
const int CELL_SIZE = 50;
const char* field[8][8] = {};

void load(const char* file)
{
    map[file] = IMG_LoadTexture(renderer, file);
}

void draw(const char* file, int x, int y)
{
    SDL_Rect texr; texr.x = x; texr.y = y; texr.w = CELL_SIZE; texr.h = CELL_SIZE;
    SDL_RenderCopy(renderer, map[file], NULL, &texr);
}

void drawField() {
    for (int row = 0; row < 8; ++row)
        for (int col = 0; col < 8; ++col) {
            draw("cell.png", col * CELL_SIZE, row * CELL_SIZE);
            draw(field[row][col], col * CELL_SIZE, row * CELL_SIZE);
        }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    bool quit = false;
    load("black_king.png");
    load("black_queen.png");
    load("black_slon.png");
    load("black_horse.png");
    load("black_tura.png");
    load("black_peshka.png");
    load("white_king.png");
    load("white_queen.png");
    load("white_slon.png");
    load("white_horse.png");
    load("white_tura.png");
    load("white_peshka.png");
    load("cell.png");

    for (int col = 0; col != 8; ++col) {
        field[1][col] = "black_peshka.png";
        field[6][col] = "white_peshka.png";
    }

    field[0][0] = "black_tura.png";
    field[0][7] = "black_tura.png";
    field[0][1] = "black_horse.png";
    field[0][6] = "black_horse.png";
    field[0][2] = "black_slon.png";
    field[0][5] = "black_slon.png";
    field[0][3] = "black_queen.png";
    field[0][4] = "black_king.png";

    field[7][0] = "white_tura.png";
    field[7][7] = "white_tura.png";
    field[7][1] = "white_horse.png";
    field[7][6] = "white_horse.png";
    field[7][2] = "white_slon.png";
    field[7][5] = "white_slon.png";
    field[7][3] = "white_queen.png";
    field[7][4] = "white_king.png";
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            if (event.type == SDL_MOUSEBUTTONDOWN)
                quit = true;
        }
        SDL_RenderClear(renderer);
        // Render stuff here

        std::cout << rand() << std::endl;
        drawField();
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}