Eyes myEyes;
Nose myNose;
Head myHead;
//Head[]  myHead= new Head[4];
Mouth myMouth;
Hair myHair;

Clown[]  myClown= new Clown[40];

float posX, posY, mousePositionX, mousePositionY, angle;
float dx, dy;
int total;



void setup() {
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

void draw() {
  background(255);
  

  


for (int i = 0; i < total; i++){
// myHead[i].display();
 myClown[i].display(); 
}
  
}

void mouseClicked(){
// myHead[total] =  new Head (mouseX, mouseY, random(100, 190), random(80,140), color(255, 207, 116));
// total ++;
 
  myClown[total] =  new Clown (mouseX, mouseY);
  total ++;
}

void Eyeballs(){
// pushMatrix();
//    mousePositionX = mouseX;
//    mousePositionY = mouseY;
//    posX = width/2;
//    posY = height/2;  
//    translate(posX,posY);
//    dx = mousePositionX - posX;
//    dy = mousePositionY - posY;
//    
//    angle = atan2(dy,dx);
//    rotate(radians(angle));
//    
//  popMatrix();
//  
//  fill(0);
//  ellipse(0,0,40,40);
//  
//  fill(255);
//  ellipse(10,0, 10,10); 


}

