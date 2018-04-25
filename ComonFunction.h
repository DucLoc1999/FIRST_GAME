#ifndef COMONFUNCTION_H_INCLUDED
#define COMONFUNCTION_H_INCLUDED
#include<iostream>
#include <SDL.h>
#include <SDL_image.h>
#include<vector>
#include <stdio.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <sstream>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_HEIGHT_BG = 600;
const int SCREEN_WIDTH_BG = 4800;
const int SCREEN_WIDTH_LASER = 36 ;
const int SCREEN_HEIGHT_LASER = 5;
const int SCREEN_WIDTH_SPHERE = 10;
const int SCREEN_HEIGHT_SPHERE = 10;
const int SCREEN_WIDTH_THREATE = 80;
const int SCREEN_HEIGHT_THREATE = 33;
const int SCREEN_HEIGHT_PLAYER = 77;
const int SCREEN_WIDTH_PLAYER = 52;
const int SCREEN_HEIGHT_UNTIL = 29;
const int SCREEN_WIDTH_UNTIL = 652;
class LTexture
{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile( std::string path );
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		void free();
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
		//std::vector<LTexture*>list_amo;
		 //void renderP int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
         /*void listamo(std::vector<LTexture*>amo)
        {
            list_amo = amo;
        }
        std::vector<LTexture*>Getlistamo()
        {
            return list_amo;
        }*/
        bool CheckCollision(const SDL_Rect &object11 ,  const SDL_Rect &object2 );

        void LoadMusic(std::string path);
        int DisplayResourceNAMessageBox();
        bool EndGame();

        std::string convertInt(int number)
        {
          std:: stringstream ss;
          ss << number;
          return ss.str();
        }
        bool MouseIn(const SDL_Rect& rect);






      //  SDL_Rect getXY( )




	protected:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
		SDL_Rect rect;

		SDL_Event event;
		//bool check = false;
};
bool init();

bool loadMedia();

void close();
LTexture finish;
int i = 0;
SDL_Window* gWindow = NULL;
bool check = false;
SDL_Rect  rect1;
SDL_Renderer* gRenderer = NULL;
TTF_Font *gFont = NULL;
LTexture gDotTexture;
LTexture gBGTexture;
LTexture LoadMau;
LTexture checktf;
LTexture loadendgame;
LTexture LoadMixer;
LTexture gTimeTextTexture;
LTexture gPromptTextTexture;
SDL_Rect rectStart;
LTexture LoadUntil;
LTexture SS;
bool BG = false;

int score = 0;
    SDL_Rect Amorect = {SCREEN_WIDTH - 20,SCREEN_HEIGHT-125,SCREEN_WIDTH_SPHERE,SCREEN_HEIGHT_SPHERE};
    SDL_Rect Amorect1 = {SCREEN_WIDTH - 20,SCREEN_HEIGHT-125,SCREEN_WIDTH_SPHERE,SCREEN_HEIGHT_SPHERE};
    SDL_Rect Amorect2 = {SCREEN_WIDTH - 20,SCREEN_HEIGHT-125,SCREEN_WIDTH_SPHERE,SCREEN_HEIGHT_SPHERE};
    SDL_Rect Amorect3 = {SCREEN_WIDTH - 20,SCREEN_HEIGHT-125,SCREEN_WIDTH_SPHERE,SCREEN_HEIGHT_SPHERE};
    SDL_Rect Amorect4 = {SCREEN_WIDTH - 20,SCREEN_HEIGHT-125,SCREEN_WIDTH_SPHERE,SCREEN_HEIGHT_SPHERE};
    SDL_Rect rectTH = {SCREEN_WIDTH,SCREEN_HEIGHT-150,SCREEN_WIDTH_THREATE-20,SCREEN_HEIGHT_THREATE-8};
    SDL_Rect rectTH1 = {SCREEN_WIDTH,SCREEN_HEIGHT-150,SCREEN_WIDTH_THREATE-20,SCREEN_HEIGHT_THREATE-8};
    SDL_Rect rectTH2 = {SCREEN_WIDTH,SCREEN_HEIGHT-150,SCREEN_WIDTH_THREATE-20,SCREEN_HEIGHT_THREATE-8};
    SDL_Rect rectTH3 = {SCREEN_WIDTH,SCREEN_HEIGHT-150,SCREEN_WIDTH_THREATE-20,SCREEN_HEIGHT_THREATE-8};
    SDL_Rect rectTH4 = {SCREEN_WIDTH,SCREEN_HEIGHT-150,SCREEN_WIDTH_THREATE-20,SCREEN_HEIGHT_THREATE-8}
