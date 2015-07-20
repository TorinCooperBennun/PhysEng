/*
 * Mesh.cpp
 *
 *  Created on: 15 Jul 2015
 *      Author: Torin
 */

#include "Mesh.h"


Mesh::Mesh()
:vertices(), indices(), colours()
{

}


Mesh::~Mesh()
{

}


int Mesh::Vertices(std::vector<float>& new_vertices)
{
	if (new_vertices.size() % 3 != 0) {
		return 1;
	}
	vertices = new_vertices;
	indices.clear();
	colours.clear();
	return 0;
}


int Mesh::Faces(std::vector<float>& new_indices)
{
	if (new_indices.size() % 3 != 0) {
		return 1;
	}
	for (float index : new_indices) {
		if (index >= vertices.size()) {
			return 1;
		}
	}
	indices = new_indices;
	return 0;
}


int Mesh::Colours(std::vector<float>& new_colours)
{
	if (new_colours.size() % 3 != 0 or new_colours.size() > vertices.size()) {
		return 1;
	}
	for (float colour : new_colours) {
		if (colour > 1.0) {
			return 1;
		}
	}
	colours = new_colours;
	return 0;
}


Mesh example_cube_mesh(float dimension)
{
	float dim = dimension;

	std::vector<float> v = {
			// front
			0.0, 0.0, 0.0,
			0.0, dim, 0.0,
			dim, dim, 0.0,
			dim, 0.0, 0.0,
			// back
			0.0, 0.0, dim,
			0.0, dim, dim,
			dim, dim, dim,
			dim, 0.0, dim,
	};

	std::vector<float> f = {
			// front
			0, 3, 1,
			3, 2, 1,
			// top
			3, 7, 2,
			7, 6, 2,
			// back
			5, 7, 4,
			5, 6, 7,
			// bottom
			1, 4, 0,
			1, 5, 4,
			// left
			0, 4, 3,
			4, 7, 3,
			// right
			1, 2, 5,
			2, 6, 5,
	};

	std::vector<float> c = {
			// front
		    1.0, 0.0, 0.0,
		    0.0, 1.0, 0.0,
		    0.0, 0.0, 1.0,
		    1.0, 1.0, 1.0,
		    // back
		    1.0, 0.0, 0.0,
		    0.0, 1.0, 0.0,
		    0.0, 0.0, 1.0,
		    1.0, 1.0, 1.0,
	};

	Mesh m;
	int result = 0;
	result = m.Vertices(v);
	result = m.Faces(f);
	result = m.Colours(c);
	if (result) {
		std::cerr << "Can't create cube!\n";
		exit(1);
	}
	return m;
}
