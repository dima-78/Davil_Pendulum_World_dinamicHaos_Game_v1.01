// Davil_Pendulum_World_dinamicHaosGame_arduboy_v1.01
// Created by @dima-78
// 2025.01.28

#include <Arduboy2.h>
#include "Tinyfont.h"
// #include <ArduboyTones.h>
#include <ArduboyPlaytune.h>

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());
// ArduboyTones tones(arduboy.audio.enabled);
ArduboyPlaytune tunes(arduboy.audio.enabled);
BeepPin2 beep;


const byte score_[] PROGMEM = {
 2,154, 0x90,62, 0,166, 0x90,64, 0,166, 0x90,66, 0,166, 0x90,64, 0,166,
 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x90,62, 0,166, 0x90,69,
 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x91,50, 0x90,66,
 0,166, 0x91,52, 0x90,62, 0,166, 0x91,54, 0x90,69, 0,166, 0x91,52, 0,166,
 0x90,71, 0x91,55, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,55, 0x90,71,
 0,55, 0x90,73, 0,55, 0x91,50, 0x90,74, 0,166, 0x91,57, 0x90,73, 0,83,
 0x90,74, 0,83, 0x91,55, 0x90,73, 0,166, 0x91,54, 0x90,71, 0,83, 0x90,69,
 0,83, 0x91,52, 0,125, 0x80, 0,41, 0x90,73, 0x91,54, 0,166, 0x90,74, 0x91,50,
 0,166, 0x90,76, 0x91,57, 0,166, 0x90,73, 0,166, 0x91,45, 0x90,78, 0,166,
 0x90,74, 0,166, 0x91,57, 0x90,73, 0,166, 0x90,71, 0,138, 0x81, 0,27, 0x91,57,
 0x90,76, 0,166, 0x90,73, 0,166, 0x91,45, 0x90,74, 0,166, 0x90,71, 0,166,
 0x91,57, 0x90,69, 0,166, 0x90,68, 0,138, 0x81, 0,27, 0x91,57, 0x90,76, 0,166,
 0x90,73, 0,166, 0x91,45, 0x90,78, 0,166, 0x90,74, 0,166, 0x91,57, 0x90,73,
 0,166, 0x90,71, 0,138, 0x81, 0,27, 0x91,57, 0x90,76, 0,166, 0x90,73, 0,166,
 0x91,45, 0x90,74, 0,166, 0x90,71, 0,166, 0x91,57, 0x90,69, 0,166, 0x90,68,
 0,138, 0x81, 0,27, 0x91,57, 0x90,73, 0,166, 0x90,71, 0,166, 0x91,59, 0x90,74,
 0,166, 0x90,73, 0,166, 0x91,61, 0x90,71, 0,166, 0x90,69, 0,166, 0x91,62,
 0x90,78, 0,166, 0x91,61, 0,166, 0x90,68, 0x91,64, 0,166, 0x91,62, 0,166,
 0x90,69, 0x91,61, 0,166, 0x91,59, 0,166, 0x91,61, 0,27, 0x80, 0,27, 0x90,71,
 0,55, 0x90,69, 0,55, 0x91,62, 0x90,68, 0,55, 0x90,69, 0,55, 0x90,71,
 0,27, 0x80, 0,27, 0x90,71, 0x91,64, 1,77, 0x91,52, 0,166, 0x90,69, 0,166,
 0x91,57, 0x90,69, 0,166, 0x91,52, 0,166, 0x91,54, 0,166, 0x91,56, 0,166,
 0x91,57, 0x80, 0,166, 0x91,59, 0,166, 0x91,61, 0,166, 0x91,59, 0,166, 0x90,76,
 0x91,62, 0,166, 0x91,61, 0,166, 0x90,81, 0x91,59, 0,166, 0x91,57, 0,166,
 0x91,64, 0,166, 0x90,71, 0,166, 0x91,52, 0x90,73, 0,166, 0x90,75, 0,166,
 0x90,76, 0x81, 0,166, 0x90,78, 0,166, 0x90,79, 0,166, 0x90,78, 0,166, 0x91,59,
 0x90,81, 0,166, 0x90,79, 0,166, 0x91,64, 0x90,78, 0,166, 0x90,76, 0,166,
 0x90,83, 0,166, 0x91,54, 0,166, 0x90,71, 0x91,56, 0,166, 0x91,58, 0,166,
 0x91,59, 0x80, 0,166, 0x91,61, 0,166, 0x91,62, 0,166, 0x91,61, 0,166, 0x90,66,
 0x91,64, 0,166, 0x91,62, 0,166, 0x90,71, 0x91,61, 0,166, 0x91,59, 0,166,
 0x91,66, 0,166, 0x90,70, 0,166, 0x91,54, 0x90,71, 0,166, 0x90,73, 0,166,
 0x91,64, 0x90,74, 0,166, 0x90,76, 0,166, 0x91,62, 0x90,78, 0,166, 0x90,76,
 0,166, 0x91,71, 0x90,79, 0,166, 0x91,70, 0x90,78, 0,166, 0x91,71, 0x90,76,
 0,166, 0x90,74, 0,166, 0x91,61, 0x90,76, 0,166, 0x90,74, 0,166, 0x91,70,
 0x90,78, 0,166, 0x91,68, 0x90,76, 0,166, 0x91,70, 0x90,74, 0,166, 0x90,73,
 0,166, 0x91,71, 0x90,74, 0,166, 0x91,69, 0x90,73, 0,166, 0x91,67, 0x90,76,
 0,166, 0x91,66, 0x90,74, 0,166, 0x91,64, 0x90,73, 0,166, 0x91,62, 0x90,71,
 0,166, 0x91,64, 0x90,73, 0,166, 0x91,62, 0,166, 0x90,70, 0x91,66, 0,83,
 0x90,68, 0,83, 0x91,64, 0x90,70, 0,166, 0x91,62, 0x90,71, 0,166, 0x91,61,
 0,166, 0x91,62, 0,166, 0x90,73, 0x91,64, 0,138, 0x80, 0,27, 0x90,73, 0x91,66,
 0,83, 0x90,74, 0,83, 0x90,73, 0,166, 0x91,54, 0,166, 0x90,71, 0,166,
 0x91,59, 0,166, 0x90,66, 0,166, 0x91,54, 0x90,68, 0,166, 0x90,70, 0,166,
 0x91,50, 0x90,71, 0,166, 0x90,73, 0,166, 0x91,47, 0x90,74, 0,166, 0x90,73,
 0,166, 0x90,76, 0,166, 0x90,74, 0,166, 0x90,73, 0x81, 0,166, 0x90,71, 0,166,
 0x90,79, 0,166, 0x91,47, 0,166, 0x91,49, 0,166, 0x91,51, 0,166, 0x91,52,
 0,166, 0x91,54, 0,166, 0x91,55, 0,166, 0x91,54, 0,166, 0x91,57, 0,166,
 0x91,55, 0,166, 0x91,54, 0,166, 0x91,52, 0,166, 0x91,57, 0,138, 0x80, 0,27,
 0x90,64, 0,166, 0x90,66, 0,166, 0x90,68, 0,166, 0x90,69, 0,166, 0x90,71,
 0,166, 0x90,73, 0,166, 0x90,71, 0,166, 0x90,74, 0,166, 0x90,73, 0,166,
 0x90,71, 0,166, 0x90,69, 0,166, 0x90,78, 0,138, 0x81, 0,27, 0x91,45, 0,166,
 0x91,47, 0,166, 0x91,49, 0,166, 0x91,50, 0,166, 0x91,52, 0,166, 0x91,54,
 0,166, 0x91,52, 0,166, 0x91,55, 0,166, 0x91,54, 0,166, 0x91,52, 0,166,
 0x91,50, 0,166, 0x91,56, 0,138, 0x80, 0,27, 0x90,71, 0,166, 0x90,76, 0,166,
 0x91,52, 0x90,74, 0,166, 0x91,54, 0x90,73, 0,166, 0x91,56, 0x90,71, 0,166,
 0x91,57, 0x90,73, 0,166, 0x91,56, 0x90,71, 0,166, 0x91,54, 0x90,74, 0,166,
 0x91,52, 0x90,73, 0,166, 0x91,50, 0x90,71, 0,166, 0x91,54, 0x90,69, 0,166,
 0x91,52, 0x90,68, 0,83, 0x90,69, 0,83, 0x91,50, 0x90,68, 0,166, 0x91,49,
 0x90,64, 0,166, 0x91,47, 0,166, 0x90,69, 0x91,49, 0,166, 0x90,71, 0x91,45,
 0,166, 0x90,73, 0x91,57, 0,166, 0x90,71, 0,166, 0x91,54, 0x90,74, 0,166,
 0x90,73, 0,166, 0x91,49, 0x90,71, 0,166, 0x90,69, 0,166, 0x91,50, 0x90,78,
 0,166, 0x91,49, 0,166, 0x91,52, 0,166, 0x90,68, 0x91,50, 0,166, 0x90,69,
 0x91,49, 0,166, 0x90,68, 0x91,47, 0,166, 0x90,69, 0x91,49, 0,166, 0x90,74,
 0x91,50, 0,166, 0x90,71, 0x91,52, 1,77, 0x91,40, 0,166, 0x90,69, 0,138,
 0x80, 0,27, 0x90,69, 0x91,45, 0,166, 0x91,49, 0,166, 0x91,50, 0,166, 0x90,73,
 0x91,52, 0,166, 0x90,74, 0x91,54, 0,166, 0x90,76, 0x91,55, 0,166, 0x90,66,
 0x91,57, 0,166, 0x91,55, 0,166, 0x90,67, 0x91,59, 0,166, 0x91,57, 0,166,
 0x90,71, 0x91,55, 0,83, 0x90,69, 0,83, 0x91,54, 0x90,67, 0,83, 0x90,69,
 0,83, 0x91,55, 0x90,71, 0,166, 0x91,54, 0,166, 0x90,74, 0x91,57, 0,83,
 0x90,73, 0,83, 0x91,55, 0x90,71, 0,83, 0x90,73, 0,83, 0x91,54, 0x90,74,
 0,166, 0x91,52, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,166, 0x90,76,
 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x90,73, 0x91,52, 0,166, 0x90,74,
 0x91,50, 0,166, 0x90,76, 0x91,57, 0,166, 0x90,74, 0,166, 0x91,45, 0x90,73,
 0,166, 0x90,71, 0,166, 0x90,69, 0x81, 0,166, 0x90,67, 0,166, 0x90,66, 0,166,
 0x90,64, 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166, 0x90,62,
 0,166, 0x90,69, 0,166, 0x90,67, 0,166, 0x90,66, 0,166, 0x90,64, 0,166,
 0x91,50, 0x90,66, 0,166, 0x91,52, 0x90,62, 0,166, 0x91,54, 0x90,69, 0,166,
 0x91,52, 0,166, 0x90,71, 0x91,55, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,52,
 0,55, 0x90,71, 0,55, 0x90,73, 0,55, 0x91,50, 0x90,74, 0,166, 0x91,57,
 0x90,73, 0,83, 0x90,74, 0,83, 0x91,55, 0x90,73, 0,166, 0x91,54, 0x90,71,
 0,83, 0x90,69, 0,83, 0x91,52, 0,125, 0x80, 0,41, 0x90,74, 0x91,54, 0,166,
 0x91,50, 0,138, 0x80, 0,27, 0x90,74, 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62,
 0x91,59, 0,166, 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x91,52, 0,138,
 0x80, 0,27, 0x90,74, 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62, 0x91,55, 0,166,
 0x91,52, 0,166, 0x90,74, 0x91,50, 0,166, 0x91,49, 0,138, 0x80, 0,27, 0x90,74,
 0x91,57, 0,166, 0x91,54, 0,166, 0x90,62, 0x91,59, 0,166, 0x91,55, 0,166,
 0x90,74, 0x91,54, 0,166, 0x91,52, 0,138, 0x80, 0,27, 0x90,74, 0x91,57, 0,166,
 0x91,54, 0,166, 0x90,62, 0x91,55, 0,166, 0x91,52, 0,166, 0x90,74, 0x91,50,
 0,166, 0x90,76, 0x91,49, 0,166, 0x90,78, 0x91,50, 0,166, 0x90,76, 0,166,
 0x91,52, 0x90,79, 0,166, 0x90,78, 0,166, 0x91,54, 0x90,76, 0,166, 0x90,74,
 0,166, 0x91,55, 0x90,83, 0,166, 0x91,54, 0,166, 0x90,73, 0x91,57, 0,166,
 0x91,55, 0,166, 0x90,74, 0x91,54, 0,166, 0x91,52, 0,166, 0x91,54, 0,27,
 0x80, 0,27, 0x90,76, 0,55, 0x90,74, 0,55, 0x91,55, 0x90,73, 0,55, 0x90,74,
 0,55, 0x90,76, 0,41, 0x80, 0,13, 0x90,76, 0x91,57, 1,77, 0x91,45, 0,166,
 0x90,74, 0,138, 0x80, 0,27, 0x90,74, 0x91,47, 0,166, 0x91,45, 0,166, 0x90,62,
 0x91,48, 0,166, 0x91,47, 0,166, 0x90,67, 0x91,45, 0,166, 0x91,43, 0,166,
 0x91,50, 0,166, 0x90,57, 0,166, 0x90,59, 0,166, 0x90,61, 0,166, 0x90,62,
 0,166, 0x90,64, 0,166, 0x90,66, 0,138, 0x81, 0,27, 0x91,49, 0x90,64, 0,166,
 0x91,47, 0x90,67, 0,166, 0x91,45, 0x90,66, 0,166, 0x91,43, 0x90,64, 0,166,
 0x91,42, 0x90,62, 0,166, 0x91,43, 0x90,71, 0,166, 0x91,42, 0,166, 0x91,45,
 0,166, 0x90,61, 0x91,43, 0,166, 0x90,62, 0x91,42, 0,166, 0x90,61, 0x91,40,
 0,166, 0x90,62, 0x91,42, 0,166, 0x90,67, 0x91,43, 0,166, 0x90,64, 0x91,45,
 1,244, 0x90,62, 0,138, 0x80, 0,27, 0x90,62, 0x91,38, 7,208, 0x80, 0x81,
 0xf0
};

