#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <EEPROM.h>


#define LEDn    5  //6
#define LEDpwm   15   //8


const int output = 0;
const int no = 1024;
int led = 5; 
const int brightness = 0;    
int fadeAmount = 5; 

String data;

const char* ssid = "ledcon";;
const char* password = "12345679";



ESP8266WebServer server(80);

String webpage = R"***(




<!DOCTYPE html>
<html>
  <head>    
    <title>SWITCH LED</title>
  </head>
<body style=" background-color: #0FFFA4;">


<style>
a1 {
  background: #FEF723;
  color: blue;
  font-family: Trebuchet MS;
  font-size: 120%;
  id="LEDn"
}
</style>

<style>
a2 {
  background: #EC26E5;
  color: #000000;
  font-family: Trebuchet MS;
  font-size: 100%;
  id="pwmplus"
}
</style>


<style>
a3 {
  background: #26DEEC;
  color: #000000;
  font-family: Trebuchet MS;
  font-size: 100%;
  id="pwmminus" 
}
</style>




<style>
a4 {
  background: #0FFFA4;
  color: #0FFFA4;
  font-family: Trebuchet MS;
  font-size: 100%;
}
</style>




<div>

<a1  id="LEDn"  text-align: right;" >ON </html</a1> 


<a4  float: right;" > &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160; </html </a4>  


<a2     id="pwmplus"  text-align: right;" > UP </html</a2> 


<a4  float: right;" > &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160; </html </a4>  


<a3 id="pwmminus"  text-align: right;" > DOWN </html</a3>  


</div>



<br/>





  <div style="background:#0000FF; width:60px; height:40px">
    <div style="background:#0000FF; width:100%; height:10%">
      <h5 align="center"><br/>ON</h5>  
    </div>      
    <div id="LEDn" style="background:#FFFF00; width:100%; height:100%"></div> 
  </div>
  <div style="background:#0000FF; width:60px; height:40px">
    <div style="background:#0000FF; width:100%; height:10%">
      <h5 align="center"><br/>up</h5>
     </div>
    <div id="pwmplus" style="background:#00EE00; width:100%; height:100%"></div>
  </div>
   <div style="background:#0000FF; width:60px; height:40px">
    <div style="background:#0000FF; width:100%; height:10%">
      <h5 align="center"><br/>down</h5>
  </div>
    <div id="pwmminus" style="background:#FF0000; width:100%; height:100%"></div>
  </div>
  </div>




<br/>
<br/>


    <h2 style="background:#FFFFFF; width:200px; height:30px">LED1</h2>

<div>
    <a1 style="background:#00FF00; width:30px; height:20px"><a2 href=/ledon4>ON</a2></a1>

<a4  float: right;" > &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160; </html </a> 

    <a1 style="background:#FF0000; width:30px; height:20px"><a3 href=/ledoff4>OFF</a3></a1>
</div>


<br/>

    <h2 style="background:#FFFFFF; width:1000px; height:30px">LED2</h2>
    <p style="background:#00FF00; width:30px; height:20px"><a href=/ledon1>ON</a></p>
    <p style="background:#FF0000; width:30px; height:20px"><a href=/ledoff1>OFF</a></p>

<br/>

    <h2  style="background:#FFFFFF; width:1000px; height:30px">PLUG</h2>
    <p style="background:#00FF00; width:30px; height:20px"><a href=/ledon2>ON</a></p>
    <p style="background:#FF0000; width:30px; height:20px"><a href=/ledoff2>OFF</a></p>

<br/>

    <h2 style="background:#FFFFFF; width:1000px; height:30px">FAN</h2>
    <p style="background:#00FF00; width:30px; height:20px"><a href=/ledon3>ON</a></p>
    <p style="background:#FF0000; width:30px; height:20px"><a href=/ledoff3>OFF</a></p>


<br/>



</body>







