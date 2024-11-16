//https://www.acmicpc.net/problem/1827

/*여행가이드 (Gold 2)

Soultion : 구현 + 기하학

8명 밖에 안되므로 브루트포스하면 되는데

원방정식과 직선 운동방정식을 연립하면 t에 대한 이차방정식이 되는데
식은 많이 복잡하나 구할 만은 하다.
주의할 점은 사람과 조우한 뒤 그 사람이 버스로 돌아가는 시간까지 고려해야 한다.
*/

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <functional>
using namespace std;

struct Person {
	double xi, yi, speed, angle;
};
list<vector<int>> permuList(int cnt);


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int people;
	double guideV;

	cin >> people;
	cin >> guideV;

	vector<Person> plist;
	for (int i = 0; i < people; i++)
	{
		Person p;
		cin >> p.xi >> p.yi >> p.speed >> p.angle;
		plist.emplace_back(p);
	}

	auto permu = permuList(people);
	int ans = 100000000;

	for (vector<int>& list : permu)
	{
		double guideX = 0.0, guideY = 0.0;
		double t = 0.0, totalTime = 0.0;
		for (int& idx : list)
		{
			Person& p = plist[idx];
			double vx = p.speed * cos(p.angle);
			double vy = p.speed * sin(p.angle);
			double xi = p.xi + t * vx - guideX;
			double yi = p.yi + t * vy - guideY;

			//이차방정식의 해가 도달 시간 t
			double a = vx * vx + vy * vy - guideV * guideV;
			double b = vx * xi + vy * yi;
			double c = xi * xi + yi * yi;

			double tnext = (-b - sqrt(b * b - a * c)) / a;
			t += tnext;
			guideX = p.xi + t * vx;
			guideY = p.yi + t * vy;
			totalTime = max(totalTime, t + sqrt(guideX * guideX + guideY * guideY) / p.speed /*comeback Time*/);
		}

		ans = min(ans, (int)(totalTime + 0.5));
	}

	cout << ans << '\n';
	
	return 0;
}



list<vector<int>> permuList(int cnt)
{
	list<vector<int>> output;

	std::function<void(vector<int>&, int)> permu = [&](vector<int>& v, int idx)
		{
			if (idx == cnt)
			{
				output.push_back(v);
				return;
			}
			for (int i = idx; i < cnt; i++)
			{
				swap(v[idx], v[i]);
				permu(v, idx + 1);
				swap(v[idx], v[i]);
			}
		};

	vector<int> init(cnt);
	for (int i = 0; i < cnt; i++)
		init[i] = i;

	permu(init, 0);

	return output;
}