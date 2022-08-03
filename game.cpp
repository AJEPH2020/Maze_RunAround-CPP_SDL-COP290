#include "game.h"

Game::Game()
{

  srand(time(0));

  // int main(){

  runningMenu = 1;
  runningPlay = 0;
  runningEsc = 0;
  runningDs = 0;
  runningIn = 0;

  fullscreen = 0;

  static int lastTime = 0;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    std::cout << "Failed at SDL_Init()" << std::endl;

  if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) < 0)
    std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;

  SDL_SetWindowTitle(window, "Maze RunAround!");

  TTF_Init();

  SDL_ShowCursor(1); // Cursor Visibility

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

  // cout << "1" << endl;

  // image.setDest(0, 0, 1280, 720);
  // image.setSource(0, 0, 4781, 2599);
  // map.setImage("helpers/images/gallery-lg5.jpg", renderer);


  // backgroundMusic.load("helpers/sounds/file_example_WAV_1MG.wav");
  // backgroundMusic.play();
  // backgroundMusic.audioPlaying = 1;

  string scr;
  ifstream scrL1ine ("highScore.txt");

  if (scrL1ine.is_open())
  {
    while ( getline (scrL1ine,scr) )
    {
      cout << scr << '\n';
    }
    scrL1ine.close();
  }
  else
  {
    cout << "highScore.txt not found" << endl;
  }

  stringstream hs (scr);
  hs >> highScore;

  // cout << "hs" << highScore << endl;
  



  menu();
  
  // play();
}

Game::~Game()
{

  TTF_Quit();
  // cout << "116" << endl;

  IMG_Quit();
  // cout << "117" << endl;

  SDL_DestroyRenderer(renderer);
  // cout << "118" << endl;
  
  SDL_DestroyWindow(window);
  // cout << "119" << endl;

  SDL_Quit();
  cout << "end" << endl;

}






void Game::menu (){




  // cout << "1" << endl;
  mainMenu.load("helpers/sounds/mainMenu.wav");
  mainMenu.play();
  mainMenu.audioPlaying = 1;

  menuNext.load("helpers/sounds/menuNext.wav");
  menuSelecting.load("helpers/sounds/menuSelecting.wav");

  // cout << "==========================" << endl;


  // cout << "2" << endl;


  pic1.setDest(0, 0, 1280, 720);
  pic1.setSource(0, 0, 6016, 3384);
  pic1.setImage("helpers/images/gallery-lg1.jpg", renderer);


  pic3.setDest(0, 0, 1280, 720);
  pic3.setSource(0, 104, 2048, 1152);
  pic3.setImage("helpers/images/gallery-lg3.jpg", renderer);

  pic4.setDest(0, 0, 1280, 720);
  pic4.setSource(0, 444, 6016, 3384);
  pic4.setImage("helpers/images/gallery-lg4.jpg", renderer);

  pic5.setDest(0, 0, 1280, 720);
  pic5.setSource(80, 0, 4620, 2599);
  pic5.setImage("helpers/images/gallery-lg5.jpg", renderer);

  pic6.setDest(0, 0, 1280, 720);
  pic6.setSource(0, 335, 4332, 2437);
  pic6.setImage("helpers/images/gallery-lg6.jpg", renderer);
  
  pic7.setDest(0, 0, 1280, 720);
  pic7.setSource(0, 0, 7259, 4083);
  pic7.setImage("helpers/images/gallery-lg7.jpg", renderer);
  
  pic8.setDest(0, 0, 1280, 720);
  pic8.setSource(1400, 0, 4357, 2451);
  pic8.setImage("helpers/images/gallery-lg8.jpg", renderer);

  pic9.setDest(0, 0, 1280, 720);
  pic9.setSource(0, 0, 3362, 1889);
  pic9.setImage("helpers/images/gallery-lg9.jpg", renderer);

  // cout << "3" << endl;


  // menuFont = TTF_OpenFont("helpers/text.ttf", 40);

  font71 = TTF_OpenFont("helpers/SteelplateTextura.ttf", 77);
  // cout << "4" << endl;


  logo.setDest(40, 30, 140, 140);
  logo.setSource(0, 0, 282, 282);
  logo.setImage("helpers/images/iit.png", renderer);
  // cout << "5" << endl;


  plateBlue1.setDest(452, 240, 350, 80);
  plateBlue1.setSource(0, 0, 1420, 395);
  plateBlue1.setImage("helpers/images/Picture1.png", renderer);
  // cout << "6" << endl;


  plateBlue2.setDest(452, 380, 350, 80);
  plateBlue2.setSource(0, 0, 1420, 395);
  plateBlue2.setImage("helpers/images/Picture1.png", renderer);
  // cout << "7" << endl;


  plateBlue3.setDest(452, 520, 350, 80);
  plateBlue3.setSource(0, 0, 1420, 395);
  plateBlue3.setImage("helpers/images/Picture1.png", renderer);
  // cout << "8" << endl;



  plateSound.setDest(1140, 650, 120, 70);
  plateSound.setSource(0, 0, 793, 543);
  plateSound.setImage("helpers/images/Picture3.png", renderer);
  // cout << "9" << endl;


  soundOn.setDest(1208, 666, 33, 32);
  soundOn.setSource(0, 0, 300, 300);
  soundOn.setImage("helpers/images/s.png", renderer);
  // cout << "10" << endl;


  soundOff.setDest(1207, 665, 35, 35);
  soundOff.setSource(0, 0, 512, 512);
  soundOff.setImage("helpers/images/ns.png", renderer);
  // cout << "11" << endl;


  plateOrange.setSource(0, 0, 1420, 395);
  plateOrange.setImage("helpers/images/Picture2.png", renderer);
  // cout << "12" << endl;


  font70 = TTF_OpenFont("helpers/text.ttf", 70);
  // cout << "13" << endl;


  // mapX = mapY = 0;
  // speed = 5;

  // player.setDest(width / 2 + 100, height / 2 - 100, playerW, playerH);
  // player.setImage("helpers/images/player.png", renderer);
  // player.setSource(0, 0, 24, 32);
  // idoll = player.createCycle(2, 24, 32, 2, 10);
  // idolr = player.createCycle(1, 24, 32, 2, 10);
  // runningl = player.createCycle(4, 24, 32, 4, 4);
  // runningr = player.createCycle(3, 24, 32, 4, 4);
  // player.setCurAnimation(idolr);

  // loadMap("helpers/map.level");




  menuLoop();
  // cout << "14" << endl;



  pic1.destroy();
  pic3.destroy();
  pic4.destroy();
  pic5.destroy();
  pic6.destroy();
  pic7.destroy();
  pic8.destroy();
  pic9.destroy();
  logo.destroy();
  plateBlue1.destroy();
  plateBlue2.destroy();
  plateBlue3.destroy();
  plateOrange.destroy();
  plateSound.destroy();
  soundOn.destroy();
  soundOff.destroy();

  TTF_CloseFont(font70);
  // cout << "15" << endl;

  TTF_CloseFont(font71);
  // cout << "16" << endl;

  

}


void Game::menuLoop()
{

  static int lastTime = 0;

  static int lastTimeMusic = 0;

  while (runningMenu)
  {

    // cout << "menu running" << endl;

    lastFrame = SDL_GetTicks();

    if (lastFrame >= (lastTimeMusic + 158000))
    {
      lastTimeMusic = lastFrame;
      mainMenu.clearAndLoop();
    }
    

    if (lastFrame >= (lastTime + 1000))
    {
      lastTime = lastFrame;
      fps = frameCount;
      frameCount = 0;
    }
    // std::cout << "fps" << fps << std::endl;

    drawMenu();
    inputMenu();
    updateMenu();


    if (runningIn)
    {

      mainMenu.pause();
      
      instScreen();

      if (mainMenu.audioPlaying)
      {
        mainMenu.resume();
      }

    }


    if (runningPlay)
    {
      // cout << "play begin" << endl;

      mainMenu.pause();
      
      play();

      if (mainMenu.audioPlaying)
      {
        mainMenu.resume();
      }

    }

  }

}



