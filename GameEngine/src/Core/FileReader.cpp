#include "FileReader.h"

FileReader::Format FileReader::format;

void FileReader::ExtractFormatFromPath(std::string path) {
	std::string extension = path.substr(path.find('.'));

	if (extension.compare(".obj"))
		format = FileReader::Format::OBJ;
	else
		format = FileReader::Format::FAILED;
}

GameObject* FileReader::ExtractObjData(std::string path) {
	std::ifstream inFile;
	inFile.open(path, std::ios::in);

	if (inFile.fail())
		return nullptr;

	GameObject* gameobject = new GameObject();
	Mesh *mesh = gameobject->CreateMesh();

	std::string line;
	char first;
	char second;
	while (std::getline(inFile, line)) {
		if (line.size() < 2)
			continue;

		first = line.at(0);
		second = line.at(1);
		if (first == '#' || first == 'o')
			continue;

		if (first == 'v') {
			if (second == ' ') {
				size_t pos = line.find(' ', 2);
				size_t initialPos = 1;

				// Decompose statement
				while (pos != std::string::npos) {
					mesh->AddVertexCoordinate(std::stof(line.substr(initialPos, pos - initialPos)));
					initialPos = pos + 1;

					pos = line.find(' ', initialPos);
				}

				// Add the last one
				mesh->AddVertexCoordinate(std::stof(line.substr(initialPos, std::min(pos, line.size()) - initialPos + 1)));
			}
		}
		else if (first == 'f') {
			size_t pos = line.find(' ', 2);
			size_t initialPos = 1;

			// Decompose statement
			while (pos != std::string::npos) {
				std::string s = line.substr(initialPos, pos - initialPos);
				mesh->AddFace(std::stof(s));
				initialPos = pos + 1;

				pos = line.find(' ', initialPos);
			}

			// Add the last one
			mesh->AddFace(std::stof(line.substr(initialPos, std::min(pos, line.size()) - initialPos + 1)));
		}
	}

	return gameobject;
}

GameObject* FileReader::ExtractData(std::string path) {
	switch (format) {
		case FileReader::Format::OBJ:
			return ExtractObjData(path);
		default:
			return nullptr;
	}
}
