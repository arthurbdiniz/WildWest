#include "Customs/MainScene.h"

MainScene::MainScene() {}

void MainScene::OnActivation() {
  m_width_middle = EngineGlobals::screen_width / 2;
  m_height_middle = EngineGlobals::screen_height / 2;
  CreateBackground();
  CreatePlayButton();
  CreateQuitButton();
  CreateMusic();

  CreateButtonSheriff();
  CreateButtonHat();
  CreateButtonBomb(); 
  CreateButtonMod();
  CreateSecondQuitButton();


}

void MainScene::OnDeactivation() {}

void MainScene::OnShown() {}

void MainScene::OnHidden() {}

void MainScene::CreatePlayButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto play = new GameObject("Play", new Vector(xMiddle, 425), 400, 100, 1);
  
  auto playImage = new Image("assets/Images/playnow.png", 0, 0, 1000, 597);
  auto playImageRenderer = new Renderer(play, playImage);

  auto playButton = new UIButton(play);

  auto script = new PlayButtonScript(play);

  AddGameObject(play);
}

void MainScene::CreateQuitButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto quit = new GameObject("Quit", new Vector(xMiddle, 535), 400, 100, 1);

  auto quitImage = new Image("assets/Images/quit.png", 0, 0, 1000, 597);
  auto mapRenderer = new Renderer(quit, quitImage);

  auto quitButton = new UIButton(quit);

  auto script = new QuitButtonScript(quit);

  AddGameObject(quit);
}



void MainScene::CreateButtonSheriff() {

  auto sheriff = new GameObject("Sheriff", new Vector(225, 675), 117, 100, 1);

  auto sheriffImage = new Image("assets/Images/sheriff.png", 0, 0, 170, 150);
  auto sheriffRenderer = new Renderer(sheriff, sheriffImage);

  auto sheriffButton = new UIButton(sheriff);

  AddGameObject(sheriff);
}

void MainScene::CreateButtonHat() {
  

  auto hat = new GameObject("hat", new Vector(350, 675), 117, 100, 1);

  auto hatImage = new Image("assets/Images/hat.png", 0, 0, 170, 150);
  auto hatRenderer = new Renderer(hat, hatImage);
  auto hatButton = new UIButton(hat);

  AddGameObject(hat);
}

void MainScene::CreateButtonBomb() {
  

  auto bomb = new GameObject("Bomb", new Vector(475, 675), 117, 100, 1);

  auto bombImage = new Image("assets/Images/bomb.png", 0, 0, 170, 150);
  auto bombRenderer = new Renderer(bomb, bombImage);

  auto bombButton = new UIButton(bomb);

  AddGameObject(bomb);
}

void MainScene::CreateButtonMod() {
  
  auto mod = new GameObject("Mod", new Vector(600, 675), 117, 100, 1);
  auto modImage = new Image("assets/Images/mod.png", 0, 0, 170, 150);
  auto modRenderer = new Renderer(mod, modImage);

  auto modButton = new UIButton(mod);

  AddGameObject(mod);
}

void MainScene::CreateSecondQuitButton() {
  int xMiddle = EngineGlobals::screen_width / 2 - 200;

  auto secondQuit = new GameObject("SecondQuit", new Vector(950, 0), 75, 80, 1);
  auto quitImage = new Image("assets/Images/exit.png", 0, 0, 130, 142);
  auto mapRenderer = new Renderer(secondQuit, quitImage);
  auto quitButton = new UIButton(secondQuit);
  auto script = new QuitButtonScript(secondQuit);

  AddGameObject(secondQuit);
}



void MainScene::CreateBackground() {

  auto background = new GameObject("Background", new Vector(0, 0),m_width_middle * 2, m_height_middle * 2, 0);
  auto backgrImage = new Image("assets/Images/bg_menu.png", 0, 0, 1000, 597);
  auto mapRenderer1 = new Renderer(background, backgrImage);

  
  AddGameObject(background);
}




void MainScene::CreateMusic(){

  auto music = new GameObject("MusicMenu", new Vector(200, 200), 200, 100);
  auto themeMusic = new UISound(music, "Music", "assets/Audio/menuAudio16BitStereo.wav", true, true);

  AddGameObject(music);

}