<script>
  window.addEventListener('load', function(){
    var n = document.getElementById('LEDn') 
    var minus = document.getElementById('pwmminus') 
    var plus = document.getElementById('pwmplus') 
    
    var xhr = new XMLHttpRequest();
    n.onmousedown = function(){
      xhr.open("GET", "LEDon", true);
      xhr.send();  
    }
    n.onmouseup = function(){
      xhr.open("GET", "LEDoff", true);
      xhr.send();  
    }
    n.addEventListener('touchstart', function(e){
      xhr.open("GET", "LEDon", true);
      xhr.send();
    }, false)
    n.addEventListener('touchend', function(e){
      xhr.open("GET", "LEDoff", true);
      xhr.send();
    }, false)
    plus.onmousedown = function(){
      xhr.open("GET", "plus", true);
      xhr.send();  
    }
    plus.onmouseup = function(){
      xhr.open("GET", "stop", true);
      xhr.send();  
    }
    plus.addEventListener('touchstart', function(e){
      xhr.open("GET", "plus", true);
      xhr.send();
    }, false)
    plus.addEventListener('touchend', function(e){
      xhr.open("GET", "stop", true);
      xhr.send();
    }, false)
    minus.onmousedown = function(){
      xhr.open("GET", "minus", true);
      xhr.send();  
    }
    minus.onmouseup = function(){
      xhr.open("GET", "stop", true);
      xhr.send();  
    }
    minus.addEventListener('touchstart', function(e){
      xhr.open("GET", "minus", true);
      xhr.send();
    }, false)
    minus.addEventListener('touchend', function(e){
      xhr.open("GET", "stop", true);
      xhr.send();
    }, false)
  },false)
</script>
</html>
)***";


void handleRoot() {
  server.send(200, "text/html", webpage);
  
}



int pwm;
int pwmCount;


void ledON(){
  led=1;
}

void ledOFF(){
  led=0;  
}

void plus(){
  pwm=3;  
}

void minus(){
  pwm=-3;  
}

void stopPWM(){
  pwm=0;  
}





void ledon1()
{
  digitalWrite(14, 1);
  server.send(200, "text/html", webpage);
}
void ledoff1()
{
  digitalWrite(14, 0);
  server.send(200, "text/html", webpage);
}


void ledon2()
{
  digitalWrite(12, 1);
  server.send(200, "text/html", webpage);
}
void ledoff2()
{
  digitalWrite(12, 0);
  server.send(200, "text/html", webpage);
}



void ledon3()
{
  digitalWrite(13, 1);
  server.send(200, "text/html", webpage);
}
void ledoff3()
{
  digitalWrite(13, 0);
  server.send(200, "text/html", webpage);
}


void ledon4()
{
  digitalWrite(0, 1);
  server.send(200, "text/html", webpage);
}
void ledoff4()
{
  digitalWrite(0, 0);
  server.send(200, "text/html", webpage);
}





void setup() {
 pinMode(13, OUTPUT); //7
 pinMode(14, OUTPUT); //5
 pinMode(5, OUTPUT); //
 pinMode(0, OUTPUT);//3

 
 pinMode(12, OUTPUT);//6
 pinMode(15, OUTPUT);//8


 
 delay(1000);
  Serial.begin(9600);

  pinMode(LEDn,OUTPUT);
  pinMode(LEDpwm,OUTPUT);





  WiFi.mode(WIFI_AP);
  IPAddress apLocalIp(192,168,4,1);
  IPAddress apSubnetMask(255,255,255,0);
  WiFi.softAPConfig(apLocalIp,apLocalIp,apSubnetMask);
  WiFi.softAP(ssid, password);



  server.on("/ledon1", ledon1);
  server.on("/ledoff1", ledoff1);


  server.on("/ledon2", ledon2);
  server.on("/ledoff2", ledoff2);


  server.on("/ledon3", ledon3);
  server.on("/ledoff3", ledoff3);

  server.on("/ledon4", ledon4);
  server.on("/ledoff4", ledoff4);

  
  server.begin();

  server.on("/", handleRoot);
  server.on("/LEDon", ledON);     
  server.on("/LEDoff", ledOFF);   
  server.on("/minus", minus);   
  server.on("/plus", plus);   
  server.on("/stop", stopPWM);   


  pwm=0;
  pwmCount=0;
  led=0;


}

void loop() {
  server.handleClient();

  digitalWrite(LEDn, led);

  pwmCount+=pwm;

  if(pwmCount>1024)pwmCount=1024;
  if(pwmCount<0)pwmCount=0;
  analogWrite(LEDpwm, pwmCount);
  


  delay(10);
}











  
