# Assembler for the hack assembly code
This assembler was developed as a part of the nand2tetris part-I course from coursera to Convert the HACK assembly code into the hack binary machine code.

## Use this project
if you just want to use this go right ahead and build main.cpp with a compiler of your choice. Then run.
> main.exe relative/path/to/assembly/file

## Modify
1. The project structure is roughly
    ```shell    
            *The-Hack-Assembler
            |-*src                  # contains all the assembler souce code
            |   |-main.cpp
            |   |-parse.hpp
            |   |-symbol_table.hpp
            |-*test                # contains some assembly files to test the assembler against.
            |    |-Add.asm
            |    |-Max.asm
            |    |-MaxL.asm
            |    |-Pong.asm
            |    |-PongL.asm
            |    |-Rect.asm
            |    |-RectL.asm
            |-README.md
    ```

2. Clone this repo
    ```shell
        git clone https://github.com/verma16Ayush/The-Hack-Assembler.git
    ```
## Few words

Too often we see all new computer science students (or enthusiasts) 
dive headfirst into alluring terms like **machine learning** or **artificial intelligence** in name of programming. What they dont ralise is that it's not really programming in a very, dare I say 'cultural', sense. It is more like using someone else's programs. Even that at the trade-off of missing out on learning standard algorithms and algorithmic thinking, let alone learning how magnificent a symbol of human genius is a computer. How just a stream of 0's and 1's can solve some the toughest problems out there. And then realising yet there are still unsolvable problems. This course might not provide any immediate glitter to your resume but it does a great job at satiating your thirst for knowledge if you have it. The guidance to each project and lack of specific solution to them also ensure that that thirst remains alive at the same time

link to the course is [here](https://www.coursera.org/learn/build-a-computer/home/welcome)