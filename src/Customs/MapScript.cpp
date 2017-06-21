#include "Customs/MapScript.h"

MapScript::MapScript(GameObject *owner) : Script(owner) {}

void MapScript::Start() {
  nakedMan = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Map1");
  //nakedManPosition = nakedMan->GetPosition();
  script = (NakedManScript *)nakedMan->GetComponent("MapScript");
}

void MapScript::ComponentUpdate() {

}

void MapScript::FixedComponentUpdate() {
  DifficultyIncrease();
  nakedManMovements = script->GetMovement();
  GetOwner()->GetPosition()->m_x -= m_velocityMap;
  //cout <<  GetOwner()->GetPosition()->m_x << endl;
  if(GetOwner()->GetPosition()->m_x  < -2000){
    GetOwner()->GetPosition()->m_x = 1960;
  }
  
  /*if (!nakedManMovements)
    return;
  if (nakedManPosition->m_x + 64 >= EngineGlobals::screen_width / 2 + 100 &&
      (nakedManMovements & 0x01))
    GetOwner()->GetPosition()->m_x -= 17;
  if (nakedManPosition->m_x <= EngineGlobals::screen_width / 2 - 100 &&
      (nakedManMovements & 0x02))
    GetOwner()->GetPosition()->m_x += 17;
  if (nakedManPosition->m_y + 64 >= EngineGlobals::screen_height / 2 + 100 &&
      (nakedManMovements & 0x04))
    GetOwner()->GetPosition()->m_y -= 17;
  if (nakedManPosition->m_y <= EngineGlobals::screen_height / 2 - 100 &&
      (nakedManMovements & 0x08))
    GetOwner()->GetPosition()->m_y += 17;
  */
}

void MapScript::DifficultyIncrease(){
  difficultyIncrease++;
  m_velocityMap = m_velocityMap + difficultyIncrease/100000;

}

void MapScript::SetVelocityMap(float velocityMap){
  this->m_velocityMap = velocityMap;
}

