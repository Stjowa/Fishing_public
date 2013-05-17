#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

int main(int argc, char* args[]){
    SDL_Surface* background=NULL;                                       //Image
    SDL_Surface* screen=NULL;                                           //Image

    SDL_Init(SDL_INIT_EVERYTHING);                                      //Starts SDL

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);             //Sets up the screen

    background = IMG_Load("background.bmp");                         //background is the image background.bmp

/*  SDL_Rect offset;
    offset.x=0;
    offset.y=0;*/
    SDL_BlitSurface(screen, NULL, background, &offset);                    //This applies the image to the screen

    SDL_Flip(screen);                                                   //Updates screen

    SDL_Delay(2000);                                                    //Pause

    SDL_FreeSurface(background);                                        //Frees the loaded image

    SDL_Quit();                                                         //Quit SDL

    return 0;
}
