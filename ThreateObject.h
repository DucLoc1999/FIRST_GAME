#ifndef THREATEOBJECT_H_INCLUDED
#define THREATEOBJECT_H_INCLUDED
#include "ComonFunction.h"
#include "MovePlaneOb.h"
#include<ctime>
#include<cstdlib>
#define HEIGHT_PLAYER 77
#define WIDTH_PLAYER  52
#define HEIGHT_THREATE 80
#define WIDTH_THREATE 33
class ThreateObject : public LTexture
{
public:
    ThreateObject();
    ~ThreateObject();
    void constructor();
    void loadIMThreate();
    void startgame(SDL_Rect &obj1,SDL_Rect &obj2,int h);
    void setup(SDL_Rect &obj1,SDL_Rect &obj2,int h, int x,int vt);
    void logic(SDL_Rect &obj1,SDL_Rect &obj2,int h,int x,int vt);
    void check1(SDL_Rect &obj1, SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h);
    void check2(SDL_Rect &obj1,SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &obj4);
    void BulletComeBack(SDL_Rect &obj1, SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h);
    void checkUntil(SDL_Rect &obj1, SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h);
    void setuplevel();
    void freeAll(ThreateObject obj1);
    void freeeverything();
    void freeRect(SDL_Rect &rect);


private:
    int val_x = SCREEN_WIDTH;;
    int val_y = SCREEN_HEIGHT-150;

};


ThreateObject ThreateOb;
ThreateObject ThreateOb1;
ThreateObject ThreateOb2;
ThreateObject ThreateOb3;
ThreateObject ThreateOb4;
ThreateObject AmoOb;
ThreateObject AmoOb1;
ThreateObject AmoOb2;
ThreateObject AmoOb3;
ThreateObject AmoOb4;
ThreateObject Load;
int level  = 0;
int level1  = 0;
int level2  = 0;
int level3  = 0;
int level4  = 0;

void ThreateObject::startgame(SDL_Rect &obj1,SDL_Rect &obj2,int h)
{

    srand(time(NULL));
    val_x = SCREEN_WIDTH;
    val_y = SCREEN_HEIGHT;
    obj1.x = val_x;
    obj1.y = val_y - h;


    obj2.x = obj1.x - 20;
    obj2.y = obj1.y +25;

}

ThreateObject::ThreateObject()
{

    startgame(rectTH,Amorect,150);
    startgame(rectTH1,Amorect1,200);
    startgame(rectTH2,Amorect2,250);
    startgame(rectTH3,Amorect3,550);



}
void ThreateObject::setup(SDL_Rect &obj1,SDL_Rect &obj2,int h, int x,int vt)
{
   if(obj1.x < 0)
      {

       srand(time(NULL));
       obj1.x = val_x;
       obj1.y = rand()%(SCREEN_HEIGHT - HEIGHT_PLAYER-150)+ h-100;

       if(obj1.y <= 0 || obj1.y >= 600)
       {

            obj1.y = rand()%(SCREEN_HEIGHT - HEIGHT_PLAYER-50)+ x;

       }
       obj2.x = obj1.x - 20;

       obj2.y = obj1.y + 25;

       }
      else
      {


          obj1.x-= vt ;

      }

}
void ThreateObject::logic(SDL_Rect &obj1,SDL_Rect &obj2,int h,int x,int vt)
{

    if(obj2.x < 0)
   {

       obj2.x = obj1.x - 20;

   }
   else
   {
       obj2.x -= vt;

   }
   if(obj2.y >= h)
       {

              obj2.y -=1;

              obj1.y -=1;

       }
       else if(obj2.y <= x)
       {

            obj2.y +=1;

            obj1.y +=1;
       }

}
ThreateObject::~ThreateObject()
{
   free();

}
void ThreateObject:: check2(SDL_Rect &obj1,SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &obj4)
{

    bool checkp0 = checktf.CheckCollision(obj1,obj2);

    if(checkp0 == true)
    {

     endgame+=1;


     obj2.x = obj3.x - 20;
     obj2.y = obj3.y +25;

     obj4.render(obj2.x,obj2.y);
    }
    else
    {

        obj4.render(obj2.x,obj2.y);
    }

}
void ThreateObject::freeRect(SDL_Rect &rect)
{

    rect = {0,0,0,0};
}
void ThreateObject::setuplevel()
{

    bool check = checktf.CheckCollision(rectIM,rectTH);
    if(check == true)
    {

        level++;

        //std::cout<<level;

    }
    bool check1 = checktf.CheckCollision(rectIM,rectTH1);
    if(check1 == true)
    {

        level1++;

    }
    bool check2 = checktf.CheckCollision(rectIM,rectTH2);
    if(check == true)
    {

        level2++;

    }
    bool check3 = checktf.CheckCollision(rectIM,rectTH3);
    if(check3 == true)
    {

        level3++;

    }
    bool check4 = checktf.CheckCollision(rectIM,rectTH4);
    if(check4 == true)
    {

        level4++;

    }

}
void ThreateObject:: check1(SDL_Rect &obj1, SDL_Rect &obj2, SDL_Rect &obj3 , ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h)
{
      setuplevel();



      if(score >= 20)

      {

          if(level == 2 || level1 == 2 || level2 == 2 || level3 == 2 || level4 == 2 )

      {

      SDL_Delay(50);
      Load.render(obj1.x,obj2.y-30);
      Load.LoadMusic("Bomb1.wav");

    srand(time(NULL));
      obj1.x = val_x;
      obj1.y = rand()%(SCREEN_HEIGHT - HEIGHT_PLAYER-150)+h;

      obj2.x = obj1.x - 20;
      obj2.y = obj1.y + 25;
      th1.loadFromFile("af1plus.png");
      th1.render(obj1.x,obj1.y);

      level = 0;
      level1 = 0;
      level2 = 0;
      level3 = 0;
      level4 = 0;
      }

      }
      else
      {
          score+=10;
      Load.LoadMusic("Bomb1.wav");

      Load.render(obj1.x,obj2.y-30);
      srand(time(NULL));
      obj1.x = val_x;
      obj1.y = rand()%(SCREEN_HEIGHT - HEIGHT_PLAYER-150)+h;

      obj2.x = obj1.x - 20;
      obj2.y = obj1.y + 25;



      th1.render(obj1.x,obj1.y);

      }




}
void ThreateObject::checkUntil(SDL_Rect &obj1, SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h)
{
    bool check = checktf.CheckCollision(obj3,obj1);
    if(check == false)
    {

      score+=10;
      Load.render(obj1.x,obj2.y-30);

      SDL_Delay(50);

      Load.LoadMusic("Bomb1.wav");

      srand(time(NULL));
      obj1.x = val_x;
      obj1.y = rand()%(SCREEN_HEIGHT - HEIGHT_PLAYER-150)+h;

      obj2.x = obj1.x - 20;
      obj2.y = obj1.y + 25;


    }
    else
    {

      th1.render(obj1.x,obj1.y);

    }
}
void ThreateObject::BulletComeBack(SDL_Rect &obj1, SDL_Rect &obj2,SDL_Rect &obj3,ThreateObject &th1,ThreateObject &amo,SDL_Rect &obj4,int h)
{
     bool check = checktf.CheckCollision(obj3,obj1);
   if(check == true)
   {

       check1(obj1,obj2,obj3,th1,amo,obj4,h);
       obj3.x = getrect.x + 60;
       obj3.y = getrect.y + 40;

   }

   else
   {

       th1.render(obj1.x,obj1.y);
   }

}
void ThreateObject::freeAll(ThreateObject obj1)
{

    obj1.free();
}