void Game::instScreen (){

  inst.setDest(0, 0, 1280, 720);
  inst.setSource(0, 0, 1280, 720);
  inst.setImage("helpers/images/Slide1.JPG", renderer);


  instScreenLoop();


  // cout << "10" << endl;
  // backgroundMusic.~Audio();
  inst.destroy();
  SDL_stack_free(inst);
  
}


void Game::instScreenLoop()
{

  static int lastTime = 0;

  while (runningIn)
  {

    lastFrame = SDL_GetTicks();
    
    if (lastFrame >= (lastTime + 1000))
    {
      lastTime = lastFrame;
      fps = frameCount;
      frameCount = 0;
    }
    // std::cout << "fps" << fps << std::endl;


    isDraw();
    isInput();
    isUpdate();


  }
}


void Game::isDraw()
{

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_Rect rect;
  rect.x = rect.y = 0;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(renderer, &rect);

  drawImage(inst);


  frameCount++;
  timerFPSMenu = SDL_GetTicks() - lastFrame;
  if (timerFPSMenu < (1000 / 50))
  {
    SDL_Delay((1000 / 50) - timerFPSMenu);
  }

  SDL_RenderPresent(renderer);
}















void Game::play (){


  boostStart = 0;
  healthStart = 0;
  taskStart = 0;

  sprint = 0;

  food = 0;
  doneEating = 0;
  firstEaten;
  tmBool = 1;


  task1Done = 0;
  task2Done = 0;
  task3Done = 0;

  task1 = 0;
  task1Start;
  t1Bool = 1;
  task1S1 = 0;
  task1S1Start;
  t1S1Bool = 1;
  task1S2 = 0;
  task1S2Start;
  t1S2Bool = 1;
  task1S3 = 0;
  task1S3Start;
  t1S3Bool = 1;
  task1S4 = 0;
  task1S4Start;
  t1S4Bool = 1;
  
  task1Given = 0;


  task2 = 0;
  task2Start;
  t2Bool = 1;
  task2S1 = 0;
  task2S1Start;
  t2S1Bool = 1;
  task2S2 = 0;
  task2S2Start;
  t2S2Bool = 1;
  task2S3 = 0;
  task2S3Start;
  t2S3Bool = 1;
  task2S4 = 0;
  task2S4Start;
  t2S4Bool = 1;
  
  task2Given = 0;


  task3 = 0;
  task3Start;
  t3Bool = 1;
  task3S1 = 0;
  task3S1Start;
  t3S1Bool = 1;
  task3S2 = 0;
  task3S2Start;
  t3S2Bool = 1;
  task3S3 = 0;
  task3S3Start;
  t3S3Bool = 1;
  task3S4 = 0;
  task3S4Start;
   t3S4Bool = 1;
  
   task3Given = 0;

  tasksGiven = 0;

  tasksDone = 0;

  tasksKnown = 0;
  taskTime = 55;

   taskD = 0;
  

  tfcStart = 0;
  taskEnd1 = 0;
  taskEnd2 = 0;
  taskEnd3 = 0;



  taskAssigned = 0;
  tFailedChk = 0;
  reset = 1;

  maxTime = 300;
  timed = 300;
  diff = 0;
  diffInc = 0;

  td1Bool = 1;
  td2Bool = 1;
  td3Bool = 1;

  loadMiniMap = 0;
  loadTaskScreen = 0;

  // cout << "2" << endl;


  backgroundMusic.load("helpers/sounds/in-game background music (enhanced base for low vol).wav");
  if (mainMenu.audioPlaying)
  {
    backgroundMusic.play();
    backgroundMusic.audioPlaying = 1;
  }

  lowHealth.load("helpers/sounds/health-or-points-low-1 sec audio.wav");
  lowHealth.audioPlaying = 1;

  giftPickUp.load("helpers/sounds/gift pick up.wav");
  giftPickUp.audioPlaying = 1;
  
  speedUp.load("helpers/sounds/shift speed up.wav");
  

  
  foodEaten.load("helpers/sounds/food eaten.wav");
  foodEaten.audioPlaying = 1;

  gameOver.load("helpers/sounds/game over.wav");
  gameOver.audioPlaying = 1;

  subtaskDone.load("helpers/sounds/getting subtask done.wav");
  subtaskDone.audioPlaying = 1;

  taskDone.load("helpers/sounds/task done.wav");
  taskDone.audioPlaying = 1;

  taskNotReady.load("helpers/sounds/Task not ready (when tries to do task on wrong checkpoint).wav");
  taskNotReady.audioPlaying = 1;



  // cout << "3" << endl;

  image.setDest(-600, 0, 2425, 720);
  image.setSource(0, 0, 8256, 2451);
  image.setImage("helpers/images/gallery-lg8.jpg", renderer);


  redTask.setSource(0, 0, 39, 39);
  redTask.setImage("helpers/images/foodRed.png", renderer);
  redTask.setDest(1200, 350, 60, 60);
  redS1.setSource(0, 0, 39, 39);
  redS1.setImage("helpers/images/foodRed.png", renderer);
  redS1.setDest(1215, 430, 30, 30);
  redS2.setSource(0, 0, 39, 39);
  redS2.setImage("helpers/images/foodRed.png", renderer);
  redS2.setDest(1215, 480, 30, 30);
  redS3.setSource(0, 0, 39, 39);
  redS3.setImage("helpers/images/foodRed.png", renderer);
  redS3.setDest(1215, 530, 30, 30);
  redS4.setSource(0, 0, 39, 39);
  redS4.setImage("helpers/images/foodRed.png", renderer);
  redS4.setDest(1215, 580, 30, 30);

  greenTask.setSource(0, 0, 39, 39);
  greenTask.setImage("helpers/images/foodGreen.png", renderer);
  greenTask.setDest(1200, 350, 60, 60);
  greenS1.setSource(0, 0, 39, 39);
  greenS1.setImage("helpers/images/foodGreen.png", renderer);
  greenS1.setDest(1215, 430, 30, 30);
  greenS2.setSource(0, 0, 39, 39);
  greenS2.setImage("helpers/images/foodGreen.png", renderer);
  greenS2.setDest(1215, 480, 30, 30);
  greenS3.setSource(0, 0, 39, 39);
  greenS3.setImage("helpers/images/foodGreen.png", renderer);
  greenS3.setDest(1215, 530, 30, 30);
  greenS4.setSource(0, 0, 39, 39);
  greenS4.setImage("helpers/images/foodGreen.png", renderer);
  greenS4.setDest(1215, 580, 30, 30);


  loadMap("helpers/map.level");


  gift1.setSource(0, 0, 78, 89);
  gift1.setImage("helpers/images/giftBlackBlack.png", renderer);
  gift2.setSource(0, 0, 51, 51);
  gift2.setImage("helpers/images/giftBlackBlack.png", renderer);


  gift3.setSource(0, 0, 51, 51);
  gift3.setImage("helpers/images/giftGoldRed.png", renderer);
  gift4.setSource(0, 0, 60, 62);
  gift4.setImage("helpers/images/giftGoldRed.png", renderer);


  gift5.setSource(0, 0, 60, 62);
  gift5.setImage("helpers/images/giftGreenOrange.png", renderer);
  gift6.setSource(0, 0, 60, 62);
  gift6.setImage("helpers/images/giftGreenOrange.png", renderer);
  gift7.setSource(0, 0, 60, 62);
  gift7.setImage("helpers/images/giftGreenOrange.png", renderer);
  gift8.setSource(0, 0, 60, 62);
  gift8.setImage("helpers/images/giftGreenOrange.png", renderer);
  gift9.setSource(0, 0, 60, 62);
  gift9.setImage("helpers/images/giftGreenOrange.png", renderer);
  gift10.setSource(0, 0, 60, 62);
  gift10.setImage("helpers/images/giftGreenOrange.png", renderer);


  gift11.setSource(0, 0, 51, 58);
  gift11.setImage("helpers/images/giftRedRed.png", renderer);
  gift12.setSource(0, 0, 51, 58);
  gift12.setImage("helpers/images/giftRedRed.png", renderer);


  gift13.setSource(0, 0, 52, 60);
  gift13.setImage("helpers/images/giftWhiteGold.png", renderer);
  gift14.setSource(0, 0, 52, 60);
  gift14.setImage("helpers/images/giftWhiteGold.png", renderer);
  gift15.setSource(0, 0, 52, 60);
  gift15.setImage("helpers/images/giftWhiteGold.png", renderer);


  gift16.setSource(0, 0, 60, 60);
  gift16.setImage("helpers/images/giftWhiteRed.png", renderer);
  gift17.setSource(0, 0, 60, 60);
  gift17.setImage("helpers/images/giftWhiteRed.png", renderer);
  gift18.setSource(0, 0, 60, 60);
  gift18.setImage("helpers/images/giftWhiteRed.png", renderer);
  gift19.setSource(0, 0, 60, 60);
  gift19.setImage("helpers/images/giftWhiteRed.png", renderer);
  gift20.setSource(0, 0, 60, 60);
  gift20.setImage("helpers/images/giftWhiteRed.png", renderer);



  // cout << "4" << endl;


  font = TTF_OpenFont("helpers/text.ttf", 70);

  font100 = TTF_OpenFont("helpers/qkmarisa.ttf", 40);

  font20 = TTF_OpenFont("helpers/qkmarisa.ttf", 20);

  // cout << "5" << endl;


  mapX = mapY = 0;
  speed = walkingSpeed;

  // cout << "6" << endl;

  player.setImage("helpers/images/player.png", renderer);
  player.setDest(width/2,height/2, playerW, playerH);
  player.setSource(0, 0, 24, 32);
  randomSpawn();

  player.setHealth(100);
  player.setScore(0);
  player.setStamina(100);

  idoll = player.createCycle(2, 24, 32, 2, 10);
  idolr = player.createCycle(1, 24, 32, 2, 10);
  runningl = player.createCycle(4, 24, 32, 4, 4);
  runningr = player.createCycle(3, 24, 32, 4, 4);
  player.setCurAnimation(idolr);


  // cout << "7" << endl;


  // cout << "8" << endl;


  miniMap.setDest(40, 80, 1208, 606);
  miniMap.setSource(0, 0, 1803, 911);
  miniMap.setImage("helpers/images/miniMap.png", renderer);


  td1.setDest(40, 80, 1208, 606);
  td1.setSource(0, 0, 1280, 720);
  td1.setImage("helpers/images/Slide1-modified.png", renderer);

  td2.setDest(40, 80, 1208, 606);
  td2.setSource(0, 0, 1280, 720);
  td2.setImage("helpers/images/Slide2-modified.png", renderer);

  td3.setDest(40, 80, 1208, 606);
  td3.setSource(0, 0, 1280, 720);
  td3.setImage("helpers/images/Slide3-modified.png", renderer);


  red.setSource(0, 0, 51, 51);
  red.setImage("helpers/images/red.png", renderer);


  foodRed.setDest(1210, 200, 40, 40);
  foodRed.setSource(0, 0, 39, 39);
  foodRed.setImage("helpers/images/foodRed.png", renderer);

  foodGreen.setDest(1210, 200, 40, 40);
  foodGreen.setSource(0, 0, 39, 39);
  foodGreen.setImage("helpers/images/foodGreen.png", renderer);

  foodOrange.setDest(1210, 200, 40, 40);
  foodOrange.setSource(0, 0, 39, 39);
  foodOrange.setImage("helpers/images/foodOrange.png", renderer);



  randomBox(1);
  randomBox(2);
  randomBox(3);
  randomBox(4);
  randomBox(5);
  randomBox(6);
  randomBox(7);
  randomBox(8);
  randomBox(9);
  randomBox(10);
  randomBox(11);
  randomBox(12);
  randomBox(13);
  randomBox(14);
  randomBox(15);
  randomBox(16);
  randomBox(17);
  randomBox(18);
  randomBox(19);
  randomBox(20);





  gameLoop();
  // cout << "9" << endl;


  backgroundMusic.~Audio();


  for (int i = 0; i < map.size(); i++)
  {
    map[i].destroy();
  }
  map.clear();
  // backgroundMusic.~Audio();
  TTF_CloseFont(font);
  TTF_CloseFont(font100);
  TTF_CloseFont(font20);
  image.destroy();
  player.destroy();
  miniMap.destroy();
  td1.destroy();
  td2.destroy();
  td3.destroy();
  red.destroy();
  foodRed.destroy();
  foodGreen.destroy();
  foodOrange.destroy();
  redTask.destroy();
  redS1.destroy();
  redS2.destroy();
  redS3.destroy();
  redS4.destroy();
  greenTask.destroy();
  greenS1.destroy();
  greenS2.destroy();
  greenS3.destroy();
  greenS4.destroy();
  gift1.destroy();
  gift2.destroy();
  gift3.destroy();
  gift4.destroy();
  gift5.destroy();
  gift6.destroy();
  gift7.destroy();
  gift8.destroy();
  gift9.destroy();
  gift10.destroy();
  gift11.destroy();
  gift12.destroy();
  gift13.destroy();
  gift14.destroy();
  gift15.destroy();
  gift16.destroy();
  gift17.destroy();
  gift18.destroy();
  gift19.destroy();
  gift20.destroy();
  // cout << "13" << endl;
  SDL_stack_free(backgroundMusic);
  // cout << "14" << endl;
  SDL_stack_free(image);
  // cout << "15" << endl;
  SDL_stack_free(font);
  SDL_stack_free(font100);
  SDL_stack_free(font20);
  // cout << "16" << endl;
  SDL_stack_free(player);
  // cout << "17" << endl;
  SDL_stack_free(map);
  // cout << "18" << endl;
  


  // cout << "--------------------------------------------------" << endl;


}


