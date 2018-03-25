#include "MushroomLoot.h"

MushroomLoot::MushroomLoot(int day, int count_baravykai, int count_raudonikiai, int count_lepsiai)
{
	_day = day;
	this->count_baravykai = count_baravykai;
	this->count_raudonikiai = count_raudonikiai;
	this->count_lepsiai = count_lepsiai;
}

const int MushroomLoot::GetDay() { return _day; }
int MushroomLoot::CountMushrooms() { return count_baravykai + count_raudonikiai + count_lepsiai; }