#pragma once
#include <array>
#include <vector>
#include "../MathEngine/Vector.h"

class Mesh {
private:
	std::vector<float> vertexCoordinates;
	std::vector<std::pair<float, float>> uvs;
	std::vector<float> normalCoordinates;
	std::vector<int> faces;

public:
	void AddVertexCoordinate(float f);
	void AddFace(int f);
};

