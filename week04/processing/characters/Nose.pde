class Nose {
  float noseX;
  float noseY;
  float noseS;
  color nosec;
  float noseXshadow;
  float noseYshadow;

  Nose(float noseXpos, float noseYpos, float noseSize, color noseColor, float noseXshade, float noseYshade) {
    noseX = noseXpos;
    noseY= noseYpos;
    noseS = noseSize;
    nosec = noseColor;
    noseXshadow = noseXshade;
    noseYshadow = noseYshade;
  }

  void display() {
    fill(nosec);
    ellipse(noseX, noseY, noseS, noseS);
    noStroke();
    fill(nosec-2);
    ellipse(noseX+12, noseY, noseXshadow, noseYshadow);
    stroke(0);
  }
}