bool playSound = true;  // флаг звука
bool soundPlayed = false; // флаг звука в крайних положениях маятника

char allLetters[101];

// маятник
float angle1 = PI / 2;
float angle2 = PI / 2;
float length1 = 32;
float length2 = 32;
float mass1 = 1.0;
float mass2 = 1.0;
float angularVel1 = 0;
float angularVel2 = 0;
float g = 0.5;
float dt = 0.5;

float pendulumOffset = 0;     // смещение по горизонтали
float pendulumSpeed = 0.5;    // скорость перемещения
bool movingPendulum = true;      // движения маятника

// след из точек
#define TRAIL_LENGTH 50 // количество точек в следе
int trailX[TRAIL_LENGTH]; // массив X-координат следа
int trailY[TRAIL_LENGTH]; // массив Y-координат следа
int trailIndex = 0;       // текущий индекс для записи новой точки

// Игрок
int playerX = 64;
int playerY = 32;
int playerSize = 6;
float playerVelocityY = 0;
float gravity = 0.05;       // сила притяжения
float jumpForce = -0.1;    // сила прыжка

unsigned long levelStartTime = 0;
bool showLevelMessage = false;

// призовые точки
int prizeX;
int prizeY;
bool prizeVisible = false;

// игровые параметры
int score = 0;
int level = 1;
bool gameOver = false;
bool inMenu = true;    // Флаг для главного меню
bool inSettings = false;  // Флаг для меню настроек
bool inHighScores = false; // Флаг для таблицы рекордов

