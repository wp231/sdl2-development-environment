#include "SDL.h"

#include <iostream>

int main(int argc, char *argv[]) {
  SDL_Window *window;
  SDL_Init(SDL_INIT_EVERYTHING);

  window =
      SDL_CreateWindow("An SDL2 Window", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  while (1) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        SDL_DestroyWindow(window);
        goto finish;
      }
    }
  }

finish:

  SDL_Quit();

  return 0;
}
