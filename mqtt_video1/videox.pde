
import VLCJVideo.*;

VLCJVideo[] movie;
VLCJVideo[] movien;
int[] vst = new int[2];
void videox_ini() {
  movie = new VLCJVideo[2];
  movie[0] = new VLCJVideo(this);
  //movie[1] = new VLCJVideo(this);
  movie[0].open(dirx+"/media/n_copy_56075006-6C8A-44C7-9591-1462B91F40C1s.mp4");
  
  movie[0].bind( VLCJVideo.MediaPlayerEventType.FINISHED, new Runnable() { public void run() {
    println("FINISHED 0");
    vst[0] = 0;
     
    //movie[0].setPosition(0);
    movie[0].pause();
    movien[0].play();
  } } );
  /*
   movie[1].bind( VLCJVideo.MediaPlayerEventType.FINISHED, new Runnable() { public void run() {
    println("FINISHED 1");
    vst[1] = 0;
    movie[1].setPosition(0);
    movie[1].pause();
    movien[1].play();
  } } );
  */
  
  movien = new VLCJVideo[2];
  movien[0] = new VLCJVideo(this);
  //movien[1] = new VLCJVideo(this);
  movien[0].setRepeat(true);
  //movien[1].setRepeat(true);
  movien[0].openAndPlay(dirx+"/media/n_a00starts.mp4");

  vst[0] = 0;
  //vst[1] = 0;
  
  
  
  

}


void videox_draw() {

  if(vst[0]==1){
    image(movie[0], 0, 0, width, height);
  } else if(vst[0]==0){
    image(movien[0], 0, 0, width, height);
  }
  
  //if(vst[1]==1){
  //  image(movie[1], width, 0, width, height);
  //} else if(vst[1]==0) {
  //  image(movien[1], width, 0, width/2, height);
  //}
}