// меню
int menuOption = 0; // 0: Start, 1: Settings, 2: High Scores
int settingsOption = 0; // 0: Gravity_Pendulum, 1: Gravity Val 2: Jump Force, 3: Pendulum Speed

bool gravityEnabled = false; // по умолчанию гравитация выключена

bool explodeAnimation = false; // флаг анимации взрыва
int explodeTimer = 0;          // таймер анимации взрыва
const int explodeDuration = 30; // длительность анимации (кадры)
struct Particle {
    float x, y;
    float vx, vy;
};
Particle particles[30]; // частицы игрока

void updatePendulum() {
    // обновление горизонтального смещения маятника
    if (movingPendulum) {
        pendulumOffset += pendulumSpeed;
        if (pendulumOffset >= 32) { // достигли правой границы
            movingPendulum = false;
        }
    } else {
        pendulumOffset -= pendulumSpeed;
        if (pendulumOffset <= -32) { // достигли левой границы
            movingPendulum = true;
        }
    }
    // уравнения движения маятника
    float num1 = -g * (2 * mass1 + mass2) * sin(angle1);
    float num2 = -mass2 * g * sin(angle1 - 2 * angle2);
    float num3 = -2 * sin(angle1 - angle2) * mass2;
    float num4 = angularVel2 * angularVel2 * length2 + angularVel1 * angularVel1 * length1 * cos(angle1 - angle2);
    float den = length1 * (2 * mass1 + mass2 - mass2 * cos(2 * angle1 - 2 * angle2));
    float angularAcc1 = (num1 + num2 + num3 * num4) / den;

    num1 = 2 * sin(angle1 - angle2);
    num2 = angularVel1 * angularVel1 * length1 * (mass1 + mass2);
    num3 = g * (mass1 + mass2) * cos(angle1);
    num4 = angularVel2 * angularVel2 * length2 * mass2 * cos(angle1 - angle2);
    den = length2 * (2 * mass1 + mass2 - mass2 * cos(2 * angle1 - 2 * angle2));
    float angularAcc2 = (num1 * (num2 + num3 + num4)) / den;

    angularVel1 += angularAcc1 * dt;
    angularVel2 += angularAcc2 * dt;
    angle1 += angularVel1 * dt;
    angle2 += angularVel2 * dt;

    // DEBUG oграничение углов для стабильности (замедляет маятник)
   // angularVel1 *= 0.99;
   // angularVel2 *= 0.99;

    // координаты конца маятника
    int x1 = arduboy.width() / 2 + length1 * sin(angle1);
    int y1 = length1 * cos(angle1);
    int x2 = x1 + length2 * sin(angle2);
    int y2 = y1 + length2 * cos(angle2);

    // проверка столкновения с конфетой
    if (playSound) {
      if (prizeVisible && abs(x2 - prizeX) < 3 && abs(y2 - prizeY) < 3) {
        if (!soundPlayed) {
                int toneFreq = 880;
                beep.tone(beep.freq(toneFreq));
                arduboy.delayShort(10);
                beep.noTone();
                soundPlayed = true;
            }
        // усложним динамику при столкновении
        // angularVel1 += random(-5, 5) * 0.01; // добавляем случайное возмущение
        // angularVel2 += random(-5, 5) * 0.01;
        
        // определяем направление отскока
        if (x2 < prizeX) {
            angularVel2 += random(-5, 5) * 0.01;
            angularVel2 -= 0.05; // отскок влево
        } else {
            angularVel2 += 0.05; // отскок вправо
        }

        if (y2 < prizeY) {
            angularVel1 += random(-5, 5) * 0.01;
            angularVel1 -= 0.05; // отскок вверх
        } else {
            angularVel1 += 0.05; // отскок вниз
        }
      } else {
            soundPlayed = false;
        }
    }
}


