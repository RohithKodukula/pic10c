# PIC 10C: Advanced Programming
This is a repository of work for Rohith Kodukula. His UID number at UCLA is 305109022 for reference. This ReadMe file contains descriptions of each folder and what is inside it.

## Assignment1
This assignment was assigned to get a working grip on how to use git commands to update a remote repository. The fridge_contents file was developed to keep a working history of what food is being kept inside the fridge. Food is consumed and removed from fridge while food is also brought to the fridge for groceries, potlucks, and what not.

## Assignment2
This assignment was given to get a good idea of how to layout different components in the Qt Layout Design Editor. The way that the editor was designed was quite self-explanatory. I added all of the necessary GUI components pretty easily but wasn't able to implement the functions because of reasons outline below.

### Installation Problems
Since this was the first Qt project having I had great trouble trying to get the environment setup. I had a consistent error in the building of my programs: 
`cannot open file: 'qtmaind.lb'`
I emailed the TA about how I can get rid of this. We shall see what happens.

The TA got back to me with some posts that I tried to use to debug my installation. Although I had seen some of the posts before, there were some that I read through to get a better idea of why I still had the error. After reinstalling Qt Creator multiple times following some of these links:
* [Reddit Post](https://www.reddit.com/r/Qt5/comments/awrray/qt_opensource_5121_default_installation_does_not/ehos1ab/)
* [Qt Forum Post](https://forum.qt.io/topic/83996/simple-application-runs-in-release-but-debug-gives-me-a-linkage-error/12)

After conversing with the TA after discussion one day I was able to change the environment path that the build folder wrongly pointed to. Thankfully I could start coding and debugging again.

### Back to Work
The layout I had implemented worked just fine. I connected all the signals from the spin boxes and sliders to the update_label() function that I had written to update the grade.

I ran into a problem where the radio buttons didn't properly update the grade on press. Quickly resolved using the `clicked()` signal.

## Final Project: Minesweeper
### Rohith's Section
The main hinderance in starting the final project was my inability to compile in my Qt environment. Emailing back and forth with the TA I had to install Qt several times from scratch. This process is detailed above in the "Installation Problems" section.

Finally started working on the project, starting with the initialization of a board and the ability to add bombs. The process of incrementing the neighboring cells took a lot of hard coding cases and probaly could have been done more efficiently.
 
 After trying to connect the QPushButtons with them disappearing I found it easier to make a new class called Cell that would act as the stacked widget that I needed. Started a new branch of this called 'rohith-experimental'.

### Zoeb's Section
* 06/03/2020 learning how to play minesweeper - used this video! https://www.youtube.com/watch?v=7B85WbEiYf4
* 06/04/2020 created new branch off master (experimental-zoeb) - working on how to design the ui. Current possible ideas include using key sequence edit widget to take input (U for uncover, F for flag) also use stack widget container to display the resulting change (if U is pressed, display either bomb or number, if F is pressed, display flagged graphic)
  * currently, I am working on how to get all of these widgets connected, I need to make another MainWindow constructor for widgets. This turned out to be harder than expected so I am going to create a new branch off of master and work on game functionality. Initially I used a vector of vectors like Rohith had done in the QT project, but after browsing stack exchange, I realized a 2D array may work better as it is more intuitive
* 06/04/2020 created new branch off master (experimental_game_funtionality-zoeb) - going to try and add some more game functionality, like what happens if you press a bomb
* 06/05/2020 (morning) progress update - So I was able to make some possible classes for bombs and a game, running these together will generate an 8x8 board (made with a 2D array) with 8 bombs (set to int value 10) and 56 blank spaces (int value 0). Tomorrow I will attempt to increment the adjacent values so they reflect how many bombs are nearby. I will also try to play around with QT and work on connecting the UI to the code.
 * 06/05/2020 (afternoon) so incrementing adjacent values was harder than I thought... I tried multiple methods but couldn't seem to get them to work - I also added a nonbombcell class but it wasn't useful. However, I have kept the file as I may be able to figure out how to use it. I will now move on to messing aroud with QT to figure out how the UI may work
 * 06/05/2020 (night) - I ran into several not so cute problems (pun intended). It was pretty hard to try and intuitively figure out how exactly to generate the board. I first tried by using the mainwindow.ui form and dragging and dropping widgets but this proved to be more difficult that expected. I rewatched some of the TA's recorded discussion sessions (specifically day 13 - adding widgets without using the ui form) but I still did not get a concrete grasp on how to scale this up to a 10x10 grid. Rohith has made more progress in this department so hopefully he can show me how. For now I guess I'll stick to trying to figure out a method of generating the board in a concise and clean manner. I also ran into some issues with git on my local machine - it was still showing branches that had been deleted on github. I don't want to create any big issues so I will store back up copies of all my code just in case. I'll also do a bit more research into git and hopefully try to get the errors resolved since committing directly from my machine is so much easier than manually uploading files. The goal for tomorrow is to figure out the git issues (I believe it has something to do with the build files not being added to git), understand more about integrating widgets in QT, and hopefully finish the code to initialize the minesweeper board fully. 
   * my current method to get the adjacent cells to display the correct value is to check if each cell has an adjacent cell that is a bomb (int value 10) and then add 1 to the cell. I think I may be running into issues because currently the first time the loop runs it tries to access an out of scope value (if the 2d array starts at [0][0] my loop starts looking for a bomb at [0 - 1][0 - 1]) **_note:_** **I just realized that I may be having issues because I have been thinking about the array as a grid with "y" values increasing upwards rather than downwards - A quick peek at https://www.tutorialspoint.com/cplusplus/cpp_multi_dimensional_arrays.htm confirmed this hypothesis.**
  I don't think I'll work on the project anymore tonight as it is rather late but I will incorporate this when I work on the goals for tomorow.
