#include "Customs/CactusScript.h"

CactusScript::CactusScript(GameObject *owner) : Script(owner) {}

void CactusScript::Start() {
  nakedMan = SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Cactus");
  nakedManPosition = nakedMan->GetPosition();
  script = (NakedManScript *)nakedMan->GetComponent("CactusScript");
}

void CactusScript::ComponentUpdate() {}

void CactusScript::FixedComponentUpdate() {
  nakedManMovements = script->GetMovement();
  GetOwner()->GetPosition()->m_x -= 10;
  //cout <<  GetOwner()->GetPosition()->m_x << endl;
  
  if(GetOwner()->GetPosition()->m_x  < -200){
    GetOwner()->GetPosition()->m_x = 1000;
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
