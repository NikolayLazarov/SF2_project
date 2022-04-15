//Main_code -> make weapon shoot into 4 directions -> 04.04.2022

#include "object.hh"
#include "Weapon.hh"
//MCUFRIEND_kbv tft;

#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

//Colours
#
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF

#define CYAN 0x07FF

#define MAGENTA 0xF81F
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
//#define PINK 0xF81F

//#define WIDTH 480
//#define HEIGHT 320
//
class Brick{
private:
//  int id;
//  int x;
//  int y;
  int brick_width;
  int brick_height;
  uint16_t color; 
//  Brick(int id,int x,int y,int brick_width,int brick_height){
//Brick(){
////  this->id = id;
////  this->x = x;
////  this->y = y;
//  this->brick_width = brick_width;
//  this->brick_height = brick_height;  
//  this->color = color;
//  }

public:
Brick(int brick_width,int brick_height, uint16_t color){
//  this->id = id;
//  this->x = x;
//  this->y = y;
  this->brick_width = brick_width;
  this->brick_height = brick_height;  
  this->color = color;
  }
  
//Brick(int x,int y,int brick_width,int brick_height, char color){
////  this->id = id;
//  this->x = x;
//  this->y = y;
//  this->brick_width = brick_width;
//  this->brick_height = brick_height;  
//  this->color = color;
//  }
  void make_block(int x,int y){
     tft.fillRect(x,y,this->brick_width,this->brick_height,this->color);
    
  }
};


 char arr[10][14] = 