void Game::gameLoop()
{

  static int lastTime = 0;

  static int lastTimeMusic = 0;

  startTime = SDL_GetTicks();
  // cout << "20" << endl;


  while (runningPlay)
  {

    lastFrame = SDL_GetTicks();

    // cout << "lastFrame" << lastFrame << endl;
    
    if (lastFrame >= (lastTimeMusic + 30000))
    {
      lastTimeMusic = lastFrame;
      backgroundMusic.clearAndLoop();
    }

    if (lastFrame >= (lastTime + 1000))
    {
      lastTime = lastFrame;
      fps = frameCount;
      frameCount = 0;
    }
    // std::cout << "fps" << fps << std::endl;
    // cout << "21" << endl;


    input();
    // cout << "22" << endl;

    update();
    // cout << "23" << endl;

    draw();
    // cout << "24" << endl;


    if (runningEsc)
    {
      // cout << "PauseMenu" << endl;
      backgroundMusic.pause();

      escapeMenu();

      if (backgroundMusic.audioPlaying)
      {
        backgroundMusic.resume();
      }
      

    }

    if (runningDs)
    {
      backgroundMusic.pause();

      deathScreen();

    }
    

  }
}







void Game::escapeMenu (){


  font69 = TTF_OpenFont("helpers/SteelplateTextura.ttf", 75);
  font68 = TTF_OpenFont("helpers/text.ttf", 68);


  escPlateBlue1.setDest(50, 240, 350, 80);
  escPlateBlue1.setSource(0, 0, 1420, 395);
  escPlateBlue1.setImage("helpers/images/Picture1.png", renderer);


  escPlateBlue2.setDest(50, 380, 350, 80);
  escPlateBlue2.setSource(0, 0, 1420, 395);
  escPlateBlue2.setImage("helpers/images/Picture1.png", renderer);


  escPlateBlue3.setDest(50, 520, 350, 80);
  escPlateBlue3.setSource(0, 0, 1420, 395);
  escPlateBlue3.setImage("helpers/images/Picture1.png", renderer);


  escPlateOrange.setSource(0, 0, 1420, 395);
  escPlateOrange.setImage("helpers/images/Picture2.png", renderer);




  escMenuLoop();










  // cout << "10" << endl;
  // backgroundMusic.~Audio();
  TTF_CloseFont(font69);
  TTF_CloseFont(font68);
  escPlateBlue1.destroy();
  escPlateBlue2.destroy();
  escPlateBlue3.destroy();
  escPlateOrange.destroy();
  SDL_stack_free(escPlateBlue1);
  SDL_stack_free(escPlateBlue2);
  SDL_stack_free(escPlateBlue3);
  SDL_stack_free(escPlateOrange);
  
}

