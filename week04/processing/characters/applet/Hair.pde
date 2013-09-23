class Hair {
  float xHpos;
  float yHpos;
  float xHsize;
  float yHsize;
  color cH;

  Hair(float xHair, float yHair, float xSize, float ySize, color cHair) {
    xHpos = xHair;
    yHpos = yHair;
    xHsize = xSize;
    yHsize = ySize;
    cH = cHair;
  }

  void display() {
    fill(cH);
    noStroke();
    ellipse(xHpos+70, yHpos, xHsize, yHsize);
    ellipse(xHpos-70, yHpos, xHsize, yHsize);
    ellipse(xHpos+70, yHpos+30, xHsize-30, yHsize-30);
    ellipse(xHpos-70, yHpos+30, xHsize-30, yHsize-30);
  }
}

