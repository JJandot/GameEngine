#pragma once
#include <array>
#include <vector>
#include "../MathEngine/Vector.h"

class Mesh {
private:
	struct Face {
		std::vector<std::array<int, 3>> vertices;
	};

	std::vector<Vector> vertexCoordinates;
	std::vector<std::pair<float, float>> uvs;
	std::vector<Vector> normalCoordinates;
	std::vector<Face> faces;

public:
	void AddVertexCoordinate(Vector v);
	void AddFace(Face f);
};

