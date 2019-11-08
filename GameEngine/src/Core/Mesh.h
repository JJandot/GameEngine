#pragma once
#include <array>
#include <vector>
#include "../MathEngine/Vector.h"

class Mesh {
private:
	struct Face {
		std::array<Vector, 3> vertices;
	};

	std::vector<Vector> vertexCoordinates;
	std::vector<std::pair<float, float>> uvs;
	std::vector<Vector> normalCoordinates;
	std::vector<Face> faces;

public:
};

