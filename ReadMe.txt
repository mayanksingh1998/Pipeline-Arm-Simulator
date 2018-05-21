To compile  the code:-
1 => open the folder and go to the directory src.
2 => Run the terminal and type the following command 

"g++ gui.cpp data.cpp pipe.cpp file.cpp -lGLU -lglut -lGLEW -lGL -o processor_simulator "
 

if any error comes up then type the command 


"g++ gui.cpp data.cpp pipe.cpp file.cpp -lGLU -lglut -lGLEW -lGL -o processor_simulator -std=c++11 "

3 => Now run the simulator by typing " ./processor_simulator ".
4 => Now program will execute you have the option to run the pipeline till end or to run upto some specific cycles type "end" to run it till end.

Note:= You must provide in.txt and latency.txt.


