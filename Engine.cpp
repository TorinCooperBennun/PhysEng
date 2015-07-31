/*
 * Engine.cpp
 *
 *  Created on: 15 Jul 2015
 *      Author: Torin
 */

#include "Engine.h"
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>


int Engine::Configure(const char *config_file)
{
	//if (config_file == NULL) {
		window_width = 1280;
		window_height = 720;
		horizontal_fov = 60;
	//}

	return 0;
}


int Engine::SetupExample()
{
	Mesh m = example_cube_mesh(2);
	AddMesh(m, "cube");

	return 0;
}


int Engine::Run()
{
	window = SDL_CreateWindow(
			"OpenGL testing",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			window_width,
			window_height,
			SDL_WINDOW_OPENGL);
	if (window == NULL) {
		std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << "\n";
		return 1;
	}

	context = SDL_GL_CreateContext(window);
	if (context == NULL) {
		std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << "\n";
		return 1;
	}

	glewExperimental = true;
	GLenum initErr = glewInit();
	if (initErr != GLEW_OK) {
		std::cerr << "glewInit failed: " << glewGetErrorString(initErr) << "\n";
		return 1;
	}

	return 0;
}


Engine::Engine()
:window(NULL), context(NULL), window_height(720), window_width(1280), horizontal_fov(60)
{

}


Engine::~Engine()
{

}


int Engine::AddMesh(Mesh& m, const char* name)
{
	/* lol */
	int index = meshes.size();
	meshes.push_back(m);
	std::string s(name);
	meshNames[s] = index;
	return index;
}
