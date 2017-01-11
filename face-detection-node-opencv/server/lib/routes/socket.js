var cv = require('opencv');

// camera properties
var camWidth = 320;
var camHeight = 240;
var camFps = 10;
var camInterval = 1000 / camFps;

// face detection properties
var rectColor = [0, 255, 0];
var rectThickness = 2;


var sumo = require('node-jumping-night');


//Drone initialize

var drone = sumo.createClient();
var video;
var buf = null;

drone.connect(function() {
  console.log("Connected...");
  //
  // drone.postureJumper();
  // drone.forward(50);
  // setTimeout(function() {
  //   drone.right(10);
  //   setTimeout(function() {
  //     drone.stop();
  //     drone.animationsLongJump();
  //     drone.animationsSlalom();
  //   }, 5000);
  // }, 1000);

  video = drone.getVideoStream();
  video.on("data", function(data) {
    buf = data;
  });

});


// initialize camera
var camera = new cv.VideoCapture(0);
camera.setWidth(camWidth);
camera.setHeight(camHeight);

module.exports = function (socket) {

  socket.on("forward", function(data){
    console.log("test forward");
    drone.backward(50);
    drone.stop();
  });
  setInterval(function() {
    if (buf == null) {
     return;
    }

    try {
      cv.readImage(buf, function(err, im) {
        if (err) {
          console.log(err);
        } else {
          if (im.width() < 1 || im.height() < 1) {
            console.log("no width or height");
            return;
          }

          //Debut facedetection
          im.detectObject('./node_modules/opencv/data/haarcascade_frontalface_alt2.xml', {}, function(err, faces) {
            if (err) throw err;

            for (var i = 0; i < faces.length; i++) {
              face = faces[i];
              im.rectangle([face.x, face.y], [face.width, face.height], rectColor, rectThickness);
            }
            socket.emit('frame', { buffer: im.toBuffer() });
          });

          //Fin facedetection


          //san passer par la facedetection:
          //socket.emit('frame', { buffer: im.toBuffer() });

        }
      });
    } catch(e) {
      console.log(e);
    }
  }, camInterval);
};