void Game::escMenuLoop()
{

  static int lastTime = 0;

  while (runningEsc)
  {

    lastFrame = SDL_GetTicks();
    
    if (lastFrame >= (lastTime + 1000))
    {
      lastTime = lastFrame;
      fps = frameCount;
      frameCount = 0;
    }
    // std::cout << "fps" << fps << std::endl;


    escDraw();
    escInput();
    escUpdate();


  }
}





void Game::deathScreen (){

  gameOver.clearAndPlay();

  dsfont100 = TTF_OpenFont("helpers/SteelplateTextura.ttf", 120);
  dsfont70 = TTF_OpenFont("helpers/text.ttf", 70);
  dsfont50 = TTF_OpenFont("helpers/qkmarisa.ttf", 40);


  dsPlateBlue1.setDest(230, 600, 300, 60);
  dsPlateBlue1.setSource(0, 0, 1420, 395);
  dsPlateBlue1.setImage("helpers/images/Picture1.png", renderer);


  dsPlateBlue2.setDest(730, 600, 300, 60);
  dsPlateBlue2.setSource(0, 0, 1420, 395);
  dsPlateBlue2.setImage("helpers/images/Picture1.png", renderer);


  dsPlateOrange.setSource(0, 0, 1420, 395);
  dsPlateOrange.setImage("helpers/images/Picture2.png", renderer);





  deathScreenLoop();


  int nScore = 100 * player.getHealth() + player.getScore();


  string ns = to_string(nScore);




  if (nScore > highScore)
  {
    highScore = nScore;

    ofstream myfile ("highScore.txt");
    if (myfile.is_open())
    {
      myfile << ns;
      myfile.close();
    }
    else cout << "Unable to find highScore.txt" << endl;

  }
  







  // cout << "10" << endl;
  // backgroundMusic.~Audio();
  TTF_CloseFont(dsfont100);
  TTF_CloseFont(dsfont70);
  TTF_CloseFont(dsfont50);
  dsPlateBlue1.destroy();
  dsPlateBlue2.destroy();
  dsPlateOrange.destroy();
  SDL_stack_free(dsPlateBlue1);
  SDL_stack_free(dsPlateBlue2);
  SDL_stack_free(dsPlateOrange);
  
}


void Game::deathScreenLoop()
{

  static int lastTime = 0;

  while (runningDs)
  {

    lastFrame = SDL_GetTicks();
    
    if (lastFrame >= (lastTime + 1000))
    {
      lastTime = lastFrame;
      fps = frameCount;
      frameCount = 0;
    }
    // std::cout << "fps" << fps << std::endl;


    dsDraw();
    dsInput();
    dsUpdate();


  }
}


void Game::dsDraw()
{

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_Rect rect;
  rect.x = rect.y = 0;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(renderer, &rect);

  if (player.getHealth() < 1)
  {
    drawImage("You Collapsed!", 220, 70, 255, 50, 50, dsfont100);
    drawImage("R. I. P.  :(", 500, 220, 255, 20, 20, dsfont50);
  }
  else if (timed < 1)
  {
    drawImage("Game Over!", 285, 120, 255, 50, 50, dsfont100);
  }

  string hl = to_string(player.getHealth());
  string h = "Health Bonus :  100 x ";
  hl = h.append(hl);
  const char* hlt = hl.c_str();
  drawImage(hlt, 90, 330, 255, 255, 255, dsfont50);
  SDL_stack_free(hlt);

  string sc = to_string(player.getScore());
  string s = "Score :  ";
  sc = s.append(sc);
  const char* scr = sc.c_str();
  drawImage(scr, 830, 330, 255, 255, 255, dsfont50);
  SDL_stack_free(scr);

  int finalScore = 100 * player.getHealth() + player.getScore();

  string fs = to_string(finalScore);
  string f = "Final Score :  ";
  fs = f.append(fs);
  const char* fsc = fs.c_str();
  drawImage(fsc, 400, 450, 255, 70, 100, dsfont50);
  SDL_stack_free(fsc);
  
  


  drawImage(dsPlateBlue1);

  drawImage(dsPlateBlue2);

  dsPlateOrange.setDest(dsMenuSelect, 600, 300, 60);
  drawImage(dsPlateOrange);


  drawImage("Main Menu", 270, 600, 100, 100, 255, dsfont70);
  drawImage("Quit", 840, 600, 100, 100, 255, dsfont70);


  frameCount++;
  timerFPSMenu = SDL_GetTicks() - lastFrame;
  if (timerFPSMenu < (1000 / 50))
  {
    SDL_Delay((1000 / 50) - timerFPSMenu);
  }

  SDL_RenderPresent(renderer);
}






