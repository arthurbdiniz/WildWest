#ifndef __PLAYER_SCRIPT__
#define __PLAYER_SCRIPT__

#include "Components/Script.h"
#include "Engine/InputSystem.h"
#include "Components/Animator.h"
#include "Components/Script.h"
#include "Components/UIText.h"
#include "Components/UISound.h"
#include "Engine/SceneManager.h"
#include "Engine/GameObject.h"
#include "Globals/EngineGlobals.h"
#include "Log/log.h"

using namespace std;

class PlayerScript : public Script {
public:
  PlayerScript(GameObject *owner);
  virtual string GetComponentName() override { return "PlayerScript"; };
  void ComponentUpdate() override;
  void FixedComponentUpdate() override;
  void Start() override;
  char GetMovement() { return movements; };

private:
  Vector m_movement = Vector(0, 0);
  float m_speed = 5;

  float walkSpeed = 17;
  float jumpForce = 0;
  float gravity = 2;
  InputSystem *input = nullptr;
  Animator *animator = nullptr;
  Vector *position = nullptr;
  char movements = 0x00; // up down left right
  int deadzone_x = EngineGlobals::screen_width / 2 + 100;
  int deadzone_y = EngineGlobals::screen_height / 2 + 100;
  int inputW = 0;
  
  void HandleInput();
  void GameCollisionCheck();
};

#endif

