#! /usr/bin/bash
g++ -c Test.cpp 
g++ Test.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app