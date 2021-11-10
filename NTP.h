#include <NTPClient.h>
WiFiUDP ntpUDP;
NTPClient ntpTime(ntpUDP);

void setTZ(int TZ) {
  ntpTime.setTimeOffset(TZ);
  preferences.begin("garlandClock",false); preferences.putInt("ntpTZ",TZ); preferences.end(); }

int getTZ() {
  preferences.begin("garlandClock",false); int TZ=preferences.getInt("ntpTZ",3600); preferences.end();
  return(TZ); }

int getNTPstatus() {
  if (ntpTime.update()) { return(1); } else { return(0); } }

void initNTP() {
  ntpTime.begin();
  ntpTime.setPoolServerName("pool.ntp.org");
  ntpTime.setTimeOffset(getTZ()); }
