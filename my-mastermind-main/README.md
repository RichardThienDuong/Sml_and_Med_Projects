# Welcome to My Mastermind
***

## Task
The project is to make a shell game where you guess a secret 4 digit code and you only have a certain amount of attempts , each guess will give you hints. 
The biggest challenge for me was consistency of putting in the hours , and alot of this was challenging, figuring out makefile, rand/srand, CTRL D EOF , and the restrictions on the random generated number for the secret code if there is no input for it . 

## Description
- takes in -c & -t or else random or default
- once have secret code & attempts print "Will you find my secret code?"
- If round > -t then end game and print lose game
- print round then ask for user input
- If wrong input then print "wrong input" then ask for input again
- run input through secret code and count # of well placed pieces there are, If count = 4 then 
- end game and print "Congratz You Did It!" else print count and continue
- run input through secret code and count # of misplaced peices then print count and continue
- back to step 3

## Installation
Nothing to install , just learning makefile made it very organized and fast to code with , and then header file to make it faster as well as link .c files

## Usage
used:  
printf(3), write(2), read(2), rand() (/ srand()), time(), atoi(), header file, makefile, 
```
./my_project argument1 argument2
```

### The Core Team
No team but had many many people help me on this.

<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
