# Local Binary Pattern

This is an implementation of a small program that computes the [Local Binary Pattern](https://en.wikipedia.org/wiki/Local_binary_patterns) of radius 1 and clockwise of an input image.

# Build and Run
```
mkdir build
cd build
cmake ..
make
```
```
./lbp ../images/lenna.png ../results/lenna.png
./lbp ../images/baboon.png ../results/baboon.png
./lbp ../images/peppers.png ../results/peppers.png
```

# Results
<img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/images/lenna.png" width="360" height="360"> <img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/results/lenna.png" width="360" height="360">
<img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/images/baboon.png" width="360" height="360"> <img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/results/baboon.png" width="360" height="360">
<img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/images/peppers.png" width="360" height="360"> <img src="https://raw.githubusercontent.com/carlospzlz/local-binary-pattern/master/results/peppers.png" width="360" height="360">
