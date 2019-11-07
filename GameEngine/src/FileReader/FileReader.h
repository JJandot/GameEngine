#pragma once
#include "ReadingStrategy.h"

namespace Reader {

	enum FileType {
		OBJ
	};

	class FileReader {
	private :
		Internal::ReadingStrategy readingStrategy;
	public:
		template<FileType fileType> FileReader();
	};
}