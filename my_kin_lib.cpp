#include "my_kin_lib.h"
#include <Adafruit_PWMServoDriver.h>

#define L1 40
#define L2 100
#define L3 100
#define MAX_GAMMA 50

#define default0  525 // + вперед - назад // пп колено
#define default1  130 // + вперед - назад // пп вперед-назад
#define default2  320 // + вверх  - вниз // пп бедро

#define default3  120 // + назад  - вперед // пл колено
#define default4  330 // + назад  - вперед // пл вперед-назад
#define default5  260 // + вверх  - вниз // пл бедро

#define default6  550 // + вперед - назад // зп колено
#define default7  92 // + вперед - назад // зп вперед-назад
#define default8  340 // - вверх  + вниз // зп бедро

#define default9 1 // + назад  - вперед // зл колено
#define default10 470 // + назад  - вперед // зл вперед-назад
#define default11 230 // + вверх  - вниз // зл бедро



// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ СТОЯ
void stand_stationary(Adafruit_PWMServoDriver pwm)
{
    pwm.setPWM(0, 0, default0-200); // Передняя правая
    pwm.setPWM(1, 0, default1+100);
    pwm.setPWM(2, 0, default2);

    pwm.setPWM(3, 0, default3+150); // Передняя левая
    pwm.setPWM(4, 0, default4-100);
    pwm.setPWM(5, 0, default5);

    pwm.setPWM(6, 0, default6-200); // Задняя правая
    pwm.setPWM(7, 0, default7+100);
    pwm.setPWM(8, 0, default8);

    pwm.setPWM(9, 0, default9+200); // Задняя левая
    pwm.setPWM(10, 0, default10-100);
    pwm.setPWM(11, 0, default11);
}


// МЕТОД ПЕРЕХОДА ИЗ ПОЛОЖЕНИЯ СИДЯ В ПОЛОЖЕНИЕ СТОЯ
void stand_up_from_down(Adafruit_PWMServoDriver pwm) 
{
  for (int i = 0; i < 100; i++)
    {
      pwm.setPWM(0, 0, default0-i*2); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      pwm.setPWM(2, 0, default2);
  
      pwm.setPWM(3, 0, default3+i*1.5); // Передняя левая
      pwm.setPWM(4, 0, default4-i);
      pwm.setPWM(5, 0, default5);
  
      pwm.setPWM(6, 0, default6-i*2); // Задняя правая
      pwm.setPWM(7, 0, default7+i);
      pwm.setPWM(8, 0, default8);
  
      pwm.setPWM(9, 0, default9+i*2); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(11, 0, default11);
      delay(10);
    }

   stand_stationary(pwm);
}


// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ СИДЯ
void sit_stationary(Adafruit_PWMServoDriver pwm)
{
    pwm.setPWM(0, 0, default0); // Передняя правая
    pwm.setPWM(1, 0, default1);
    pwm.setPWM(2, 0, default2);

    pwm.setPWM(3, 0, default3); // Передняя левая
    pwm.setPWM(4, 0, default4);
    pwm.setPWM(5, 0, default5);

    pwm.setPWM(6, 0, default6); // Задняя правая
    pwm.setPWM(7, 0, default7);
    pwm.setPWM(8, 0, default8);

    pwm.setPWM(9, 0, default9); // Задняя левая
    pwm.setPWM(10, 0, default10);
    pwm.setPWM(11, 0, default11);
}


// МЕТОД ПРИСЕДАНИЯ ИЗ ПОЛОЖЕНИЯ СТОЯ
void sit_down_from_stationary(Adafruit_PWMServoDriver pwm) 
{
  for (int i = 100; i > 0; i--)
    {
      pwm.setPWM(0, 0, default0-i*2); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      pwm.setPWM(2, 0, default2);
  
      pwm.setPWM(3, 0, default3+i*1.5); // Передняя левая
      pwm.setPWM(4, 0, default4-i);
      pwm.setPWM(5, 0, default5);
  
      pwm.setPWM(6, 0, default6-i*2); // Задняя правая
      pwm.setPWM(7, 0, default7+i);
      pwm.setPWM(8, 0, default8);
  
      pwm.setPWM(9, 0, default9+i*2); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(11, 0, default11);
      delay(10);
    }
  
    sit_stationary(pwm);
}


