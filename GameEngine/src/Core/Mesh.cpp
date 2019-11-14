#include "Mesh.h"

void Mesh::AddVertexCoordinate(Vector v) {
	vertexCoordinates.push_back(v);
}

void Mesh::AddFace(Face f) {
	faces.push_back(f);
}