void Game::draw()
{

  // cout << "25" << endl;

  SDL_SetRenderDrawColor(renderer, 75, 130, 50, 255);
  SDL_Rect rect;
  rect.x = rect.y = 0;
  rect.w = width;
  rect.h = height;

  // cout << "26" << endl;


  SDL_RenderFillRect(renderer, &rect);

  // cout << "27" << endl;


  drawImage(image);
  // cout << "28" << endl;

  // drawImage("Test - 1", 900, 40, 255, 0, 0);
  // drawImage("Hello!!", 905, 90, 255, 100, 100, font);
  // cout << "29" << endl;


  drawMap();
  // cout << "30" << endl;



  drawImage(gift1);
  drawImage(gift2);
  drawImage(gift3);
  drawImage(gift4);
  drawImage(gift5);
  drawImage(gift6);
  drawImage(gift7);
  drawImage(gift8);
  drawImage(gift9);
  drawImage(gift10);
  drawImage(gift11);
  drawImage(gift12);
  drawImage(gift13);
  drawImage(gift14);
  drawImage(gift15);
  drawImage(gift16);
  drawImage(gift17);
  drawImage(gift18);
  drawImage(gift19);
  drawImage(gift20);




  drawImage(player);
  // cout << "31" << endl;


  string ht = to_string(player.getHealth());
  const char* hlt = ht.c_str();
  drawImage("Health:", 30, 15, 255, 255, 255, font);
  drawImage(hlt, 210, 15, 255 - player.getHealth()*2.55, player.getHealth()*2.55, 0, font);
  SDL_stack_free(hlt);


  string sc = to_string(player.getScore());
  const char* scr = sc.c_str();
  drawImage("Score:", 30, 95, 255, 255, 255, font);
  drawImage(scr, 190, 95, 255, 255, 255, font);
  SDL_stack_free(scr);


  int tm = SDL_GetTicks();
  timed = maxTime - (tm - startTime)/1000;
  string ti = to_string(timed);
  const char* tim = ti.c_str();
  drawImage("Time:", 1050, 20, 255, 255, 255, font);
  if (timed < 10)
  {
    drawImage(tim, 1170, 20, 255, 0, 0, font);
  } else {
    drawImage(tim, 1170, 20, 255, 255, 255, font);
  }
  SDL_stack_free(tim);


  string stm = to_string(player.getStamina());
  const char* stmn = stm.c_str();
  drawImage("Stamina:", 15, 630, 255, 255, 255, font);
  drawImage(stmn, 220, 630, 255 - player.getStamina()*2.55, player.getStamina()*2.55, player.getStamina()*2.55, font);
  SDL_stack_free(stmn);



  drawImage(foodRed);

  drawImage("Food", 1200, 240, 255, 255, 255, font20);


  if ((timed + diff > 270 && timed + diff < 275) && timed >10)
  {
    drawImage(foodOrange);

    drawImage("Food will be ready soon!", width/2-260, 630, 255, 255, 255, font100);
    doneEating = 0;
  }
  if (timed + diff > 254 && timed + diff < 271)
  {

    drawImage(foodGreen);

    int remFdTm = timed - 255 + diff;
    string fd = to_string(remFdTm);
    if (fd.length() == 1)
    {
      string z = "0";
      fd = z.append(fd);
    }
    
    const char* fdT = fd.c_str();
    drawImage(fdT, 1216, 209, 255 - remFdTm*255/15, 0, remFdTm*255/15, font20);
    SDL_stack_free(fdT);

    food = 1;
    diffInc = 0;

    if (doneEating)
    {
      int tm = SDL_GetTicks();
      if (tmBool)
      {
        firstEaten = tm;
        tmBool = 0;
      }

      if (tm < (firstEaten + 3000)) // to look
      {
        drawImage("Congrats! Health 100% :)", width/2-270, 630, 255, 255, 255, font100); 
      }
    }

  }
  if (timed + diff > 240 && timed + diff < 255)
  {

    if (!diffInc)
    {
      diff += 30;
      diffInc = 1;
    }

    food = 0;
  }



  if (task1)
  {
    int tm = SDL_GetTicks();
    if (t1Bool)
    {
      task1Start = tm;
      t1Bool = 0;
    }

    if (tm < (task1Start + 3000)) // to look
    {
      drawImage("New Task Ready! :')", width/2-220, 330, 255, 255, 255, font100); 
    }

    if (task1S1)
    {
      int tm = SDL_GetTicks();
      if (t1S1Bool)
      {
        task1S1Start = tm;
        t1S1Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task1S1Start + 3000)) // to look
      {
        drawImage("Good Job! The Director will be arriving shortly. ", 90, 330, 255, 255, 255, font100); 
      }
    }

    if (task1S2)
    {
      int tm = SDL_GetTicks();
      if (t1S2Bool)
      {
        task1S2Start = tm;
        t1S2Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task1S2Start + 3000)) // to look
      {
        drawImage("Great! The Dean has also been Informed :')", 150, 330, 255, 255, 255, font100);  
      }
    }

    if (task1S3)
    {
      int tm = SDL_GetTicks();
      if (t1S3Bool)
      {
        task1S3Start = tm;
        t1S3Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task1S3Start + 3000)) // to look
      {
        drawImage("Good Going! The Alumni would also be arriving soon.", 5, 320, 255, 255, 255, font100); 
        drawImage("Now don't forget to book a table! ;^)", 220, 380, 255, 255, 255, font100); 
      }
    }

    if (task1S4)
    {
      int tm = SDL_GetTicks();
      if (t1S4Bool)
      {
        task1S4Start = tm;
        t1S4Bool = 0;
        tasksDone++;
        task1Done = 1;
        taskD = 1;
        taskDone.clearAndPlay();
      }

      if (tm < (task1S4Start + 3000)) // to look
      {
        drawImage("Congrats! Task 1 completed successfully. :')", 120, 330, 255, 255, 255, font100); 
      }
    }
  }

  if (task2)
  {
    int tm = SDL_GetTicks();
    if (t2Bool)
    {
      task2Start = tm;
      t2Bool = 0;
    }

    if (tm < (task2Start + 3000)) // to look
    {
      drawImage("New Task Ready! :')", width/2-220, 330, 255, 255, 255, font100); 
    }

    if (task2S1)
    {
      int tm = SDL_GetTicks();
      if (t2S1Bool)
      {
        task2S1Start = tm;
        t2S1Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task2S1Start + 3000)) // to look
      {
        drawImage("Hurrey! Cash withdrawn successfully :^)", 150, 330, 255, 255, 255, font100); 
      }
    }

    if (task2S2)
    {
      int tm = SDL_GetTicks();
      if (t2S2Bool)
      {
        task2S2Start = tm;
        t2S2Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task2S2Start + 3000)) // to look
      {
        drawImage("Great! You found the right Sports shop :')", 150, 330, 255, 255, 255, font100); 
      }
    }

    if (task2S3)
    {
      int tm = SDL_GetTicks();
      if (t2S3Bool)
      {
        task2S3Start = tm;
        t2S3Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task2S3Start + 3000)) // to look
      {
        drawImage("Great! you got some good last moment advice ;^)", 90, 320, 255, 255, 255, font100); 
        drawImage("Now hurry up before the spot gets filled! ;^)", 130, 380, 255, 255, 255, font100);  
      }
    }

    if (task2S4)
    {
      int tm = SDL_GetTicks();
      if (t2S4Bool)
      {
        task2S4Start = tm;
        t2S4Bool = 0;
        tasksDone++;
        task2Done = 1;
        taskD = 1;
        taskDone.clearAndPlay();
      }

      if (tm < (task2S4Start + 3000)) // to look
      {
        drawImage("Congrats! Task 2 completed succesfully. :')", 120, 330, 255, 255, 255, font100); 
      }
    }
  }

  if (task3)
  {
    int tm = SDL_GetTicks();
    if (t3Bool)
    {
      task3Start = tm;
      t3Bool = 0;
    }

    if (tm < (task3Start + 3000)) // to look
    {
      drawImage("New Task Ready! :')", width/2-220, 330, 255, 255, 255, font100); 
    }

    if (task3S1)
    {
      int tm = SDL_GetTicks();
      if (t3S1Bool)
      {
        task3S1Start = tm;
        t3S1Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task3S1Start + 3000)) // to look
      {
        drawImage("Nice! The lecture was great :')", 250, 330, 255, 255, 255, font100); 
      }
    }

    if (task3S2)
    {
      int tm = SDL_GetTicks();
      if (t3S2Bool)
      {
        task3S2Start = tm;
        t3S2Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task3S2Start + 3000)) // to look
      {
        drawImage("Good! You got your lab equipments :')", 230, 330, 255, 255, 255, font100); 
      }
    }

    if (task3S3)
    {
      int tm = SDL_GetTicks();
      if (t3S3Bool)
      {
        task3S3Start = tm;
        t3S3Bool = 0;
        subtaskDone.clearAndPlay();
      }

      if (tm < (task3S3Start + 3000)) // to look
      {
        drawImage("The workshop was great!", width/2-270, 320, 255, 255, 255, font100); 
        drawImage("Now hurry up before the last ticket gets sold! ;^)", 120, 380, 255, 255, 255, font100); 
      }
    }

    if (task3S4)
    {
      int tm = SDL_GetTicks();
      if (t3S4Bool)
      {
        task3S4Start = tm;
        t3S4Bool = 0;
        tasksDone++;
        task3Done = 1;
        taskD = 1;
        taskDone.clearAndPlay();
      }

      if (tm < (task3S4Start + 3000)) // to look
      {
        drawImage("Congrats! Task 3 completed succesfully. :)", 120, 330, 255, 255, 255, font100); 
      }
    }
  }

  


  if (tasksDone == 1)
  {
    int tm = SDL_GetTicks();
    if (td1Bool)
    {
      td1Bool = 0;
      player.setScore(player.getScore()+10000);
      maxTime += 10;
      taskEnd1 = tm;
    }

    if (tm < (taskEnd1 + 3000)) // to look
    {
      drawImage("Bonus: 10000sp + 10hp :')", width/2-240, 370, 255, 255, 255, font100); 
    }

  }
  if (tasksDone == 2)
  {

    int tm = SDL_GetTicks();
    if (td2Bool)
    {
      td2Bool = 0;
      player.setScore(player.getScore()+15000);
      maxTime += 15;
      taskEnd2 = tm;
    }

    if (tm < (taskEnd2 + 3000)) // to look
    {
      drawImage("Bonus: 15000sp + 15hp :')", width/2-240, 370, 255, 255, 255, font100); 
    }
  }
  if (tasksDone == 3)
  {
    int tm = SDL_GetTicks();
    if (td3Bool)
    {
      td3Bool = 0;
      player.setScore(player.getScore()+20000);
      maxTime += 20;
      taskEnd3 = tm;
    }

    if (tm < (taskEnd3 + 3000)) // to look
    {
      drawImage("Bonus: 20000sp + 20hp :')", width/2-240, 370, 255, 255, 255, font100); 
    }
  }


  if (!taskAssigned && timed < 290)
  {
    int tm = SDL_GetTicks();

    if (tFailedChk)
    {
      if (!taskD)
      {
        player.setScore(player.getScore()-7500);
      }
      tFailedChk = 0;
      tfcStart = tm;
    }
    

    if (!taskD)
    {
      if (tm < (tfcStart + 3000)) // to look
      {
        drawImage("Task Failed: -7500sp :(", width/2-220, 370, 255, 255, 255, font100); 
      }
    }
  }
  




  if (task1)
  {
    if (task1S1 && task1S2 && task1S3 && task1S4)
    {
      drawImage(greenTask);
    }
    else
    {
      drawImage(redTask);

      if (taskTime >= 0 && taskTime < 94)
      {
        int remFdTm = 93 - taskTime;
        string fd = to_string(remFdTm);
        if (fd.length() == 1)
        {
          string z = "0";
          fd = z.append(fd);
        }

        const char* TT = fd.c_str();
        drawImage(TT, 1216, 370, 0, remFdTm*255/93, 255 - remFdTm*255/93, font20);
        SDL_stack_free(TT);

      }
    }

    if (task1S1)
    {
      drawImage(greenS1);
    }
    else
    {
      drawImage(redS1);
    }

    if (task1S2)
    {
      drawImage(greenS2);
    }
    else
    {
      drawImage(redS2);
    }

    if (task1S3)
    {
      drawImage(greenS3);
    }
    else
    {
      drawImage(redS3);
    }

    if (task1S4)
    {
      drawImage(greenS4);
    }
    else
    {
      drawImage(redS4);
    }

  }



  if (task2)
  {
    if (task2S1 && task2S2 && task2S3 && task2S4)
    {
      drawImage(greenTask);
    }
    else
    {
      drawImage(redTask);

      if (taskTime >= 0 && taskTime < 94)
      {
        int remFdTm = 93 - taskTime;
        string fd = to_string(remFdTm);
        if (fd.length() == 1)
        {
          string z = "0";
          fd = z.append(fd);
        }

        const char* TT = fd.c_str();
        drawImage(TT, 1216, 370, 0, remFdTm*255/93, 255 - remFdTm*255/93, font20);
        SDL_stack_free(TT);

      }
    }

    if (task2S1)
    {
      drawImage(greenS1);
    }
    else
    {
      drawImage(redS1);
    }

    if (task2S2)
    {
      drawImage(greenS2);
    }
    else
    {
      drawImage(redS2);
    }

    if (task2S3)
    {
      drawImage(greenS3);
    }
    else
    {
      drawImage(redS3);
    }

    if (task2S4)
    {
      drawImage(greenS4);
    }
    else
    {
      drawImage(redS4);
    }

  }



  if (task3)
  {
    if (task3S1 && task3S2 && task3S3 && task3S4)
    {
      drawImage(greenTask);
    }
    else
    {
      drawImage(redTask);

      if (taskTime >= 0 && taskTime < 94)
      {
        int remFdTm = 93 - taskTime;
        string fd = to_string(remFdTm);
        if (fd.length() == 1)
        {
          string z = "0";
          fd = z.append(fd);
        }

        const char* TT = fd.c_str();
        drawImage(TT, 1216, 370, 0, remFdTm*255/93, 255 - remFdTm*255/93, font20);
        SDL_stack_free(TT);

      }
    }

    if (task3S1)
    {
      drawImage(greenS1);
    }
    else
    {
      drawImage(redS1);
    }

    if (task3S2)
    {
      drawImage(greenS2);
    }
    else
    {
      drawImage(redS2);
    }

    if (task3S3)
    {
      drawImage(greenS3);
    }
    else
    {
      drawImage(redS3);
    }

    if (task3S4)
    {
      drawImage(greenS4);
    }
    else
    {
      drawImage(redS4);
    }

  }
  


  





  if (loadMiniMap)
  {
    int xloc = location % 400;
    int yloc = location / 400;

    red.setDest(3*xloc + 42, 3*yloc + 80, 6, 6);

    drawImage(miniMap);

    drawImage(red);

    drawImage("M a p !", 40, 10, 0, 50, 100, font);

  }


  if (loadTaskScreen)
  {

    if (task1 && !task1Done)
    {
      drawImage(td1);

      drawImage("Task Description !", 40, 10, 0, 50, 100, font);
    }
    else if (task2 && !task2Done)
    {
      drawImage(td2);

      drawImage("Task Description !", 40, 10, 0, 50, 100, font);
    }
    else if (task3 && !task3Done)
    {
      drawImage(td3);

      drawImage("Task Description !", 40, 10, 0, 50, 100, font);
    }
    else
    {
      // taskNotReady.clearAndPlay();
      drawImage("No Task Ready Yet !", 430, 330, 0, 50, 100, font);
    }
    
    
    
    


  }








       




  frameCount++;
  // cout << "40" << endl;

  int x = SDL_GetTicks();
  timerFPS = x - lastFrame;

  // cout << "SDL_GetTicks() " << x << endl;
  // cout << "lastFrame " << lastFrame << endl;
  // cout << "timerFPS " << timerFPS << endl;

  // cout << "41" << endl;

  if (timerFPS < (1000 / 120))
  {
    // cout << "42" << endl;

    SDL_Delay((1000 / 120) - timerFPS);
    // cout << "43" << endl;

  }

  // cout << "32" << endl;


  SDL_RenderPresent(renderer);
  // cout << "33" << endl;

}




