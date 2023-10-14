### Snapper CPP

Straightforward Library Integration with OpenCV.

The objective of this project is to create a simplified version of a shared library between Android and iOS, which will transition some algorithms utilized in OpenV for mobile development purposes.

### Build the Project

```shell
mkdir build/
cd build
cmake ..
make

# Run binary
./snapper-cpp
```

### LSP

To ensure the autocomplete feature of our IDEs correctly locates the include (header) files in the project using CMake, it's necessary to build CMake using the following command:

```shell
cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
```

The output of the command need to generate `compile_commands.json`, it will ensure `clangd` find everything. The json file needs to be in the project root or in the build folder.
