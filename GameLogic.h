#pragma once

//namespace SpawnTiming
//{
//	int 
//}
#include "StateType.h"
#include "GameDifficulty.h"
#include <string>

struct SharedContext;
class GameLogic
{
public:
	GameLogic(SharedContext* sharedContext);

	void addScore(int score) { m_score += score; }
	void clearScore() { m_score = 0; }
	unsigned int getScore() const { return m_score; }
	GameDifficulty getGameDifficulty() const { return m_gameDifficulty; }
	void setGameDifficulty(const GameDifficulty gameDifficulty) { m_gameDifficulty = gameDifficulty; }

	void updateUI(const StateType stateType, const std::string& name, const std::string& text);

private:
	unsigned int m_score;
	SharedContext* m_sharedContext;
	GameDifficulty m_gameDifficulty;
	
};

