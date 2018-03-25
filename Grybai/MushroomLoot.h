#pragma once
struct MushroomLoot
{
	int count_baravykai, count_raudonikiai, count_lepsiai;
	const int GetDay();

	MushroomLoot(int day, int count_baravykai, int count_raudonikiai, int count_lepsiai);
	MushroomLoot() : _day(0), count_baravykai(0), count_raudonikiai(0), count_lepsiai(0) {}

	bool operator< (MushroomLoot &other) const 
	{
		return _day < other.GetDay();
	}

	int CountMushrooms();

private:
	int _day;
};
