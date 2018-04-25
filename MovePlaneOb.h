#ifndef MOVEPLANEOB_H_INCLUDED
#define MOVEPLANEOB_H_INCLUDED
//#include "ThreateObject.h"
#include "ComonFunction.h"
#include<vector>
#include<iostream>
#define HEIGHT_PLAYER 77
#define WIDTH_PLAYER  52
#define HEIGHT_THREATE 80
#define WIDTH_THREATE 33
const int LEVEL_WIDTH = 1130;
const int LEVEL_HEIGHT = 600;
class Dot : public LTexture
{
    public:
		static const int DOT_WIDTH = 20;
		static const int DOT_HEIGHT = 150;
		static const int DOT_VEL = 5;

		Dot();


		void handleEvent( SDL_Event& e );
		void move();

		void render( int camX, int camY );
		void renderuntil(int x, int y);
		void renderP(int x,int y);
		void renderM(int x, int y);
		SDL_Rect getrectIM();
		SDL_Rect thanhmau;
		 void listamo(std::vector<Dot*>amo)
        {
            list_amo = amo;
        }
        std::vector<Dot*>Getlistamo()
        {
            return list_amo;
        }




    protected:


		int mVelX, mVelY;
		int mPosX,mPosY;
       std::vector<Dot*> list_amo;




};

SDL_Rect rectTD ={160,190,SCREEN_WIDTH_LASER,SCREEN_HEIGHT_LASER};
SDL_Rect RectUntil ={0,0,SCREEN_WIDTH_UNTIL,SCREEN_HEIGHT_UNTIL};
SDL_Rect rectIM = {0,-10,SCREEN_WIDTH_LASER,SCREEN_HEIGHT_LASER};
SDL_Rect camera1 = { 0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT };
SDL_Rect set1;

Dot *amo = new Dot;





Dot dot;


Dot::Dot()
{

    mPosX = 150;
    mPosY = 100;
    getXY.x  = mPosX + 60;
    getXY.y  = mPosY + 40;





    mVelX = 0;
    mVelY = 0;

    thanhmau.x = mPosX;
    thanhmau.y = mPosY+50;
    thanhmau.w = 61;
    thanhmau.h = 11;



}

void Dot::handleEvent( SDL_Event& e )
{

	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL ; break;
            case SDLK_DOWN: mVelY += DOT_VEL;   break;
            case SDLK_LEFT: mVelX -= DOT_VEL;   break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += DOT_VEL;    break;
            case SDLK_DOWN: mVelY -= DOT_VEL;  break;
            case SDLK_LEFT: mVelX += DOT_VEL;   break;
            case SDLK_RIGHT: mVelX -= DOT_VEL;    break;
        }
    }
    else if(e.type == SDL_MOUSEBUTTONDOWN)
    {
      if(e.button.button == SDL_BUTTON_LEFT)
      {
        i++;

         if(endgame != 5)
         {

         LbuttonAmo.loadFromFile("laser.png");

         LoadMixer.LoadMusic("scratch.wav");
         }



      }
      else if(e.button.button == SDL_BUTTON_RIGHT)
      {

          i++;

         if(endgame != 5)
         {

         LbuttonAmo.loadFromFile("sphere.png");

         LoadMixer.LoadMusic("scratch.wav");
         }



      }
    }
    else if(e.type == SDL_KEYDOWN)
    {
        if(e.key.keysym.sym == SDLK_SPACE)
        {
            if(score >= 20)
            {


            LoadUntil.loadFromFile("until.png");

            }
        }

    }


}

void Dot::move()
{

    mPosX += mVelX;

    RectUntil.x = mPosX + 75;

    //rectIM.x = mPosX + 40;



    getrect.x = mPosX;
    thanhmau.x = mPosX ;



    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > LEVEL_WIDTH ) )
    {
        mPosX -= mVelX;
        getrect.x = mPosX;
        thanhmau.x = mPosX ;
        getXY.x = mPosX + 40;

    }

    mPosY += mVelY;
    RectUntil.y = mPosY +15;
   // rectIM.y = mPosY + 40;

    thanhmau.y = mPosY+50;

    getrect.y = mPosY;





    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > LEVEL_HEIGHT ) )
    {
        mPosY -= mVelY;
        getrect.y = mPosY;
        thanhmau.y = mPosY+50;
        getXY.y = mPosY +60;





    }
}
void Dot:: renderM(int x,int y)
{
    if(endgame <= 1)
    {

    LoadMau.loadFromFile("mau.png");

    }
    else if(endgame == 2)
    {

    LoadMau.loadFromFile("mau1.png");

    }
    else if(endgame == 3)
    {

    LoadMau.loadFromFile("mau2.png");

    }
    else if(endgame == 4 )
    {

    LoadMau.loadFromFile("mau3.png");

    }
    else if(endgame == 5)
    {


        LoadMau.free();




    }


    LoadMau.render(thanhmau.x,thanhmau.y);

}

void Dot::render( int camX, int camY )
{
    bool check = checktf.CheckCollision(getrect,rectTH);

    bool check1 = checktf.CheckCollision(getrect,rectTH1);

    bool check2 = checktf.CheckCollision(getrect,rectTH2);

    bool check3 = checktf.CheckCollision(getrect,rectTH3);

    bool check4 = checktf.CheckCollision(getrect,rectTH4);


    if(check == true || check1 == true || check2 == true || check3 == true || check4 == true)
    {

     endgame = 5;

     gDotTexture.loadFromFile("no.png");
     gDotTexture.render( mPosX - camX, mPosY-camY  );
     LoadMixer.LoadMusic("Bomb1.wav");

    }
    else
    {

	gDotTexture.render( mPosX - camX, mPosY-camY  );

    }
}
void Dot::renderuntil(int x, int y)
{

    LoadUntil.render(RectUntil.x,RectUntil.y);

}

void Dot::renderP( int x, int y )
{


    LbuttonAmo.render(rectIM.x,rectIM.y);

	if(rectIM.x < SCREEN_WIDTH  && i >= 1 )
    {

        rectIM.x+=15;

        rectTD.x = rectIM.x;
        if(rectIM.x >= SCREEN_WIDTH  )
        {
            gDotTexture.loadFromFile("plane_fly_bullet.png");
        }
        else
        {
            gDotTexture.loadFromFile("plane_fly.png");

        }


    }
    else
    {
        if(i>=1)
        {
         LoadMixer.LoadMusic("scratch.wav");

        rectIM.x = mPosX + 60;
        rectTD.x = rectIM.x;
        rectIM.y = mPosY +40;
        rectTD.y = rectIM.y;
        }
    }








}






#endif // MOVEPLANEOB_H_INCLUDED
