#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "GameObject.h"

class FileReader {
private:
	enum class Format {
		FAILED = -1,
		OBJ
	};

	static Format format;
	static void ExtractFormatFromPath(std::string path);
	static GameObject* ExtractObjData(std::string path);

public:
	static GameObject* ExtractData(std::string path);

};
