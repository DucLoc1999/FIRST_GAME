
#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_
#include "BaseObject.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10
#include<vector>

class AmoObject: public LTexture
{
public:


  AmoObject();

  void HandleMove(const int& x_border, const int& y_border);

  int get_type()  {return amo_type_;}
  void set_type(const int& type) {amo_type_ = type;}


  bool G;

   void renderPlus(int x,int y);

  SDL_Rect beginx(int x,int y)
  {
      rect.x = x;
      rect.y =y;
  }
 std::vector<AmoObject*> amo_list;




protected:
  int x;
  int y;
  bool is_move_;
  int amo_type_;
  SDL_Rect rect;
};

AmoObject::AmoObject()
{

    x = 0;
    y = 0;
    is_move_ = false;
    amo_type_ = 0;
}
void AmoObject::renderPlus(int x,int y)
{
    LbuttonAmo.render(x,y);

}

#endif
