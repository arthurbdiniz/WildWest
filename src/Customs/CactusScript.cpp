#include "Customs/CactusScript.h"

CactusScript::CactusScript(GameObject *owner) : Script(owner) {}

void CactusScript::Start() {
  player = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Cactus");
  script = (PlayerScript *)player->GetComponent("CactusScript");
}

void CactusScript::ComponentUpdate() {}

void CactusScript::FixedComponentUpdate() {
  Move();
  ScreenCollisionCheck();
  GameCollisionCheck();
  DifficultyIncrease();
}

void CactusScript::Move(){
  playerMovements = script->GetMovement();
  GetOwner()->GetPosition()->m_x -= velocityCactus;
  int newPosition = rand() % 500 + 1000;
  
  if(GetOwner()->GetPosition()->m_x  < -200){
    GetOwner()->GetPosition()->m_x = newPosition;
  }

}

void CactusScript::GameCollisionCheck() {
  
  for (auto obj : GetOwner()->GetCollisions()) {
    cout << "Collisions" << endl;
    GetOwner()->ClearCollisions();
    SceneManager::GetInstance()->SetCurrentScene("GameOver"); 
  }
}
void CactusScript::ScreenCollisionCheck() {}

void CactusScript::DifficultyIncrease(){
  difficultyIncrease++;
  velocityCactus = velocityCactus + difficultyIncrease/100000;
}
