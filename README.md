# Base64Lib
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg "Build") ![License](https://img.shields.io/badge/license-MIT%20License-lightgrey.svg "License") ![Version](https://img.shields.io/badge/version-0.1.0-blue.svg)

A simple [Base64 <sup>1</sup>][1] library to encode and decode text. 

## Usage
This is a header only library so copying to your project would be easiest. Text can be encoded or decoded by passing it to an object of `Base64`. It accepts a string and returns a string. [`padding` <sup>2</sup>](https://en.wikipedia.org/wiki/Base64#Output_padding) and [`leastSignificantBit` <sup>3</sup>](https://en.wikipedia.org/wiki/Bit_numbering#Least_significant_bit) are calculated in a separate function.

```c++
Base64::Base64 obj;
obj.encode64("testEncode");            // Output: dGVzdEVuY29kZQ==
obj.decode64("aG93c0l0R29pbmc=");      // Output: howsItGoing
```

## References
1. [Base64 Wikipedia](https://en.wikipedia.org/wiki/Base64)
2. [Base64 Padding](https://en.wikipedia.org/wiki/Base64#Output_padding)
3. [Least Significant Bit](https://en.wikipedia.org/wiki/Bit_numbering#Least_significant_bit)

[1]: https://en.wikipedia.org/wiki/Base64
