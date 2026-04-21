# Battle-of-the-Boxes---COP-3003
Team Members: Ethan Pedrick, Fisher Nowicki, Brittney Moore, Woodolph Sylvain

## Setup Instructions:
1. Clone the repository locally.
2. Open the project in your IDE.

the build/run buttons should work in your IDE

### windows
if you are using visual studio then install git from here: https://git-scm.com/install/ <br>
even if you already have git installed from visual studio you need install it again from the above link

### linux
to build manually in a terminal
```bash
cmake -B build
cmake --build build
```
make sure you have all of sfml's requirements found on [sfml's documentation](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#customize-the-cmake-project-and-executable-names)

## Game Description
A roguelike turn-based dungeoncrawler (innovative, I know...) where the user plays as a box trying to escape an Amazon warehouse. During their escape, they have to battle zombie-like workers and finally defeat Jeff Bezos to win.

### Controls
The player will use either W, A, S, and D keys to move throughout the game, with some moments requiring input from the the players mouse with on screen buttons.

## Project Requirements
### OOP Requirements
- __Classes & Objects__
  - multiple classes and objects interact to form the project
- __Encapsulation__
  - all class data members are private and use methods to modify their values
  - m_currentStage within the StageController class is private. to change the value of m_currentStage you must use the changeStage method
- __Composition__
  - Character "has-a" HealthPool component
- __Inheritance__
  - PlayerCharacter and Enemy are derived classes of Character
- __Templates__
  - \
- __Polymorphism__
  - The Card class has a virtual __use__ method which is used with an array of Card derived objects in the Character class
- __Abstract Classes__
  - The __use__ method within the Card class is a pure virtual function
### Programming Requirements
- Use of:
  - Functions
    - functions are used in every class
  - Control structures
    - Control structures are used throughout function implementations
  - Arrays and/or vectors
    - A vector is used for managing the list of cards within a Deck object
- Exception Handling
  - \
### GUI Requirements
- Event-driven GUI
  - sfml uses an event loop to manage user input and drawing graphics to the screen
- 3 different interactive components
  - Buttons such as start or exit buttons
  - Cards that increase in scale when hovered can be dragged around the screen
  - HealthPools display their m_current_health and b_block data members with bars on screen
- Input validation
  - clicking of buttons validate that the user's mouse is hovering over the button before it sets the m_clicked data member to true
- Clear, user-facing error messages
  - an error message is given when image files required by the game are failed to be found
- Logical layout and usability
  - layout of the gui is sensical and uses ratios of screen width and height for positioning rather than arbitrary numbers
  - gui elements are reactive to user input and show that they are working with every action
 
## UML diagram
![UML Diagram Image](uml.png)
to generate an image from the d2 code run: d2 uml.d2 uml.png
