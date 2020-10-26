#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node
{
	bool exist;
	bool cutPoint;
	int num;
	int pre;
	int min;
};
struct path
{
	int x, y;
};

vector<vector<int>>connect;
vector<vector<path>>component;
vector<node>nodes;

void dfs(int u, int &time) {
	nodes[u].num = nodes[u].min = ++time;
	path newPath;
	newPath.x = u;
	for (int i = 0; i < connect[u].size(); i++)
	{
		newPath.y = connect[u][i];
		if (nodes[connect[u][i]].num == 0)
		{
			component[0].push_back(newPath);
			nodes[connect[u][i]].pre = u;
			dfs(connect[u][i], time);
			if (nodes[u].min > nodes[connect[u][i]].min)
			{
				nodes[u].min = nodes[connect[u][i]].min;
			}
			if (nodes[connect[u][i]].min >= nodes[u].num)
			{
				nodes[u].cutPoint = true;
				path pop;
				vector<path>newComponent;
				do
				{
					pop = component[0][component[0].size() - 1];
					newComponent.push_back(pop);
					component[0].pop_back();
				} while (pop.x != u || pop.y != connect[u][i]);
				component.push_back(newComponent);
			}
		}
		else if (nodes[u].num > nodes[connect[u][i]].num && nodes[u].pre != connect[u][i])
		{
			component[0].push_back(newPath);
			if (nodes[u].min > nodes[connect[u][i]].num)
			{
				nodes[u].min = nodes[connect[u][i]].num;
			}
		}
	}
}

int main() {
	int num, x, y, t, safe, way, numcase = 0;
	set<int>load;
	while (cin >> num && num)
	{
		t = safe = 0;
		way = 1;
		connect.clear();
		component.clear();
		component.resize(1);
		nodes.clear();
		while (num--)
		{
			cin >> x >> y;
			if (connect.size() < x + 1)
			{
				connect.resize(x + 1);
				nodes.resize(x + 1);
			}
			if (connect.size() < y + 1)
			{
				connect.resize(y + 1);
				nodes.resize(y + 1);
			}
			nodes[x].exist = true;
			nodes[y].exist = true;
			connect[x].push_back(y);
			connect[y].push_back(x);
		}
		for (int i = 1; i < nodes.size(); i++)
		{
			if (nodes[i].num == 0 && nodes[i].exist)
			{
				dfs(i, t);
				int rootchild = 0;
				for (int j = 0; j < connect[i].size(); j++)
				{
					if (nodes[connect[i][j]].pre == i)
					{
						rootchild++;
					}
				}
				if (rootchild < 2)
				{
					nodes[i].cutPoint = false;
				}
			}
		}
		//component
		/*for (int i = 1; i < component.size(); i++)
		{
			cout << i << ": ";
			for (int j = 0; j < component[i].size(); j++)
			{
				cout << component[i][j].x << "," << component[i][j].y << " ";
			}
			cout << "\n";
		}
		cout << "Cut: \n";
		for (int i = 1; i < nodes.size(); i++)
		{
			if (nodes[i].cutPoint)
			{
				cout << i << " ";
			}
		}
		cout << '\n';

		*/
		for (int i = 1; i < component.size(); i++)
		{
			if (component[i].size() == 1)
			{
				if (connect[component[i][0].x].size() == 1)
				{
					safe++;
				}
				if (connect[component[i][0].y].size() == 1)
				{
					safe++;
				}
			}
			else
			{
				int count = 0;

				load.clear();
				for (int j = 0; j < component[i].size(); j++)
				{
					load.insert(component[i][j].x);
					load.insert(component[i][j].y);
				}
				for (set<int>::iterator it = load.begin(); it != load.end(); ++it)
				{
					//cout << *it << " ";
					if (nodes[*it].cutPoint)
					{
						count++;
					}
				}
				//cout << '\n';
				if (count == 0)
				{
					safe += 2;
					way *= (load.size() * (load.size() - 1) / 2);
				}
				else if (count == 1)
				{
					safe++;
					way *= (load.size() - 1);
				}
			}
		}
		cout << "Case " << ++numcase << ": " << safe << " " << way << "\n";
	}
	system("pause");
	return 0;
}