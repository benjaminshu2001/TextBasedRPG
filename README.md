# Choose Your Own Adventure! (Text-based)
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: Dennis Chen - https://github.com/dchen090  
 >          David Kim - https://github.com/thedjkim   
 >          Benjamin Shu - https://github.com/benjaminshu2001

## Project Description
> We are creating a “Choose Your Own Adventure” text-based game that will allow users to choose their own actions based on the scenarios provided.
 > * Why is it important or interesting to us?
 > * The idea of a “Choose Your Own Adventure” game appealed to us because we had all experienced the joy and anticipation from seeing our decisions being put into play within a book when we were younger. The premise of allowing one to make their own decisions freely (albeit restricted from only a number of choices due to the infinite possibilities that one can make during any situation) should allow for most people to enjoy the concept as they have the ability to see the results of their decisions in real time. We plan on implementing a basic combat system in order to enhance the experience, which hopefully will make the game more exciting overall. As such, the player can win if they finish the story, or lose if they run out of health. 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++ - This will be the main programming language that we use to code this program
 >   * Git - main way of transferring data and information w/ teammates, version control system
 >   * Vim - primary text editor for C++
 >   * GoogleTest - primary way for making unit test cases and testing our code
 > * What will be the input/output of your project?
 >   * Input: User commands via std::cin
 >   * Output: Consequences for your actions, std::cout responses based on the scenarios given
 > * Our Three Design Patterns 
 > * Strategy
 >   * We had picked this pattern because for a text-intensive game, there will be many functions that may overlap and because of that, we will be able to create an interface for families of related objects and algorithms. An example of the strategy pattern in this project would be creating algorithms for an “interact” feature, which would differ based on the object the user is interacting with. With the strategy pattern, we would define a family of algorithms, encapsulate them, and then incorporate them within the program. 
 > * Composite
 >   * We decided to use the composite design pattern because since we will have multiple objects/classes, we wanted to make the client and code less complex. It will make the code less complex by allowing us to reuse code in leaf classes, and make the client less complex by allowing it to treat composite and individual parts uniformly. A feature we will implement with this is us being able to implement new components into our code easier.
 > * Visitor
 >   * Our project uses the visitor design pattern because of our subsystems like inventory, which can hold some list of variables. We believe that using the visitor pattern will allow us to see what is in our inventory container through the amount of visits per type of equipment. The feature we will be implementing with visitor is being able to list the amount of each type of item (armor and weapon in this inventory system).
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 ![strategy pattern](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/strategy_design_pattern.png?raw=true)
 
 This is the strategy pattern that incorporates two different functionalities based on the type of attack in our combat system. For instance, if you were 
 to attack with a normal attack, you would just attack with your raw strength. With the stronger attack, you would utilize mana, a secondary resource, which allows
 you to deal more damage to the enemy.
 
 ![composite pattern](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/composite_design_pattern.png?raw=true)
 
 This is the composite pattern, which allows us to traverse through areas within our game. Within each area, we are allowed to move in a direction and fight monsters if 
 there are any present. By utilizing the composite pattern, we are able to traverse through many different types of areas based on one's location.
 
 ![visitor pattern](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/visitor_design_pattern.png?raw=true)
 
 This is the visitor pattern, where we can obtain the count of each type of equipment in the player's inventory system. Each item will be visited and accepted, which causes flow of control in order to obtain full object control. This adds additional information to the user and allows ut to define a new operation without changing the classes (in this instance, the types of items stored in the inventory). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.
 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 
 ![Starting Screen](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/Start.png)
 
 Here is the starting screen, where you can either input 2 chars, 'x' or 'z'. 'X' starts the game, while 'z' stops the program.
 
 ![Name](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/PlayerName.png)
 
 Here, the player inputs a name, which will be outputted in other functions to refer to the player.
 
 ![Map](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/Map.png)
 
 While not in your inventory screen or a fight, the player can input 'm' to output the entire map and your location relative to all other rooms.
 
 ![Inventory](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/Inventory.png)
 
 While not already in an inventory screen or a fight, the player can input 'i' to output their inventory screen and manage it from there with various inputs.
 
 ![Fighting](https://github.com/cs100/final-project-dchen090-bshu005-dkim417/blob/master/images/Fighting.png)
 
 During a fight, the player can input '1' or '2' to output damage towards the monster in a room. Fighting ends when either the player health or monster health reaches 0.
 
 ## Installation/Usage
 > To install and run this game, download the repository and files, run make, and then input ./Game.
 > Afterwards, prompts will appear on the screen informing the player of what actions can be done, and what inputs one uses to do those actions.
 ## Testing
 > We ran through our game multiple times from beginning to end, doing everything possible and fixing any bugs that popped up along the way. In terms of unit tests, we used google tests as well. In order to access the unit tests, simply run "cmake3 .", make, then ./test, in this respective order. 