void Game::drawMenu()
{

  int x = (lastFrame/7000) % 8;

  if (x < 1 && x >= 0)
  {
    drawImage(pic1);
  }
  else if (x < 3 && x >= 2)
  {
    drawImage(pic3);
  }
  else if (x < 4 && x >= 3)
  {
    drawImage(pic4);
  }
  else if (x < 5 && x >= 4)
  {
    drawImage(pic5);
  }
  else if (x < 6 && x >= 5)
  {
    drawImage(pic6);
  }
  else if (x < 2 && x >= 1)
  {
    drawImage(pic7);
  }
  else if (x < 8 && x >= 7)
  {
    drawImage(pic8);
  }
  else if (x < 7 && x >= 6)
  {
    drawImage(pic9);
  }


  // drawImage("Test - 1", 900, 40, 255, 0, 0);

  // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  // SDL_Rect rect;
  // rect.x = rect.y = 0;
  // rect.w = width;
  // rect.h = height;
  // SDL_RenderFillRect(renderer, &rect);


  drawImage("Maze RunAround!", 330, 70, 255, 50, 50, font71);


  drawImage(plateBlue1);


  drawImage(plateBlue2);


  drawImage(plateBlue3);


  drawImage(plateSound);

  if (mainMenu.audioPlaying){
    drawImage(soundOn);
  } else {
    drawImage(soundOff);
  }


  plateOrange.setDest(452, menuSelect, 350, 80);
  drawImage(plateOrange);


  drawImage("Play", 585, 250, 100, 100, 255, font70);
  drawImage("Instructions", 490, 390, 100, 100, 255, font70);
  drawImage("Quit", 587, 530, 100, 100, 255, font70);



  drawImage(logo);


  string fd = to_string(highScore);
  string z = "High Score:  ";
  fd = z.append(fd);
  
  const char* hSc = fd.c_str();
  drawImage(hSc, 20, 650, 255, 255, 255, font70);
  SDL_stack_free(hSc);
  

  // drawMap();
  // drawImage(player); // replace order to hide player(test)

  frameCount++;
  timerFPSMenu = SDL_GetTicks() - lastFrame;
  if (timerFPSMenu < (1000 / 60))
  {
    SDL_Delay((1000 / 60) - timerFPSMenu);
  }

  SDL_RenderPresent(renderer);
}




void Game::escDraw()
{

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  SDL_Rect rect;
  rect.x = rect.y = 0;
  rect.w = width;
  rect.h = height;
  SDL_RenderFillRect(renderer, &rect);


  drawImage("Pause Menu", 50, 70, 200, 50, 255, font69);

  drawImage(escPlateBlue1);

  drawImage(escPlateBlue2);

  drawImage(escPlateBlue3);

  escPlateOrange.setDest(50, escMenuSelect, 350, 80);
  drawImage(escPlateOrange);


  drawImage("Resume", 100, 250, 100, 100, 255, font68);
  drawImage("Main Menu", 100, 390, 100, 100, 255, font68);
  drawImage("Quit", 100, 530, 100, 100, 255, font68);


  frameCount++;
  timerFPSMenu = SDL_GetTicks() - lastFrame;
  if (timerFPSMenu < (1000 / 50))
  {
    SDL_Delay((1000 / 50) - timerFPSMenu);
  }

  SDL_RenderPresent(renderer);
}


void Game::drawImage(Object o)
{

  SDL_Rect destination = o.getDest();
  SDL_Rect source = o.getSource();

  SDL_RenderCopyEx(renderer, o.getTex(), &source, &destination, 0, NULL, SDL_FLIP_NONE);
}

