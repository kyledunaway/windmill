Kyle Dunaway
CSCI 566


windmill
========
OpenGL Windmill For Graphic Interface Class at CSU Chico


Extract the zip file to a folder, then naviage to said folder.

The Makefile titled "OSXMakefile" will compile the program for OSX.

The Mafefile titled "Makefile" will compile the program for Linux, hopefully.



Run

> make

The executable is labeled "main"

Run

> ./main

The program should start.

The keys for this program are:

r - To reset the windmill

s - To start and stop the windmil

y - to rotate the windmill


Difficulties and Challenges

The rotation, scale, and transformations were the hardest part of this program, hence the idea behind the program.  
Once the order of those were figured out, the program came together quite well.  Building piece by piece was the best way to tackle this program as once i have a post being rendered, and rotating, starting/stoping, and resetting, adding the blades wasnt too difficult.

The design implementation was to use a static vec3 array for the unit cube, and pass this cube around to each cube object.  From this, each cube object was able to manipulate the unit cube to be scaled to where i wanted them located.

