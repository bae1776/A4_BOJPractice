//https://www.acmicpc.net/problem/20119

/*클레어와 물약
* 대회 링크 : https://www.acmicpc.net/category/detail/2335
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <list>
#include <utility>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int potionCount, recipeCount;
	cin >> potionCount >> recipeCount;

	list<pair<unordered_set<int>, int>> recipeList(recipeCount);

	for (int i = 0; i < recipeCount; i++)
	{
		pair<unordered_set<int>, int> singleRecipe;

		int recipePotions;
		cin >> recipePotions;

		
		for (int j = 0; j < recipePotions; j++)
		{
			int PotionNumber;
			cin >> PotionNumber;
			singleRecipe.first.insert(PotionNumber);
		}
		
		int recipeResult;
		cin >> recipeResult;
		singleRecipe.second = recipeResult;

		recipeList.emplace_back(singleRecipe);
	}

	int myPotionCount;
	cin >> myPotionCount;

	vector<char> canMake(potionCount + 1, false);
	queue<int> potionQueue;

	for (int i = 0; i < myPotionCount; i++)
	{
		int potionNum;
		cin >> potionNum;

		potionQueue.push(potionNum);
	}

	int totalPotion = 0;

	while (!potionQueue.empty())
	{
		int nowPotion = potionQueue.front();
		potionQueue.pop();

		if (canMake[nowPotion] == false)
		{
			canMake[nowPotion] = true;
			totalPotion++;
		}

		for (auto listElem = recipeList.begin(); listElem != recipeList.end(); listElem++)
		{
			auto get = listElem->first.find(nowPotion);

			if (get != listElem->first.end())
			{
				listElem->first.erase(get++);
				if (listElem->first.size() == 0)
				{
					potionQueue.push(listElem->second);
					listElem = recipeList.erase(listElem);
				}
			}
			
		}
	}


	cout << totalPotion << '\n';
	for (int i = 1; i <= potionCount; i++)
		if (canMake[i] == true)
			cout << i << ' ';

	



	


	return 0;
}