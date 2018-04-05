import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;
import processing.serial.*;

Serial myPort;
Minim minim;
AudioPlayer glass;

void setup() {
  myPort = new Serial(this, Serial.list()[0], 9600);
  minim = new Minim(this);
  glass = minim.loadFile("glass.mp3");
}

void draw() {
}

void serialEvent(Serial p) {
  glass.play();
}

void stop()
{
  glass.close();
  minim.stop();
  super.stop();
}