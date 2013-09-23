void Eyeballs (float _PosX, float _PosY) {
  
  posX = _PosX;
  posY = _PosY;
  
  pushMatrix();

    translate(posX, posY);
    float dx = mousePosX - posX;
    float dy = mousePosY - posY;
    
    angle = atan2 (dy,dx);
    rotate(angle);
    
    fill (255);
    ellipse(0,0,40,40);
    
    fill(0);
    ellipse(10, 10, 10,10);
    
  popMatrix();
}

