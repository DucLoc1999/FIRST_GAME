#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include "ComonFunction.h"
class start : public LTexture
{
public:
    void  loadImage();
    start();
    //~start();
    bool startgame();
    bool MouseEV(SDL_Event &e,SDL_Rect &rectStart);
    bool PlayGame(SDL_Event &e,SDL_Rect &rectStart);


    void renderst(int x, int y);
    //bool setload = false;
private:
    //SDL_Rect rectStart;
    //SDL_Event e;


};
start loadst;
start::start()
{

    rectStart.x = SCREEN_WIDTH/2-100;
    rectStart.y = SCREEN_HEIGHT/2;
}
void start ::loadImage()
{
    loadst.loadFromFile("start.png");
}
void start::renderst(int x , int y)
{

    loadst.render(rectStart.x,rectStart.y);

}
bool start::MouseEV(SDL_Event &e,SDL_Rect &rectStart)
{

    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e.button.x;
        int y = e.button.y;
        std::cout<<x;
        return (x >= rectStart.x && y >= rectStart.y && x < rectStart.x+rectStart.w && y < rectStart.y+rectStart.h);
    }
}
bool start::PlayGame(SDL_Event &e,SDL_Rect &rectStart)
{

    bool PG;
    SDL_Rect camera={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    loadst.loadFromFile("bkground.png");
    renderst(camera.x,camera.y);

    if(PG == MouseEV(e,rectStart))
    {

       loadst.free();

       return true;

    }
}

#endif // START_H_INCLUDED
