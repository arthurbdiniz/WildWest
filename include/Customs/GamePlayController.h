#ifndef SQUAREORDIE_MISSILECONTROLLER_H
#define SQUAREORDIE_MISSILECONTROLLER_H

#include <Engine/GameObject.h>
#include <Globals/EngineGlobals.h>
#include <stdlib.h>
#include <time.h>

class GamePlayController {
public:
  static GamePlayController *GetInstance();
  void AddPlayer(GameObject *player);
  void AddCactus(GameObject *cactus);
  
  void StartGame();
  void EndGame();

  

private:
  GamePlayController();
  
  void PositPlayer();
  void PositCactus();
  
  void ActivatePlayer();
  void DeactivatePlayer();
  
  void ActivateCactus();
  void DeactivateCactus();

  GameObject *m_cactus = nullptr;
  GameObject *m_player = nullptr;

  static GamePlayController *m_instance;

  int m_wPos = 0;
  int m_hPos = 0;
};

#endif // SQUAREORDIE_MISSILECONTROLLER_H
