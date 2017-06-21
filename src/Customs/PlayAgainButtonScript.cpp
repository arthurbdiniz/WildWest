#include "Customs/PlayAgainButtonScript.h"

PlayAgainButtonScript::PlayAgainButtonScript(GameObject *owner) : Script(owner) {}

void PlayAgainButtonScript::Start() {
  m_uiButton = (UIButton *)GetOwner()->GetComponent("UIButton");
}

void PlayAgainButtonScript::ComponentUpdate() {
  if (m_uiButton->IsClicked()) {

    
    
    position = SceneManager::GetInstance() // Sets Player position
                   ->GetScene("Gameplay")
                   ->GetGameObject("Cactus")
                   ->GetPosition();
                               
  	position->m_x = 1500;


    auto script = (MapScript*)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Map1")
                   ->GetComponent("MapScript");
    //script->SetVelocityMap(0.0);



    SceneManager::GetInstance()->SetCurrentScene("Gameplay");
  	
  }
}