void drawPendulum() {
    int originX = arduboy.width() / 2 + pendulumOffset; // cмещенный центр
    int originY = 0;

    int x1 = originX + length1 * sin(angle1);
    int y1 = originY + length1 * cos(angle1);
    int x2 = x1 + length2 * sin(angle2);
    int y2 = y1 + length2 * cos(angle2);

  /*
  int x1 = arduboy.width() / 2 + length1 * sin(angle1);
  int y1 = length1 * cos(angle1);
  int x2 = x1 + length2 * sin(angle2);
  int y2 = y1 + length2 * cos(angle2);
  */
  
  // обновление следа маятника
  trailX[trailIndex] = x2;
  trailY[trailIndex] = y2;
  trailIndex = (trailIndex + 1) % TRAIL_LENGTH; // циклический индекс

  // отображение следа маятника
  for (int i = 0; i < TRAIL_LENGTH; i++) {
    int index = (trailIndex + i) % TRAIL_LENGTH; // циклический доступ к массиву
    arduboy.drawPixel(trailX[index], trailY[index], WHITE);
  }
    
  // отображаем маятник
  // arduboy.drawLine(arduboy.width() /2 , 0, x1, y1, WHITE); // удлиняет первое колено на 32 пикселя
  arduboy.drawLine(originX, originY, x1, y1, WHITE); // смещает маятник влево вправо на 32 пикселя
  arduboy.drawLine(x1, y1, x2, y2, WHITE);
  arduboy.fillCircle(x1, y1, 2, WHITE);
  arduboy.fillCircle(x2, y2, 2, WHITE);
}

