#include "Composite.h"

void Composite::Mix()
{
	for (const auto& child : childs)
		child->Mix();
}

void Composite::Add(Nutrients* uk)
{
	childs.push_back(uk);
}

void Composite::Remove(Nutrients* uk)
{
	auto finded = find(childs.begin(), childs.end(), uk);
	if (finded != childs.end())
		childs.erase(finded);
	else
		cout << "Не получилось";
}

Nutrients* Composite::GetChild(int node)
{
	return childs[node];
}