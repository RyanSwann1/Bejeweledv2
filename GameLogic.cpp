#include "GameLogic.h"
#include "SharedContext.h"


GameLogic::GameLogic(SharedContext* sharedContext) :
	m_score(0),
	m_sharedContext(sharedContext)
{
}

void GameLogic::updateUI(const StateType stateType, const std::string& name, const std::string & text)
{
	GUI_Manager* guiManager = m_sharedContext->m_guiManager;

	guiManager->updateInterface(stateType, name, text);
}