void updatePlayer() {
  // применение гравитации
  playerVelocityY += gravity;
  playerY += playerVelocityY;

  // ограничение падения
  if (playerY > arduboy.height() - playerSize) {
    playerY = arduboy.height() - playerSize;
    playerVelocityY = 0;
  }

  // ограничение выхода за верх экрана
  if (playerY < 0) {
    playerY = 0;
    playerVelocityY = 0;
  }
}

void drawPlayer() {
  arduboy.fillRect(playerX, playerY, playerSize, playerSize, WHITE);
}

void spawnPrize() {
  prizeX = random(arduboy.width());
  prizeY = random(arduboy.height());
  prizeVisible = true;
}

void drawPrize() {
  if (prizeVisible) {
    arduboy.fillCircle(prizeX, prizeY, 3, WHITE);
  }
}

void drawHUD() {
  tinyfont.setCursor(0, 0);
  tinyfont.print("Score: ");
  tinyfont.print(score);
  tinyfont.setCursor(80, 0);
  tinyfont.print("Level: ");
  tinyfont.print(level);
}

void checkCollisions() {
  int x1 = arduboy.width() / 2 + length1 * sin(angle1);
  int y1 = length1 * cos(angle1);
  int x2 = x1 + length2 * sin(angle2);
  int y2 = y1 + length2 * cos(angle2);

  // проверка столкновения игрока с маятником
 /* if (abs(playerX - x2) < playerSize && abs(playerY - y2) < playerSize) {
    gameOver = true;
  }
  */
  
  if (!explodeAnimation && abs(playerX - x2) < playerSize && abs(playerY - y2) < playerSize) {
    explodeAnimation = true;
    explodeTimer = 0;

    // инициализация частиц
    for (int i = 0; i < 10; i++) {
        particles[i].x = playerX + playerSize / 2;
        particles[i].y = playerY + playerSize / 2;
        particles[i].vx = random(-2, 3); // горизонтальная скорость (-2 до 2)
        particles[i].vy = random(-2, 3); // вертикальная скорость (-2 до 2)
        playShardSound();
    }
  }


  // проверка столкновения с конфетой
  if (abs(playerX - prizeX) < playerSize && abs(playerY - prizeY) < playerSize) {
    prizeVisible = false;
    score++;
   if (!soundPlayed) {
                int toneFreq = 2000;
                int toneFreq_1 = 1000;
                beep.tone(beep.freq(toneFreq));
                arduboy.delayShort(10);
                beep.noTone();
                beep.tone(beep.freq(toneFreq_1));
                arduboy.delayShort(10);
                beep.noTone();
                beep.tone(beep.freq(toneFreq));
                arduboy.delayShort(10);
                beep.noTone();
                soundPlayed = true;
       }
     
    /* if (!soundPlayed) {
        tunes.tone(2000, 50); // Тон на 2000 Гц длительностью 50 мс
        delay(50);            // Задержка между тонами
        tunes.tone(1000, 50); // Тон на 1000 Гц длительностью 50 мс
        delay(50);
        tunes.tone(2000, 50); // Тон на 2000 Гц длительностью 50 мс
        soundPlayed = true;
    }
    */
    if (score % 10 == 0) {
      nextLevel();
    } else {
      spawnPrize();
    }
  }
}