//    {
//     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
//     {'1','0','0','0','0','1','1','1','1','0','0','0','0','1'},
//     {'1','0','0','0','0','1','1','0','0','0','0','0','0','1'},
//     {'1','1','1','0','0','0','0','0','0','0','0','0','0','1'},
//     {'1','0','1','0','0','1','1','1','1','0','0','0','0','1'},
//     {'1','0','1','0','0','1','1','1','1','0','0','0','0','1'},
//     {'1','0','0','0','0','0','0','0','0','0','0','1','1','1'},
//     {'1','0','0','0','0','0','0','1','1','0','0','0','0','1'},
//     {'1','0','0','0','0','1','1','1','1','1','0','0','0','1'},
//     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
//   };

       {
     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
     {'1','0','0','0','0','1','1','1','1','0','0','0','0','1'},
     {'1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
     {'1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
     {'1','0','0','0','0','1','1','1','1','0','0','0','0','1'},
     {'1','0','0','0','0','1','1','1','1','0','0','0','0','1'},
     {'1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
     {'1','0','0','0','0','0','0','0','0','0','0','0','0','1'},
     {'1','0','0','0','0','1','1','1','1','0','0','0','0','1'},
     {'1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
   };

int arr_cords[10][14][5];


//  Brick brick(30,30,'r');
Brick brick(30,30, WHITE);
void make_matrix(){
  
  int len = 14;
  int hight = 10;

  //chaneged and put them in the fillRect
  int boxW = 30;
  int boxH = 30;
  int counter_x, counter_y = 0;
   
  for(int i= 0;i <hight; i++){
    
    counter_y = i * (HEIGHT/hight);
    tft.fillRect(0, counter_y,480,35,BLACK);
   for (int j  = 0;j<len;j++){
      counter_x = j *(WIDTH/14)+5;
      if (arr[i][j] == '1'){
        arr_cords[i][j][0] = 1;
        arr_cords[i][j][1] = counter_x;
        arr_cords[i][j][2] = counter_y;
        arr_cords[i][j][3] = boxW;
        arr_cords[i][j][4] = boxH;
        
        //tft.fillRect(counter_x,counter_y,boxW,boxH,RED);    
          brick.make_block(counter_x,counter_y);
      }
    }
   }
}

void print_matrix_cords(){
   for (int i = 0; i <10; i++){
    for(int j = 0; j<14; j++){
           if (arr_cords[i][j][0] == 1){
            Serial.print(arr_cords[i][j][1]);
            Serial.print(" | ");
            Serial.print(arr_cords[i][j][2]);
            Serial.print(" | ");
            Serial.print(arr_cords[i][j][3]);
            Serial.print(" | ");
            Serial.print(arr_cords[i][j][4]);
            Serial.print("\n");
        }
        else{
          Serial.print("none\n ");
          
        }
      }
   }
   delay(500);
}

//void clear_message(int x,int y, int y,const char* message)

int col[8];
void showmsgXY(int x, int y, int sz, /*const GFXfont *f,*/ const char *msg, uint16_t r)
{
int16_t x1, y1;
uint16_t wid, ht;
//tft.setFont(f);
tft.setCursor(x, y);
tft.setTextColor(r);
tft.setTextSize(sz);
tft.print(msg);
}

void showlives(int x, int y, int sz, Object p1, Object p2, uint16_t c){
  tft.setCursor(x, y);
  tft.setTextColor(c);
  tft.setTextSize(sz);
  tft.print("RED - ");
  tft.print(p1.get_lives());
  tft.print("  BLUE - ");
  tft.print(p2.get_lives());
//   tft.setTextColor(WHITE);
}


//void message_lost(int x, int y, int sz, Object p1){
void message_lost(int x, int y, int sz, const char* player,uint16_t r){
  tft.setCursor(x, y);
  tft.setTextColor(r);
  tft.setTextSize(sz);
  tft.println(player);
  tft.print(" lost!");
}

void setup() {

tft.reset();
Serial.begin(9600);
uint16_t ID = tft.readID();
tft.begin(ID);
tft.setRotation(1);
}


void loop() {

Object hero1(1,380,80,20,20,RED);
Object hero2(2,100,220,20,20,BLUE);

bool flag = true;

  //restart cords of weapon after every restart
  //also at the begginging put them near heros position
make_matrix();
//print_matrix_cords();
//Brick(){}

//Object hero1(1,380,80,20,20);
hero1.make_hero();
//hero1.make_weapon();

//Object hero2(2,100,220,20,20);
hero2.make_hero();
showlives(100, 100, 2,hero1,hero2, WHITE);
        delay(2000);
        showlives(100, 100, 2, hero1,hero2, BLACK);
      delay(500);


flag = true;
int flag2 = true;
while(flag == true){
  
  int sensorValueX1 = analogRead(A13);
  int sensorValueY1 = analogRead(A14);
  int sensorValueS1 = digitalRead(21);
  // print out the value you read:
  int sensorValueX2 = analogRead(A11);
  int sensorValueY2 = analogRead(A12);
  int sensorValueS2 = digitalRead(20);

  delay(50);

  if (sensorValueX1 >530 || sensorValueX1 < 500 || sensorValueY1 > 530 || sensorValueY1 < 500 || sensorValueS1 == 0 ){

      if(sensorValueX1 >530 ){
        hero1.hero_move_up(hero2);
         if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490 || sensorValueS2 == 0) {
    
            if(sensorValueX2 >530 ){
              hero2.hero_move_up(hero1);
            
            }
             else if(sensorValueX2 < 490 ){
              hero2.hero_move_down(hero1);
            }
            else if(sensorValueY2 > 530){
              hero2.hero_move_right(hero1);
            }
            else if(sensorValueY2 < 490){
              hero2.hero_move_left(hero1);
            }
            else if (sensorValueS2 == 0){
             flag2 =  hero2.bullet_right(hero1);
            }
                
          }
      }
       else if(sensorValueX1 < 500 ){
        hero1.hero_move_down(hero2);
        if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490  || sensorValueS2 == 0) {
              if(sensorValueX2 >530 ){
                hero2.hero_move_up(hero1);
              
              }
               else if(sensorValueX2 < 490 ){
                hero2.hero_move_down(hero1);
              }
              else if(sensorValueY2 > 530){
                hero2.hero_move_right(hero1);
              }
              else if(sensorValueY2 < 490){
                hero2.hero_move_left(hero1);
              }
              else if (sensorValueS2 == 0){
              flag2 = hero2.bullet_right(hero1);
            }
            }
      
      }
      else if(sensorValueY1 > 530){
        hero1.hero_move_right(hero2);
        if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490 || sensorValueS2 == 0) {
    
              if(sensorValueX2 >530 ){
                hero2.hero_move_up(hero1);
              
              }
               else if(sensorValueX2 < 490 ){
                hero2.hero_move_down(hero1);
              }
              else if(sensorValueY2 > 530){
                hero2.hero_move_right(hero1);
              }
              else if(sensorValueY2 < 490){
                hero2.hero_move_left(hero1);
              }
              else if (sensorValueS2 == 0){
              flag2 = hero2.bullet_right(hero1);
            }
            }
      
      }
      else if(sensorValueY1 < 500){
        hero1.hero_move_left(hero2);
           if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490 || sensorValueS2 == 0) {
    
            if(sensorValueX2 >530 ){
              hero2.hero_move_up(hero1);
            
            }
             else if(sensorValueX2 < 490 ){
              hero2.hero_move_down(hero1);
            }
            else if(sensorValueY2 > 530){
              hero2.hero_move_right(hero1);
            }
            else if(sensorValueY2 < 490){
              hero2.hero_move_left(hero1);
            }
            else if (sensorValueS2 == 0){
              flag2 = hero2.bullet_right(hero1);
            }
          }
         
      }
      
      else if (sensorValueS1 == 0){
        flag2 = hero1.bullet_right(hero2);
           if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490 || sensorValueS2 == 0) {
    
            if(sensorValueX2 >530 ){
              hero2.hero_move_up(hero1);
            
            }
             else if(sensorValueX2 < 490 ){
              hero2.hero_move_down(hero1);
            }
            else if(sensorValueY2 > 530){
              hero2.hero_move_right(hero1);
            }
            else if(sensorValueY2 < 490){
              hero2.hero_move_left(hero1);
            }
            else if (sensorValueS2 == 0){
              flag2 = hero2.bullet_right(hero1);
            }
            
          }
        }

  }
  else if (sensorValueX2> 530 || sensorValueX2 < 490 || sensorValueY2 > 530 || sensorValueY2 < 490 || sensorValueS2 == 0) {
    
    if(sensorValueX2 >530 ){
      hero2.hero_move_up(hero1);
    
    }
     else if(sensorValueX2 < 490 ){
      hero2.hero_move_down(hero1);
    }
    else if(sensorValueY2 > 530){
      hero2.hero_move_right(hero1);
    }
    else if(sensorValueY2 < 490){
      hero2.hero_move_left(hero1);
    }
    else if (sensorValueS2 == 0){
       flag2 = hero2.bullet_right(hero1);
//        continue;
      }
  }

  if (flag2 == false){
    if ( hero1.get_lives() ==0  ){
      message_lost(100, 100, 2, "RED", RED);
      delay(3000);
      flag = false;
      //it has to restart
//  delay(1500);
//   message_lost(100, 100, 2, "RED", BLACK);
    }
    else if ( hero2.get_lives() ==0  ){
      message_lost(100, 100, 2, "BLUE", BLUE);
      delay(1500);
      flag = false;
      //it should restart
//  delay(1500);
//   message_lost(100, 100, 2, "BLUE", BLACK);
    }
    else{
      delay(500 );
    hero1.delete_weapon();
    hero2.delete_weapon();
    delay(100);
    hero1.delete_hero();
    hero2.delete_hero();
    delay(500);
  showmsgXY(100, 100, 3, " A player was shot!", RED);
  delay(1500);
  showmsgXY(100, 100, 3, " A player was shot!", BLACK);

  showmsgXY(100, 100, 2, " Retart in 3...", RED);
  delay(700);
  showmsgXY(100, 100, 2, " Retart in 3...", BLACK);
  
//  tft.setTextColor(BLUE);
  showmsgXY(100, 100, 2, " Retart in 2...", RED);
  delay(700);
  showmsgXY(100, 100, 2, " Retart in 2...", BLACK);
  
  showmsgXY(100, 100, 2, " Retart in 1...",RED);
  delay(700);
  showmsgXY(100, 100, 2, " Retart in 1...",BLACK);

    make_matrix();
    hero1.restart_hero();
    hero2.restart_hero();

      showlives(100, 100, 2,hero1,hero2, WHITE);
        delay(2000);
        showlives(100, 100, 2, hero1,hero2, BLACK);
      delay(1000);
     
    flag2 = true;
    }    
  }
 }
}
  
