#include "object.hh"
MCUFRIEND_kbv tft;

Object::Object(){
    this->lives = 3;
    this->id = id;
    this->x = x;
    this->y = y;
    this->height_hero = height_hero;
    this->width_hero = width_hero;
    //proba weapon2
    this->weapon_x = weapon_x;
    this->weapon_y = weapon_y;
    this->direct = direct;    
//    this.color = color;
}
  Object::Object(int id, int x, int y, int height_hero, int width_hero){
    this->lives = 3;
    this->id =id;
    this->x = x;
    this->y = y;
    this->height_hero = height_hero;
    this->width_hero = width_hero;
//    this->direct = 'u';
    this->direct = direct;
//    this->weapon_x = height_hero;
//    this->weapon_y = width_hero;

  }

  int Object::get_lives(){
    return this->lives;
  }
  
  int Object::get_id(){
    return this->id;
  }

  int Object::get_x(){
    return this->x;
  }
  int Object::get_y(){
   return this->y;
  }
  
  int Object::get_height_hero(){
    return this->height_hero;
  }
  int Object::get_width_hero(){
    return this->width_hero;
  }

  int Object::get_direct(){
    return this->direct;
  }

  void Object::set_lives(int lives){
    this->lives = lives;
  }
  void Object::set_x(int x){
    this->x = x;
  }

  void Object::set_y(int y){
    this->y = y;
  }

  void Object::set_height_hero(int new_height){
    this->height_hero = new_height;
  }

  void Object::set_width_hero(int new_width){
    this->width_hero = new_width;
  }

  void Object::set_direct(int new_direct){
    this->direct = new_direct;
  }

//  void Object::make_brick(int counter_x, int counter_y, int boxW, int boxH, char color){
//    //see type for RED (colors) -> change char color to the right color
//    if (color == 'r'){
//        tft.fillRect(counter_x,counter_y,boxW,boxH,RED);  
//    }
//    
//  }
    
  void Object::make_hero(){
//    tft.fillRect(this->x,this->y,this->height_hero,this->width_hero,BLUE);
  tft.fillRect(this->x,this->y,this->height_hero,this->width_hero,BLUE);
  }
  
  void Object::delete_hero(){
    tft.fillRect(this->x,this->y,this->height_hero,this->width_hero,BLACK);
  }

//  Object Object::get_others_cords(Object &other){
//    Serial.print(other.get_x());
//    Serial.print(" , ");
//    Serial.println(other.get_y());
//    return other;
//    
//  }

//void compare_cords(int ){
  
