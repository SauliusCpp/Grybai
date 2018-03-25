#pragma once

#include <vector>
#include "MushroomLoot.h"

class IO
{
public:
	static std::vector<MushroomLoot> ReadLoot(const char* path);
	static void SaveLoot(const char* path, const std::vector<MushroomLoot> &loot, MushroomLoot &bestDay);
};

