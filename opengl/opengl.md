# OpenGL Syllabus

1. Introduction to the OpenGL Environment
 a. What you will need (You probably already have most)
   i. MSYS2 on Windows
   i. glut
   i. glu (glue functions)
   i. OpenGL library
   i. GLFW windowing toolkit
   i. IDE
   i. Debugger set up (can be gdb, or graphical debugger in the IDE)
   i. Microsoft vscode environment to collaboratively edit with in class
   i. git and github setup.
   i. Just for grins: processing (quick and easy coding)
   i. Lots of setup to do, all good to know
 a. What is OpenGL?
   i. An API for high-performance rendering
   i. Focused on gaming and simulation, not 2d applications
   i. Has low-level access to framebuffer (raw pixels) for applications like video
   i. Ability to define 3d objects and perform transformations.
   i. Pipeline that uses hardware (graphics card) for awesome speed.
   i. OpenGL does not cover opening windows (glut, GLFW, GTK, sdl...)
   i. The future (OpenGL vs. Vulkan)
   i. What OpenGL does NOT do
     a. audio
     a. video
     a. nice fonts
     a. windows
     a. text and mouse input
1. Intro
 a. Graphics rendering hardware
 a. The rendering pipeline
 a. 3d vs. 2d graphics
1. First Program
 a. glut, a primitive portable windowing toolkit
 a. Immediate mode: old, simple, but slower
 a. Solid color and Gouraud shading
 a. OpenGL drawing primitives
1. Transformations
 a. matrix math
 a. the transformation stack
1. Lighting
 a. ambient
 a. spot
 a. materials
