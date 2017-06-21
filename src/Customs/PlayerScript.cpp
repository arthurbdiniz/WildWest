#include "Customs/PlayerScript.h"
#include "Components/UIText.h"
PlayerScript::PlayerScript(GameObject *owner) : Script(owner){};

void PlayerScript::Start() {
  position = GetOwner()->GetPosition();
  animator = (Animator *)GetOwner()->GetComponent("Animator");
  input = InputSystem::GetInstance();
}

void PlayerScript::ComponentUpdate() {
static int lastDirection=1;
  // movement animation and input detection
  animator->GetAnimation("Walk Side")->SetFlip(false, false);
  animator->PlayAnimation("Walk Side");

  movements = movements & 0x00;
  if (input->GetKeyPressed(INPUT_W)) {
  
    movements = movements | 0x08;

    auto var = GetOwner()->GetComponent("UISound"); //Play Jump Sound Effect         
    var->Start();

    animator->PlayAnimation("Walk Up");

  } 
  if(position->m_y < 600){
    animator->PlayAnimation("Walk Up");

  }

  if (InputSystem::GetInstance()->GetKeyUp(INPUT_ESCAPE)) {
    SceneManager::GetInstance()->SetCurrentScene("Main");

  }
 

}

void PlayerScript::FixedComponentUpdate() {
  if (0x08 & movements){
    inputW++;  
    if(inputW < 11){
      jumpForce = 10;
      position->m_y = position->m_y - jumpForce;
      jumpForce = jumpForce - gravity;

    }
    
  }
  if(position->m_y < 600){
    position->m_y = position->m_y - jumpForce;
    jumpForce = jumpForce - gravity;

  }
  if(position->m_y >= 600){
    position->m_y = 600;
    inputW = 0;
  }

}

void PlayerScript::GameCollisionCheck() {
 
}


