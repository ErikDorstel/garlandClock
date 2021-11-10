String httpget(String request) {
  String response="";

  // gerlandClock specific pages

  if (request.indexOf("/setTZ")>=0) {
    int a=request.indexOf(",")+1;
    setTZ(request.substring(a).toInt()); }

  else if (request.indexOf("/getTZ")>=0) {
    response+=String(getTZ()); }

  else if (request.indexOf("/setBright")>=0) {
    int a=request.indexOf(",")+1;
    setBright(request.substring(a).toInt()); }

  else if (request.indexOf("/getBright")>=0) {
    response+=String(getBright()); }

  else if (request.indexOf("/getNTPstatus")>=0) {
    response+=String(getNTPstatus()); }

  // WLAN Choose specific pages

  else if (request.indexOf("/chooseAP")>=0) { response=choose_html; }

  else if (request.indexOf("/statusAP")>=0) { if (statusStation==true) { response="<div class=\"x1\">WLAN AP " + ssidStation + " connected.</div>";
    response+="<div class=\"x1\">IP Address " + WiFi.localIP().toString() + "</div>"; } else { response="<div class=\"x1\">No WLAN AP connected.</div>"; } }

  else if (request.indexOf("/configAP")>=0) { response=a2h(ssidStation) + "," + a2h(passwordStation) + ","; }

  else if (request.indexOf("/scanAP")>=0) {
    int indexes=WiFi.scanNetworks(); for (int index=0;index<indexes;++index) { if (WiFi.SSID(index)!="") {
      response+="<div class=\"x1\" onclick=\"setAP(\'" + WiFi.SSID(index) + "\');\">" + WiFi.RSSI(index) + "&nbsp;dB&nbsp;&nbsp;&nbsp;&nbsp;" + WiFi.SSID(index) + "</div>"; } } }

  else if (request.indexOf("/connectAP")>=0) {
    int a=request.indexOf(",")+1; int b=request.indexOf(",",a)+1;
    ssidStation=h2a(request.substring(a,b-1)); passwordStation=h2a(request.substring(b));
    reconnectWLAN(); }

  // Default page

  else { response=index_html; }

  return response; }
