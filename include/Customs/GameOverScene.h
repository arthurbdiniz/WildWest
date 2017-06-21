#ifndef __GAME_OVER_SCENE__
#define __GAME_OVER_SCENE__

#include "Components/RectangleRenderer.h"
#include "Components/Renderer.h"
#include "Components/UIButton.h"
#include "Components/UIText.h"
#include "Components/UISound.h"
#include "Customs/PlayButtonScript.h"
#include "Customs/PlayAgainButtonScript.h"
#include "Customs/QuitButtonScript.h"
#include "Engine/Image.h"
#include "Engine/Scene.h"
#include "Globals/EngineGlobals.h"
#include "Components/Script.h"
#include "Customs/PlayerScript.h"
#include "Customs/ScoreScript.h"
#include "Engine/SceneManager.h"
#include "Engine/GameObject.h"


class GameOverScene : public Scene {
public:
  GameOverScene();
  virtual void OnActivation() override;
  virtual void OnDeactivation() override;
  virtual void OnShown() override;
  virtual void OnHidden() override;

  UIText *m_playerScoreText;

private:
  int m_width_middle;
  int m_height_middle;
  void CreatePlayAgainButton();
  void CreateQuitButton();

  void CreateMusic();
  void CreateBackground();
  void CreatePlayerScore();

};

#endif
