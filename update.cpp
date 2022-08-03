#include "update.h"

void Game::update()
{

    player.updateAnimation();

    if (l)
    {

        // cout << fps << endl;

        Entity x;
        x.setDest(player.getDX() - speed, player.getDY(), playerW, playerH);

        bool coll = false;

        for (int i = 0; i < map.size(); i++)
        {
            bool col = collision(x, map[i]);
            
            if (col)
            {
                location = i;
            }
            
            if (col && map[i].getSolid())
            {

                if (player.getCurAnimation() != runningl)
                {
                    player.setCurAnimation(runningl);
                }

                coll = true;
            }
        }

        if (!coll)
        {
            // cout << "++++++++++++++++++++++++" << i << endl;
            if (player.getCurAnimation() != runningl)
            {
                player.setCurAnimation(runningl);
            }
            player.setDest(player.getDX() - speed, player.getDY());
        }
    }
    if (r)
    {

        Entity x;
        x.setDest(player.getDX() + speed, player.getDY(), playerW, playerH);

        bool coll = false;

        for (int i = 0; i < map.size(); i++)
        {
            bool col = collision(x, map[i]);
            
            if (col)
            {
                location = i;
            }

            if (col && map[i].getSolid())
            {

                if (player.getCurAnimation() != runningr)
                {
                    player.setCurAnimation(runningr);
                }

                coll = true;
            }
        }

        if (!coll)
        {
            if (player.getCurAnimation() != runningr)
            {
                player.setCurAnimation(runningr);
            }
            player.setDest(player.getDX() + speed, player.getDY());
        }
    }
    if (u)
    {

        Entity x;
        x.setDest(player.getDX(), player.getDY() - speed, playerW, playerH);

        bool coll = false;

        for (int i = 0; i < map.size(); i++)
        {
            bool col = collision(x, map[i]);
            
            if (col)
            {
                location = i;
            }

            if (col && map[i].getSolid())
            {

                if (player.getCurAnimation() == idoll)
                {
                    player.setCurAnimation(runningl);
                }
                if (player.getCurAnimation() == idolr)
                {
                    player.setCurAnimation(runningr);
                }

                coll = true;
            }
        }

        if (!coll)
        {
            if (player.getCurAnimation() == idoll)
            {
                player.setCurAnimation(runningl);
            }
            if (player.getCurAnimation() == idolr)
            {
                player.setCurAnimation(runningr);
            }
            player.setDest(player.getDX(), player.getDY() - speed);
        }
    }
    if (d)
    {

        Entity x;
        x.setDest(player.getDX(), player.getDY() + speed, playerW, playerH);

        bool coll = false;

        for (int i = 0; i < map.size(); i++)
        {
            bool col = collision(x, map[i]);

            if (col)
            {
                location = i;
            }

            if (col && map[i].getSolid())
            {

                if (player.getCurAnimation() == idoll)
                {
                    player.setCurAnimation(runningl);
                }
                if (player.getCurAnimation() == idolr)
                {
                    player.setCurAnimation(runningr);
                }

                coll = true;
            }
        }

        if (!coll)
        {
            if (player.getCurAnimation() == idoll)
            {
                player.setCurAnimation(runningl);
            }
            if (player.getCurAnimation() == idolr)
            {
                player.setCurAnimation(runningr);
            }
            player.setDest(player.getDX(), player.getDY() + speed);
        }
    }





    if (player.getDX() < 320)
    {
        player.setDest(320, player.getDY());
        scroll(speed, 0);
    }
    if (player.getDX() > width - 348)
    {
        player.setDest(width - 348, player.getDY());
        scroll(-speed, 0);
    }
    if (player.getDY() < 180)
    {
        player.setDest(player.getDX(), 180);
        scroll(0, speed);
    }
    if (player.getDY() > height - 218)
    {
        player.setDest(player.getDX(), height - 218);
        scroll(0, -speed);
    }

    if (fullscreen){
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    }
    if (!fullscreen){
        SDL_SetWindowFullscreen(window, 0);
    }

    int tm = SDL_GetTicks();

    if ((player.getHealth() > 0) && (tm >= (healthStart + 1000)))
    {
      healthStart = tm;
      player.setHealth(player.getHealth() - 1);
      if (player.getHealth() < 10)
      {
        lowHealth.clearAndPlay();
      }
    }
    

    if (tm >= (taskStart + 1000))
    {
      taskStart = tm;
      taskTime = (tm - startTime - 5000)/1000 % 98;
    }


    if (taskTime == 93)
    {
        if (reset)
        {
            taskAssigned = 0;
            tFailedChk = 1;

            reset = 0;
        }
    }
    if (taskTime == 96)
    {
        task1 = 0;
        task2 = 0;
        task3 = 0;
    }

    if (taskTime == 0 && !taskAssigned)
    {
        reset = 1;
        tFailedChk = 0;
        taskAssigned = 1;
        taskD = 0;
        
        if (tasksGiven == 0)
        {
            tasksGiven++;
            int t = rand() % 3;

            if (t == 0)
            {
                task1 = 1;
                task1Given = 1;
            }
            else if (t == 1)
            {
                task2 = 1;
                task2Given = 1;
            }
            else
            {
                task3 = 1;
                task3Given = 1;
            }
        }
        else if (tasksGiven == 1)
        {
            tasksGiven++;
            int t = rand() % 2;

            if (task1Given)
            {
                if (t == 0)
                {
                    task2 = 1;
                    task2Given = 1;
                }
                else if (t == 1)
                {
                    task3 = 1;
                    task3Given = 1;
                }
            }
            else if (task2Given)
            {
                if (t == 0)
                {
                    task1 = 1;
                    task1Given = 1;
                }
                else if (t == 1)
                {
                    task3 = 1;
                    task3Given = 1;
                }
            }
            else if (task3Given)
            {
                if (t == 0)
                {
                    task1 = 1;
                    task1Given = 1;
                }
                else if (t == 1)
                {
                    task2 = 1;
                    task2Given = 1;
                }
            }
        }
        else if (tasksGiven == 2)
        {
            tasksGiven++;
            if (task1Given && task2Given)
            {
                task3 = 1;
                task3Given = 1;
            }
            else if (task2Given && task3Given)
            {
                task1 = 1;
                task1Given = 1;
            }
            else if (task1Given && task3Given)
            {
                task2 = 1;
                task2Given = 1;
            }
        }

    }


    if (player.getStamina() < 1)
    {
        speed = walkingSpeed;
    }

    if (r || l || u || d)
    {
        if (sprint)
        {
            if ((player.getStamina() > 0) && (tm >= (boostStart + 50)))
            {
              boostStart = tm;
              player.setStamina(player.getStamina() - 1);
            }

        }

        if ((player.getStamina() < 100) && (tm >= (boostStart + 100)))
        {
          boostStart = tm;
          player.setStamina(player.getStamina() + 1);
        }

    } else {

        if ((player.getStamina() < 100) && (tm >= (boostStart + 50)))
        {
          boostStart = tm;
          player.setStamina(player.getStamina() + 1);
        }

    }


    if (gift1.getDX() < player.getDX() + playerW + 24 && gift1.getDX() > player.getDX() - 24 && gift1.getDY() < player.getDY() + playerH + 24 && gift1.getDY() > player.getDY() - 24)
    {

        giftPickUp.clearAndPlay();

        int f = rand() % 2;
        if (f == 0)
        {
            player.setScore(player.getScore() - 10000);
        }
        else 
        {
            player.setScore(player.getScore() + 10000);

        }

        randomBox(1);
    }

    if (gift2.getDX() < player.getDX() + playerW + 24 && gift2.getDX() > player.getDX() - 24 && gift2.getDY() < player.getDY() + playerH + 24 && gift2.getDY() > player.getDY() - 24)
    {

        giftPickUp.clearAndPlay();

        int f = rand() % 2;
        if (f == 0)
        {
            player.setScore(player.getScore() - 10000);
        }
        else 
        {
            player.setScore(player.getScore() + 10000);

        }

        randomBox(2);
    }
    

    if (gift3.getDX() < player.getDX() + playerW + 24 && gift3.getDX() > player.getDX() - 24 && gift3.getDY() < player.getDY() + playerH + 24 && gift3.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 2000);

        randomBox(3);
    }

    if (gift4.getDX() < player.getDX() + playerW + 24 && gift4.getDX() > player.getDX() - 24 && gift4.getDY() < player.getDY() + playerH + 24 && gift4.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 2000);

        randomBox(4);
    }

    if (gift5.getDX() < player.getDX() + playerW + 24 && gift5.getDX() > player.getDX() - 24 && gift5.getDY() < player.getDY() + playerH + 24 && gift5.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(5);
    }

    if (gift6.getDX() < player.getDX() + playerW + 24 && gift6.getDX() > player.getDX() - 24 && gift6.getDY() < player.getDY() + playerH + 24 && gift6.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(6);
    }
    
    if (gift7.getDX() < player.getDX() + playerW + 24 && gift7.getDX() > player.getDX() - 24 && gift7.getDY() < player.getDY() + playerH + 24 && gift7.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(7);
    }

    if (gift8.getDX() < player.getDX() + playerW + 24 && gift8.getDX() > player.getDX() - 24 && gift8.getDY() < player.getDY() + playerH + 24 && gift8.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(8);
    }

    if (gift9.getDX() < player.getDX() + playerW + 24 && gift9.getDX() > player.getDX() - 24 && gift9.getDY() < player.getDY() + playerH + 24 && gift9.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(9);
    }

    if (gift10.getDX() < player.getDX() + playerW + 24 && gift10.getDX() > player.getDX() - 24 && gift10.getDY() < player.getDY() + playerH + 24 && gift10.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 200);

        randomBox(10);
    }


    if (gift11.getDX() < player.getDX() + playerW + 24 && gift11.getDX() > player.getDX() - 24 && gift11.getDY() < player.getDY() + playerH + 24 && gift11.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();

        int f = rand() % 3;
        if (f == 0)
        {
            if (player.getHealth() < 20)
            {
                player.setHealth(0);
            }
            else
            {
                player.setHealth(player.getHealth() - 20);
            }
            
        }
        else 
        {
            if (player.getHealth() > 80)
            {
                player.setHealth(100);
            }
            else
            {
                player.setHealth(player.getHealth() + 20);
            }

        }

        randomBox(11);
    }

    if (gift12.getDX() < player.getDX() + playerW + 24 && gift12.getDX() > player.getDX() - 24 && gift12.getDY() < player.getDY() + playerH + 24 && gift12.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();

        int f = rand() % 3;
        if (f == 0)
        {
            if (player.getHealth() < 20)
            {
                player.setHealth(0);
            }
            else
            {
                player.setHealth(player.getHealth() - 20);
            }
            
        }
        else 
        {
            if (player.getHealth() > 80)
            {
                player.setHealth(100);
            }
            else
            {
                player.setHealth(player.getHealth() + 20);
            }

        }

        randomBox(12);
    }
    
    if (gift13.getDX() < player.getDX() + playerW + 24 && gift13.getDX() > player.getDX() - 24 && gift13.getDY() < player.getDY() + playerH + 24 && gift13.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 800);

        randomBox(13);
    }
    
    if (gift14.getDX() < player.getDX() + playerW + 24 && gift14.getDX() > player.getDX() - 24 && gift14.getDY() < player.getDY() + playerH + 24 && gift14.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 800);

        randomBox(14);
    }

    if (gift15.getDX() < player.getDX() + playerW + 24 && gift15.getDX() > player.getDX() - 24 && gift15.getDY() < player.getDY() + playerH + 24 && gift15.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 800);

        randomBox(15);
    }

    if (gift16.getDX() < player.getDX() + playerW + 24 && gift16.getDX() > player.getDX() - 24 && gift16.getDY() < player.getDY() + playerH + 24 && gift16.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 500);

        randomBox(16);
    }

    if (gift17.getDX() < player.getDX() + playerW + 24 && gift17.getDX() > player.getDX() - 24 && gift17.getDY() < player.getDY() + playerH + 24 && gift17.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 500);

        randomBox(17);
    }

    if (gift18.getDX() < player.getDX() + playerW + 24 && gift18.getDX() > player.getDX() - 24 && gift18.getDY() < player.getDY() + playerH + 24 && gift18.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 500);

        randomBox(18);
    }

    if (gift19.getDX() < player.getDX() + playerW + 24 && gift19.getDX() > player.getDX() - 24 && gift19.getDY() < player.getDY() + playerH + 24 && gift19.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 500);

        randomBox(19);
    }

    if (gift20.getDX() < player.getDX() + playerW + 24 && gift20.getDX() > player.getDX() - 24 && gift20.getDY() < player.getDY() + playerH + 24 && gift20.getDY() > player.getDY() - 24)
    {
        giftPickUp.clearAndPlay();
        player.setScore(player.getScore() + 500);

        randomBox(20);
    }




    if (player.getHealth() < 1 || timed < 1)
    {
        runningDs = 1;
    }

    
    

}



void Game::updateMenu()
{


    
    if (fullscreen)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!fullscreen)
        SDL_SetWindowFullscreen(window, 0);
}


void Game::escUpdate()
{
    
    if (fullscreen)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!fullscreen)
        SDL_SetWindowFullscreen(window, 0);
}


void Game::dsUpdate()
{
    
    if (fullscreen)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!fullscreen)
        SDL_SetWindowFullscreen(window, 0);
}


void Game::isUpdate()
{
    
    if (fullscreen)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!fullscreen)
        SDL_SetWindowFullscreen(window, 0);
}