void Game::drawImage(const char *msg, int x, int y, int r, int g, int b, TTF_Font *font) // Text on screen
{

  SDL_Surface *surf;
  SDL_Texture *tex;
  SDL_Color color;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255; // transparency
  SDL_Rect rect;
  surf = TTF_RenderText_Solid(font, msg, color);
  tex = SDL_CreateTextureFromSurface(renderer, surf);

  rect.x = x;
  rect.y = y;
  rect.w = surf->w;
  rect.h = surf->h;

  SDL_FreeSurface(surf);
  SDL_RenderCopy(renderer, tex, NULL, &rect);
  SDL_DestroyTexture(tex);
}



void Game::loadMap(const char *filename)
{

  Object temp;
  temp.setImage("helpers/images/final2.png", renderer);

  int current, mx, my, mw, mh;
  ifstream in(filename);
  if (!in.is_open())
  {
    cout << "failed to open map file." << endl;
    return;
  }

  in >> mw;
  in >> mh;
  in >> mx;
  in >> my;

  for (int i = 0; i < mh; i++)
  {
    for (int j = 0; j < mw; j++)
    {
      if (in.eof())
      {
        cout << "Finished to end of file too soon." << endl;
        return;
      }

      in >> current;

      if (current < 18 && current > 0)
      {
        temp.setSolid(1);
        temp.setSource((current - 1) * 32, 0, 32, 32);
        temp.setDest((j * tilesize) + mx, (i * tilesize) + my, tilesize, tilesize);
        temp.setID(current);
        if (current == 13 || current == 14 || current == 35 || current == 22)
          temp.setSolid(0);
        map.push_back(temp);
      }
    }
  }

  in.close();
}

void Game::drawMap()
{
                  
  for (int i = 0; i < map.size(); i++)
  {
    if (
      map[i].getDX() >= mapX - tilesize && map[i].getDY() >= mapY - tilesize && map[i].getDX() <= mapX + width && map[i].getDY() <= mapY + height)
    {
      drawImage(map[i]);
    }
  }
}

void Game::scroll(int x, int y)
{

  for (int i = 0; i < map.size(); i++)
  {
    map[i].setDest(map[i].getDX() + x, map[i].getDY() + y);
  }

  gift1.setDest(gift1.getDX() + x, gift1.getDY() + y);
  gift2.setDest(gift2.getDX() + x, gift2.getDY() + y);
  gift3.setDest(gift3.getDX() + x, gift3.getDY() + y);
  gift4.setDest(gift4.getDX() + x, gift4.getDY() + y);
  gift5.setDest(gift5.getDX() + x, gift5.getDY() + y);
  gift6.setDest(gift6.getDX() + x, gift6.getDY() + y);
  gift7.setDest(gift7.getDX() + x, gift7.getDY() + y);
  gift8.setDest(gift8.getDX() + x, gift8.getDY() + y);
  gift9.setDest(gift9.getDX() + x, gift9.getDY() + y);
  gift10.setDest(gift10.getDX() + x, gift10.getDY() + y);
  gift11.setDest(gift11.getDX() + x, gift11.getDY() + y);
  gift12.setDest(gift12.getDX() + x, gift12.getDY() + y);
  gift13.setDest(gift13.getDX() + x, gift13.getDY() + y);
  gift14.setDest(gift14.getDX() + x, gift14.getDY() + y);
  gift15.setDest(gift15.getDX() + x, gift15.getDY() + y);
  gift16.setDest(gift16.getDX() + x, gift16.getDY() + y);
  gift17.setDest(gift17.getDX() + x, gift17.getDY() + y);
  gift18.setDest(gift18.getDX() + x, gift18.getDY() + y);
  gift19.setDest(gift19.getDX() + x, gift19.getDY() + y);
  gift20.setDest(gift20.getDX() + x, gift20.getDY() + y);

}

bool Game::collision(Object a, Object b)
{

  if ((a.getDX() < (b.getDX() + b.getDW())) && ((a.getDX() + a.getDW()) > b.getDX()) && (a.getDY() < (b.getDY() + b.getDH())) && ((a.getDY() + a.getDH()) > b.getDY()))
  {
    return true;
  }
  else
  {
    return false;
  }
}


