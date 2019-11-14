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

	std::string line;
	while (std::getline(inFile, line)) {
		if (line.at(0) == '#')
			continue;
	}

	return nullptr;
}

GameObject* FileReader::ExtractData(std::string path) {
	switch (format) {
		case FileReader::Format::OBJ:
			return ExtractObjData(path);
		default:
			return nullptr;
	}
}
