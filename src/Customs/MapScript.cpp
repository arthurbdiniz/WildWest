#include "Customs/MapScript.h"

MapScript::MapScript(GameObject *owner) : Script(owner) {}

void MapScript::Start() {
}

void MapScript::ComponentUpdate() {

}

void MapScript::FixedComponentUpdate() {
  DifficultyIncrease();
  
  GetOwner()->GetPosition()->m_x -= m_velocityMap;
  if(GetOwner()->GetPosition()->m_x  < -2000){
    GetOwner()->GetPosition()->m_x = 1960;
  }
  
}

void MapScript::DifficultyIncrease(){
  difficultyIncrease++;
  m_velocityMap = m_velocityMap + difficultyIncrease/100000;

}

void MapScript::SetVelocityMap(float velocityMap){
  this->m_velocityMap = velocityMap;
}

