char *choose_html=R"(

<!DOCTYPE html>
<html lang="en"><head>
<title>garlandClock - ESP32 LED Ring Clock</title>
<meta name="author" content="Erik Dorstel">
<meta name="generator" content="vi">
<meta name="repository" content="https://github.com/ErikDorstel/garlandClock">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta charset="utf-8">
<style>
html  { font-family:Arial; }
div   { background-color:#888888; color:#ffffff; border:0px; padding:0px; margin:0px; text-align:center; width:100%; user-select:none; display:inline-block; }
input { background-color:#A0B0C0; padding:0.2em; width:90%; font-size:1em; color:#ffffff; outline:none; border:0px; }
input[type=checkbox] { width:1.2em; height:1.2em; }
.x0a  { background-color:#C0A0A0; padding:0.2em 0em 0.1em; width:100%; font-size:1.5em; }
.x0b  { background-color:#C0A0A0; padding:0.1em 0em 0.2em; width:100%; font-size:1.2em; }
.x0   { background-color:#C0A0A0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x1   { background-color:#A0B0C0; padding:0.4em 0em; width:100%; font-size:1.5em; }
.x2   { background-color:#888888; padding:0.4em 0em; width:48%; font-size:1.5em; }
.x3   { background-color:#888888; padding:0.4em 0em; width:32%; font-size:1.5em; }
.x4   { background-color:#888888; padding:0.4em 0em; width:24%; font-size:1.5em; }
</style>
<script>

function initChoose() { ajaxObj=[]; statusChoose(); statusChooseID=window.setInterval("statusChoose();",5000); requestAJAX("configAP"); }

function statusChoose() { requestAJAX("statusAP"); }

function configAP(value) {
  document.getElementById("APName").value=h2a(value.split(",")[0]); document.getElementById("APPassword").value=h2a(value.split(",")[1]); }

function scanAP() { document.getElementById("scanAP").innerHTML="<div class=\"x1\">Scan for WLAN Networks ...</div>"; requestAJAX("scanAP"); }

function setAP(value) {
  document.getElementById("APName").value=value; document.getElementById("APPassword").value="";
  document.getElementById("scanAP").innerHTML="<div class=\"x1\">&nbsp;</div>"; }

function connectAP() {
  if (document.getElementById("APName").value!="" & document.getElementById("APPassword").value!="") {
    document.getElementById("scanAP").innerHTML="<div class=\"x1\">&nbsp;</div>";
    document.getElementById("statusAP").innerHTML="<div class=\"x1\">Connecting WLAN AP "+document.getElementById("APName").value+" ...</div>";
    window.clearInterval(statusChooseID); window.setTimeout("initChoose();",5000);
    requestAJAX("connectAP,"+a2h(document.getElementById("APName").value)+","+a2h(document.getElementById("APPassword").value)); } }

function requestAJAX(value) {
  ajaxObj[value]=new XMLHttpRequest; ajaxObj[value].url=value; ajaxObj[value].open("GET",value,true);
  ajaxObj[value].setRequestHeader("Content-Type","application/x-www-form-urlencoded"); ajaxObj[value].addEventListener('load',replyAJAX); ajaxObj[value].send(); }

function replyAJAX(event) {
  if (event.target.status==200) {
    if (event.target.url.startsWith("connectAP")) { }
    else if (event.target.url=="configAP") { configAP(event.target.responseText); }
    else document.getElementById(event.target.url).innerHTML=event.target.responseText; } }

function a2h(aValue) { hValue=[]; for (idx=0;idx<aValue.length;idx++) { hValue.push(Number(aValue.charCodeAt(idx)).toString(16)); } return hValue.join(''); }
function h2a(hValue) { aValue=""; for (idx=0;idx<hValue.length;idx+=2) { aValue+=String.fromCharCode(parseInt(hValue.substr(idx,2),16)); } return aValue; }

</script></head><body onload="initChoose();">

<div><div class="x0a">garlandClock</div></div>
<div><div class="x0b">LED Ring Clock</div></div>
<div id="scanAP"><div class="x1">&nbsp;</div></div>
<div><div class="x2">WLAN Name</div>
     <div class="x2">Password</div></div>
<div><div class="x2"><form><input id="APName" type="text"></form></div>
     <div class="x2"><form><input id="APPassword" type="password"></form></div></div>
<div id="statusAP"><div class="x1">&nbsp;</div></div>
<div><div class="x3" onclick="connectAP();">Connect</div>
     <div class="x3" onclick="scanAP();">Scan</div>
     <div class="x3" onclick="location.replace('/');">Cancel</div></div>

</body></html>

)";
