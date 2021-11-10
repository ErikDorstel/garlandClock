#include <Adafruit_NeoPixel.h>
#define gpio 15
Adafruit_NeoPixel ring=Adafruit_NeoPixel(60,gpio,NEO_GRB+NEO_KHZ800);

int lastNTP;

void setBright(int ledBright) {
  ring.setBrightness(ledBright);
  preferences.begin("garlandClock",false); preferences.putInt("ledBright",ledBright); preferences.end(); }

int getBright() {
  preferences.begin("garlandClock",false); int ledBright=preferences.getInt("ledBright",5); preferences.end();
  return(ledBright); }

void initNEOLED() {
  ring.begin(); ring.setBrightness(getBright()); }

void displayRing(int hour,int minute,int second) {
  if (hour>11) { hour-=12; } hour=(hour*5)+(minute/12); int hour1=hour-1; int hour2=hour+1;
  if (hour1<0) { hour1+=60; } if (hour2>59) { hour2-=60; }
  ring.clear();
  for (int a=0;a<=55;a+=5) { ring.setPixelColor(a,64,64,0); }
  ring.setPixelColor(second,0,255,0);
  ring.setPixelColor(hour,0,0,255);
  ring.setPixelColor(hour1,0,0,255);
  ring.setPixelColor(hour2,0,0,255);
  ring.setPixelColor(minute,255,0,0);
  ring.show(); }

void neoledWorker() {
  ntpTime.update(); if (ntpTime.getSeconds()!=lastNTP) { lastNTP=ntpTime.getSeconds();
    displayRing(ntpTime.getHours(),ntpTime.getMinutes(),ntpTime.getSeconds()); } }