//}

    bool Object::check_borders(/*Object & object,*/ int object_x, int object_y_up, int object_y_down){
        bool flag = true;
        if (object_x >= 175 && object_x <=277){
            if (object_y_up >=32 &&object_y_up<=32+30){
            flag = false;  
            }
            //obj_y_1 down obj_y_2 up
            else if ((object_y_down >=128 &&object_y_up<=160+30)/* || ( object_y_2 >=128 &&object_y_2<=160+30 )*/){
              flag = false;
            }
            else if (object_y_down >=256 &&object_y_down<=256+30){
              flag = false;
            }
        }
        return flag;
        
    }

    bool Object::borders_Y(/*Object & object,*/ int object_x_r, int object_x_l, int object_y){
      bool flag = true;
      if (object_x_r >= 175 && object_x_l <=277+30) {
        if (object_y >=32 &&object_y<=32+30){
          flag = false;
        }
        else if (object_y >=128 &&object_y<=160+30){
          flag = false;
        }
        else if (object_y >=256 &&object_y<=256+30){
          flag = false;
        }
      }
      return flag;
    }

   void Object::hero_move_right(){
    int object_x = this->x+ this->width_hero + 15;
    int object_y_up = this->y;
    int object_y_down = this->y+this->width_hero+15;
    
    if (object_x >= WIDTH-30){
      Serial.println("Hitting right");
    }
    else if (check_borders(object_x, object_y_up,object_y_down) ==  false)
    {
      Serial.println("Hitting forbiden right spaces");
    }
    else{
      delete_hero();
    delete_weapon();
    set_x(this->x+5);
   make_hero();
     make_weapon_right();
    }

//this->weapon_x+15 < 480-30?
    
  }
   void Object::hero_move_left(){
    int object_x = this->x-10-5-30;
//    int object_x_r = this->x
//     int object_x = this->x -(20); 
     int object_y_up = this->y;
     int object_y_down = this->y+this->width_hero;
    //depends on size of object
    if (object_x < 30 ){
    Serial.println("Hitting left");
    }
    else if (check_borders(object_x, object_y_up,object_y_down) ==  false){
       Serial.println("Hitting forbidden left");    
    }
    else{
      delete_hero();
    delete_weapon();
//    delay(100);
    set_x(this->x-5);
    make_hero();
    make_weapon_left();
//  delete_weapon(this->weapon_x, this->weapon_y);
      
    }

    
//    if (this->x > 30 && this->weapon_x > 30  ){ }
    
  }
  void Object::hero_move_up(){
    int object_x_l = this->x;
    int object_x_r = this->x+ this->width_hero;//not sure
    int object_y = this->y-17;
//int object_y = this->y;
if (object_y <= 30 /*&& this->weapon_y > 30 */ ){
  Serial.println("Hitting up");
  } 
  else if(borders_Y(object_x_r, object_x_l, object_y)== false)
    {
      Serial.println("Hitting forbidden up");
    }
 else{
    delete_hero();
    delete_weapon();
    set_y(this->y-5);
    make_hero();
    make_weapon_up();
 }
  
}
    
  void Object::hero_move_down(){
   int object_x_l = this->x;//not sure
      int object_x_r = this->x+ this->width_hero;//not sure
    int object_y = this->y+ this->height_hero + 15;
    if ( object_y > HEIGHT-30){
         Serial.println("Hitting up");
    }
   else if (borders_Y(object_x_r, object_x_l, object_y)== false)
    {
      Serial.println("Hitting down");
    }
    else{
    delete_hero();
    delete_weapon();
    set_y(this->y+5);
    make_hero();
    make_weapon_down();
 
    }
  }

  void Object::make_weapon_right(){
    //set_weapon_x(width  +/-);
    this->weapon_x = this->x + this->width_hero;
    this->weapon_y  = this->y;
    this->direct  = 1; 
    tft.fillRect(this->weapon_x, this->weapon_y,10,10,GREEN);
  }
  void Object::make_weapon_left(){
    this->weapon_x = this->x -10;
    this->weapon_y  = this->y;
    this->direct  = 2;
    tft.fillRect(this->weapon_x,this->weapon_y ,10,10,GREEN);
  }
  //
  void Object::make_weapon_up(){
    this->weapon_y = this->y - 10;
    this->weapon_x  = this->x; 
    this->direct  = 3;
    tft.fillRect(this->weapon_x,this->weapon_y,10,10,GREEN);
  }
  void Object::make_weapon_down(){
    this->weapon_y = this->y  + this->width_hero;
    this->weapon_x  = this->x; 
    this->direct  = 4;
    tft.fillRect(this->weapon_x,this->weapon_y,10,10,GREEN);
  }
    void Object::delete_weapon(){
      tft.fillRect(this->weapon_x,this->weapon_y,10,10,BLACK);
  }

    bool Object::bullet_right(Object &other){
      bool flag = true;
     char dir = this->direct;
     Serial.print("this is the direction ");
     Serial.print(dir);
//  
      switch(dir){
        case 1:
        Serial.println("this is right");
        for (int i = 0; i <5; i ++){
        int next_bullet = this->weapon_x + 10 + (i * 30);
        if(this->weapon_x<other.get_x()
        &&((next_bullet+30 >= other.get_x() && next_bullet+30<=other.get_x()+20) ||
          (next_bullet >= other.get_x() && next_bullet <=other.get_x()+20))
        &&(this->weapon_y >= other.get_y()-5 && this->weapon_y <=other.get_y()+20))
        {        
          //fix issue where it doesnt allays puts purple and overrides the shots
          tft.fillRect(next_bullet,this->weapon_y, 30,5, PURPLE);
          delay(500);
          tft.fillRect(next_bullet,this->weapon_y, 30,5, BLACK);
          other.set_lives(other.get_lives()-1);
          flag = false; 
          break;
  
          }
        else{
          tft.fillRect(next_bullet,this->weapon_y, 30,5, OLIVE);
        delay(100);
        tft.fillRect(next_bullet,this->weapon_y, 30,5, BLACK);
        }
        }
        break;
        case 2:
        Serial.println("this is left");
        for (int i =  1; i <6; i ++){
          int next_bullet = this->weapon_x + (-i*30);
          //use the function for geting width;
          if( (this->weapon_x >other.get_x()+20) //checks if weapon is behind the enemy 
          &&(//checks whether the start is in the enemy
            (next_bullet <= other.get_x()+20 && next_bullet >= other.get_x())|| 
             //checks whether the end is in the enemy
            ( next_bullet+30 >= other.get_x() && next_bullet +30 <= other.get_x()+20)) 
           && (//checks whether the enemy is near the same y cords 
            this->weapon_y >= other.get_y()-5 && this->weapon_y <=other.get_y()+20)){
            tft.fillRect(next_bullet ,this->weapon_y, 30,5, PURPLE);
            delay(1000);
            tft.fillRect(next_bullet ,this->weapon_y, 30,5, BLACK);
            other.set_lives(other.get_lives()-1);
            flag = false;
            break;          
          }
          else{
            tft.fillRect(next_bullet ,this->weapon_y, 30,5, OLIVE);
            delay(100);
            tft.fillRect(next_bullet,this->weapon_y, 30,5, BLACK);
          
          }
        } 
        break;
        //not done
        case 3:Serial.println("up");
        for (int i =  1; i <5; i ++){
          int next_bullet = this->weapon_y + (-i * 30);
          if ( (this->weapon_y > other.get_y()+20) && 
          ((next_bullet <= other.get_y()+20 && next_bullet >=other.get_y())|| 
            //(next_bullet>other.get_y() && next_bullet+30 <other.get_y()+20)|| not sure why it doesnt work
            (next_bullet+30 >= other.get_y() &&next_bullet + 30 <= other.get_y()+20))&&
          (this->weapon_x>=other.get_x()-5 && this->weapon_x <=other.get_x()+20)){
            tft.fillRect(this->weapon_x,next_bullet, 5,30, PURPLE);
            delay(1000);
            tft.fillRect(this->weapon_x,next_bullet, 5,30, BLACK);
            other.set_lives(other.get_lives()-1);
            flag = false;
            break;
          }
          else{
            tft.fillRect(this->weapon_x,next_bullet, 5,30, OLIVE);
        delay(100);
        tft.fillRect(this->weapon_x,next_bullet, 5,30, BLACK);
          } 
      }    
        break;
        
        case 4:Serial.println("this is down"); 
        for (int i =  0; i <4; i ++){
          int next_bullet = this->weapon_y + 10  + (i * 30);
          if ((next_bullet >= other.get_y())&&
            ((next_bullet+30 >= other.get_y() &&next_bullet+30 <= other.get_y()+20)||//sth is not right here
            (next_bullet >= other.get_y() && next_bullet <= other.get_y()+20))
            &&(this->weapon_x >= other.get_x()-5 && this->weapon_x <= other.get_x() +20)){
              tft.fillRect(this->weapon_x,next_bullet, 5,30, PURPLE);
              delay(100);
              tft.fillRect(next_bullet,this->weapon_y, 30,5, BLACK);
              other.set_lives(other.get_lives()-1);
              
              flag = false;
              break;
            }
          
//        tft.fillRect(this->weapon_x,this->weapon_y+ 10 + (i * 30), 30,5, OLIVE);
        tft.fillRect(this->weapon_x,next_bullet, 5,30, OLIVE);
        delay(100);
        
      tft.fillRect(this->weapon_x,next_bullet, 5,30, BLACK);
      }    break;
        
        default:Serial.println("none");break;
      }
      
      return flag;
    }
  