void ThreateObject::constructor()
{

  setup(rectTH,Amorect,50,100,4);
  setup(rectTH1,Amorect1,260,150,6);
  setup(rectTH2,Amorect2,200,100,3);
  setup(rectTH3,Amorect3,80,200,5);

//.............................................................................................................

 if(score >= 50 )
 {
     setup(rectTH4,Amorect4,60 ,150 ,5);
     logic(rectTH4,Amorect4,380,100,8);
     BulletComeBack(rectTH4,Amorect4,rectIM ,ThreateOb4,AmoOb4,rect1,60);
     check2(getrect,Amorect4,rectTH4,AmoOb4);
 }


//..................................................................................................................

  logic(rectTH,Amorect,300,50,9);
  logic(rectTH1,Amorect1,300,100,10);
  logic(rectTH2,Amorect2,250,50,11);
  logic(rectTH3,Amorect3,200,50,12);



//.........................................................................................
   BulletComeBack(rectTH,Amorect ,rectIM ,ThreateOb,AmoOb,rect1,150);
   BulletComeBack(rectTH1,Amorect1,rectIM ,ThreateOb1,AmoOb1,rect1,100);
   BulletComeBack(rectTH2,Amorect2,rectIM ,ThreateOb2,AmoOb2,rect1,200);
   BulletComeBack(rectTH3,Amorect3,rectIM ,ThreateOb3,AmoOb3,rect1,250);

   /*checkUntil(rectTH,Amorect,RectUntil ,ThreateOb,AmoOb,rect1,150);
   checkUntil(rectTH1,Amorect1,RectUntil ,ThreateOb1,AmoOb1,rect1,200);
   checkUntil(rectTH2,Amorect2,RectUntil ,ThreateOb2,AmoOb2,rect1,300);
   checkUntil(rectTH3,Amorect3,RectUntil ,ThreateOb3,AmoOb3,rect1,250);

*/
//..........................................................................................

    check2(getrect,Amorect,rectTH,AmoOb);
    check2(getrect,Amorect1,rectTH1,AmoOb1);
    check2(getrect,Amorect2,rectTH2,AmoOb2);
    check2(getrect,Amorect3,rectTH3,AmoOb3);
//..........................................................................................




}
void ThreateObject::freeeverything()
{

     if(endgame == 5)
    {

        freeAll(ThreateOb);
        freeAll(ThreateOb1);
        freeAll(ThreateOb2);
        freeAll(ThreateOb3);
        freeAll(ThreateOb4);
        freeAll(AmoOb);
        freeAll(AmoOb1);
        freeAll(AmoOb2);
        freeAll(AmoOb3);
        freeAll(AmoOb4);
        freeRect(rectIM);
        freeRect(rectTD);
        freeRect(rectTH);
        freeRect(rectTH1);
        freeRect(rectTH2);
        freeRect(rectTH3);
        freeRect(rectTH4);
        freeRect(Amorect);
        freeRect(Amorect1);
        freeRect(Amorect2);
        freeRect(Amorect3);
        freeRect(Amorect4);

        gDotTexture.free();
        LbuttonAmo.free();
        LoadMau.free();
        gDotTexture.free();
        LoadMixer.free();






    }

}


void ThreateObject::loadIMThreate()
{


    ThreateOb.loadFromFile("af1.png");
    ThreateOb1.loadFromFile("af1.png");
    ThreateOb2.loadFromFile("af1.png");
    ThreateOb3.loadFromFile("af1.png");
    ThreateOb4.loadFromFile("af1.png");
    AmoOb.loadFromFile("sphere2.png");
    AmoOb1.loadFromFile("sphere2.png");
    AmoOb2.loadFromFile("sphere2.png");
    AmoOb3.loadFromFile("sphere2.png");
    AmoOb4.loadFromFile("sphere2.png");
    Load.loadFromFile("no.png");

}








#endif // THREATEOBJECT_H_INCLUDED
