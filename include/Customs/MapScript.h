#ifndef __MAP_SCRIPT__
#define __MAP_SCRIPT__

#include "Components/Script.h"
#include "Engine/SceneManager.h"
#include "Globals/EngineGlobals.h"

class MapScript : public Script {
public:
  MapScript(GameObject *owner);
  std::string GetComponentName() override { return "MapScript"; };
  void FixedComponentUpdate() override;
  void Start() override;
  void SetVelocityMap(float velocityMap);

protected:
  void ComponentUpdate() override;
  void DifficultyIncrease();
  

private:

  float m_velocityMap = 10;
  float difficultyIncrease = 0;
};

#endif