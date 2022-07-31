# EzGL

### A powerful graphics library designed to abstract away writing graphics code at 0 cost. Spend time building beautiful, lightway, easy to use, powerful graphics, not fighting the graphics API. 

Compile this with CMake. (This comes with a demo of how to use this in EzALExe, for which you'll have to create a test.ogg file in the directory next to the executable for it to play)

The default graphics library for this is glad

To choose a different libraries change the target_compile_definitions for EzGL in the EzGL subdirectory

The current available graphics libraries:
glad

The current available graphics APIs:
OpenGL 3

The current available window APIs:
glfw

I'd be glad to accept additions to EzGL to improve the library

EzGL's structure is based on openGL

Thanks to Victor Gordon for some of the code!
You can find their channel here: https://www.youtube.com/c/VictorGordan/videos
Their github here: https://github.com/VictorGordan
And their code here: https://github.com/VictorGordan/opengl-tutorials
