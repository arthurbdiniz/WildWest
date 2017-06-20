#include "Customs/GamePlayScene.h"

void GamePlayScene::OnActivation() {
  CreateNakedMan();
  CreateMap();
  CreateCactus();
  CreateScore();
  //CreateCactus2();
}

void GamePlayScene::OnDeactivation() {}

void GamePlayScene::OnShown() {}

void GamePlayScene::OnHidden() {}

void GamePlayScene::CreateNakedMan() {
  int xPos = EngineGlobals::screen_width / 2 - 300;
  int yPos = EngineGlobals::screen_height / 2 + 200;

  auto player = new GameObject("NakedMan", new Vector(xPos, yPos), 120, 147, 2);
  player->SetTag("Player");


  // animations
  auto playerSprite = new Image("assets/Images/player.png", 0, 0, 1199, 294);

  auto StopUpAnimation = new Animation(player, playerSprite);
        StopUpAnimation->AddFrame(new Frame(0, 384, 415, 507));

  
  auto walkSideAnimation = new Animation(player, playerSprite);
  for (int i = 0; i < 10; i++)
    walkSideAnimation->AddFrame(new Frame(i * 120, 0, 120, 147));
  
  auto walkUpAnimation = new Animation(player, playerSprite);
  for (int i = 1; i < 5; i++)
    walkUpAnimation->AddFrame(new Frame(i * 120, 147, 120, 147));

  

  // animator
  auto playerAnimator = new Animator(player);

  playerAnimator->AddAnimation("Walk Side", walkSideAnimation);
  playerAnimator->AddAnimation("Walk Up", walkUpAnimation);
  playerAnimator->AddAnimation("Stop Up", StopUpAnimation);
 
  GamePlayController::GetInstance()->AddPlayer(player);

  // Script
  auto playerScript = new PlayerScript(player);

  // Collider
  auto playerCollider = new RectangleCollider(player, Vector(0, 0), 80, 130, 0);
  
  // rigidbody
  //auto nakedManRB = new Rigidbody(nakedMan);

  AddGameObject(player);


/***
  std::string playerName = "Player";
  auto player = new GameObject(playerName, new Vector(xPos, yPos), 40, 60, 2);
  player->SetTag("Player");
  
  auto playerRectangle = new RectangleRenderer(player, Vector(0, 0), 40, 60);
    
  int color1 = rand() % 255, color2 = rand() % 255, color3 = rand() % 255;
  playerRectangle->SetColor(color1, color2, color3, 255);
  auto playerScript = new PlayerScript(player);
  auto playerCollider = new RectangleCollider(player, Vector(0, 0), 40, 60, 0);
  //CatchAllController::GetInstance()->AddPlayer(player);
  AddGameObject(player);

    *///
}

void GamePlayScene::CreateMap() {

  auto map1 = new GameObject("Map1", new Vector(0 ,-350  ),2000, 1200, 0);
  map1->SetTag("Map1");

  auto map2 = new GameObject("Map2", new Vector(1980 ,-350  ),2000, 1200, 0);
  map2->SetTag("Map2");

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

/************
  auto cactus = new GameObject("Cactus", new Vector(800 ,600),80, 150 , 1);
  cactus->SetTag("Cactus");
  // Renderer
  auto cactusImage = new Image("assets/Images/cactus.png", 0, 0, 373, 520);
  auto cactusRenderer = new Renderer(cactus, cactusImage);
  
  // Collider
  auto cactusCollider = new RectangleCollider(cactus, Vector(0, 0), 100, 500, 1);

  // Script
  auto cactusScript = new CactusScript(cactus);

  GamePlayController::GetInstance()->AddCactus(cactus);

  
  AddGameObject(cactus);

  *****/

  std::string playerName = "Cactus";
  auto cactus = new GameObject(playerName, new Vector(800, 620), 80, 120, 2);
  cactus->SetTag("Cactus");
  
  //auto cactusRectangle = new RectangleRenderer(cactus, Vector(0, 0), 40, 60);
  auto cactusImage = new Image("assets/Images/cactus.png", 0, 0, 373, 520);
  auto cactusRenderer = new Renderer(cactus, cactusImage);
  
  //cactusRectangle->SetColor(66, 244, 95, 255);
  auto cactusScript = new CactusScript(cactus);
  auto cactusCollider = new RectangleCollider(cactus, Vector(0, 0), 50, 120, 0);
  //CatchAllController::GetInstance()->AddPlayer(cactus);
  AddGameObject(cactus);
}

void GamePlayScene::CreateScore() {

  
  auto score = new GameObject("Score", new Vector(800, 20), 60, 100, 2);
  score->SetTag("Score");
  
  auto scoreText = new UIText(score, "0", "assets/Carnevalee/Carnevalee-Freakshow.ttf", 150, 0 , 0, 0, 0, 1);

  //auto scoreRectangle = new RectangleRenderer(score, Vector(0, 0), 500, 150);
    
  //int color1 = rand() % 255, color2 = rand() % 255, color3 = rand() % 255;
  //scoreRectangle->SetColor(color1, color2, color3, 255);
  auto scoreScript = new ScoreScript(score);
  
  //CatchAllController::GetInstance()->AddPlayer(cactus);
  AddGameObject(score);


}
