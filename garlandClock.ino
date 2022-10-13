boolean debug=true;

const char* appName="garlandClock";
const char* appDesc="LED Ring Clock";

#include "WLAN.h"
#include "DNS.h"
#include "NTP.h"
#include "NEOLED.h"
#include "HTTP.h"

void setup() {
  if (debug) { Serial.begin(115200); }
  initWLAN();
  initDNS();
  initHTTP();
  initNTP();
  initNEOLED(); }

void loop() { wlanWorker(); httpWorker(); dnsWorker(); neoledWorker(); }
