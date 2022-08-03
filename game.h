#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <ctime>
#include <sstream>


#include "object.h"
#include "audio.h"
#include "entity.h"
#include "input.h"


using namespace std;

#define width 1280
#define height 720

#define tilesize 20

#define playerW 16
#define playerH 24

#define walkingSpeed 8
#define runningSpeed 12

class Game
{
public:
    Game();
    ~Game();

    void menu();

    void menuLoop();
    void drawMenu();
    void inputMenu();
    void updateMenu();


    void play();

    void gameLoop();
    void draw();
    void input();
    void update();


    void escapeMenu();
    void deathScreen();
    void instScreen();

    void instScreenLoop();
    void deathScreenLoop();
    void escMenuLoop();
    void escDraw();
    void escInput();
    void escUpdate();


    void dsDraw();
    void dsInput();
    void dsUpdate();


    void isDraw();
    void isInput();
    void isUpdate();


    void randomBox(int n);
    void randomSpawn();
    void doorCheck();
    void foodCheck();

    void drawImage(Object o);
    void drawImage(const char *msg, int x, int y, int r, int g, int b, TTF_Font *font);

    void loadMap(const char *filename);
    void drawMap();

    void scroll(int x, int y);
    bool collision(Object a, Object b);

private:
    SDL_Renderer *renderer;
    SDL_Window *window;


    bool runningPlay, runningMenu, runningEsc;
    bool runningDs, runningIn, fullscreen;

    int frameCount, timerFPS, timerFPSMenu, lastFrame, fps;

    TTF_Font *font;
    TTF_Font *font100;
    TTF_Font *font20;

    int startTime;

    int boostStart = 0;
    int healthStart = 0;
    int taskStart = 0;

    bool sprint = 0;

    bool food = 0;
    bool doneEating = 0;
    int firstEaten;
    bool tmBool = 1;


    bool task1 = 0;
    int  task1Start;
    bool t1Bool = 1;
    bool task1S1 = 0;
    int  task1S1Start;
    bool t1S1Bool = 1;
    bool task1S2 = 0;
    int  task1S2Start;
    bool t1S2Bool = 1;
    bool task1S3 = 0;
    int  task1S3Start;
    bool t1S3Bool = 1;
    bool task1S4 = 0;
    int  task1S4Start;
    bool t1S4Bool = 1;
    
    bool task1Given = 0;
    bool task1Done = 0;


    bool task2 = 0;
    int  task2Start;
    bool t2Bool = 1;
    bool task2S1 = 0;
    int  task2S1Start;
    bool t2S1Bool = 1;
    bool task2S2 = 0;
    int  task2S2Start;
    bool t2S2Bool = 1;
    bool task2S3 = 0;
    int  task2S3Start;
    bool t2S3Bool = 1;
    bool task2S4 = 0;
    int  task2S4Start;
    bool t2S4Bool = 1;
    
    bool task2Given = 0;
    bool task2Done = 0;


    bool task3 = 0;
    int  task3Start;
    bool t3Bool = 1;
    bool task3S1 = 0;
    int  task3S1Start;
    bool t3S1Bool = 1;
    bool task3S2 = 0;
    int  task3S2Start;
    bool t3S2Bool = 1;
    bool task3S3 = 0;
    int  task3S3Start;
    bool t3S3Bool = 1;
    bool task3S4 = 0;
    int  task3S4Start;
    bool t3S4Bool = 1;
    
    bool task3Given = 0;
    bool task3Done = 0;


    int tasksGiven = 0;

    int tasksDone = 0;

    int tasksKnown = 0;
    int taskTime = 55;

    bool taskD = 0;
    

    int tfcStart = 0;
    int taskEnd1 = 0;
    int taskEnd2 = 0;
    int taskEnd3 = 0;



    bool taskAssigned = 0;
    bool tFailedChk = 0;
    bool reset = 1;

    int maxTime = 300;
    int timed = 300;
    int diff = 0;
    bool diffInc = 0;

    bool td1Bool = 1;
    bool td2Bool = 1;
    bool td3Bool = 1;


    int highScore = 0;


    Object image;
    int mousex, mousey;

    Object red;
    Object foodRed;
    Object foodGreen;
    Object foodOrange;

    Object redTask;
    Object greenTask;
    Object redS1;
    Object greenS1;
    Object redS2;
    Object greenS2;
    Object redS3;
    Object greenS3;
    Object redS4;
    Object greenS4;

    int location;
    
    Object miniMap;
    Object td1;
    Object td2;
    Object td3;
    bool loadMiniMap = 0;
    bool loadTaskScreen = 0;

    Audio backgroundMusic;
    Audio speedUp;
    Audio lowHealth;
    Audio giftPickUp;

    Audio foodEaten;
    Audio gameOver;
    Audio subtaskDone;
    Audio taskDone;
    Audio taskNotReady;


    Object gift1;
    Object gift2;
    Object gift3;
    Object gift4;
    Object gift5;
    Object gift6;
    Object gift7;
    Object gift8;
    Object gift9;
    Object gift10;
    Object gift11;
    Object gift12;
    Object gift13;
    Object gift14;
    Object gift15;
    Object gift16;
    Object gift17;
    Object gift18;
    Object gift19;
    Object gift20;

    Entity player;

    vector<Object> map;

    int mapX, mapY;

    int speed;

    bool l, r, u, d, fall;

    int idoll, idolr, runningl, runningr;

    // int idol, shield;

    bool playRun = 0;




    //menu

    // TTF_Font *menuFont;
    TTF_Font *font70;
    TTF_Font *font71;

    Audio mainMenu;
    Audio menuNext;
    Audio menuSelecting;

    Object pic1;
    Object pic3;
    Object pic4;
    Object pic5;
    Object pic6;
    Object pic7;
    Object pic8;
    Object pic9;

    Object logo;
    Object plateBlue1;
    Object plateBlue2;
    Object plateBlue3;
    Object plateOrange;

    Object plateSound;
    Object soundOn;
    Object soundOff;

    int menuSelect = 240;


    //escape menu
    TTF_Font *font69;
    TTF_Font *font68;
    Object escPlateBlue1;
    Object escPlateBlue2;
    Object escPlateBlue3;
    Object escPlateOrange;

    int escMenuSelect = 240;


    //deathScreen menu
    TTF_Font *dsfont100;
    TTF_Font *dsfont70;
    TTF_Font *dsfont50;
    Object dsPlateBlue1;
    Object dsPlateBlue2;
    Object dsPlateOrange;

    int dsMenuSelect = 230;


    //instructions screen
    Object inst;


};

#endif