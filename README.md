# EzGL

### A powerful graphics library designed to abstract away writing graphics code at 0 cost. Spend time building beautiful, lightway, easy to use, powerful graphics, not fighting the graphics API.

There currently isn't any direct documentation since the header files + OpenGL documentation should be enough since EzGL is designed to be very very similar to them except C++ and with an extra layer so that different APIs can be used too.

First, clone this project with git and using the --recursive argument. Compile this with CMake. (This comes with a demo of how you can use this library and its different features this in the Example subdirectory, for which you'll have to create a test.png file a directory named Textures in the directory next to the executable for the texture to show and put the shaders in the Shaders subdirectory next to the executable to disable the results from the 1st window in the demo)

The default graphics library for this is glad
The default window API for this is glfw

To choose a different libraries change the target_compile_definitions for EzGL in the EzGL subdirectory

The current available graphics libraries:
glad

The current available graphics APIs:
OpenGL 3

The current available window APIs:
glfw

I'd be glad to accept additions to EzGL to improve the library

EzGL's structure is based on openGL

Thanks to Victor Gordon for some of the code! <br/>
You can find their channel here: https://www.youtube.com/c/VictorGordan/videos <br/>
Their github here: https://github.com/VictorGordan <br/>
And their code here: https://github.com/VictorGordan/opengl-tutorials <br/>
