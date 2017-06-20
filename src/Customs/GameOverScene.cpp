#include "Customs/GameOverScene.h"

GameOverScene::GameOverScene() {}

void GameOverScene::OnActivation() {
  m_width_middle = EngineGlobals::screen_width / 2;
  m_height_middle = EngineGlobals::screen_height / 2;
  CreateBackground();
  CreateLogo();
  CreatePlayAgainButton();
  CreateQuitButton();
  CreatePlayerScore();
  //CreateMusic();
  //CreateGamemodes();

}

void GameOverScene::OnDeactivation() {}

void GameOverScene::OnShown() {}

void GameOverScene::OnHidden() {}


void GameOverScene::CreateLogo() {
  /*
  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto logo = new GameObject("Logo", new Vector(xMiddle, 100), 200, 100, 1);

  auto logoText =
      new UIText(logo, "Wild West ", "assets/Archivo_Black/ArchivoBlack-Regular.ttf",
                 200, 255, 255, 255, 255, 1);

  AddGameObject(logo);
  */
}



void GameOverScene::CreatePlayAgainButton() {
  /*
  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto play = new GameObject("Play", new Vector(xMiddle, 400), 40, 100, 1);
  //auto playText = new UIText(play, "Play", "assets/Raleway/Raleway-Regular.ttf",
   //                          200, 255, 255, 255, 150, 1);

  auto playImage = new Image("assets/Images/playnow.png", 0, 0, 1000, 597);
  auto mapRenderer = new Renderer(play, playImage);

  auto playButton = new UIButton(play);

  auto script = new PlayButtonScript(play);

  AddGameObject(play);


  */

  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto playAgain = new GameObject("PlayAgain", new Vector(xMiddle, 400), 200, 100, 1);

  auto playAgainText = new UIText(playAgain, "Play Again", "assets/Raleway/Raleway-Regular.ttf",
                             200, 255, 255, 255, 150, 1);

  auto playAgainButton = new UIButton(playAgain);

  //auto script = new QuitButtonScript(playAgain);

  AddGameObject(playAgain);
}

void GameOverScene::CreateQuitButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto quit = new GameObject("Quit", new Vector(xMiddle, 500), 200, 100, 1);

  auto quitText = new UIText(quit, "Quit", "assets/Raleway/Raleway-Regular.ttf",
                             200, 255, 255, 255, 150, 1);

  auto quitButton = new UIButton(quit);

  auto script = new QuitButtonScript(quit);

  AddGameObject(quit);
}

void GameOverScene::CreateBackground() {
  auto background = new GameObject("Background", new Vector(0, 0),m_width_middle * 2, m_height_middle * 2, 0);

  auto backgrImage = new Image("assets/Images/bg_menu.png", 0, 0, 1000, 597);
  auto mapRenderer1 = new Renderer(background, backgrImage);

  //auto backgroundRectangle = new RectangleRenderer(background, Vector(0, 0), m_width_middle * 2, m_height_middle * 2);
  //backgroundRectangle->SetColor(100, 100, 20, 255);
  AddGameObject(background);
}




void GameOverScene::CreateMusic(){

  auto music = new GameObject("Music", new Vector(200, 200), 200, 100);

  auto themeMusic = new UISound(music, "Music", "assets/Audio/beat.wav", false, true);

  AddGameObject(music);

}

void GameOverScene::CreatePlayerScore() {
 /*
  auto var = (UIText *)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Score")
                   ->GetComponent("UIText");
    */               
  //var->SetText(std::to_string(score));


  int xMiddle = EngineGlobals::screen_width / 2 - 100;

  auto playerScore = new GameObject("Score", new Vector(xMiddle, 300), 200, 100, 1);
/*
  auto var = (UIText *)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Score")
                   ->GetComponent("UIText");
     */              
  //std::string score = var->GetText(); // Como pegar Text de outra view
  //cout << var->GetText() << endl;

  auto playerScoreText = new UIText(playerScore, "Score", "assets/Raleway/Raleway-Regular.ttf",
                             200, 255, 255, 255, 150, 1);



  

  AddGameObject(playerScore);
}
