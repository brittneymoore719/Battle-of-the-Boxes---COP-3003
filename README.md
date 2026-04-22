# Battle of the Boxes
Brief description of your project (1–2 sentences).

A roguelike turn-based dungeoncrawler (innovative, I know...) 
where the user plays as a box trying to escape an Amazon warehouse. 
During their escape, they have to battle zombie-like workers and finally 
defeat Jeff Bezos to win.

---
## Team Members
- Ethan Pedrick
- Fisher Nowicki
- Brittney Moore
- Woodolph Sylvain
---

## Setup Instructions:
1. Clone the repository locally.
2. Open the project in your IDE.

the build/run buttons should work in your IDE

to build manually in a terminal
```bash
cmake -B build
cmake --build build
```
if you are using visual studio then install git from here: https://git-scm.com/install/ <br>
even if you already have git installed from visual studio you need install it again from the above link

if you are on linux make sure you have all of sfml's requirements 
found on [sfml's documentation](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#customize-the-cmake-project-and-executable-names)
---
## Features
- Feature 1 card decks
- Feature 2 pass button
- Feature 3 discard button
- Feature 4 exit
- Feature 5 block and attack
- Feature 6 the characters box and worker

---
## OOP Concepts Used
## Encapsulation
All classes’ members are private
Getter and setter functions are used if necessary
Characters have getHealthPool() methods to get access to a character’s health pool

## Abstraction
Updatable is an abstract class
Allows Stages and UiButtons to update when necessary
Stage and UiButton implement update() differently

## Inheritance
PlayerCharacter and Enemy extend Character
Ui elements extend UiElementBase

## Polymorphism / Composition
Card is a base class with virtual use() method
BasicAttack and Block implement use() differently.
Characters are built from smaller parts like Deck and HealthPool

## Team Contributions
### Member 1: Ethan 
- Responsibility 1
- Responsibility 2
### Member 2: Fisher
- Responsibility 1
- Responsibility 2
### Member 3: Brittney
- Responsibility 1
- Responsibility 2
### Member 4: Woodoplh 
- Responsibility 1
- Responsibility 2
---

## AI and External Resources Disclosure (Required)
You must clearly document **all external help used** in this project.
### AI Tools
List any AI tools used (e.g., ChatGPT, Copilot, etc.) and describe:
- What you asked the AI to do
- What code or explanation it generated
- What you modified or learned from it
Example:
- ChatGPT: Helped generate initial structure for the Task class. We
modified variable names, added validation, and integrated it with our
TaskManager.

## AI tools used

-Github AI: Helped to solve errors that we came across. 
- Claude: Helped to solve errors we came across, especially after trying to debug it for 30+ mins.
- ChatGPT: Helped to solve errors came across, pasting the error into ChatGPT to figure why it wasn't working.

### External Resources
List all non-AI resources used:
- Websites (e.g., Stack Overflow, tutorials)
- Documentation
- YouTube videos
- Sample code
Include links when possible.

Youtube videos used:
-Youtube Video on Github https://www.youtube.com/watch?v=a9u2yZvsqHA
-Youtube Video on Guthub https://www.youtube.com/watch?v=Oaj3RBIoGFc&t=633s
-Youtube video on SFML https://www.youtube.com/watch?v=yEiZalvDOj4&t=457s
-Youtube video on pointers https://www.youtube.com/watch?v=eNofmKYzje4

### Collaboration Policy Statement
All submitted work reflects our team’s understanding. Any external code
has been:
- Reviewed
- Modified as needed
- Integrated by our team


## Aditional Notes
- We initally had a much larger projected but condensed due to time constraints
