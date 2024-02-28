#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    bool quit = false;
    SDL_Texture* text = IMG_LoadTexture(renderer, "Untitled.png");
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
        SDL_Rect texr; texr.x = rand() % 100; texr.y = rand() % 100; texr.w = 50; texr.h = 50;
        SDL_RenderCopy(renderer, text, NULL, &texr);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}