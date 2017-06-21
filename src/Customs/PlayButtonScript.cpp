#include "Customs/PlayButtonScript.h"

PlayButtonScript::PlayButtonScript(GameObject *owner) : Script(owner) {}

void PlayButtonScript::Start() {
  m_uiButton = (UIButton *)GetOwner()->GetComponent("UIButton");
}

void PlayButtonScript::ComponentUpdate() {
  if (m_uiButton->IsClicked()) {

    SceneManager::GetInstance()->SetCurrentScene("Gameplay");
    /*
    auto var = (UISound *)SceneManager::GetInstance()
                   ->GetScene("MainScene")
                   ->GetGameObject("MusicMenu")
                   ->GetComponent("UISound");
                   
  	var->Stop();
  	*/
  }
}
