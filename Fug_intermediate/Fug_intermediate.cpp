#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
public:
	int Id, Rank;
	string Name;
	Player(int pId, string pName, int pRank)
	{
		Id = pId;
		Name = pName;
		Rank = pRank;
	}
};

class Hero
{
public:
	int Id, HP, Damage;
	string Name;
	Hero(int hId, string hName, int hHP, int hDamage)
	{
		Id = hId;
		Name = hName;
		HP = hHP;
		Damage = hDamage;
	}
};
class PlayerManager
{
public:
	vector<Player> players;
	void CreatePlayer(int pId, string pName, int pRank)
	{
		Player new_player(pId, pName, pRank);
		players.push_back(new_player);
	}

	Player GetPlayerByName(string pName)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name)
			{
				return players[i];
			}
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}

	Player GetPlayerById(int pId)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pId == players[i].Id)
			{
				return players[i];
			}
		}
		Player empty_player(0, "This player does not exist", 0);
		return empty_player;
	}
	void DeletePlayer(string pName, int pId = 0 )
	{
		this->players;
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name || pId == players[i].Id)
			{
				players.erase(players.begin() + i);
				break;
			}
		}
	}
	void AllPlayersInfo()
	{
		for (const auto& elem : players)
		{
			cout << "Name: " << elem.Name << "\t" << "Id: " << elem.Id << "\tRank: " << elem.Rank << endl;
		}
	}
	void ShowPlayerInfo(string pName, int pId = 0)
	{
		for (int i = 0; i < players.size(); i++)
		{
			if (pName == players[i].Name || pId == players[i].Id)
			{
				cout << "Name: " << players[i].Name << "\t" << "Id: " << players[i].Id << "\tRank: " << players[i].Rank << endl;
				break;
			}
		}
		Player empty_player(0, "This player does not exist", 0);

	}
};

int main()
{
	PlayerManager players;
	players.CreatePlayer(1, "Glebid", 0);
	players.CreatePlayer(2, "Andrel", 0);
	players.CreatePlayer(3, "Dimkrat", 0);
	
	players.AllPlayersInfo();

	players.DeletePlayer("" , 1);

	players.AllPlayersInfo();
	players.ShowPlayerInfo("" , 2);
}
