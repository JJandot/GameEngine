#include "../stdafx.h"
#include "FileReader.h"

namespace Reader {
	template<FileType fileType>
	FileReader<fileType>::FileReader() {
		if (fileType == OBJ)
			readingStrategy = Internal::ObjStrategy;
	}

	template<FileType fileType>
	void FileReader<fileType>::Read() {
		readingStrategy.Read();
	}
}