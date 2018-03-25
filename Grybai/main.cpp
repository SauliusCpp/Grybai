#include <iostream>
#include <tuple>
#include <algorithm>
#include "IO.h"

std::vector<MushroomLoot> MergedLoot(const std::vector<MushroomLoot> &lootVector)
{
	std::vector<MushroomLoot> merged;

	for (int i = 0; i < lootVector.size(); i++)
	{
		MushroomLoot loot = lootVector[i];

		bool mergerAlreadyExists = false;

		for (int m = 0; m < merged.size(); m++)
		{
			if (merged[m].GetDay() == loot.GetDay())
			{
				mergerAlreadyExists = true;

				MushroomLoot* mergeInto = &merged[m];

				mergeInto->count_baravykai += loot.count_baravykai;
				mergeInto->count_raudonikiai += loot.count_raudonikiai;
				mergeInto->count_lepsiai += loot.count_lepsiai;
			}
		}

		if (!mergerAlreadyExists) merged.push_back(loot);
	}

	return merged;
}

MushroomLoot GetBestDay(const std::vector<MushroomLoot> &lootVector)
{
	MushroomLoot bestDay;

	for (MushroomLoot lootDay : lootVector)
	{
		if (lootDay.CountMushrooms() > bestDay.CountMushrooms()) bestDay = lootDay;
	}

	return bestDay;
}

int main()
{
	std::vector<MushroomLoot> merged = MergedLoot(IO::ReadLoot("U1.txt"));

	std::sort(merged.begin(), merged.end());

	MushroomLoot bestDay = GetBestDay(merged);

	IO::SaveLoot("u1rex.txt", merged, bestDay);
}