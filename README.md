# Learning Graphical User Interfaces 

## Requirements

- QT library
- VTK library
- OpenCV 4.3.0 with Qt and VTK support

## Steps to build

To compile on Linux, mac or Windows using Mingw

```
mkdir build
cd build
cmake ..
make
```

## Executables

The following applications are generated.

```
./build/sample1
./build/sample2
./build/sample3
./build/sample4
./build/sample5
./build/sample6
```

Sample 1. Basic GUI
- Differences between Qt and Normal GUI
- Create a window
- Move
- Resize
- Wait for key
- Destroy

Sample 2. Qt functions
- Properties window
- Overlay
- Status Bar
- Note: Save and load

Sample 3. Create a Slider
- Create a slider
- Event slider
- Add +1 to image

Sample 4. Create a button
- Create a button
- Event button
- Change color to gray

Sample 5. Advanced UI. OpenGL
- Create an interface
- Add some boxes
- Update

Sample 6. Advanced UI. VTK
- Create basic VTK sample
