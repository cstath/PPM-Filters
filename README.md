# PPM-Filters
Image filtering for PPM files

Installation
-

Build command line executable

`make -C filter`

Build Qt graphical version of the application

`make -C GUI`

Build unit test executable

`make -C test`

Build everything

`make`

Usage
-

Run in terminal

example `./filter -f gray -f diff -f blur -o output.ppm input.ppm`

will open input.ppm, apply gray, diff, and blur filters in the given order, and save the result in output.ppm.