void updateExplosion() {
    if (explodeAnimation) {
        for (int i = 0; i < 30; i++) {
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;
        }
        explodeTimer++;

        // звук бум в анимации
        if (explodeTimer % 5 == 0) { // каждые 5 кадров
            playShardSound();
        }

        // конец анимации
        if (explodeTimer > explodeDuration) {
            explodeAnimation = false;
            gameOver = true;
        }
    }
}

void drawExplosion() {
    if (explodeAnimation) {
        for (int i = 0; i < 30; i++) {
            arduboy.fillCircle(particles[i].x, particles[i].y, 1, WHITE);
        }
    }
}

void playShardSound() {
    int frequency = random(100, 2000);
    int duration = random(20, 100);  
    tunes.tone(frequency, duration);
    // tunes.tone(1397,300);
}

void drawVictoryFireworks() {
    for (int i = 0; i < 50; i++) {
        int x = random(arduboy.width());
        int y = random(arduboy.height());
        arduboy.drawPixel(x, y, WHITE);
        if (playSound) {
            int freq = random(500, 2000); 
            int duration = random(20, 50);
            tunes.tone(freq, duration);
        }
    }
}

void celebrateVictory() {
    for (int i = 0; i < 30; i++) { // 30 циклов анимации
        arduboy.clear();
        drawVictoryFireworks();
        arduboy.display();
        delay(50);
    }
}


/* void nextLevel() {
  level++;
  arduboy.display();
  arduboy.clear();
  arduboy.setCursor(32, 24);
  arduboy.print("Level: ");
  arduboy.print(level);
  delay(1000);
  // while (!arduboy.pressed(A_BUTTON) || !arduboy.pressed(B_BUTTON)) {
  //  arduboy.idle();
  // }
  if (level > 3) {
    gameOver = true;
    return;
  }


  // Увеличиваем сложность
  angularVel1 *= 1.1;
  angularVel2 *= 1.1;
  mass1 += 0.5;
  mass2 += 0.5;
  g += 0.1;
  spawnPrize();
}
*/

void nextLevel() {
    level++;
    showLevelMessage = true;  // включаем показ сообщения уровня
    levelStartTime = millis();  // запоминаем текущее время

    if (level > 3) {
        gameOver = true;
        return;
    }

    // увеличиваем сложность
    angularVel1 *= 1.1;
    angularVel2 *= 1.1;
    mass1 += 0.5;
    mass2 += 0.5;
    g += 0.1;

    spawnPrize();
}

void updateLevelMessage() {
    if (showLevelMessage) {
        arduboy.clear();
        arduboy.setCursor(32, 24);
        arduboy.print(F("Level: "));
        arduboy.print(level);
        arduboy.display();

        // проверяем, прошло ли 2 секунды
        if (millis() - levelStartTime > 2000) {
            showLevelMessage = false;  // убираем сообщение уровня
        }
    }
}

void drawGameOverScreen() {
  arduboy.clear();
  arduboy.setCursor(32, 24);
  if (level > 3) {
    arduboy.print("YOU WIN!");
    celebrateVictory();
  } else {
    arduboy.print("GAME OVER!");
  }
  arduboy.display();
}

