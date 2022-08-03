#include "input.h"


void Game::input() // Key-bindings
{

  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      backgroundMusic.pause();
      backgroundMusic.audioPlaying = 0;

      runningPlay = 0;
      runningMenu = 0;
      cout << "Quitting!" << endl;
    }

    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_ESCAPE)
      {
        runningEsc = 1;
      }
      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x down" << endl;
        // player.setCurAnimation(shield);
      }
      if (e.key.keysym.sym == SDLK_LEFT)
      {
        l = 1;
        r = 0;
      }
      if (e.key.keysym.sym == SDLK_a)
      {
        l = 1;
        r = 0;
      }
      if (e.key.keysym.sym == SDLK_RIGHT)
      {
        l = 0;
        r = 1;
      }
      if (e.key.keysym.sym == SDLK_d)
      {
        l = 0;
        r = 1;
      }
      if (e.key.keysym.sym == SDLK_UP)
      {
        u = 1;
        d = 0;
      }
      if (e.key.keysym.sym == SDLK_w)
      {
        u = 1;
        d = 0;
      }
      if (e.key.keysym.sym == SDLK_DOWN)
      {
        u = 0;
        d = 1;
      }
      if (e.key.keysym.sym == SDLK_s)
      {
        u = 0;
        d = 1;
      }


      if (e.key.keysym.sym == SDLK_LSHIFT || e.key.keysym.sym == SDLK_RSHIFT)
      {

        sprint = 1;

        if (player.getStamina() > 0)
        {
          speed = runningSpeed;
        }
        
        // if (l || r || u || d)
        // {
        //   speedUp.clearAndPlay();
        // }

      }

      if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_f || e.key.keysym.sym == SDLK_SPACE)
      {

        doorCheck();

      }

      if (e.key.keysym.sym == SDLK_m)
      {
        loadMiniMap = 1;
      }

      if (e.key.keysym.sym == SDLK_TAB)
      {
        loadTaskScreen = 1;
      }

    }
    if (e.type == SDL_KEYUP)
    {

      if (e.key.keysym.sym == SDLK_e)
      {

        foodCheck();

      }

      if (e.key.keysym.sym == SDLK_LEFT)
      {
        l = 0;
        player.setCurAnimation(idoll);
      }
      if (e.key.keysym.sym == SDLK_a)
      {
        l = 0;
        player.setCurAnimation(idoll);
      }
      if (e.key.keysym.sym == SDLK_RIGHT)
      {
        r = 0;
        player.setCurAnimation(idolr);
      }
      if (e.key.keysym.sym == SDLK_d)
      {
        r = 0;
        player.setCurAnimation(idolr);
      }
      if (e.key.keysym.sym == SDLK_UP)
      {
        u = 0;
        if (player.getCurAnimation() == runningl)
        {
          player.setCurAnimation(idoll);
        }
        if (player.getCurAnimation() == runningr)
        {
          player.setCurAnimation(idolr);
        }
      }
      if (e.key.keysym.sym == SDLK_w)
      {
        u = 0;
        if (player.getCurAnimation() == runningl)
        {
          player.setCurAnimation(idoll);
        }
        if (player.getCurAnimation() == runningr)
        {
          player.setCurAnimation(idolr);
        }
      }
      if (e.key.keysym.sym == SDLK_DOWN)
      {
        d = 0;
        if (player.getCurAnimation() == runningl)
        {
          player.setCurAnimation(idoll);
        }
        if (player.getCurAnimation() == runningr)
        {
          player.setCurAnimation(idolr);
        }
      }
      if (e.key.keysym.sym == SDLK_s)
      {
        d = 0;
        if (player.getCurAnimation() == runningl)
        {
          player.setCurAnimation(idoll);
        }
        if (player.getCurAnimation() == runningr)
        {
          player.setCurAnimation(idolr);
        }
      }

      if (e.key.keysym.sym == SDLK_LSHIFT || e.key.keysym.sym == SDLK_RSHIFT)
      {
        sprint = 0;
        speed = walkingSpeed;
      }


      if (e.key.keysym.sym == SDLK_p)
      {
        if (backgroundMusic.audioPlaying == 0)
        {
          // cout << "p up play" << endl;
          backgroundMusic.resume();
          backgroundMusic.audioPlaying = 1;
          cout << "p up" << endl;
        }
        else
        {
          // cout << "p up pause" << endl;
          backgroundMusic.pause();
          backgroundMusic.audioPlaying = 0;
          cout << "p up" << endl;
        }
      }

      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x up" << endl;
        // player.reverse(1, idol);
      }

      if (e.key.keysym.sym == SDLK_m)
      {
        loadMiniMap = 0;
      }

      if (e.key.keysym.sym == SDLK_TAB)
      {
        loadTaskScreen = 0;
      }

      if (e.key.keysym.sym == SDLK_F11)
      {
        fullscreen = !fullscreen;
      }

    }

    SDL_GetMouseState(&mousex, &mousey);
  }
}






