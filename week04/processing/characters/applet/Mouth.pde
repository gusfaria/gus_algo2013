class Mouth {
  float posXmouth;
  float posYmouth;
  float mouthSx;
  float mouthSy;
  float strokeWidth;
  color lips;
  
  Mouth(float xMouth, float yMouth, float sMouthX, float sMouthY, color lipsColor) {
    posXmouth = xMouth;
    posYmouth = yMouth;
    mouthSx = sMouthX;
    mouthSy = sMouthY;
    lips = lipsColor;
  }

  void display () { 
    
    strokeWeight(8);
    stroke(lips);
    fill(0);
    ellipse(posXmouth, posYmouth, mouthSx, mouseY*0.1);
    
  }
}

