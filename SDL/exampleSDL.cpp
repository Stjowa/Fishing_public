#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <iostream>

SDL_Surface *SDL_loadImage(std::string);
void applySurface(int, int, SDL_Surface*, SDL_Surface*);

int main(int argc, char* args[]){
    const int SCREEN_WIDTH = 680;                                                                   //Width const for size of screen
    const int SCREEN_HEIGHT = 480;                                                                  //height const for size of screen
    const int SCREEN_BPP = 32;                                                                      //'B'its 'P'er 'P'ixel
    SDL_Surface* message=NULL;
    SDL_Surface* background=NULL;                                                                   //Image
    SDL_Surface* screen=NULL;                                                                       //Image
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
        std::cout << "Program is closing, could not be init";
        return 1;
    }                                                                                               //Starts SDL

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);              //Sets up the screen

    if(screen == NULL){
        std::cout << "Program is closing, could not load screen";
        return 1;
    }

    SDL_WM_SetCaption("Paragon Hacking", NULL);

    background = SDL_loadImage("background.bmp");                                                     //background is the image background.bmp
    SDL_GetError();

    SDL_BlitSurface(background, NULL, screen, NULL);                                                //This applies the image to the screen

    SDL_Flip(screen);                                                                               //Updates screen

    SDL_Delay(2000);                                                                                //Pause

    SDL_FreeSurface(background);                                                                    //Frees the loaded image

    SDL_Quit();                                                                                     //Quit SDL

    return 0;
}

SDL_Surface *SDL_loadImage(std::string filename){
    SDL_Surface* loadedImage=NULL;                                                                  //Temp storage for loaded image
    SDL_Surface* optimizedImage=NULL;

    loadedImage = SDL_LoadBMP(filename.c_str());                                                    //Loads the imaged passed in

    if(loadedImage!=NULL){                                                                          //Make sure the image was loaded
        optimizedImage = SDL_DisplayFormat(loadedImage);                                            //Created the optimized image
        SDL_FreeSurface(loadedImage);                                                               //Free the loaded (old) image
    }

    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
    SDL_Rect offset;

    offset.x=x;
    offset.y=y;

    SDL_BlitSurface(source, NULL, destination, &offset);
}