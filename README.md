# seamcarving

The purpose of *seam carving* is to give a way to reduce an image's size.
To do so, the algorithm only deletes the useless pixels, the ones that do not change
the general informations of the image.
This special implementation of seam carving uses SDL to be able to watch the results
of the algorithm.

## Installation and usage
To be able to compile the program, you need to install the *SDL* library (1.2 version).
If you want to launch the tests, you also need *cmocka* unit tests library.

Then with make, it's all super easy

* `make` to compile the main program
* `./seamcarving` to execute

To make sure all tests pass

* `make test`
* `./unit_tests`

## Contributing
Feel free to participate! I will be happy to review any pull requests.
Just make sure to test what you do, and to check that old tests still pass.

## Contributors
* Hugues de Valon - hugues.devalon@gmail.com
