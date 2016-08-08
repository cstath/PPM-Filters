# PPM-Filters
This application provides basic image filtering for files in ppm format. You can apply successive filters and export the filtered image into an output file. The filters currently available, are gray, blur, median and diff filters. 

It also includes a simplistic Qt graphical front-end of the application, allowing for interactive image processing.

Installation
-

In order to clone the repository open a command line and issue

`git clone https://cstath@bitbucket.org/cstath/ppm-filters.git`

Enter the repository directory

`cd ppm-filters`

To build the program run

`make`

To build only the command line executable run

`make -C filter`

To build only the Qt graphical version of the application

`make -C GUI`

In order to build only the test executable

`make -C test`



Usage
-

To run the executables, first enter the bin directory

`cd bin`

and to transform an image input.ppm into a grayscale version and save it as output.ppm

`./filter -f gray -o output.ppm input.ppm`

You can also supply a list of multiple filters to be applied successively, for example

`./filter -f gray -f diff -f blur -f median -o output.ppm input.ppm`

To run the graphical version issue

`./filterQt`

