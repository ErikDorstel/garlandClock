char *index_html=R"(

<!DOCTYPE html>
<html lang="en"><head>
<title>garlandClock - ESP32 LED Ring Clock</title>
<meta name="author" content="Erik Dorstel">
<meta name="generator" content="vi">
<meta name="repository" content="https://github.com/ErikDorstel/garlandClock">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta charset="utf-8">
<style>
html { font-family:Arial; }
div  { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
.x0a { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0  { background-color:#C0A0A0; padding:0.3em 0em; width:100%; font-size:1.4em; }
.x1  { background-color:#A0B0C0; padding:0.3em 0em; width:100%; font-size:1.4em; }
.x2  { background-color:#888888; padding:0.3em 0em; width:48%; font-size:1.4em; }
.x3  { background-color:#888888; padding:0.3em 0em; width:32%; font-size:1.4em; }
.x4  { background-color:#888888; padding:0.3em 0em; width:24%; font-size:1.4em; }
</style>
<script>

function CLOCKinit() {
  ajaxObj=[]; ntpTZ=3600; ledBright=5; NTPstatus=0;
  requestAJAX('getTZ'); requestAJAX('getBright'); requestAJAX('getNTPstatus');
  doRange(); }

function doDisplay() {
  if (NTPstatus==1) { document.getElementById("statusBtn").innerHTML="Time synchronized"; }
  else { document.getElementById("statusBtn").innerHTML="Time not in sync"; }
  if (ntpTZ>=0) { document.getElementById("tzBtn").innerHTML="Timezone UTC +"+ntpTZ/3600; }
  else { document.getElementById("tzBtn").innerHTML="Timezone UTC &#8722;"+ntpTZ/-3600; }
  document.getElementById("brightBtn").innerHTML="Brightness "+ledBright+" / 255"; }

function tzDef() { ntpTZ=3600; doRange("ntp"); }
function tzDec() { ntpTZ-=3600; doRange("ntp"); }
function tzInc() { ntpTZ+=3600; doRange("ntp"); }
function brightDef() { ledBright=5; doRange("bright"); }
function brightDec1() { ledBright-=1; doRange("bright"); }
function brightDec10() { ledBright-=10; doRange("bright"); }
function brightInc10() { ledBright+=10; doRange("bright"); }
function brightInc1() { ledBright+=1; doRange("bright"); }

function doRange(target) {
  if (ntpTZ<23*-3600) { ntpTZ=23*-3600; }
  if (ntpTZ>23*3600) { ntpTZ=23*3600; }
  if (ledBright<0) { ledBright=0; }
  if (ledBright>255) { ledBright=255; }
  doDisplay();
  if (target=="ntp") { requestAJAX('setTZ,'+ntpTZ); }
  if (target=="bright") { requestAJAX('setBright,'+ledBright); } }

function getNTPstatus() { requestAJAX('getNTPstatus'); }

function requestAJAX(value) {
  ajaxObj[value]=new XMLHttpRequest; ajaxObj[value].url=value; ajaxObj[value].open("GET",value,true);
  ajaxObj[value].setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj[value].addEventListener('load',replyAJAX); ajaxObj[value].send(); }

function replyAJAX(event) {
  if (event.target.status==200) {
    if (event.target.url=="getTZ") { ntpTZ=event.target.responseText*1; doDisplay(); }
    else if (event.target.url=="getBright") { ledBright=event.target.responseText*1; doDisplay(); }
    else if (event.target.url=="getNTPstatus") { NTPstatus=event.target.responseText*1; doDisplay(); } } }

</script></head><body onload="CLOCKinit();">

<div><div class="x0a">garlandClock</div></div>
<div><div class="x0b">LED Ring Clock</div></div>

<div class="x1" onclick="location.replace('/chooseAP');">Choose WLAN AP</div></div>

<div>
<div><div class="x0" id="statusBtn" onclick="getNTPstatus();"></div></div>
<div><div class="x1" id="tzBtn" onclick="tzDef();"></div></div>
<div><div class="x2" onclick="tzDec();">&#8722;</div>
     <div class="x2" onclick="tzInc();">+</div></div>
<div><div class="x1" id="brightBtn" onclick="brightDef();"></div></div>
<div><div class="x4" onclick="brightDec10();">&#8722; 10</div>
     <div class="x4" onclick="brightDec1();">&#8722; 1</div>
     <div class="x4" onclick="brightInc1();">+ 1</div>
     <div class="x4" onclick="brightInc10();">+ 10</div></div>
</div>

</body></html>

)";
