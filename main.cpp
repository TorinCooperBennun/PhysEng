/*
 * main.cpp
 *
 *  Created on: 15 Jul 2015
 *      Author: Torin
 */

#include "Engine.h"


int main(int argc, char *argv[])
{
	Engine game;

	if (game.Configure() != 0) {
		std::cerr << "Configuration failed\n";
		return 1;
	}

	if (game.Run() != 0) {
		std::cerr << "Engine failed\n";
		return 1;
	}

	return 0;
}
