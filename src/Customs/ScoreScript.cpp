#include "Customs/ScoreScript.h"

ScoreScript::ScoreScript(GameObject *owner) : Script(owner) {}

void ScoreScript::Start() {
  //score = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Score");
  //playerPosition = player->GetPosition();
  //script = (PlayerScript *)player->GetComponent("ScoreScript");
}

void ScoreScript::ComponentUpdate() {}

void ScoreScript::FixedComponentUpdate() {
  score++;
  UpdateScore();
 
}

void ScoreScript::UpdateScore(){

  auto var = (UIText *)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Score")
                   ->GetComponent("UIText");
                   
  var->SetText(std::to_string(score));

}


