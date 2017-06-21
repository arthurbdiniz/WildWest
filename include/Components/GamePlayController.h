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
  
  void ActivatePlayers();
  void DeactivatePlayers();
  
  void ActivateCactus();
  void DeactivateCactus();

  std::vector<GameObject *> m_cactus;
  GameObject *m_player = nullptr;

  static GamePlayController *m_instance;

  int m_wPos[4] = {0, EngineGlobals::screen_width - 40, 0,
                   EngineGlobals::screen_width - 40};
  int m_hPos[4] = {0, EngineGlobals::screen_height - 60,
                   EngineGlobals::screen_height - 60, 0};
};

#endif // SQUAREORDIE_MISSILECONTROLLER_H
