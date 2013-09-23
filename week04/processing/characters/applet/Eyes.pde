class Eyes {
  float x, y, xs, ys;
  color c;
  float d;
  float f;
  float offsetX;


  Eyes(float xPos, float yPos, float xSize, float ySize, color eyeColor, float eyeDist, float freq) {
    x = xPos;
    y = yPos;
    xs = xSize;
    ys = ySize;
    c = eyeColor;
    d = eyeDist;
    f= freq;
  }

  void display() {
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


