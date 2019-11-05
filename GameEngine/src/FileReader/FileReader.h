#pragma once
#include "ObjStrategy.h"
#include "ReadingStrategy.h"

namespace Reader {

	enum FileType {
		OBJ
	};

	template<FileType fileType>
	class FileReader {
	private :
		Internal::ReadingStrategy readingStrategy;
	public:
		FileReader();
		void Read();
	};
}