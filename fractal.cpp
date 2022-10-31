#include "/usr/local/include/SDL2/SDL.h"
#include <numeric>
#include <complex>
#include <cmath>

using namespace std;

int in_set(complex<double> c) {
  complex<double> z(0, 0);
  for (int i = 0; i < 100; i++) {

    z = pow(z, 2) + c;
    if (norm(z) > 10)
      return i;
  }
  return 0;
}

int main(int argc, char *argv[])
{

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = nullptr;
  //  SDL_Renderer* renderer = nullptr;
  window = SDL_CreateWindow(
      "Fractal", 
      SDL_WINDOWPOS_CENTERED, 
      SDL_WINDOWPOS_CENTERED, 
      1000, 
      1000,
      0
      );

  if (window == NULL) {
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  bool quit = false;

  SDL_Event e;
  while (!quit) {
    if (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }
  }

//  SDL_Delay(10000);

  SDL_DestroyWindow(window);
  /*
     SDL_CreateRenderer(window, 0, 0);
     SDL_RenderSetScale(renderer, 2, 2);

     for (double x = 0.0; x < 1.0; x += 0.1)
     for (double y = 0.0; y < 1.0; y += 0.1) {
     x = lerp(-2.0, 2.0, x);
     y = lerp(-2.0, 2.0, y);
     int iters = in_set(complex<double>(x, y));
     if (iters == 0) {
     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
     SDL_RenderDrawPointF(renderer, x, y);
     }
     else {
     SDL_SetRenderDrawColor(renderer, 255-iters, 255-iters, 255-iters, 255);
     SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
     }

     }

     SDL_RenderPresent(renderer);
     SDL_Delay(10000);

*/

  // close SDL
  SDL_Quit();

  return 0;
}
