A traveller of the skies - Guide your space-ship through the sea of cosmos.

Galaxian is an Open-GL based "old-day" type 2D game. 
This project was done as a part of Computer Graphics Course, 6th Semester (B.Tech), Computer Science and Engineering Department, Harcourt Butler Technological Institute, kanpur.

The project was made with an objective of learning 2D Animations and basic transformations. It has been written in C++ but can be converted to C language without much change. (No Classes has been used). This game is inspired by the classical DOS-era shooting games.
https://en.wikipedia.org/wiki/Galaxian

Installation on Linux Distribution

1. Install OpenGL using the following command: sudo apt-get install freeglut3 freeglut3-dev mesa-utils
2. Open the main.cpp file and compile it with: gcc main.cpp -lGL -lGLU -lglut -lstdc++

Note : Game may not work properly in linux. For best result use any windows os.

To run on Windows

1.Install MinGw c++ compiler / codeblock .
2.Install openGL in codeblocks
3.open the main.cpp file and compile it in codeblocks.


Play-Controls

Left Key = Move the ship left

Right Key =  Move the ship right

Spacebar/Left Click = Shooting

'P'/'p'/Right Click = Pause/Resume Game

'R'/'r' = Resume Game (Works only in Pause Game Screen)

'Q'/Esc Key = Quit Game

'S'/'s' = Start the game (works only in start screen)


Settings

When the program is executed for the first time the setting file with default values is generated. User can edit that file in order to achieve desired effect in the game.


Project Highlights

1. Collision-Detection Algorithm in the file move.cpp
2. Mouse Hovering Effect in the Menu
3. Double Buffering to achieve flicker-free animation. High FPS (60 Frames per seconds)
4. All Basic OpenGl function has been used
5. Settings and highscore saved using files

Project Contributors :

1. Ambrish Awasthi  86/13

2. Amit  Gautam  87/13

3. Deepak  Kumar 93/13

4. Gaurav  Sharma  526/13

