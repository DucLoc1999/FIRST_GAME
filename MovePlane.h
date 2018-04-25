#ifndef MOVEPLANE_H_INCLUDED
#define MOVEPLANE_H_INCLUDED

#ifndef MOVEPLANE_H_INCLUDED
#define MOVEPLANE_H_INCLUDED
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
		void renderP(int x,int y);
		SDL_Rect rectIM = {mPosX+60,mPosY+40,SCREEN_WIDTH_LASER,SCREEN_HEIGHT_LASER};


    protected:
		int mPosX, mPosY;

		int mVelX, mVelY;


};
SDL_Rect rectTD ;
Dot dot;
Dot::Dot()
{

    mPosX = 100;
    mPosY = 150;
    rectIM.y = mPosY+40;

    mVelX = 0;
    mVelY = 0;

}

void Dot::handleEvent( SDL_Event& e )
{

	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL ;break;
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

      LbuttonAmo.loadFromFile( "laser.png" );


      }
      else if(e.button.button == SDL_BUTTON_RIGHT)
      {

          LbuttonAmo.loadFromFile("sphere.png");


      }
    }


}

void Dot::move()
{
    mPosX += mVelX;
    rectTD.x = mPosX;
    //std::cout<<rectTD.x<<std::endl;


    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > LEVEL_WIDTH ) )
    {
        mPosX -=mVelX;

    }

    mPosY += mVelY;

    rectTD.y = mPosY;

    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > LEVEL_HEIGHT ) )
    {
        mPosY -= mVelY;

    }
}

void Dot::render( int camX, int camY )
{

	gDotTexture.render( mPosX - camX, mPosY-camY  );
}

void Dot::renderP( int x, int y )
{
      //  std::cout<<test<<" ";

       {
          LbuttonAmo.render(rectIM.x,rectIM.y);

       }


	if(rectIM.x<SCREEN_WIDTH )
    {
       rectIM.x+=10;

    }
    else
    {
        rectIM.x = mPosX + 60;
        rectIM.y = mPosY +40;
    }



}
/*SDL_Rect Dot::getxy()
{

    rectTD.x = mPosX;
    rectTD.y = mPosY;
}*/





#endif


#endif // MOVEPLANE_H_INCLUDED
