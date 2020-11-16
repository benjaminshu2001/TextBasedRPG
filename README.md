 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Choose Your Own Adventure! (Text-based)
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: Dennis Chen - https://github.com/dchen090  
 >          David Kim - https://github.com/thedjkim   
 >          Benjamin Shu - https://github.com/benjaminshu2001

 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
> We are creating a “Choose Your Own Adventure” text-based game that will allow users to choose their own actions based on the scenarios provided.
 > * Why is it important or interesting to you?
 > * The idea of a “Choose Your Own Adventure” game appealed to us because we had all experienced the joy and anticipation from seeing our decisions being put into play within a book when we were younger. The premise of allowing one to make their own decisions freely (albeit restricted from only a number of choices due to the infinite possibilities that one can make during any situation) should allow for most people to enjoy the concept as they have the ability to see the results of their decisions in real time. We plan on implementing a basic combat system in order to enhance the experience, which hopefully will make the game more exciting overall. As such, the player can win if they finish the story, or lose if they run out of health. 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++ - This will be the main programming language that we use to code this program
 >   * Git - main way of transferring data and information w/ teammates, version control system
 >   * Vim - primary text editor for C++
 > * What will be the input/output of your project?
 >   * Input: User commands via std::cin
 >   * Output: Consequences for your actions, std::cout responses based on the scenarios given
 > * What are the three design patterns you will be using. For each design pattern you must:
 >  * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > * Strategy
 >   * We had picked this pattern because for a text-intensive game, there will be many functions that may overlap and because of that, we will be able to create an interface for families of related objects and algorithms. An example of the strategy pattern in this project would be creating algorithms for an “interact” feature, which would differ based on the object the user is interacting with. With the strategy pattern, we would define a family of algorithms, encapsulate them, and then incorporate them within the program. 
 > * Composite
 >   * We decided to use the composite design pattern because since we will have multiple objects/classes, we wanted to make the client and code less complex. It will make the code less complex by allowing us to reuse code in leaf classes, and make the client less complex by allowing it to treat composite and individual parts uniformly. A feature we will implement with this is us being able to implement new components into our code easier.
 > * Iterator
 >   * Our project uses the iterator design pattern because of our subsystems like inventory, which can hold some list of variables. We believe that using the iterator pattern will allow us to see what is in our inventory container faster and simpler. The feature we will be implementing with iterator is being able to traverse containers.
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
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
