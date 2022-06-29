# Ivy
 A really simple text encryption algorithm. It was made specifically for that one easteregg in 
 [Pendulums](https://github.com/FedNazar/Pendulums) demo.
 
## Usage
 It's a command line utility.
 
 `ivy [-e]/[-d] [input filename] [output filename] [key]`
 
 ### Switches
 - -e - encrypt
 - -d - decrypt
 
 You can also use backslash (`/e`, `/d`).
 
 ### Examples
 `ivy -e input.txt output.txt D8W9EF0JBF89W1IQ`
 `ivy /d input.txt output.txt D8W9EF0JBF89W1IQ`
 
 ### Note
 This algorithm works with UTF-16 encoded files only.
 
## Example

### Original message
`Hello World!`

### Encrypted
Uses the key: `D8W9EF0JBF89W1IQ`

`368 205 -252 -12 -105 360 63 503 378 436 204 -87 `
 
## Building
 Use Microsoft Visual Studio C++ 2017 or higher to compile it. No other dependencies required.
