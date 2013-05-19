#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

#include "exampleSDL.h"

#ifndef PARA_GON_HACKING_FRAMEWORK_H
#define PARA_GON_HACKING_FRAMEWORK_H

void optionDifficultyFrame(){
    applySurface(-500, 0, optionDifficulty, screen);

    optionDifficultyEasyFont   = TTF_RenderText_Solid(font, "Easy"   , textColor);
    optionDifficultyNormalFont = TTF_RenderText_Solid(font, "Normal" , textColor);
    optionDifficultyHardFont   = TTF_RenderText_Solid(font, "Hard"   , textColor);

    applySurface(350, 200, optionDifficultyEasyFont    , screen);
    applySurface(350, 275, optionDifficultyNormalFont  , screen);
    applySurface(350, 350, optionDifficultyHardFont    , screen);

    SDL_Flip(screen);
}

void startFrame(){
    applySurface(-200,-200, background, screen); 
   
    titleFont         = TTF_RenderText_Solid(font, "Fishing_public"  , textColor);
    singlePlayerFont  = TTF_RenderText_Solid(font, "Single Player"   , textColor);
    optionsFont       = TTF_RenderText_Solid(font, "Options"         , textColor);
    exitFont          = TTF_RenderText_Solid(font, "Exit"            , textColor);

    applySurface(325,  50, titleFont          , screen);
    applySurface(350, 300, singlePlayerFont   , screen);
    applySurface(350, 350, optionsFont        , screen);
    applySurface(350, 400, exitFont           , screen);
}

void optionFrame(){
    applySurface(-350, -100, options, screen);

    optionSoundFont          = TTF_RenderText_Solid(font, "Sound"           , textColor);
    optionDisplayFont        = TTF_RenderText_Solid(font, "Display"         , textColor);
    optionDifficultyFont     = TTF_RenderText_Solid(font, "Difficulty"      , textColor);

    applySurface(350, 200, optionSoundFont      , screen);
    applySurface(350, 300, optionDisplayFont    , screen);
    applySurface(350, 400, optionDifficultyFont , screen);

    SDL_Flip(screen);
}

#endif
