#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

#ifndef PARA_GON_HACKING_SDLSTUFF_H
#define PARA_GON_HACKING_SDLSTUFF_H

char* GROUP_TITLE = "Paragon Hacking";
char* GAME_NAME = "Fishing_public";
char* GAME_DIFFICULTY = "normal";

int SCREEN_WIDTH = 1024; //Width const for size of screen
int SCREEN_HEIGHT = 640; //height const for size of scree1
int SCREEN_BPP = 32;

Mix_Music *music = NULL;

SDL_Event event;

TTF_Font* font=NULL;
SDL_Color textColor = {255, 0, 0};

SDL_Surface *background=NULL,
            *screen=NULL,
            *options=NULL,
            *optionDifficulty=NULL,
            *titleFont=NULL,
            *singlePlayerFont=NULL,
            *optionsFont=NULL,
            *optionSoundFont=NULL,
            *optionDisplayFont=NULL,
            *optionDifficultyFont=NULL,
            *optionDifficultyEasyFont=NULL,
            *optionDifficultyNormalFont=NULL,
            *optionDifficultyHardFont=NULL,
            *exitFont=NULL;


SDL_Surface* loadImage(std::string);
void applySurface(int, int, SDL_Surface*, SDL_Surface*);
bool init();
void cleanAndClose();
bool loadFiles();

void startFrame();
void optionFrame();
void optionDifficultyFrame();

SDL_Surface* loadImage(std::string filename){
    SDL_Surface* loadedImage=NULL;                                                                  //Temp storage for loaded image
    SDL_Surface* optimizedImage=NULL;

    loadedImage = IMG_Load(filename.c_str());                                                    //Loads the imaged passed in

    if(loadedImage!=NULL){                                                                          //Make sure the image was loaded
        optimizedImage = SDL_DisplayFormat(loadedImage);                                            //Created the optimized image
        SDL_FreeSurface(loadedImage);                                                               //Free the loaded (old) image
    }

    if(optimizedImage!=NULL){
        Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 255, 0, 255);
        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }

    return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
    SDL_Rect offset;

    offset.x=x;
    offset.y=y;

    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init(){
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
        std::cout << "Program is closing, could not be init";
        return 1;
    }                                                                                               //Starts SDL

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);              //Sets up the screen

    if(screen == NULL){
        std::cout << "Program is closing, could not load screen" << std::endl;
        return 1;  
    }

    if(TTF_Init()==-1){
        std::cout << "Program is closing, TTF could not be init" << std::endl;
        return false;
    }

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
        std::cout << "Program is closing, OpenAudio could not init" << std::endl;
        return false;
    }

    SDL_WM_SetCaption(GROUP_TITLE, NULL);
    return true;
}

void cleanAndClose(){
    //Add each image that needs to be freed here!
    SDL_FreeSurface(background);
    SDL_FreeSurface(options);
    SDL_FreeSurface(optionDifficulty);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(titleFont);
    SDL_FreeSurface(singlePlayerFont);
    SDL_FreeSurface(optionsFont);
    SDL_FreeSurface(optionSoundFont);
    SDL_FreeSurface(optionDisplayFont);
    SDL_FreeSurface(optionDifficultyFont);
    SDL_FreeSurface(optionDifficultyEasyFont);
    SDL_FreeSurface(optionDifficultyNormalFont);
    SDL_FreeSurface(optionDifficultyHardFont);
    SDL_FreeSurface(exitFont);

    SDL_Quit();
}

bool loadFiles(){
    
    optionDifficulty = loadImage("background.jpg");
    options = loadImage("background.jpg");
    background = loadImage("background.jpg");

    font = TTF_OpenFont("starting.ttf", 52);

    if(background==NULL){
        std::cout << "ERROR:backgound.jpg" << std::endl;   
        return false;
    }
    if(font==NULL){
        std::cout << "ERROR:font~starting.ttf" << std::endl; 
        return false;
    }
    if(options==NULL){
        std::cout << "ERROR:options" << std::endl;
        return false;
    }
    if(optionDifficulty==NULL){
        std::cout << "ERROR:optionDifficulty" << std::endl;
        return false;
    }
    return true;
}

#endif
