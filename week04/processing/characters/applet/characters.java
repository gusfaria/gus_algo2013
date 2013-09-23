import processing.core.*; 
import processing.xml.*; 

import java.applet.*; 
import java.awt.Dimension; 
import java.awt.Frame; 
import java.awt.event.MouseEvent; 
import java.awt.event.KeyEvent; 
import java.awt.event.FocusEvent; 
import java.awt.Image; 
import java.io.*; 
import java.net.*; 
import java.text.*; 
import java.util.*; 
import java.util.zip.*; 
import java.util.regex.*; 

public class characters extends PApplet {

Eyes myEyes;
Nose myNose;
Head myHead;
//Head[]  myHead= new Head[4];
Mouth myMouth;
Hair myHair;

Clown[]  myClown= new Clown[40];


int total;
public void setup() {
  size(800, 600);
  smooth();
  fill(255);
//  myHead = new Head (100, 130, 180, 140, color(255, 207, 116));
//  myEyes = new Eyes (100, 100, 60, 60, color(255, 0, 0), 80, 50); 
//  myNose = new Nose (100, 130, 50, color(255, 0, 0), 10, 25);
//  myMouth = new Mouth (100, 180, 70, 30, color(255, 0, 0));
//  myHair = new Hair (100,120,100,100, color(0,255,0));

total = 0;
}

public void draw() {
  background(0);

//  myHair.display();
//  myHead.display();
//  myEyes.display();
//  myNose.display();
//  myMouth.display();

for (int i = 0; i < total; i++){
// myHead[i].display(); 
 myClown[i].display(); 
}
  
}

public void mouseClicked(){
// myHead[total] =  new Head (mouseX, mouseY, random(100, 190), random(80,140), color(255, 207, 116));
// total ++;
 
  myClown[total] =  new Clown (mouseX, mouseY);
  total ++;
}

class Clown {

  Eyes myEyes;
  Nose myNose;
  Head myHead;
  Mouth myMouth;
  Hair myHair;

  float PosX, PosY;


  Clown(float x, float y) {
    PosX = x;
    PosY = y;
    myHead = new Head (PosX, PosY+30, random(90, 180), random(70, 140), color(255, random(207,220), random(50,116)));
    myEyes = new Eyes (PosX, PosY, 60, 60, color(random(255), random(255), random(255)), 80, 50); 
    myNose = new Nose (PosX, PosY+30, 50, color(random(100,255), 0, 0), 10, 25);
    myMouth = new Mouth (PosX, PosY+80, random(70, 100), random(10, 100), color(255, 0, 0));
    myHair = new Hair (PosX, PosY+20, 100, 100, color(random(255), random(255), random(255)));
  }

  public void display() {
    myHair.display();
    myHead.display();
    myEyes.display();
    myNose.display();
    myMouth.display();
  }
}

class Eyes {
  float x, y, xs, ys;
  int c;
  float d;
  float f;
  float offsetX;


  Eyes(float xPos, float yPos, float xSize, float ySize, int eyeColor, float eyeDist, float freq) {
    x = xPos;
    y = yPos;
    xs = xSize;
    ys = ySize;
    c = eyeColor;
    d = eyeDist;
    f= freq;
  }

  public void display() {
    strokeWeight(1);
    if (frameCount % f < 8) {
      fill(0);
      ellipse( x-d/2, y, xs, ys/10);
      ellipse( x+d/2, y, xs, ys/10);
      

      
    } 
    else {
      strokeWeight(1);
      //LEFT EYES
      //white
      fill(255);
      ellipse(x-d/2, y, xs, ys);

      //iris
      fill(c);
      ellipse(x-d/2, y, 15, 15);

      //pupil
      fill(0);
      ellipse(x-d/2, y, 5, 5);
      
      //little white ball
      fill(255);
      
      ellipse(x-d/2+2, y-2, 4, 4);

      //center reference
//      fill(0, 255, 0);
//      ellipse (x, y, 5, 5);

      //RIGHT EYES
      //white
      strokeWeight(1);
      fill(255);
      ellipse(x+d/2, y, xs, ys);

      //iris
      fill(c);
      ellipse(x+d/2, y, 15, 15);

      //pupil
      fill(0);
      ellipse(x+d/2, y, 5, 5);
      
      //little white ball
      fill(255);
      
      ellipse(x+d/2+2, y-2, 4, 4);
      
    }
  }
}


class Hair {
  float xHpos;
  float yHpos;
  float xHsize;
  float yHsize;
  int cH;

  Hair(float xHair, float yHair, float xSize, float ySize, int cHair) {
    xHpos = xHair;
    yHpos = yHair;
    xHsize = xSize;
    yHsize = ySize;
    cH = cHair;
  }

  public void display() {
    fill(cH);
    noStroke();
    ellipse(xHpos+70, yHpos, xHsize, yHsize);
    ellipse(xHpos-70, yHpos, xHsize, yHsize);
    ellipse(xHpos+70, yHpos+30, xHsize-30, yHsize-30);
    ellipse(xHpos-70, yHpos+30, xHsize-30, yHsize-30);
  }
}

class Mouth {
  float posXmouth;
  float posYmouth;
  float mouthSx;
  float mouthSy;
  float strokeWidth;
  int lips;
  
  Mouth(float xMouth, float yMouth, float sMouthX, float sMouthY, int lipsColor) {
    posXmouth = xMouth;
    posYmouth = yMouth;
    mouthSx = sMouthX;
    mouthSy = sMouthY;
    lips = lipsColor;
  }

  public void display () { 
    
    strokeWeight(8);
    stroke(lips);
    fill(0);
    ellipse(posXmouth, posYmouth, mouthSx, mouseY*0.1f);
    
  }
}

class Nose {
  float noseX;
  float noseY;
  float noseS;
  int nosec;
  float noseXshadow;
  float noseYshadow;

  Nose(float noseXpos, float noseYpos, float noseSize, int noseColor, float noseXshade, float noseYshade) {
    noseX = noseXpos;
    noseY= noseYpos;
    noseS = noseSize;
    nosec = noseColor;
    noseXshadow = noseXshade;
    noseYshadow = noseYshade;
  }

  public void display() {
    fill(nosec);
    ellipse(noseX, noseY, noseS, noseS);
    noStroke();
    fill(nosec-2);
    ellipse(noseX+12, noseY, noseXshadow, noseYshadow);
    stroke(0);
  }
}

class Head {
  float headX, headY;
  float headXs, headYs;
  int skin;

  Head (float headXpos, float headYpos, float headXsize, float headYsize, int skinColor) {
    headX = headXpos; 
    headY = headYpos;
    headXs = headXsize; 
    headYs = headYsize;
    skin = skinColor;
  }

  public void display() {
    noStroke();
    fill(skin);
    ellipse(headX, headY, headXs, headYs);
    stroke(0);
  }
}

  static public void main(String args[]) {
    PApplet.main(new String[] { "--bgcolor=#FFFFFF", "characters" });
  }
}
