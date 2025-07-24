# Shifratori

Shifratori is a simple console-based encrypter/decrypter with colored output, written in C++.

## Features

- XOR encryption with a random key  
- ANSI-colorized console output  
- Command-line parsing that respects quotes and spaces  
- Modular engine design  

## Build

Using CMake:

```bash
git clone https://github.com/Vladyslaa/Shifratori.git
cd Shifratori
mkdir build && cd build
cmake ..
make
```

## Usage Example

```bash
> encrypt "Hello world"
Coded text: <C9 D5 C2 0A A5 9F 75 D0 86 2C 75>
Key: <81 B0 AE 66 CA BF 02 BF F4 40 11>
> decrypt "C9 D5 C2 0A A5 9F 75 D0 86 2C 75" "81 B0 AE 66 CA BF 02 BF F4 40 11"
Decoded text: <Hello world>
```

## Future Horizons 

| Priority | Feature               | Probability |
|:---------|:----------------------|:------------|
| P0       | Securely store the key| 69%         |
| P1       | GUI                   | 11.61%      |
| P2       | File encryption       | 4.20%       |
| P3       | Quantum-resistant algo| 1.48%       |

## License

MIT License, do WTF you want