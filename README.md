# Bacon_Number
**Problem Overview** <br/>
This project will use the BRIDGES API with an actor/movie dataset from IMDB. You be building a graph using BRIDGES elements, which will enable you to visualize the network of connections between actors and movies. Note that the BRIDGES visualization will also be a means to debug your program, as it will let you view your data structure and its contents after each operation. The actor/movie dataset has been curated from IMDB as a text file containing a set of actor/movie pairs, one pair per line.

The driver will be managing the actors and movies details so you can focus on operations related to the graph.

The primary function you will be writing is to determine the Bacon Number. The concept is a game created to demonstrate six degrees of separation as it plays out for actors. The goal is to link any actor to Kevin Bacon through other actors and the movies they were in. Each actor counts as one degree and the complete process should be six or less.

**Resources**<br/>
Bacon Number: https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon
Six degrees of separation: https://en.wikipedia.org/wiki/Six_degrees_of_separation
Bridges Site: http://bridgesuncc.github.io/
Getting Started: http://bridgesuncc.github.io/bridges_setup.html
API Documentation: http://bridgesuncc.github.io/doc/cxx-api/current/html/index.html

**Solution Specifications**<br/>

Implement AddVertex, AddEdge, VisualizeVertex, VisualizeEdge, ResetVisualizer, and GetBaconNumber for the adjacency graph implementation in ImdbGraph.cpp. A class header and function stubs has been given to you. Please read the header file for detailed description of the functions.

**Test Driver** <br/>
Create alternate tests to cover all the test functions
Create an user input test file to allow for consistent and repeatable testing

**Sign Up For BRIDGES** <br/>
_Note -- you only need todo this once. If you have an account already, you do not need to do it again._

Please sign up for a BRIDGES account at Bridges Sign Up. Once you have an account, put your username and the API Sha1 key in the BridgesUser.h file.

Sign up for (bridges](http://bridges-cs.herokuapp.com/signup)
Navigate to your profile.
Put your User Name in BridgesUser.h file
Put your API Sha1 Key in BridgesUser.h file
These steps are need to make sure you have access to the IMDB data and visualization for the project.

**Setup Local IDE** <br/>
Follow the Bridges Setup Directions to configure your system. Please install the libraries in your student242/include folder for the make file to work properly. (If you install in another directory, the make file will need to be altered.)

_A script has been created for **Code.CS**. If you are using a different IDE, take a look at the website for set up details. You can also look at supplied set up script to see the exact commands which are being used by **Code.CS**._

If you are using **Code.CS**, do the following:

cd [Name]
./setup_bridges_on_linux.sh
Compiling Graph Implementations
A make file has been provided to help with compiling your code. Simply run make to compile your code after the set up has been completed. Then execute ./ImdbGraph.out. These commands have been tested on c9.io and the lab computers.

make
./ImdbGraph.out
The build files can be cleaned up by running make clean.
