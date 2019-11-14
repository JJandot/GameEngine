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
