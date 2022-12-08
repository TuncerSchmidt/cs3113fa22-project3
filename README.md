# cs3113fa22-project3

Tuncer Schmidt


# HOW TO BUILD


#It is really important to learn how to build. Go to the folder and enter folder system "cd cs3113....." 
Then, user needs to type "make clean" and after that type "make all". project3 file will be created directly. 
In my github I already added project3 file so if you type make all before make clean it will say there is nothing to commit. 
After that, for test it is really important, you need to type "./project2 quantumNumber processNumber Size ModelName". After that all output will be seen in the console directly. 
Do not forget to put "./" it is really important otherwise bash will say no command found. 
In my code I have many functions to get all necessary result. I wrote many lines of  code. It includes many functions such as  CheckForAlloc which is a function that was created to make allocation correctly according to first fit model.
CheckForFree which was created to make RELEASE operation correctly, each time it output values, ListAvailable function was created to print all the lists that
were created, there is a special format for output, ListAssigned is a function that shows all the available spots in our space, Lastly FindA function is for finding the requested variable name, if it is finds, it return output in a certain format. Basically all of them 
are for implementing first fit model. 

# ASSUMPTIONS
I was planning to solve the project by creating an array full of 0's. After each allocation I was planning to convert them to 1, or after free operation I was planning to make them 0.
After that I was planning to create and put files in array. However I could not complete the project. On my pc I get correct answer however on gradescope I get segmentaion fault
and I don't know how to solve it.
#DISCUSSION OF BUGS OR MISSING FEATURES


# CHOOSING THE QUANTUM
 Changing the number of quantum can make our code faster or slower according to implementation. For example when we increase 
 number of quantum our program
will be slower and it is very likely that we are going to get more Fault, I mean deadlocks. 
Smaller values of quantum will cause more switches so it will be make
our code slower. 

When code reads more line from same file, it is very likely that 
instruction will fail and at the end it will lead to deadlock 

# LIST OF ANY BUGS
One of the biggest problem that I had was input file because I dont have correct test files I mean all of them. So it is hard to understand what is wrong with my code. In addition to that while sending my code through gradescope, for random tests I got alloc ... failed output. I am guessing that that I did not write my code efficiently even thought I used calloc and malloc. This is the biggest problem that I have had.
I could not complete the project. I believe that testfile should be given to us. Otherwise it is really difficult to guess what is the problem. Because of that problem, I could not complete the project.

# LIST OF ANY PEOPLE, WEB, OR EXTERNAL RESOURCES THAT I USED FOR HELP


https://www.programiz.com/c-programming/c-dynamic-memory-allocation
https://www.youtube.com/watch?v=sJOZ3lvJnRI
https://www.youtube.com/watch?v=8nnIHB6RJaE
https://www.youtube.com/watch?v=N3rG_1CEQkQ
https://www.youtube.com/watch?v=y4eHnIVGSjc
Sean Nguyen: We discussed about understanding malloc and calloc and free function. We also tried to understand the how the model works. We did some sample examples on the paper.
