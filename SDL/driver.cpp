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

#include "driver.h"

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

    int buttonX=0,
        buttonY=0,
        frame=1;

    while(run){ 
        while(SDL_PollEvent(&event)){
        
        //Mouse is moved
            if(event.type == SDL_MOUSEMOTION){

            }

        //Mouse button is pressed
            if(event.type == SDL_MOUSEBUTTONDOWN){
                //if(event.type == SDL_BUTTON_LEFT){
                    buttonX = event.button.x;
                    buttonY = event.button.y;

                    std::cout << "LEFT: ";
                //Starting menu -> Options
                    if((buttonX>350)&&(buttonX<525)&&(buttonY>370)&&(buttonY<400)&&(frame==1)){
                        ++frame;
                        optionFrame();
                        //SDL_Delay(1000);
                    }
                //Options menu -> Difficulty
                    if((buttonX>350)&&(buttonX<585)&&(buttonY>420)&&(buttonY<450)&&(frame==2)){
                        ++frame;
                        optionDifficultyFrame();
                    }
                //Option menu -> Display
                //Option menu -> Sound
                //Difficulty -> Easy
                //Difficulty -> Normal
                //Difficulty -> Hard
                //Start menu -> exit
                    if((buttonX>350)&&(buttonX<445)&&(buttonY>420)&&(buttonY<450)&&(frame==1)){
                        run=false;
                    }
                //}
                std::cout << "(" << buttonX << ", " << buttonY << " )" << std::endl;
            }
        
        //Key pressed down            
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
        
        if(frame==1)    startFrame();
        if(frame==2)    optionFrame();

        if( SDL_Flip(screen) == -1){
            std::cout << "screen could not be fliped to screen" << std::endl;
            return 1;
        }
    }

    cleanAndClose();                                                                                     //Quit SDL

    std::cout << "Program is quiting" << std::endl;

    return 0;
}
