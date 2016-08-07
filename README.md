# PPM-Filters
This application provides basic image filtering for files in ppm format. You can apply successive image filters and export the filtered image in an output file. The filters currently available, are gray, blur and diff filters. 

There is also a Qt graphical version of the application, still under development.

Installation
-

In order to build the command line executable run

`make -C filter`

To build the Qt graphical version of the application

`make -C GUI`

In order to build the respective unit test executable

`make -C test`

To build everything run

`make`

Usage
-

As an example enter the binaries directory

`cd bin`

and run in terminal

`./filter -f gray -o output.ppm input.ppm`

to transform input.ppm image into a grayscale version in output.ppm.

You can also supply a list of successive filters to be applied

`./filter -f gray -f diff -f blur -o output.ppm input.ppm`

will open input.ppm, apply gray, diff, and blur filters in the given order, and save the result in output.ppm.