void resetGame() {
  // сброс положения маятника
  angle1 = PI / 2;
  angle2 = PI / 2;
  angularVel1 = 0;
  angularVel2 = 0;

  // сброс игрока
  playerX = 64;
  playerY = 32;
  playerVelocityY = 0;

  // сброс призовых точек
  spawnPrize();

  // сброс игровых параметров
  score = 0;
  level = 1;
  gameOver = false;
  arduboy.clear();
}

void handleSoundToggle() {
    if (arduboy.justPressed(B_BUTTON)) {
        playSound = !playSound; // переключение состояния звука
        if (playSound) {
            arduboy.audio.on(); 
        } else {
            arduboy.audio.off();
        }
    }

    // отображение звука в меню
    tinyfont.setCursor(75, 55);
    if (playSound) {
        tinyfont.print(F("Sound: On"));
    } else {
        tinyfont.print(F("Sound: Off"));
    }
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.print(F(" DAVIL PENDULUM WORLD\n"
                  "  (HAOS version 1.01)\n"
                  "  LEFT: moveLeft\n"
                  " RIGHT: moveRight\n"
                  "     A: jump\n"
                  "     B: mainMenu\n"
                  " A + B: Exit\n"
                  "  Press A to start"));
  arduboy.display();

  while (!arduboy.pressed(A_BUTTON)) {
    arduboy.idle();
  }
  spawnPrize();

  tunes.initChannel(PIN_SPEAKER_1);
#ifndef AB_DEVKIT
  // if not a DevKit
  tunes.initChannel(PIN_SPEAKER_2);
#else
  // if it's a DevKit
  tunes.initChannel(PIN_SPEAKER_1); // use the same pin for both channels
  tunes.toneMutesScore(true);       // mute the score when a tone is sounding
#endif
  arduboy.invert(!arduboy.audio.enabled()); // invert display if sound muted

    if (!tunes.playing())
    tunes.playScore(score_);

    // DEBUG create all ascii letters from 32-126
  size_t newLineCounter = 0;
  for (size_t i = 0; i < 100; i++) {
    if ((i % 26) == 0) {
      allLetters[i] = '\n';
      newLineCounter++;
    }
    else{
      allLetters[i] = (char) (i+32) - newLineCounter;
    }
  }
  allLetters[100] = '\0';
  
}

void loop() {
  if (!arduboy.nextFrame()) return;
  arduboy.pollButtons();
  arduboy.clear();
  beep.timer();

  if (inMenu) {
    drawMenu();
    handleMenuInput();
  } else if (inSettings) {
    drawSettings();
    handleSettingsInput();
  } else if (inHighScores) {
    drawHighScores();
    handleHighScoresInput();
  } else if (explodeAnimation) {
        updateExplosion();
        drawExplosion();     
  } else if (showLevelMessage) {
        updateLevelMessage();
        return;  // ждем окончания показа сообщения
  } else if (!gameOver) {
    handleInput();
    updatePendulum();
    updatePlayer();
    drawPendulum();
    drawPlayer();
    drawPrize();
    drawHUD();
    checkCollisions();
  } else {
    drawGameOverScreen();
    if (arduboy.justPressed(A_BUTTON) || arduboy.justPressed(B_BUTTON)) {
      inMenu = true;
      resetGame();
    }
  }
  arduboy.display();
}

void drawMenu() {
  arduboy.setCursor(32, 5);
  arduboy.print(F("MAIN MENU"));

  arduboy.setCursor(20, 20);
  arduboy.print(menuOption == 0 ? "> StartHaos" : "  StartHaos");

  arduboy.setCursor(20, 30);
  arduboy.print(menuOption == 1 ? "> Settings" : "  Settings");

  arduboy.setCursor(20, 40);
  arduboy.print(menuOption == 2 ? "> Scores" : "  Scores");
}

void handleMenuInput() {
  if (arduboy.justPressed(UP_BUTTON)) {
    menuOption = (menuOption - 1 + 3) % 3;
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    menuOption = (menuOption + 1) % 3;
  }
  if (arduboy.justPressed(A_BUTTON)) {
    if (menuOption == 0) {
      inMenu = false;
    } else if (menuOption == 1) {
      inSettings = true;
      inMenu = false;
    } else if (menuOption == 2) {
      inHighScores = true;
      inMenu = false;
    }
  }
  handleSoundToggle();
  
}

