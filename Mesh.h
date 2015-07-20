/*
 * Mesh.h
 *
 *  Created on: 15 Jul 2015
 *      Author: Torin
 */

#ifndef MESH_H_
#define MESH_H_

#include <vector>

class Mesh {
public:
	Mesh();
	virtual ~Mesh();

	int Vertices(std::vector<float>& new_vertices);
	int Faces(std::vector<float>& new_indices);
	int Colours(std::vector<float>& new_colours);

private:
	std::vector<float>& vertices;
	std::vector<float>& indices;
	std::vector<float>& colours;
};

Mesh example_cube_mesh(float dimension);

#endif /* MESH_H_ */
