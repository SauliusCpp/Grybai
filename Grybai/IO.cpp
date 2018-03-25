#include "IO.h"

#include <fstream>

std::vector<MushroomLoot> IO::ReadLoot(const char* path)
{
	std::ifstream reader(path);

	int tries;
	reader >> tries;

	std::vector<MushroomLoot> loot = std::vector<MushroomLoot>(tries);

	for (int i = 0; i < tries; i++)
	{
		int day, count_baravykai, count_raudonikiai, count_lepsiai;

		reader >> day;
		reader >> count_baravykai >> count_raudonikiai >> count_lepsiai;

		loot[i] = MushroomLoot(day, count_baravykai, count_raudonikiai, count_lepsiai);
	}

	return loot;
}

void IO::SaveLoot(const char* path, const std::vector<MushroomLoot> &loot, MushroomLoot &bestDay)
{
	std::ofstream writer(path);

	for (MushroomLoot lootDay : loot)
	{
		writer << lootDay.GetDay();
		writer << ' ' << lootDay.count_baravykai << ' ' << lootDay.count_raudonikiai << ' ' << lootDay.count_lepsiai << '\n';
	}

	writer << bestDay.GetDay() << ' ' << bestDay.CountMushrooms();
}