;SDL_Rect getrect = {100,150,SCREEN_WIDTH_PLAYER,SCREEN_HEIGHT_PLAYER};
SDL_Rect getXY;

int endgame = 0;

LTexture LbuttonAmo;

//LTexture ThreateOb;
bool LTexture::MouseIn(const SDL_Rect &rect)
{
       int x = event.button.x;
       int y = event.button.y;
      // std::cout<<x<<" ";
       return (x >= rect.x && y >= rect.y && x < rect.x+rect.w && y < rect.y+rect.h);
}

LTexture::LTexture()
{

	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );

		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );

			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;

		SDL_FreeSurface( loadedSurface );

	mTexture = newTexture;
	return mTexture != NULL;
}
bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{

	free();
	std :: stringstream text ;
	text.str(""); text << text;
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, text.str().c_str(), textColor );
	if( textSurface != NULL )
	{
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	return mTexture != NULL;
}


void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}


	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}




void close()
{
	gDotTexture.free();
	gBGTexture.free();
	LoadMixer.free();
	LoadUntil.free();
	LoadMau.free();
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}
bool init()
{
	bool success = true;


		gWindow = SDL_CreateWindow( "Demo Game ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

	return success;
}

bool loadMedia()
{
	bool success = true;
	if( !gDotTexture.loadFromFile( "plane_fly.png" ) )
	{
		success = false;
	}
	if( !gBGTexture.loadFromFile( "bg48001.png" ) )
	{
		success = false;
	}

	//Open the font
	gFont = TTF_OpenFont( "lazy.ttf", 28 );
	if( gFont != NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Set text color as black
		SDL_Color textColor = { 1201, 255, 255, 255 };

		//Load prompt texture
		if( !gPromptTextTexture.loadFromRenderedText( "Press Enter to Reset Start Time.", textColor ) )
		{
			printf( "Unable to render prompt texture!\n" );
			success = false;
		}
	}





	return success;
}
void LTexture::LoadMusic(std::string path)
{
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    Mix_Chunk *gLow = NULL;
    gLow = Mix_LoadWAV(path.c_str());
    Mix_PlayChannel( -1, gLow, 0 );
}
bool LTexture::CheckCollision(const SDL_Rect &object1, const SDL_Rect &object2)
{

  int left_a = object1.x;
  int right_a = object1.x + object1.w-35;
  int top_a = object1.y ;
  int bottom_a = object1.y + object1.h-35;

  int left_b = object2.x-8;
  int right_b = object2.x + object2.w;
  int top_b = object2.y-8;
  int bottom_b = object2.y + object2.h;

  // Case 1: size object 1 < size object 2
  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

 if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  // Case 2: size object 1 < size object 2
  if (left_b > left_a  && left_b < right_a)
  {
    if (top_b > top_a  && top_b < bottom_a)
    {
      return true;
    }
  }

  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
    // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;


}

bool LTexture::EndGame()
{
    SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    if(endgame == 5)
    {
     SDL_Color textColor = { 0, 255, 0, 255 };
     std::stringstream timeText;
     timeText.str("");
     timeText << "Milliseconds since start time " << score;
     gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) ;

    }
    return false;
}




#endif
