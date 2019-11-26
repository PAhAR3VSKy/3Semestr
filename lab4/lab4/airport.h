#pragma once
#include <iostream>
#include <queue>

class airport
{
public:
	airport();
	airport(int);
private:
	std::queue <int> *takeoff;
	std::queue <int> *landing;
};

