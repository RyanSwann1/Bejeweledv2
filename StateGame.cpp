#include "StateGame.h"
#include "StateManager.h"
#include "SharedContext.h"
#include "EntityManager.h"
#include "GUI_Manager.h"
#include <assert.h>
#include <iostream>

StateGame::StateGame(StateManager* stateManager)
	: StateBase(stateManager),
	m_board(stateManager->getSharedContext())
{
	m_thisState = StateType::Game;
}

StateGame::~StateGame()
{
}

void StateGame::onEnter()
{
	EntityManager* entityManager = m_stateManager->getSharedContext()->m_entityManager;
	GUI_Manager* guiManager = m_stateManager->getSharedContext()->m_guiManager;
	m_board.init(); //Initialize the board
	entityManager->add(new Selector(entityManager));

	if (!guiManager->setCurrentInterface(StateType::Game))
	{
		std::cerr << "Unable to switch to interface: StateType::Game" << "\n";
	}
}

void StateGame::onExit()
{
	m_stateManager->getSharedContext()->m_entityManager->purgeEntities();
}

void StateGame::onCreate()
{

}

void StateGame::onDestroy()
{
	
}

void StateGame::update(const float deltaTime)
{
	SharedContext* sharedContext = m_stateManager->getSharedContext();
	sharedContext->m_entityManager->update(deltaTime);
	sharedContext->m_board->update(deltaTime);
	sharedContext->m_gameTimer->update(-deltaTime);

	sharedContext->m_guiManager->updateInterface(StateType::Game, "Time Text", std::to_string(static_cast<int>(sharedContext->m_gameTimer->getElaspedTime())));

	if (sharedContext->m_gameTimer->isExpired())
	{
		m_stateManager->switchTo(StateType::DifficultySelector);
		sharedContext->m_gameTimer->restart();
	}
}

void StateGame::draw(sf::RenderWindow & window)
{
	SharedContext* sharedContext = m_stateManager->getSharedContext();
	sharedContext->m_entityManager->draw(window);
	sharedContext->m_guiManager->draw(window);
}