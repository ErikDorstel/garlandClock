boolean debug=false;

#include "WLAN.h"
#include "DNS.h"
#include "NTP.h"
#include "NEOLED.h"
#include "HTTP.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initWLAN();
  initNTP();
  initNEOLED(); }

void loop() { httpWorker(); dnsWorker(); neoledWorker(); }
