//========================================================
//
//
//
//========================================================

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>



const char* GROUP_TITLE = "Paragon Hacking";
const char* GAME_NAME = "Fishing_public";

const int SCREEN_WIDTH = 1024;                                                               //Width const for size of screen
const int SCREEN_HEIGHT = 640;                                                                  //height const for size of scree1
const int SCREEN_BPP = 32;

SDL_Event event;

TTF_Font* font=NULL;
SDL_Color textColor = {255, 0, 0};

SDL_Surface *background=NULL,
            *screen=NULL,
            *options=NULL,
            *titleFont=NULL,
            *singlePlayerFont=NULL,
            *optionsFont=NULL,
            *optionSoundFont=NULL,
            *optionDisplayFont=NULL,
            *optionDifficultyFont=NULL,
            *exitFont=NULL;


SDL_Surface* loadImage(std::string);
void applySurface(int, int, SDL_Surface*, SDL_Surface*);
bool init();
void cleanAndClose();
bool loadFiles();

void startFrame();
void optionFrame();


int main(int argc, char* args[]){
    SDL_Event event;
    bool run=true;
    
    if(init()==false){
        std::cout << "Program is closing, could not be init" << std::endl;
        return 1;
    }

    if(!loadFiles()){
        std::cout << "Program in closing, could not load files" << std::endl;
        return 1;
    }
    
    applySurface(-200, -200, background, screen);                                                         //This applies the image to the screen
    
    titleFont                = TTF_RenderText_Solid(font, "Fishing_public"  , textColor);
    singlePlayerFont         = TTF_RenderText_Solid(font, "Single Player"   , textColor);
    optionsFont              = TTF_RenderText_Solid(font, "Options"         , textColor);
    exitFont                 = TTF_RenderText_Solid(font, "Exit"            , textColor);

    optionSoundFont          = TTF_RenderText_Solid(font, "Sound"           , textColor);
    optionDisplayFont        = TTF_RenderText_Solid(font, "Display"         , textColor),
    optionDifficultyFont     = TTF_RenderText_Solid(font, "Difficulty"      , textColor);

    startFrame();

    if( SDL_Flip(screen) == -1){
        std::cout << "screen could not be fliped to screen" << std::endl;
        return 1;   
    }                                                                               //Updates screen

    int buttonX=0,
        buttonY=0,
        frame=1;

    while(run){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_MOUSEMOTION){

            }

            if(event.type == SDL_MOUSEBUTTONDOWN){
                //if(event.type == SDL_BUTTON_LEFT){
                    buttonX = event.button.x;
                    buttonY = event.button.y;

                    std::cout << "LEFT: ";

                    if((buttonX>350)&&(buttonX<525)&&(buttonY>370)&&(buttonY<400)&&(frame==1)){
                        ++frame;
                        optionFrame();     
                    }

                    if((buttonX>350)&&(buttonX<445)&&(buttonY>420)&&(buttonY<450)){
                        run=false;
                    }
                //}
                std::cout << "(" << buttonX << ", " << buttonY << " )" << std::endl;
            }
            
            if(event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        run=--frame;
                        break;
                    case SDLK_UP: 
                    case SDLK_DOWN: 
                    case SDLK_LEFT: 
                    case SDLK_RIGHT: 
                    default:
                        break;
                }
            }

            if(event.type == SDL_QUIT){
                run=false;
            }
        }
        
        if(frame==1)  startFrame();

        SDL_Flip(screen);
    }

    cleanAndClose();                                                                                     //Quit SDL

    std::cout << "Program is quiting" << std::endl;

    return 0;
}

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

    SDL_WM_SetCaption(GROUP_TITLE, NULL);
    return true;
}

void cleanAndClose(){
    //Add each image that needs to be freed here!
    SDL_FreeSurface(background);
    SDL_FreeSurface(options);

    SDL_Quit();
}

bool loadFiles(){
    
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
    return true;
}

void startFrame(){
    applySurface(-200, -200, background, screen); 
    
    applySurface(325,  50, titleFont          , screen);
    applySurface(350, 300, singlePlayerFont   , screen);
    applySurface(350, 350, optionsFont        , screen);
    applySurface(350, 400, exitFont           , screen);
}

void optionFrame(){
    applySurface(-350, -100, options, screen);

    applySurface(350, 225, optionSoundFont      , screen);
    applySurface(350, 300, optionDisplayFont    , screen);
    applySurface(350, 370, optionDifficultyFont , screen);

    SDL_Flip(screen);
}
