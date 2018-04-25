#include "ThreateObject.h"

ThreateObject ThreateOb;
ThreateObject ThreateOb1;
ThreateObject ThreateOb2;

ThreateObject::ThreateObject()
{

    val_x = SCREEN_WIDTH;
    val_y = SCREEN_HEIGHT-200;
    rectTH.x = val_x;
    rectTH.y = val_y;
    rectTH1.x = val_x;
    rectTH1.y = val_y;
}
ThreateObject::~ThreateObject()
{


}
void ThreateObject::movePlaneThreate1(int x,int y)
{

    ThreateOb2.render(rectTH1.x,rectTH1.y-200);
    if(rectTH1.x < 0 )
   {
       srand((time(NULL)));
       rectTH1.x = val_x;
       rectTH1.y = rand()%300;

   }
   else
   {
       rectTH1.x -= 3;

   }
}
void ThreateObject::movePlaneThreate(int x,int y)
{


    ThreateOb.render(rectTH.x,rectTH.y);
    ThreateOb1.render(rectTH.x,rectTH.y-100);

    if(rectTH.x < 0)
   {
       srand((time(NULL)));
       rectTH.x = val_x;
       rectTH.y = rand()%400;

   }
   else
   {
       rectTH.x -= 5;

   }



}
void ThreateObject::loadIMThreate()
{
    ThreateOb.loadFromFile("af1.png");
    ThreateOb1.loadFromFile("af1.png");
    ThreateOb2.loadFromFile("af1.png");



}
