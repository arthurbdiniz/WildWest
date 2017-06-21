#include "Customs/CactusScript.h"

CactusScript::CactusScript(GameObject *owner) : Script(owner) {}

void CactusScript::Start() {
  player = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Cactus");
  //playerPosition = player->GetPosition();
  script = (PlayerScript *)player->GetComponent("CactusScript");
}

void CactusScript::ComponentUpdate() {
  
}

void CactusScript::FixedComponentUpdate() {
  Move();
  ScreenCollisionCheck();
  GameCollisionCheck();
  DifficultyIncrease();
  
  
  
}

void CactusScript::Move(){
  playerMovements = script->GetMovement();
  GetOwner()->GetPosition()->m_x -= velocityCactus;
  //cout << velocityCactus << endl;
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
void CactusScript::ScreenCollisionCheck() {
  //cout << GetOwner()->GetTag()  << endl;


  if (GetOwner()->GetPosition()->m_x < 0){
    //cout << "Out of Screen "<< endl;
  }
    
    //if (GetOwner()->GetPosition()->m_x < 0)
    //cout << GetOwner()->GetPosition()->m_x<< endl;
         

  //} 
}

void CactusScript::DifficultyIncrease(){
  difficultyIncrease++;
  velocityCactus = velocityCactus + difficultyIncrease/100000;

}
