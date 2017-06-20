#include "Customs/GamePlayController.h"
#include <Components/UIText.h>
#include <Engine/SceneManager.h>
#include <Engine/Timer.h>
#include <Customs/PlayerScript.h>
#include <Customs/CactusScript.h>

GamePlayController *GamePlayController::m_instance = nullptr;

void GamePlayController::AddPlayer(GameObject *player) {
  m_player = player;
}

GamePlayController *GamePlayController::GetInstance() {
  if (!m_instance)
    m_instance = new GamePlayController();
  return m_instance;
}

void GamePlayController::StartGame() {
 
  DeactivateCactus();
  DeactivatePlayer();
  PositPlayer();
  PositCactus();
  ActivatePlayer();
  ActivateCactus();
}

void GamePlayController::PositPlayer() {
  
}

void GamePlayController::ActivatePlayer() {
  
    auto script = (PlayerScript *)m_player->GetComponent("PlayerScript");
    //script->ResetMovementCheck();
    m_player->ClearCollisions();
    m_player->active = true;
  
}

void GamePlayController::DeactivatePlayer() {
  m_player->active = false;
}

GamePlayController::GamePlayController() {}

void GamePlayController::AddCactus(GameObject *cactus) { m_cactus = cactus; }

void GamePlayController::DeactivateCactus() { m_cactus->active = false; }

void GamePlayController::ActivateCactus() { m_cactus->active = true; }

void GamePlayController::PositCactus() {
  //m_cactus->SetPosition(Vector(m_wPos, m_hPos));
}


void GamePlayController::EndGame() {
    DeactivateCactus();
    DeactivatePlayer();
  
}



