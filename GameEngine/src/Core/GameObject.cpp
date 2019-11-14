#include "GameObject.h"

Mesh* GameObject::CreateMesh() {
	Mesh *mesh = new Mesh();
	meshes.push_back(mesh);
	return mesh;
}
