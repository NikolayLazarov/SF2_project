#ifndef _OBJECT_HH_
#define _OBJECT_HH_

#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
extern MCUFRIEND_kbv tft;

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define YELLOW 0xFFE0
#define GREEN 0x07E0
#define OLIVE 0x7BE0
#define PURPLE 0x780F
#define WIDTH 480
#define HEIGHT 320

class Object{
  private:
  int lives;
  int id;
  int x;
  int y;
  int org_x;
  int org_y;
  int height_hero;
  int width_hero;


  //proba weapon2
  int weapon_x;
  int weapon_y;

  int direct;
  uint16_t color;
  public:
  Object();
  
  Object(int id, int x, int y, int height_hero, int width_hero,uint16_t color);

  int get_lives();
  int get_id();

  int get_x();
  int get_y();
  
  int get_height_hero();
  int get_width_hero();  
  int get_direct();
  uint16_t get_color();
  void set_lives(int lives);
  void set_x(int x);

  void set_y(int y);

  void set_height_hero(int new_height);

  void set_width_hero(int new_width);

  void set_direct(int new_direct);
   void set_color(uint16_t color);

//  void make_brick(int counter_x, int counter_y, int boxW, int boxH, char color);
  
  void make_hero();

  void delete_hero();
  void restart_hero();

  bool check_borders(/*Object & object,*/ int object_x, int object_up, int object_down);
  bool borders_Y(/*Object & object,*/ int object_x_r, int object_x_l, int object_y);

  bool check_for_enemy_XR(Object &other,int next_bullet); 
  bool check_for_enemy_XL(Object &other,int next_bullet);
  bool check_for_enemy_YU(Object &other,int next_bullet);
  bool check_for_enemy_YD(Object &other,int next_bullet);
   
  void hero_move_right(Object &other);
  void hero_move_left(Object &other);
  void hero_move_up(Object &other);
  void hero_move_down(Object &other);
  
  void make_weapon_right();
  void make_weapon_left();
  void make_weapon_up();
  void make_weapon_down();
  void delete_weapon();
  bool bullet_right(Object &other);

  bool overlap_enemy_R(Object &other);

//  Object get_others_cords(Object &other);
};

#endif