// НАКЛОН ВПРАВО
void tilt_right(Adafruit_PWMServoDriver pwm)
{
  for (int i = 0; i < 40; i++)
    {
      pwm.setPWM(2, 0, default2+i); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      
      pwm.setPWM(5, 0, default5+i); // Передняя левая
      pwm.setPWM(3, 0, default3+i);
      
      pwm.setPWM(8, 0, default8-i/2); // Задняя правая
      pwm.setPWM(7, 0, default7+i);  
      
      pwm.setPWM(11, 0, default11-i); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(9, 0, default9+i);
      
      delay(10);
    }
    tilt_right_stationary(pwm);
}

// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ НАКЛОНА ВПРАВО
void tilt_right_stationary(Adafruit_PWMServoDriver pwm)
{
      pwm.setPWM(2, 0, default2+40); // Передняя правая
      pwm.setPWM(1, 0, default1+40);
      
      pwm.setPWM(5, 0, default5+40); // Передняя левая
      pwm.setPWM(3, 0, default3+40);
      
      pwm.setPWM(8, 0, default8-20); // Задняя правая
      pwm.setPWM(7, 0, default7+40);  
      
      pwm.setPWM(11, 0, default11-40); // Задняя левая
      pwm.setPWM(10, 0, default10-40);
      pwm.setPWM(9, 0, default9+40);
}


// ВОЗВРАЩЕНИЕ ИЗ НАКЛОНА ВПРАВО
void sit_stationary_from_tilt_right(Adafruit_PWMServoDriver pwm)
{
  for (int i = 40; i > 0; i--)
    {
      pwm.setPWM(2, 0, default2+i); // Передняя правая
      pwm.setPWM(1, 0, default1+i);
      
      pwm.setPWM(5, 0, default5+i); // Передняя левая
      pwm.setPWM(3, 0, default3+i);
      
      pwm.setPWM(8, 0, default8-i/2); // Задняя правя
      pwm.setPWM(7, 0, default7+i);  
      
      pwm.setPWM(11, 0, default11-i); // Задняя левая
      pwm.setPWM(10, 0, default10-i);
      pwm.setPWM(9, 0, default9+i); 
      
      delay(10);
    }
  sit_stationary(pwm);
}


// НАКЛОН ВЛЕВО
void tilt_left(Adafruit_PWMServoDriver pwm)
{
  for (int i = 0; i < 40; i++)
    {
      pwm.setPWM(0, 0, default0-i); // Передняя правая
      pwm.setPWM(2, 0, default2-i); 
      
      pwm.setPWM(4, 0, default4-i); // Передняя левая
      pwm.setPWM(5, 0, default5-i); 
      
      pwm.setPWM(6, 0, default6-i); // Задняя правая
      pwm.setPWM(7, 0, default7+i); 
      pwm.setPWM(8, 0, default8+i); 
      
      pwm.setPWM(10, 0, default10-i); // Задняя левая
      pwm.setPWM(11, 0, default11+i);
      delay(10);
    }
    tilt_left_stationary(pwm);
}


// СТАЦИОНАРНОЕ ПОЛОЖЕНИЕ НАКЛОНА ВЛЕВО
void tilt_left_stationary(Adafruit_PWMServoDriver pwm)
{
      pwm.setPWM(0, 0, default0-40); // Передняя правая
      pwm.setPWM(2, 0, default2-40); 
      
      pwm.setPWM(4, 0, default4-40); // Передняя левая
      pwm.setPWM(5, 0, default5-40); 
      
      pwm.setPWM(6, 0, default6-40); // Задняя правая
      pwm.setPWM(7, 0, default7+40); 
      pwm.setPWM(8, 0, default8+40); 
      
      pwm.setPWM(10, 0, default10-40); // Задняя левая
      pwm.setPWM(11, 0, default11+40);
}


// ВОЗВРАЩЕНИЕ ИЗ НАКЛОНА ВЛЕВО
void sit_stationary_from_tilt_left(Adafruit_PWMServoDriver pwm)
{
  for (int i = 40; i > 0; i--)
    {
      pwm.setPWM(0, 0, default0-i); // Передняя правая
      pwm.setPWM(2, 0, default2-i); 
      
      pwm.setPWM(4, 0, default4-i); // Передняя левая
      pwm.setPWM(5, 0, default5-i); 
      
      pwm.setPWM(6, 0, default6-i); // Задняя правая
      pwm.setPWM(7, 0, default7+i); 
      pwm.setPWM(8, 0, default8+i); 
      
      pwm.setPWM(10, 0, default10-i); // Задняя левая
      pwm.setPWM(11, 0, default11+i);
      delay(10);
    }
  sit_stationary(pwm);
}
