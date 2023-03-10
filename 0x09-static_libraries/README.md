## What Is A "C" Library? What Is It Good For?
One of the tools that compilers supply us with are libraries. A library is a file containing several object files, that can be used as a single entity in a linking phase of a program. Normally the library is indexed, so it is easy to find symbols (functions, variables and so on) in them. For this reason, linking a program whose object files are ordered in libraries is faster than linking a program whose object files are separate on the disk. Also, when using a library, we have fewer files to look for and open, which even further speeds up linking.

Unix systems (as well as most other modern systems) allow us to create and use two kinds of libraries - static libraries and shared (or dynamic) libraries.

Static libraries are just collections of object files that are linked into the program during the linking phase of compilation, and are not relevant during runtime. This last comment seems obvious, as we already know that object files are also used only during the linking phase, and are not required during runtime - only the program's executable file is needed in order to run the program.

C - Static libraries


TASKS


[0. A library is not a luxury but one of the necessities of life](libmy.a)


Create the static library libmy.a containing all the functions listed below:


If you haven’t coded all of the above functions create empty ones with the right prototype.


Don’t forget to push your main.h file to your repository. It should at least contain all the prototypes of the above functions.


[1. Without libraries what have we? We have no past and no future](create_static_lib.sh)


Create a script called create_static_lib.sh that creates a static library called liball.a from all the .c files that are in the current directory.
