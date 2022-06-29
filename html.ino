
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



<style>
div1 {
  position: relative;
  left: 300px;
  bottom: 0;
  right: 0;
  width: 200px;
  border: 3px solid #73AD21;
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

<div1>

<a2 id=/ledon4>ON</a2></a1>

<a4  float: right;" > &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160; </html </a> 

    
<a3 href=/ledoff4>OFF</a3></a1>

</div1>


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