void Game::inputMenu() // Key-bindings
{

  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      runningMenu = 0;
      cout << "Quitting!" << endl;
    }

    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_ESCAPE)
      {
        runningMenu = 0;
      }
      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x down" << endl;
        // player.setCurAnimation(shield);
      }

    }
    if (e.type == SDL_KEYUP)
    {

      if (e.key.keysym.sym == SDLK_p)
      {
        if (mainMenu.audioPlaying == 0)
        {
          // cout << "p up play" << endl;
          mainMenu.resume();
          mainMenu.audioPlaying = 1;

        }
        else
        {
          // cout << "p up pause" << endl;
          mainMenu.pause();
          mainMenu.audioPlaying = 0;
        }
        
        menuSelecting.play();

      }

      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x up" << endl;
        // player.reverse(1, idol);
      }


      if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
      {
        if (menuSelect == 380)
        {
          menuSelect = 240;
        }
        else if (menuSelect == 520)
        {
          menuSelect = 380;
        }
        else if (menuSelect == 240)
        {
          menuSelect = 520;
        }

        menuNext.clearAndPlay();
        
      }

      if (e.key.keysym.sym == SDLK_s || e.key.keysym.sym == SDLK_DOWN)
      {
        if (menuSelect == 240)
        {
          menuSelect = 380;
        }
        else if (menuSelect == 380)
        {
          menuSelect = 520;
        }
        else if (menuSelect == 520)
        {
          menuSelect = 240;
        }

        menuNext.clearAndPlay();
        
      }

      if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_f || e.key.keysym.sym == SDLK_SPACE)
      {
        if (menuSelect == 240)
        {
          runningPlay = 1;
        }
        else if (menuSelect == 380)
        {
          runningIn = 1;
        }
        else if (menuSelect == 520)
        {
          runningMenu = 0;
        }

        menuSelecting.clearAndPlay();

      }

      if (e.key.keysym.sym == SDLK_F11)
        fullscreen = !fullscreen;
    }

    SDL_GetMouseState(&mousex, &mousey);
  }
}









void Game::escInput() // Key-bindings
{

  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      runningEsc = 0;
      runningPlay = 0;
      runningMenu = 0;

      cout << "Quitting!" << endl;
    }

    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_ESCAPE)
      {
        runningEsc = 0;
      }
      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x down" << endl;
        // player.setCurAnimation(shield);
      }

    }
    if (e.type == SDL_KEYUP)
    {

      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x up" << endl;
        // player.reverse(1, idol);
      }

      if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
      {
        if (escMenuSelect == 240)
        {
          escMenuSelect = 380;
        }
        else if (escMenuSelect == 380)
        {
          escMenuSelect = 520;
        }
        else if (escMenuSelect == 520)
        {
          escMenuSelect = 240;
        }

        menuNext.clearAndPlay();
        
      }


      if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
      {
        if (escMenuSelect == 380)
        {
          escMenuSelect = 240;
        }
        else if (escMenuSelect == 520)
        {
          escMenuSelect = 380;
        }
        else if (escMenuSelect == 240)
        {
          escMenuSelect = 520;
        }

        menuNext.clearAndPlay();
        
      }


      if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_f || e.key.keysym.sym == SDLK_SPACE)
      {
        if (escMenuSelect == 240)
        {
          runningEsc = 0;
        }
        else if (escMenuSelect == 380)
        {
          runningEsc = 0;
          runningPlay = 0;

        } else if (escMenuSelect == 520)
        {
          runningEsc = 0;
          runningPlay = 0;
          runningMenu = 0;
        }

        menuSelecting.clearAndPlay();

      }

      if (e.key.keysym.sym == SDLK_F11)
        fullscreen = !fullscreen;
    }

    SDL_GetMouseState(&mousex, &mousey);

    // if (e.type == SDL_MOUSEBUTTONDOWN)
    // {
    //   if (e.key.keysym.sym == SDL_BUTTON_LEFT)
    //   {
    //     if (mousex > 452 && mousex < 452 + 350 && mousey > 240 && mousey < 240 + 80)
    //     {
    //       runningEsc = 0;
    //     }
        
    //   }
    // }

  }
}




void Game::dsInput() // Key-bindings
{

  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      runningDs = 0;
      runningPlay = 0;
      runningMenu = 0;

      cout << "Quitting!" << endl;
    }

    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_ESCAPE)
      {
        runningDs = 0;
        runningPlay = 0;
      }
      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x down" << endl;
        // player.setCurAnimation(shield);
      }

    }
    if (e.type == SDL_KEYUP)
    {

      if (e.key.keysym.sym == SDLK_x)
      {
        cout << "x up" << endl;
        // player.reverse(1, idol);
      }

      if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d)
      {
        if (dsMenuSelect == 230)
        {
          dsMenuSelect = 730;
        }
        else if (dsMenuSelect == 730)
        {
          dsMenuSelect = 230;
        }

        menuNext.clearAndPlay();
        
      }


      if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a)
      {
        if (dsMenuSelect == 730)
        {
          dsMenuSelect = 230;
        }
        else if (dsMenuSelect == 230)
        {
          dsMenuSelect = 730;
        }

        menuNext.clearAndPlay();
        
      }


      if (e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_f)
      {
        if (dsMenuSelect == 230)
        {
          runningDs = 0;
          runningPlay = 0;
        }
        else if (dsMenuSelect == 730)
        {
          runningDs = 0;
          runningPlay = 0;
          runningMenu = 0;

        }

        menuSelecting.clearAndPlay();

      }

      if (e.key.keysym.sym == SDLK_F11)
        fullscreen = !fullscreen;
    }

    SDL_GetMouseState(&mousex, &mousey);
    
  }
}





void Game::isInput() // Key-bindings
{

  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      runningIn = 0;
      runningMenu = 0;

      cout << "Quitting!" << endl;
    }

    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_ESCAPE)
      {
        runningIn = 0;
      }

    }
    if (e.type == SDL_KEYUP)
    {

      if (e.key.keysym.sym == SDLK_F11)
        fullscreen = !fullscreen;
    }

    SDL_GetMouseState(&mousex, &mousey);
    
  }
}
