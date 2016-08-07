# seamcarving

The purpose of *seam carving* is to give a way to reduce an image's size.
To do so, the algorithm only deletes the useless pixels, the ones that do not change
the general informations of the image.
This special implementation handles only BMP images (so far...) using the QDBMP library.

## Installation and usage
To install and compile the program, you will need a C compiler and GNU `make`.
If you want to launch the tests, you also need *cmocka* unit tests library.

Download the code using `git`: `git clone https://github.com/HugZz/seamcarving`  
Or just download the ZIP directly from GitHub and extract it.

Then with `make`, it's all super easy

* `cd seamcarving`
* `make` to compile the main program
* `./seamcarving ORIGINAL_FILE NEW_WIDTH DESTINATION_FILE` to execute

To make sure all tests pass

* `make test`
* `./unit_tests`

## Contributing
Feel free to participate! I will be happy to review any pull requests.
Just make sure to test what you do, and to check that old tests still pass.

## Contributors
* Hugues de Valon - hugues.devalon@gmail.com