void drawSettings() {
    arduboy.setCursor(40, 0);
    arduboy.print(F("SETTINGS"));

    // гравитациия On/Off
    tinyfont.setCursor(10, 10);
    tinyfont.print(settingsOption == 0 ? "> Gravity_Pendulum: " : "  Gravity_Pendulum: ");
    tinyfont.print(gravityEnabled ? "ON" : "OFF");

    // настройка силы гравитации
    tinyfont.setCursor(10, 20);
    tinyfont.print(settingsOption == 1 ? "> Gravity Val: " : "  Gravity Val: ");
    tinyfont.print(gravity); // значение гравитации

    // Настройка силы прыжка
    tinyfont.setCursor(10, 30);
    tinyfont.print(settingsOption == 2 ? "> Jump Force: " : "  Jump Force: ");
    tinyfont.print(jumpForce); // значение прыжка

    // Настройка скорости маятника
    tinyfont.setCursor(10, 40);
    tinyfont.print(settingsOption == 3 ? "> Pendulum Spd: " : "  Pendulum Spd: ");
    tinyfont.print(dt); // значение скорости маятника

    arduboy.setCursor(20, 55);
    arduboy.print(F("Press B to Back"));
}


/* void handleSettingsInput() {
  if (arduboy.justPressed(UP_BUTTON)) {
    settingsOption = (settingsOption - 1 + 3) % 3;
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    settingsOption = (settingsOption + 1) % 3;
  }
  if (arduboy.justPressed(LEFT_BUTTON)) {
    if (settingsOption == 0) gravity = max(0.05, gravity - 0.05);
    if (settingsOption == 1) jumpForce = max(-5.0, jumpForce - 0.1);
    if (settingsOption == 2) dt = max(0.05, dt - 0.01);
  }
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    if (settingsOption == 0) gravity = min(0.5, gravity + 0.05);
    if (settingsOption == 1) jumpForce = min(0, jumpForce + 0.1);
    if (settingsOption == 2) dt = min(0.5, dt + 0.01);
  }
  if (arduboy.justPressed(B_BUTTON)) {
    inSettings = false;
    inMenu = true;
  }
}
*/

void handleSettingsInput() {
    if (arduboy.justPressed(UP_BUTTON)) {
        settingsOption = (settingsOption - 1 + 4) % 4; // ходим вверх, цикличность
    }
    if (arduboy.justPressed(DOWN_BUTTON)) {
        settingsOption = (settingsOption + 1) % 4; // ходим вниз, цикличность
    }

    // обработка пунктов меню
    switch (settingsOption) {
        case 0: // включение/отключение гравитации
            if (arduboy.justPressed(LEFT_BUTTON) || arduboy.justPressed(RIGHT_BUTTON)) {
                gravityEnabled = !gravityEnabled; // ON/OFF
            }
            break;

        case 1: // настройка гравитации
            if (arduboy.justPressed(LEFT_BUTTON)) gravity = max(0.01, gravity - 0.01);
            if (arduboy.justPressed(RIGHT_BUTTON)) gravity = min(1.0, gravity + 0.01);
            break;

        case 2: // сила прыжка
            if (arduboy.justPressed(LEFT_BUTTON)) jumpForce = max(-5, jumpForce - 0.1);
            if (arduboy.justPressed(RIGHT_BUTTON)) jumpForce = min(0, jumpForce + 0.1);
            break;

        case 3: // скорость маятника
            if (arduboy.justPressed(LEFT_BUTTON)) dt = max(0.01, dt - 0.01);
            if (arduboy.justPressed(RIGHT_BUTTON)) dt = min(1, dt + 0.01);
            break;
    }

    // бэк в гл. меню
    if (arduboy.justPressed(B_BUTTON)) {
        //currentMenu = MAIN_MENU; // DEBUG
        inSettings = false;
        inMenu = true; // возврат в меню
    }
}


void drawHighScores() {
  arduboy.setCursor(32, 10);
  arduboy.print(F("HIGH SCORES"));
  arduboy.setCursor(20, 30);
  arduboy.print(F("Press B to Back"));
}

void handleHighScoresInput() {
  if (arduboy.justPressed(B_BUTTON)) {
    inHighScores = false;
    inMenu = true; // взврат в меню
  }
}

void handleInput() {
  if (arduboy.pressed(LEFT_BUTTON) && playerX > 0) {
    playerX -= 2;
  }
  if (arduboy.pressed(RIGHT_BUTTON) && playerX < (arduboy.width() - playerSize)) {
    playerX += 2;
  }
  if (arduboy.pressed(A_BUTTON)) {
    playerVelocityY = jumpForce; // прыжок вверх
  }
  if (arduboy.justPressed(B_BUTTON)) {
    inMenu = true; // выход в меню
    resetGame();
  }
}
