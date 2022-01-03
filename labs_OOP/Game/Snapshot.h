#pragma once

#include "Objects/Field.h"

class Snapshot
{
public:
	Snapshot() = default;
	void hash_func_to_file(std::string filename);
	int hash_func_ret(std::string filename);
	void save_to_file(Field* field, std::string filename, int mode);
};
