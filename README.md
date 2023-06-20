# SDL2 Development environment
Set up the C++ development environment for SDL2 on Ubuntu.

## Environment installation

- CMake
```shell
sudo apt install cmake -y
```

- SDL2
```shell
sudo apt install libsdl2-dev -y
```

- SDL2-OtherMode
```shell
sudo apt install libsdl2-image-dev libsdl2-net-dev libsdl2-ttf-dev libsdl2-mixer-dev -y
```

## Compilation

- cmake
```shell
cmake -S <workspacePath> -B <workspacePath>/build
```

- make
```shell
cd ./build && make
```

- Run
```shell
./build/<projectName>
```
