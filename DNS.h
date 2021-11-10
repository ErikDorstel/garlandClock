void dnsWorker() {
  if (dnsServer.parsePacket()) {
    byte request[200]; int requestlength; requestlength=dnsServer.available(); dnsServer.read(request,requestlength);
    // type A, class IN, aurora.tesla
    byte host[]={1,0,0,1,0,0,0,0,0,0,6,0x61,0x75,0x72,0x6F,0x72,0x61,5,0x74,0x65,0x73,0x6C,0x61,0,0,1,0,1};
    // resolve all hosts to 192.168.4.1 (captive portal)
    // if (memcmp(request+2,host,10)==0 & memcmp(request+requestlength-4,host+24,4)==0) {
    // resolve host aurora.tesla to 192.168.4.1
    if (memcmp(request+2,host,requestlength-2)==0) {
      byte data1[]={0x81,0x80,0,1,0,1,0,0,0,0};
      byte data2[]={0xC0,0x0C,0,1,0,1,0,0,0,0x3C,0,4,192,168,4,1};
      byte reply[200]; memcpy(reply,request,2); memcpy(reply+2,data1,10);
      memcpy(reply+12,request+12,requestlength-12); memcpy(reply+requestlength,data2,16);
      dnsServer.beginPacket(dnsServer.remoteIP(),dnsServer.remotePort());
      dnsServer.write(reply,requestlength+16); dnsServer.endPacket();
      if (debug) { Serial.println("Reply DNS Packet with host aurora.tesla to " + dnsServer.remoteIP().toString() + "."); } } } }
