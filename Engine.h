/*
 * Engine.h
 *
 *  Created on: 15 Jul 2015
 *      Author: Torin
 */

#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include <map>
#include <string>
#include "Mesh.h"

class Engine {
public:
	Engine();
	virtual ~Engine();

	int Configure(const char *config_file = NULL);
	int SetupExample();
	int Run();



private:
	SDL_Window *window;
	SDL_GLContext context;
	int window_height, window_width;
	float horizontal_fov;

	std::vector<Mesh> meshes;
	std::map<std::string, unsigned int> meshNames;

	int AddMesh(Mesh& m, const char *name);
};

#endif /* ENGINE_H_ */
