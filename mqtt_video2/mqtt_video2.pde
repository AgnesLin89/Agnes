import processing.javafx.*;
import mqtt.*;

MQTTClient client;
String dirx = "";
int mid = 0;
void setup() {
  //size(1440, 1080, FX2D);
  fullScreen(FX2D, 1);
  dirx = sketchPath();

  client = new MQTTClient(this);
  client.connect("mqtt://test.mosquitto.org:1883");
  
  videox_ini();
}

void draw() {
  //background(0);
  videox_draw();

}



void clientConnected() {
  println("client connected");
  client.subscribe("/IMU");
}

void messageReceived(String topic, byte[] payload) {
  println("new message: " + topic + " - " + new String(payload));
  String[] str = split(new String(payload), '\t');
  printArray(str);
  mid = int(str[0]);
  if(mid==1){
    //background(255, 0, 0);
    //if(vst[0]==0){
      //vst[0] = 1;
      //movien[0].setPosition(0);
      //movien[0].pause();
      //movie[0].play();
    //}
  } else if(mid==2){
    //background(0, 0, 255);
    if(vst[1]==0){
      vst[1] = 1;
      //movien[1].setPosition(0);
      movien[1].pause();
      movie[1].play();
      movie[1].setVolume(100);
    }
  }
}

void connectionLost() {
  println("connection lost");
}
