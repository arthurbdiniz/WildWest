#ifndef __GAME_OVER_SCENE__
#define __GAME_OVER_SCENE__

#include "Components/RectangleRenderer.h"
#include "Components/Renderer.h"
#include "Components/UIButton.h"
#include "Components/UIText.h"
#include "Components/UISound.h"
#include "Customs/CatchAllButtonScript.h"
#include "Customs/MissileButtonScript.h"
#include "Customs/PlayButtonScript.h"
#include "Customs/QuitButtonScript.h"
#include "Engine/Image.h"
#include "Engine/Scene.h"
#include "Globals/EngineGlobals.h"
#include "Components/Script.h"
#include "Customs/PlayerScript.h"
#include "Engine/SceneManager.h"
#include "Engine/GameObject.h"


class GameOverScene : public Scene {
public:
  GameOverScene();
  virtual void OnActivation() override;
  virtual void OnDeactivation() override;
  virtual void OnShown() override;
  virtual void OnHidden() override;

private:
  int m_width_middle;
  int m_height_middle;
  void CreateLogo();
  void CreatePlayAgainButton();
  void CreateQuitButton();

  void CreateMusic();
  void CreateBackground();
  void CreatePlayerScore();
  //void CreateGamemodes();

};

#endif
