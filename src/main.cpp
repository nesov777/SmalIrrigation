#include <Arduino.h>
#include <Narcoleptic.h>
//#define SLEEP1 43200000   // период сна в миллисекундах (пример: 60*60*12*1000 = 43200000 - 12 часов)
//#define SLEEP2 180000   // период сна в миллисекундах (пример: 60*3*1000 = 180000 - три минуты)
//#define PUMP 60000         // время работы в миллисекундах (пример: 60*1000 = 60000 - одна минута)
#define SLEEP1 10000
#define SLEEP2 10000
#define PUMP 15000
#define PUMP_PIN 7            // пин мосфета

void setup() {
  // все пины как входы, экономия энергии
 for (byte i = 0; i < 21; i++) {
   pinMode(i, INPUT);
 }
}

void loop() {
  Narcoleptic.delay(SLEEP2);          //При подаче питания помпа включается не сразу, а спустя время SLEEP2. На сллучай "мигания" питания, чтобы не было потопа
  pinMode(PUMP_PIN, OUTPUT);          //активируем пин помпы
  digitalWrite(PUMP_PIN, HIGH);       //подаем питание на помпу
  Narcoleptic.delay(PUMP);            //ждем пока помпа отработает заданное время
  digitalWrite(PUMP_PIN, LOW);        //отключаем помпу
  pinMode(PUMP_PIN, INPUT);           //деактивируем пин помпы
  Narcoleptic.delay(SLEEP1);          //ждем время SLEEP1(+SLEEP2 в начале цикла) до следующего полива
}
