#include "Customs/GamePlayScene.h"

void GamePlayScene::OnActivation() {
  CreateNakedMan();
  CreateMap();
  CreateCactus();
}

void GamePlayScene::OnDeactivation() {}

void GamePlayScene::OnShown() {}

void GamePlayScene::OnHidden() {}

void GamePlayScene::CreateNakedMan() {
  int xPos, yPos;
  xPos =EngineGlobals::screen_width / 2 - 300;
  yPos =EngineGlobals::screen_height / 2 + 200;

  auto nakedMan = new GameObject("NakedMan", new Vector(xPos, yPos), 120, 147, 2);

  // renderer
  //auto nakedManImage = new Image("assets/player.png", 0, 128, 96, 96);
//  auto nakedManRenderer = new Renderer(nakedMan, nakedManImage);

  // circle renderer
  // auto cr = new CircleRenderer(nakedMan, Vector(32, 32), 32);

  // rect renderer
  // auto rr = new RectangleRenderer(nakedMan, Vector(0, 0), 64, 64);

  // animations
  auto nakedManSprite = new Image("assets/Images/player.png", 0, 0, 1199, 294);

  

  auto StopRightAnimation = new Animation(nakedMan, nakedManSprite);
         StopRightAnimation->AddFrame(new Frame(0, 0, 415, 507));

  auto StopLeftAnimation = new Animation(nakedMan, nakedManSprite);
        StopLeftAnimation->AddFrame(new Frame(0, 128, 415, 507));

  auto StopUpAnimation = new Animation(nakedMan, nakedManSprite);
        StopUpAnimation->AddFrame(new Frame(0, 384, 415, 507));

  auto walkSideAnimation = new Animation(nakedMan, nakedManSprite);
  for (int i = 0; i < 10; i++){

    walkSideAnimation->AddFrame(new Frame(i * 120, 0, 120, 147));
  }
  
    

  auto walkUpAnimation = new Animation(nakedMan, nakedManSprite);
  for (int i = 1; i < 5; i++)
    walkUpAnimation->AddFrame(new Frame(i * 120, 147, 120, 147));

  

  // animator
  auto nakedManAnimator = new Animator(nakedMan);

  nakedManAnimator->AddAnimation("Walk Side", walkSideAnimation);
  nakedManAnimator->AddAnimation("Walk Up", walkUpAnimation);

  nakedManAnimator->AddAnimation("Stop Up", StopUpAnimation);
  //nakedManAnimator->AddAnimation("Stop Left", StopLeftAnimation);
  //nakedManAnimator->AddAnimation("Stop Right", StopRightAnimation);  
  // script
  auto nakedManScript = new NakedManScript(nakedMan);

  auto nakedManCollider = new RectangleCollider(nakedMan, Vector(0, 0), 400, 300, 0);
  // rigidbody
  // auto nakedManRB = new Rigidbody(nakedMan);

  AddGameObject(nakedMan);
}

void GamePlayScene::CreateMap() {
//Original resolution is 2000/1500
//6000,4500 = 3x
  auto map1 = new GameObject("Map1", new Vector(0 ,-350  ),2000, 1200);
  auto map2 = new GameObject("Map2", new Vector(1980 ,-350  ),2000, 1200);

  // Renderer
  auto mapImage = new Image("assets/Images/map_edited.png", 0, 0, 1000, 597);
  auto mapRenderer1 = new Renderer(map1, mapImage);
  auto mapRenderer2 = new Renderer(map2, mapImage);



  // Script
  auto mapScript = new MapScript(map1);
  auto mapScript2 = new MapScript(map2);

  AddGameObject(map1);
  AddGameObject(map2);
}


void GamePlayScene::CreateCactus() {

  auto cactus = new GameObject("Cactus", new Vector(800 ,600  ),80, 150 , 1);
  
  // Renderer
  auto cactusImage = new Image("assets/Images/cactus.png", 0, 0, 373, 520);
  auto cactusRenderer = new Renderer(cactus, cactusImage);
  
  auto cactusCollider = new RectangleCollider(cactus, Vector(0, 0), 300, 400, 0);

  // Script
  auto cactusScript = new CactusScript(cactus);
  
  AddGameObject(cactus);
}