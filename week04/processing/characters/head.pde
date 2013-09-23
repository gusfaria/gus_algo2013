class Head {
  float headX, headY;
  float headXs, headYs;
  color skin;

  Head (float headXpos, float headYpos, float headXsize, float headYsize, color skinColor) {
    headX = headXpos; 
    headY = headYpos;
    headXs = headXsize; 
    headYs = headYsize;
    skin = skinColor;
  }

  void display() {
    noStroke();
    fill(skin);
    ellipse(headX, headY, headXs, headYs);
    stroke(0);
  }
}

