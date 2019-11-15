#include "Mesh.h"

void Mesh::AddVertexCoordinate(float v) {
	vertexCoordinates.push_back(v);
}

void Mesh::AddFace(int f) {
	faces.push_back(f);
}
