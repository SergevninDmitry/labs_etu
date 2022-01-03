#pragma once
#include "Objects/Field.h"
#include "Snapshot.h"


class Loader {
public:
	Loader() = default;
	bool try_load(Snapshot saver, std::string filename);
	Field* load_from_file(std::string filename);
};