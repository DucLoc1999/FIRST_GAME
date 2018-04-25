#include "ComonFunction.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

class LTexture : public BaseObject
{
public:
enum AmoType
{
 NONE,
 LASER,
 SPHERE
};

AmoObject();
~AmoObject();

void HandleInputAction(SDL_Event events, SDL_Rect rect_obj);
void HandleMove(const int x_boder, const int y_border);
unsigned int get_type() const {return amo_type_;}

private:
int x_val_;
int y_val_;
bool is_move_;
unsigned int amo_type_;
};
