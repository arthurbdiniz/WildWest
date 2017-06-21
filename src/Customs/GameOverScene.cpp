#include "Customs/GameOverScene.h"

GameOverScene::GameOverScene() {}

void GameOverScene::OnActivation() {
  m_width_middle = EngineGlobals::screen_width / 2;
  m_height_middle = EngineGlobals::screen_height / 2;
  CreateBackground();
  CreatePlayAgainButton();
  CreateQuitButton();
  CreatePlayerScore();
  

}

void GameOverScene::OnDeactivation() {}

void GameOverScene::OnShown() {

  auto var = (UIText *)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Score")
                   ->GetComponent("UIText");
        
  std::string score = var->GetText(); // Como pegar Text de outra view
  m_playerScoreText->SetText(score);
  auto script = (ScoreScript*)SceneManager::GetInstance()
                   ->GetScene("Gameplay")
                   ->GetGameObject("Score")
                   ->GetComponent("ScoreScript");
                   script->SetScore(0);


}
void GameOverScene::OnHidden() {}


void GameOverScene::CreatePlayAgainButton() {

  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto playAgain = new GameObject("PlayAgain", new Vector(xMiddle, 400), 400, 100, 1);

 
  auto playAgainImage = new Image("assets/Images/playagain.png", 0, 0, 1000, 597);
  auto playAgainImageRenderer = new Renderer(playAgain, playAgainImage);

  auto playAgainButton = new UIButton(playAgain);

  auto script = new PlayAgainButtonScript(playAgain);

  AddGameObject(playAgain);
}

void GameOverScene::CreateQuitButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto quit = new GameObject("Quit", new Vector(xMiddle, 500), 400, 100, 1);

  auto quitImage = new Image("assets/Images/quit.png", 0, 0, 1000, 597);
  auto quitImageRenderer = new Renderer(quit, quitImage);

  auto quitButton = new UIButton(quit);

  auto script = new QuitButtonScript(quit);

  AddGameObject(quit);
}

void GameOverScene::CreateBackground() {
  auto background = new GameObject("Background", new Vector(0, 0),m_width_middle * 2, m_height_middle * 2, 0);

  auto backgrImage = new Image("assets/Images/bg_menu.png", 0, 0, 1000, 597);
  auto mapRenderer1 = new Renderer(background, backgrImage);
  AddGameObject(background);
}

void GameOverScene::CreateMusic(){

  auto music = new GameObject("Music", new Vector(200, 200), 200, 100);

  auto themeMusic = new UISound(music, "Music", "assets/Audio/beat.wav", false, true);

  AddGameObject(music);

}

void GameOverScene::CreatePlayerScore() {
 
  int xMiddle = EngineGlobals::screen_width / 2 - 100;
  auto playerScore = new GameObject("Score", new Vector(xMiddle, 20), 200, 100, 1);
  auto playerScoreText = new UIText(playerScore, "Score: ", "assets/Carnevalee/Carnevalee-Freakshow.ttf",
                             150, 0, 0, 0, 150, 1);
  m_playerScoreText = playerScoreText;
  AddGameObject(playerScore);
}
