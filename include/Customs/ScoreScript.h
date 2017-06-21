#ifndef __SCORE_SCRIPT__
#define __SCORE_SCRIPT__

#include "Components/Script.h"
#include "Customs/PlayerScript.h"
#include "Engine/SceneManager.h"
#include "Engine/GameObject.h"
#include "Globals/EngineGlobals.h"

class ScoreScript : public Script {
public:
	ScoreScript(GameObject *owner);
  	std::string GetComponentName() override { return "ScoreScript"; };
  	void FixedComponentUpdate() override;
  	void Start() override;
  	void SetScore(int score);
  
protected:
  	void ComponentUpdate() override;
  	void UpdateScore();
  	
 

private:
	int m_score = 0;
  
};

#endif