# Projet-Parrot-CIR3
##Introduction:
This project is a new way to command a parrot sumo.
You can use object of different colors to drive it (green/red for example) from your laptop.

##Way to compile the project:
To compile the project you will need:
```libpcap-dev mplayer libopencv-dev libopencv``` you can run apt-get install on a debian based distribution.
Then you can run ```./compile.sh``` to compile and run the program. 
Once you have compiled the program you can find the executable (```projetCir```)in the build directory.

If you want to launch the programm without connecting the parrot you can change the line ```int sumoOk = 1``` to ```int sumoOk = 0``` and then recompile the code.

The source code is in the ```projetCir``` folder.

##How to use the program.
Once the compilation is done you can run the program by typing : ```build/projetCir```. Before running the program make sure that you have already connected the parrot drone to your computer. 
###Calibration time:
To use the program you will need to calibrate the colors you want. To achieve that, present a "color1" object then move cursors until you see distinctly the object in white in the first window. Then repeat this action with your "color2" object.

Once the calibration is done you can press a key.

###Control the parrot:
Then you can control the parrot with your "color1" object just move it up to move the parrot forward etc.

We have implemented two special movements : for the jump, take your "color2" object and move it up as fast as you can. 
For a slalom you can move it as fast as you can on the right.

####Used library:
For this project we have used the <a href=https://github.com/iloreen/libsumo>lisumo</a> library and <a href=http://opencv.org/>opencv</a>.
