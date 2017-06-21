#ifndef __GAME_PLAY_SCENE__
#define __GAME_PLAY_SCENE__

#include "Components/CircleRenderer.h"
#include "Components/CircleCollider.h"
#include "Components/RectangleRenderer.h"
#include "Components/RectangleCollider.h"
#include "Components/Renderer.h"
#include "Components/Rigidbody.h"
#include "Components/UIText.h"
#include "Components/UISound.h"
#include "Customs/GamePlayController.h"
#include "Customs/MapScript.h"
#include "Customs/CactusScript.h"
#include "Customs/PlayerScript.h"
#include "Customs/ScoreScript.h"
#include "Engine/GameObject.h"
#include "Components/UIText.h"
#include "Engine/Scene.h"

class GamePlayScene : public Scene {
public:
  void OnActivation() override;
  void OnDeactivation() override;
  void OnShown() override;
  void OnHidden() override;
  

private:
  void CreateNakedMan();
  void CreateMap();
  void CreateCactus();
  void CreateScore();
  void CreateMusic();

};

#endif