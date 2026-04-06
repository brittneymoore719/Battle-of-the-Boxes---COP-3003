# Battle-of-the-Boxes---COP-3003
Team Members: Ethan Pedrick, Fisher Nowicki, Brittney Moore, Woodolph Sylvain

## Setup Instructions:
1. Clone the repository locally.
2. Open the project in your IDE.

the build/run buttons should work in your IDE

to build manually in a terminal
```bash
cmake -B build
cmake --build build
```
if you are on linux make sure you have all of sfml's requirements found on [sfml's documentation](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#customize-the-cmake-project-and-executable-names)

Game Description:
  A roguelike turn-based dungeoncrawler (innovative, I know...) where the user plays as a box trying to escape an Amazon warehouse. During their escape, they have to battle zombie-like workers and finally defeat Jeff Bezos to win.

Controls:
The player will use either W, A, S, and D keys to move throughout the game, with some moments requiring input from the the players mouse with on screen buttons.
## UML diagram
![UML Diagram Image](uml.png)
to generate an image from the d2 code run: d2 uml.d2 uml.png
