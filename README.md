# Sliding Puzzle with SDL2
A simple sliding puzzle game made with SDL2. It features a menu to choose difficulty and a stopwatch to measure time elapsed.

![Sliding-Puzzle-gif-1](assets/Sliding-Puzzle-1.gif?raw=true)
![Sliding-Puzzle-gif-2](assets/Sliding-Puzzle-2.gif?raw=true)

## Requirements for Linux
Requires the following to be installed:
  - git
  - g++
  - make
  - cmake
  - SDL2
  - SDL2_ttf
 
On Debian-based systems (including Ubuntu), SDL2 and SDL2_ttf can be installed by doing:
```
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
```

More info on SDL installations at https://wiki.libsdl.org/Installation

## Run on Linux
```
git clone --recurse-submodules https://github.com/SirFourier/Sliding-Puzzle-with-SDL2.git
cd Sliding-Puzzle-with-SDL2
cmake .
make
./Sliding-Puzzle
```

## Code structure
![diagram-of-code-structure](assets/code-structure.png?raw=true)
