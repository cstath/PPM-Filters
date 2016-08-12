# PPM-Filters
This application provides basic image filtering for files in ppm format. You can apply successive filters and export the filtered image into an output file. The filters currently supported, are gray, blur, median, diff and color filters.

A Qt graphical front-end of the application is also included, allowing for interactive image processing.

About the Filters
-

- gray: turns the image into grayscale.
- blur: each pixel takes the average value of it's neighbours.
- median: each pixel takes the median value of it's neighbours.
- diff: each pixel takes the difference between its maximum and its minimum neighbours.
- color: each color channel (r,g,b) is multiplied by a separate scale factor.

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

to transform an image input.ppm into a grayscale version and save it as output.ppm

`./filter -f gray -o output.ppm input.ppm`

You can also supply a list of multiple filters to be applied successively, for example

`./filter -f diff -f blur -f median -f color 0.5 0.5 1 -o output.ppm input.ppm`

To run the graphical version issue

`./filterQt`

