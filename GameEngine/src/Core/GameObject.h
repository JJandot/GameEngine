#pragma once
#include "Mesh.h"

class GameObject {
private:
	int id;
	std::string name;

	std::vector<Mesh> meshes;
};

