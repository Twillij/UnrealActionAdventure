# Work Plan
The work plan currently contains a list of all the tasks that will be worked on for this project in chronogically descending order.  
As tasks get finished, new tasks will appear in the list.  


## Task 001: Basic main menu

### Description
Create a new main menu level.  
Contains Start and Quit option.  
- Start loads the default test level.
- Quit closes the app.

### Status
Completed 24 April 2023


## Task 002: Basic test level

### Description
Create a new level for testing gameplay.  
It needs to contain:
- A spawner for the player character
- A platform for the character to run around on
- Basic lighting and skybox

### Status
Completed 24 April 2023


## Task 003: Set up Gameplay Ability System

### Description
Enable the GAS plugin.  
Add the dependency to the build.cs.  
Ensure the module can be accessed for development.  

### Status
Completed 26 April 2023


## Task 004: Basic character attribute set

### Description
Create a basic attribute set with two values: HP and MP.  
Implement this on the base character class.  
This also means it needs to be set up with an Ability System Component.

### Status
Completed 26 April 2023


## Task 005: Basic save game

### Description
Create a basic save game object.  
Save game contains basic player info:
- Last player position
- Last map name
- Last attribute values, like HP and MP

### Status
Completed 01 May 2023


## Task 006: Basic load game

### Description
Create a basic functionality for loading the saved game.
By completion, we should be able to spawn a character with the same params as the previous session.

### Status
Completed 10 May 2023


## Task 007: Basic pause menu

### Description
Create a basic pause menu that pauses the game.  
It should show these basic options:
- Restart game
- Return to title
- Quit game
- Open dev menu

And also have these basic functionalities implemented.

### Status
Completed 10 May 2023


## Task 008: Basic initializer for character attributes

### Description
Set up a basic initialization process for character attributes.  
This should involve creating an initializer gameplay effect and storing it for the character.

### Status
Completed 12 May 2023


## Task 009: Basic save interface

### Description
Set up a basic save interface class to implement to different objects.  
Each object should be able to implement their own saving and loading behaviour from the interface.

### Status
Started 15 May 2023


## Task 010: Loading of character attributes

### Description
Enable the loading of character attributes when entering the game or loading a new map.

### Status
Not yet started
