# Ivy
 A really simple text encryption algorithm. It was made specifically for that one easteregg in 
 [Pendulums](https://github.com/FedNazar/Pendulums) demo.
 
## Usage
 It's a command line utility.
 
 `ivy [operation] [input filename] [output filename] [key]`
 
 ### Operations
 - -e - encrypt
 - -d - decrypt
 
 ### Example
 `ivy -e input.txt output.txt D8W9EF0JBF89W1IQ`
 
 ### Note
 This algorithm works with UTF-16 encoded files only.
 
## Building
 Use Microsoft Visual Studio 2017 (with standard C++ components installed) or higher to compile it.
