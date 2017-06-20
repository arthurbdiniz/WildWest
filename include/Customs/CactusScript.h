#ifndef __CACTUS_SCRIPT__
#define __CACTUS_SCRIPT__

#include "Components/Script.h"
#include "Customs/PlayerScript.h"
#include "Engine/SceneManager.h"
#include "Engine/GameObject.h"
#include "Globals/EngineGlobals.h"

class CactusScript : public Script {
public:
  CactusScript(GameObject *owner);
  std::string GetComponentName() override { return "CactusScript"; };
  void FixedComponentUpdate() override;
  void Start() override;

protected:
  void ComponentUpdate() override;
  void Move();
  void GameCollisionCheck();
  void ScreenCollisionCheck();

private:
  GameObject *player = nullptr;
  Vector *playerPosition = nullptr;
  PlayerScript *script = nullptr;
  char playerMovements;
};

#endif