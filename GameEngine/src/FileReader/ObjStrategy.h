#pragma once
#include "ReadingStrategy.h"

namespace Reader {

	namespace Internal {
		class ReadingStrategy;

		class ObjStrategy : public ReadingStrategy {
		public:
			void Read();
		};

	}
}

