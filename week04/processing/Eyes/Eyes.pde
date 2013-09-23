float posX, posY, mousePosX, mousePosY;
float angle;
float positionX = width/2;
float positionY = height/2;
  
void setup () {
  size (640, 480);
  smooth ();
  positionX = width/2;
  positionY = height/2;
}
  
 void draw () {
  background(50);
  
  fill(0,255,0);
  ellipse(positionX-50, positionY, 110, 100);
  ellipse(positionX-40, positionY-10, 90, 100);
  ellipse(positionX+50, positionY, 110, 100);
  ellipse(positionX+40, positionY-10, 90, 100);
  
  fill(239,228,217);
  ellipse(width/2, height/2+20, 100,150);

  Eyeballs(width/2-20, height/2);
  Eyeballs(width/2+20, height/2);
  
  //Nose
  fill(255,0,0);
  noStroke();
  ellipse(width/2, height/2+30, 50,30);
  
  fill(0);
  strokeWeight(5);
  stroke(255,0,0);
  ellipse(width/2, height/2+60, 50,mouseY*0.1);
  noStroke();
  
  mousePosX = mouseX;
  mousePosY = mouseY;
 
 } 


