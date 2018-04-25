
#include "ComonFunction.h"
#include "MovePlaneOb.h"
#include "ThreateObject.h"
#include "START.h"
#include <SDL_mixer.h>
#include <ctime>
#include <cstdlib>

#define  SLD 2
void initttf()
{
    if(TTF_Init() == -1)
        printf(" can't init ttf \n");
}

int main( int argc, char* args[] )
{
        initttf();
	        init();
	       // init1();
	        if (!loadMedia())
                printf(" can't load media");
	        bool quit = false;

			SDL_Color textColor = { 255, 255, 255, 255 };

			std::stringstream timeText;

			SDL_Event e;

			Dot dot;
            LTexture EG;
			start letgogame;

			ThreateObject threateOb;
			ThreateObject threateOb1;

			threateOb.loadIMThreate();
			letgogame.loadImage();

			SDL_Rect camera = { 0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT };
			SDL_Rect camera1 = { 0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT };



			while( !EG.EndGame() )
			{



				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					dot.handleEvent( e );


                }

				dot.move();
				timeText.str( "" );
				timeText << "Milliseconds since start time " << 100;
                 gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor );


                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				SDL_RenderClear( gRenderer );
				gBGTexture.render( 0, 0, &camera );



				//letgogame.renderst(camera1.x,camera1.y);
                 if(camera.x < SCREEN_WIDTH*4 && endgame != 5 )
                 {
                     camera.x +=2;
                 }
                 else
                 {

                     camera.x = 0;

                 }

                 dot.render( camera1.x, camera1.y );
                 dot.renderM(camera1.x,camera1.y);
                 dot.renderuntil(camera1.x,camera1.y);
				//letgogame.renderst(camera1.x,camera1.y);

                 threateOb.constructor();
                // letgogame.MouseEV(e,rectStart);

                 for(int i=0;i< SLD-1;i++)
                 {

                     dot.renderP(camera.x,camera.y);
                 }
                 threateOb.freeeverything();

	             TTF_Font *font = TTF_OpenFont( "lazy.ttf", 32 );

                 SDL_Color mau = {0,0,0,255};
                 if(font == NULL)
                    printf("fuck\n");
                 SDL_Surface *scoreSurface = TTF_RenderText_Solid(font, "text", mau );
                SDL_Texture *scoreTexture = SDL_CreateTextureFromSurface(gRenderer, scoreSurface );
                SDL_Rect rect = {100, 100 ,300 ,50};
                SDL_RenderCopy( gRenderer, scoreTexture, NULL, &rect);

            SDL_FreeSurface(scoreSurface);
            SDL_DestroyTexture(scoreTexture);
				SDL_RenderPresent( gRenderer );

            }


   close();

	return 0;

}
