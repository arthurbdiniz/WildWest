#ifndef __CACTUS_SCRIPT__
#define __CACTUS_SCRIPT__

#include "Components/Script.h"
#include "Customs/NakedManScript.h"
#include "Engine/SceneManager.h"
#include "Globals/EngineGlobals.h"

class CactusScript : public Script {
public:
  CactusScript(GameObject *owner);
  std::string GetComponentName() override { return "CactusScript"; };
  void FixedComponentUpdate() override;
  void Start() override;

protected:
  void ComponentUpdate() override;

private:
  GameObject *nakedMan = nullptr;
  Vector *nakedManPosition = nullptr;
  NakedManScript *script = nullptr;
  char nakedManMovements;
};

#endif