void Game::randomBox(int n)
{

  int time = rand();

  int randNum = time % (9722);

  // cout << "==============   " << n << randNum << endl;


  int roadBlkNo = 0;
  for (int i = 0; i < map.size(); i++)
  {
    if (roadBlkNo == randNum)
    {
      if (n == 1)
      {
        gift1.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 2)
      {
        gift2.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 3)
      {
        gift3.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 4)
      {
        gift4.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 5)
      {
        gift5.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 6)
      {
        gift6.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 7)
      {
        gift7.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 8)
      {
        gift8.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 9)
      {
        gift9.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 10)
      {
        gift10.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 11)
      {
        gift11.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 12)
      {
        gift12.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 13)
      {
        gift13.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 14)
      {
        gift14.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 15)
      {
        gift15.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 16)
      {
        gift16.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 17)
      {
        gift17.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 18)
      {
        gift18.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 19)
      {
        gift19.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      else if (n == 20)
      {
        gift20.setDest(map[i].getDX()-tilesize,map[i].getDY(), tilesize, tilesize);
      }
      

      return;
    }
    if (map[i].getID() == 14)
    {
      roadBlkNo++;
    }
    
  }

}


void Game::randomSpawn()
{


  int time = rand();

  int randNum = time % (9722);

  // cout << "-------------   " << map.size() << endl;
  // cout << "-------------   " << randNum << endl;

  int roadBlkNo = 0;
  for (int i = 0; i < map.size(); i++)
  {
    if (roadBlkNo == randNum)
    {
      scroll(width/2 - map[i].getDX() + tilesize, height/2 - map[i].getDY());

      // cout << "-------------X   " << player.getDX() << endl;
      // cout << "-------------Y   " << player.getDY() << endl;

      // cout << "-------------mapX   " << map[i].getDX() << endl;
      // cout << "-------------mapY   " << map[i].getDY() << endl;


      return;
    }
    if (map[i].getID() == 14)
    {
      roadBlkNo++;
    }
    
  }

}


void Game::doorCheck(){

  for (int i = 0; i < map.size(); i++)
  {
    bool col = collision(player, map[i]);

    if (col)
    {
      if (((i / 400) == 128 && (i % 400) == 197) || ((i / 400) - 1 == 128 && (i % 400) == 197) || ((i / 400) == 128 && (i % 400) - 1 == 197) || ((i / 400) - 1 == 128 && (i % 400) - 1 == 197))
      {
        if (task1 && task1S1 && task1S2 && task1S3 && !task1S4)
        {
          task1S4 = 1;
        }
      }
      if (((i / 400) == 5 && (i % 400) == 82) || ((i / 400) - 1 == 5 && (i % 400) == 82) || ((i / 400) == 5 && (i % 400) - 1 == 82) || ((i / 400) - 1 == 5 && (i % 400) - 1 == 82))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }
        
      }
      if (((i / 400) == 29 && (i % 400) == 22) || ((i / 400) - 1 == 29 && (i % 400) == 22) || ((i / 400) == 29 && (i % 400) - 1 == 22) || ((i / 400) - 1 == 29 && (i % 400) - 1 == 22))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 54 && (i % 400) == 21) || ((i / 400) - 1 == 54 && (i % 400) == 21) || ((i / 400) == 54 && (i % 400) - 1 == 21) || ((i / 400) - 1 == 54 && (i % 400) - 1 == 21))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 78 && (i % 400) == 21) || ((i / 400) - 1 == 78 && (i % 400) == 21) || ((i / 400) == 78 && (i % 400) - 1 == 21) || ((i / 400) - 1 == 78 && (i % 400) - 1 == 21))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 103 && (i % 400) == 11) || ((i / 400) - 1 == 103 && (i % 400) == 11) || ((i / 400) == 103 && (i % 400) - 1 == 11) || ((i / 400) - 1 == 103 && (i % 400) - 1 == 11))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 94 && (i % 400) == 71) || ((i / 400) - 1 == 94 && (i % 400) == 71) || ((i / 400) == 94 && (i % 400) - 1 == 71) || ((i / 400) - 1 == 94 && (i % 400) - 1 == 71))
      {
        if (task1 && !task1S1 && !task1S2 && !task1S3 && !task1S4)
        {
          task1S1 = 1;
        }
        
      }
      if (((i / 400) == 95 && (i % 400) == 102) || ((i / 400) - 1 == 95 && (i % 400) == 102) || ((i / 400) == 95 && (i % 400) - 1 == 102) || ((i / 400) - 1 == 95 && (i % 400) - 1 == 102))
      {
        if (task3 && task3S1 && task3S2 && task3S3 && !task3S4)
        {
          task3S4 = 1;
        }
      }
      if (((i / 400) == 71 && (i % 400) == 73) || ((i / 400) - 1 == 71 && (i % 400) == 73) || ((i / 400) == 71 && (i % 400) - 1 == 73) || ((i / 400) - 1 == 71 && (i % 400) - 1 == 73))
      {
        if (task2 && task2S1 && task2S2 && !task2S3 && !task2S4)
        {
          task2S3 = 1;
        }
      }
      if (((i / 400) == 65 && (i % 400) == 110) || ((i / 400) - 1 == 65 && (i % 400) == 110) || ((i / 400) == 65 && (i % 400) - 1 == 110) || ((i / 400) - 1 == 65 && (i % 400) - 1 == 110))
      {
        if (task1 && task1S1 && task1S2 && task1S3 && !task1S4)
        {
          task1S4 = 1;
        }
      }
      if (((i / 400) == 52 && (i % 400) == 110) || ((i / 400) - 1 == 52 && (i % 400) == 110) || ((i / 400) == 52 && (i % 400) - 1 == 110) || ((i / 400) - 1 == 52 && (i % 400) - 1 == 110))
      {
        if (task1 && task1S1 && task1S2 && task1S3 && !task1S4)
        {
          task1S4 = 1;
        }
      }
      if (((i / 400) == 50 && (i % 400) == 95) || ((i / 400) - 1 == 50 && (i % 400) == 95) || ((i / 400) == 50 && (i % 400) - 1 == 95) || ((i / 400) - 1 == 50 && (i % 400) - 1 == 95))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 48 && (i % 400) == 81) || ((i / 400) - 1 == 48 && (i % 400) == 81) || ((i / 400) == 48 && (i % 400) - 1 == 81) || ((i / 400) - 1 == 48 && (i % 400) - 1 == 81))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 23 && (i % 400) == 51) || ((i / 400) - 1 == 23 && (i % 400) == 51) || ((i / 400) == 23 && (i % 400) - 1 == 51) || ((i / 400) - 1 == 23 && (i % 400) - 1 == 51))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 25 && (i % 400) == 140) || ((i / 400) - 1 == 25 && (i % 400) == 140) || ((i / 400) == 25 && (i % 400) - 1 == 140) || ((i / 400) - 1 == 25 && (i % 400) - 1 == 140))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 24 && (i % 400) == 151) || ((i / 400) - 1 == 24 && (i % 400) == 151) || ((i / 400) == 24 && (i % 400) - 1 == 151) || ((i / 400) - 1 == 24 && (i % 400) - 1 == 151))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 15 && (i % 400) == 181) || ((i / 400) - 1 == 15 && (i % 400) == 181) || ((i / 400) == 15 && (i % 400) - 1 == 181) || ((i / 400) - 1 == 15 && (i % 400) - 1 == 181))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 79 && (i % 400) == 174) || ((i / 400) - 1 == 79 && (i % 400) == 174) || ((i / 400) == 79 && (i % 400) - 1 == 174) || ((i / 400) - 1 == 79 && (i % 400) - 1 == 174))
      {
        if (task2 && task2S1 && task2S2 && task2S3 && !task2S4)
        {
          task2S4 = 1;
        }
      }
      if (((i / 400) == 55 && (i % 400) == 186) || ((i / 400) - 1 == 55 && (i % 400) == 186) || ((i / 400) == 55 && (i % 400) - 1 == 186) || ((i / 400) - 1 == 55 && (i % 400) - 1 == 186))
      {
        if (task2 && task2S1 && !task2S2 && !task2S3 && !task2S4)
        {
          task2S2 = 1;
        }
      }
      if (((i / 400) == 89 && (i % 400) == 243) || ((i / 400) - 1 == 89 && (i % 400) == 243) || ((i / 400) == 89 && (i % 400) - 1 == 243) || ((i / 400) - 1 == 89 && (i % 400) - 1 == 243))
      {
        if (task3 && task3S1 && task3S2 && !task3S3 && !task3S4)
        {
          task3S3 = 1;
        }
      }
      if (((i / 400) == 98 && (i % 400) == 273) || ((i / 400) - 1 == 98 && (i % 400) == 273) || ((i / 400) == 98 && (i % 400) - 1 == 273) || ((i / 400) - 1 == 98 && (i % 400) - 1 == 273))
      {
        if (task3 && !task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S1 = 1;
        }
      }
      if (((i / 400) == 80 && (i % 400) == 268) || ((i / 400) - 1 == 80 && (i % 400) == 268) || ((i / 400) == 80 && (i % 400) - 1 == 268) || ((i / 400) - 1 == 80 && (i % 400) - 1 == 268))
      {
        if (task2 && !task2S1 && !task2S2 && !task2S3 && !task2S4)
        {
          task2S1 = 1;
        }
      }
      if (((i / 400) == 37 && (i % 400) == 212) || ((i / 400) - 1 == 37 && (i % 400) == 212) || ((i / 400) == 37 && (i % 400) - 1 == 212) || ((i / 400) - 1 == 37 && (i % 400) - 1 == 212))
      {
        if (task1 && task1S1 && !task1S2 && !task1S3 && !task1S4)
        {
          task1S2 = 1;
        }
      }
      if (((i / 400) == 15 && (i % 400) == 311) || ((i / 400) - 1 == 15 && (i % 400) == 311) || ((i / 400) == 15 && (i % 400) - 1 == 311) || ((i / 400) - 1 == 15 && (i % 400) - 1 == 311))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 21 && (i % 400) == 331) || ((i / 400) - 1 == 21 && (i % 400) == 331) || ((i / 400) == 21 && (i % 400) - 1 == 331) || ((i / 400) - 1 == 21 && (i % 400) - 1 == 331))
      {
        if (food && !doneEating)
        {
          tmBool = 1;
          doneEating = 1;
          player.setHealth(100);
          foodEaten.clearAndPlay();
        }

        if (task3 && task3S1 && !task3S2 && !task3S3 && !task3S4)
        {
          task3S2 = 1;
        }

      }
      if (((i / 400) == 21 && (i % 400) == 371) || ((i / 400) - 1 == 21 && (i % 400) == 371) || ((i / 400) == 21 && (i % 400) - 1 == 371) || ((i / 400) - 1 == 21 && (i % 400) - 1 == 371))
      {
        if (task1 && task1S1 && task1S2 && !task1S3 && !task1S4)
        {
          task1S3 = 1;
        }
      }
      
    }
    
  }

}



void Game::foodCheck(){

  for (int i = 0; i < map.size(); i++)
  {
    bool col = collision(player, map[i]);

    if (col)
    {
      if (((i / 400) == 128 && (i % 400) == 197) || ((i / 400) - 1 == 128 && (i % 400) == 197) || ((i / 400) == 128 && (i % 400) - 1 == 197) || ((i / 400) - 1 == 128 && (i % 400) - 1 == 197))
      {
        player.setHealth(100);
        player.setScore(player.getScore()-3000);
      }
      if (((i / 400) == 65 && (i % 400) == 110) || ((i / 400) - 1 == 65 && (i % 400) == 110) || ((i / 400) == 65 && (i % 400) - 1 == 110) || ((i / 400) - 1 == 65 && (i % 400) - 1 == 110))
      {
        player.setHealth(100);
        player.setScore(player.getScore()-3000);
      }
      if (((i / 400) == 52 && (i % 400) == 110) || ((i / 400) - 1 == 52 && (i % 400) == 110) || ((i / 400) == 52 && (i % 400) - 1 == 110) || ((i / 400) - 1 == 52 && (i % 400) - 1 == 110))
      {
        player.setHealth(100);
        player.setScore(player.getScore()-3000);
      }
      
    }
    
  }

}