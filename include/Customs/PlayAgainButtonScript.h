#ifndef __PLAY_AGAIN_BUTTON_SCRIPT__
#define __PLAY_AGAIN_BUTTON_SCRIPT__

#include "Components/Script.h"
#include "Components/UIButton.h"
#include "Components/UISound.h"
#include "Engine/GameObject.h"
#include "Customs/MapScript.h"

using namespace std;

class PlayAgainButtonScript : public Script {
public:
  PlayAgainButtonScript(GameObject *owner);
  string GetComponentName() override { return "PlayAgainButtonScript"; };
  void ComponentUpdate() override;
  void Start() override;

private:
  UIButton *m_uiButton = nullptr;
  Vector *position = nullptr;
};
#endif
