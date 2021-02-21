#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <numeric>

using namespace std;

class Hero
{
public:
	int Id, HP, Damage;
	string Name;
	Hero(int hId = 0, string hName = "", int hHP = 0, int hDamage = 0)
	{
		Id = hId;
		Name = hName;
		HP = hHP;
		Damage = hDamage;
	}
};

class Player
{
public:
	int Id, Rank;
	string Name;
	Hero hero;
	Player(int pId = 0, string pName = "", int pRank = 0)
	{
		Id = pId;
		Name = pName;
		Rank = pRank;
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
	void AssignHero(int Id, Hero hero)
	{
		this->players;
		for (auto& elem : players)
		{
			if (Id = elem.Id)
			{
				elem.hero = hero;
			}
		}
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
	void DeletePlayer(string pName = "", int pId = 0 )
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
	}
};
class HeroManager
{
public:
	vector<Hero> heroes;
	void CreateHero(int Id, string Name, int HP , int Damage)
	{
		Hero new_hero(Id, Name, HP, Damage);
		heroes.push_back(new_hero);
	}

	Hero GetHeroByName(string Name)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name)
			{
				return heroes[i];
			}
		}
		Hero empty_hero(0, "This player does not exist", 0,0);
		return empty_hero;
	}

	Hero GetHeroById(int Id)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Id == heroes[i].Id)
			{
				return heroes[i];
			}
		}
		Hero empty_hero(0, "This player does not exist", 0, 0);
		return empty_hero;
	}
	void DeleteHero(string Name = "", int Id = 0)
	{
		this->heroes;
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name || Id == heroes[i].Id)
			{
				heroes.erase(heroes.begin() + i);
				break;
			}
		}
	}
	void AllHeroesInfo()
	{
		for (const auto& elem : heroes)
		{
			cout << "Name: " << elem.Name << "\t" << "Id: " << elem.Id << "\tHP: " << elem.HP << "\tDamage: " << elem.Damage << endl;
		}
	}
	void ShowHeroInfo(string Name, int Id = 0)
	{
		for (int i = 0; i < heroes.size(); i++)
		{
			if (Name == heroes[i].Name || Id == heroes[i].Id)
			{
				cout << "Name: " << heroes[i].Name << "\t" << "Id: " << heroes[i].Id << "\tHP: " << heroes[i].HP << "\tDamage: " << heroes[i].Damage << endl;
				break;
			}
		}

	}
};

class Team
{
public:
	string Name;

	struct PlayerHero
	{
		Player player;
		Hero hero;
		PlayerHero() : player(), hero()
		{

		}
	};

	vector<PlayerHero> team;

};

class TeamManager
{
public:
	
	vector<Team> teams;
	void GenerateNewTeams(PlayerManager players, HeroManager heroes)
	{
		this->teams;
		teams.clear();
		
		int random_player;
		vector<int> random_players(players.players.size());
		iota(random_players.begin(), random_players.end(), 0);

		int random_hero;
		vector<int> random_heroes(heroes.heroes.size());
		iota(random_heroes.begin(), random_heroes.end(), 0);

		for (int t = 0; t<2; t++)
		{
			teams.resize(t + 1);
			for (int i = 0; i < 5; i++)
			{
				random_player = rand() % random_players.size();
				random_players.erase(random_players.begin() + random_player);

				random_hero = rand() % random_heroes.size();
				random_heroes.erase(random_heroes.begin() + random_hero);
				teams[t].team.resize(i+1);
				teams[t].team[i].player = players.players[random_player];
				teams[t].team[i].hero = heroes.heroes[random_hero];
			}
		}
		
	}
	void GetTeamInfo(PlayerManager& players, HeroManager& heroes)
	{
		for (const auto& elem : teams)
		{
			for (int i = 0; i < 5; i++)
			{
				players.ShowPlayerInfo(elem.team[i].player.Name);
				heroes.ShowHeroInfo(elem.team[i].hero.Name);
			}
			cout << "\n\n\n";
		}
	}

};
void InitializeUnits(PlayerManager& players, HeroManager& heroes)
{
	vector<string> player_names = { "Glebelul", "Glebid", "Glebuhnuv", "Gleb Proshlogodniy","Glebilliard", "Glebanka","Glebabka","Glebatya","Gleboomer","Glebaran","Gleboomerang","Gleboohanka","Glebochka","Glebochko","Glebass", "Glebariga" };
	vector<string> hero_names = { "Andrel", "Androker", "Anduryn", "Nedroker","Andrain","Dimkrat", "Yasha Lavka", "Kopchik","Gorobchik","Grobchik","Groshi","Bariga", "Batya", "Ushel po sigaretu", "Widerell", "Dimbass", "Kapchik", "Kapa_F", "Dimkursed", "Allah", "Na Travelah" };
	int random;
	string temp_name;
	for (int i = 0; i < 10; i++)
	{
		random = rand() % player_names.size();
		temp_name = player_names[random];
		player_names.erase(player_names.begin() + random);

		players.CreatePlayer(i+1, temp_name , 0);
	}
	for (int i = 0; i < 15; i++)
	{
		random = rand() % hero_names.size();
		temp_name = hero_names[random];
		hero_names.erase(hero_names.begin() + random);

		heroes.CreateHero(i+1, temp_name, rand() % 60 + 10, rand() % 60 + 10);
	}

}
int main()
{

	srand(time(NULL));
	PlayerManager players;
	HeroManager heroes;
	TeamManager teams;
	InitializeUnits(players, heroes);

	teams.GenerateNewTeams(players, heroes);

	teams.GetTeamInfo(players, heroes);
	//players.CreatePlayer(1, "Glebid", 0);
	//players.CreatePlayer(2, "Andrel", 0);
	//players.CreatePlayer(3, "Dimkrat", 0);
	//heroes.CreateHero(1, "Glebelul", 1, 1);
	
	//players.AllPlayersInfo();
	//heroes.AllHeroesInfo();
	//players.DeletePlayer("" , 1);
	//players.GetPlayerById(1).hero = heroes.GetHeroById(1);
	//players.AllPlayersInfo();
	//players.ShowPlayerInfo("" , 2);
}
