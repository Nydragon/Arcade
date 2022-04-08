/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** testmain2
*/

//Compilation line ::: ::
//  g++ testmain2.cpp ../../shared/csv.cpp ../../shared/operators.cpp Sdl2GraphicsLib.cpp -o testtestmain -lSDL2 -lSDL2_image -lSDL2_ttf -lm


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <fstream>
#include "Sdl2GraphicsLib.hpp"

int main(int argc, char *argv[])
{

	Sdl2GraphicsLib GraphLibSDL2;
    gfx_config_t mockConfig = {"", "../../../assets/nibbler/NibblerTestTileset.png", "../../../assets/nibbler/BADABB__.TTF", 64, 64, 12, 10}; //this is a mock tool for the mock function
    std::queue<char> que;
    std::string queualias = "LOL";
	int game = 1;
	int X = 0;
	int Y= 0;
	int A = 0;

	GraphLibSDL2.checkConfig(mockConfig);
	while (game) {
		GraphLibSDL2.flush();
        GraphLibSDL2.recordInputs();
        que = GraphLibSDL2.getInput();
		//get inputs and display on terminal
        if (que.size() != 0) {
            queualias = que.back();
			std::cout << queualias << std::endl;
		}
		if (queualias == "q")
			game = 0;
			
		//mock movement to check if it works
		if (queualias == "d" && X < mockConfig.windowWidth - 1) {
			X = X + 1;
			std::cout << X << "and max size is : "<< mockConfig.windowWidth<< std::endl;
		}
		if (queualias == "w" && Y > 0)
			Y--;
		if (queualias == "a" && X > 0)
			X--;
		if (queualias == "s" && Y < mockConfig.windowHeight - 1) {
			Y++;
			std::cout << Y << std::endl;
		}
		if (queualias == "r") {
			A = rand() % 4;
			std::cout << A << std::endl;
		}
		//end of mock movement check
		//
		//
		//
		//

        if (que.size() != 0) {
            GraphLibSDL2.popInput();
			queualias = "";
		}
		GraphLibSDL2.drawTile(5,0,0, ORIENT_TOP);
		GraphLibSDL2.drawTile(5,0,1, ORIENT_TOP);
		GraphLibSDL2.drawTile(5,0,2, ORIENT_TOP);
		

		GraphLibSDL2.drawTile(1,X,Y, ORIENT_TOP);
		GraphLibSDL2.drawTile(2 ,X+1, Y+1,ORIENT_TOP);
		GraphLibSDL2.drawTile(3 ,X+2, Y+2, A);
		GraphLibSDL2.drawText("LETS GO QT", 50, 50);
		GraphLibSDL2.drawText("LETS GO QT", 500, 500);
		GraphLibSDL2.display();
    }
	return 0;
}