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

Too often we see all new computer sciece students (or enthusiasts) 
dive headfirst into alluring terms like **machine learning** or **artificial intelligence** in name of coding or programming. what they dont ralise that it is not really programming in a very, dare I say 'cultural', sense. It is more of using someone else's programs. what it costs is missing out on learning how magnificent of a symbol is a computer of human genius. how a stream 0's and 1's can be capable of solving some the toughest problems. And realising yet there are still unsolvable problems. This course might not provide any immediate glitter to your resume but it does a great job at satiating your thirst for knowledge if you have it. The guidance to each project and lack of specific solution to them also ensure that that thirst remains alive at the same time

link to the course is [here](https://www.coursera.org/learn/build-a-computer/home/welcome)