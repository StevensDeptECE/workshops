# OpenGL Workshops

Welcome to the OpenGL Workshops hosted by Professor Dov Kruger. These workshops
were hosted on Tuesdays and Thursdays in June 2022. Contact
[Prof. Kruger](mailto:dkruger@stevens.edu) if you are interested in joining
future workshops. The following will function as a log of the workshops with a
basic tutorial for getting setup. Best of luck and have fun with it!

## Getting Started - June 7, 2022

In this session, students prepared their environments to work with OpenGL and
made sure that they were able to run the immediate mode programs. If you are
following along and have any issues with getting started, please [open a new
issue](https://github.com/StevensDeptECE/workshops/issues/new/choose) or send
[Prof. Kruger](mailto:dkruger@stevens.edu) an email.

### Setting up

#### On Windows 10

1. [Install MSYS2](https://www.msys2.org/)

1. Run MSYS2: `MSYS2 MinGW 64-bit` from the Windows Start Menu.

   - Make sure you are running the correct executable or else you will have
     trouble with the C++ compiler not recognizing your system correctly.

   - Already installed MSYS2 but haven't used it in a while? Make sure to run `pacman -Syu` to update your environment. If you get a message saying that you need to restart MSYS2 (or if you're unsure) then run `pacman -Syu` again. This will make sure your packages also in the update in the event that the first update only covered `msys2-runtime` and associated packages.

1. Install initial dependencies

  ```shell
  pacman -S git nano make mingw64/mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-gcc mingw-w64-x86_64-toolchain mingw-w64-x86_64-freeglut
  ```

#### On Linux (Ubuntu)

1. Install initial dependencies

  ```shell
  sudo apt install build-essential freeglut3-dev
  ```

#### On Linux (Arch)

1. Install initial dependencies

  ```shell
  sudo pacman -S base-devel freeglut
  ```

### Compiling your first program(s)

1. In the `MSYS2 MinGW 64-bit` shell, go to this directory

1. Run `cd 00immediatemode` to go into the directory with the immediate mode demos

1. Run `make` to compile all of the immediate mode demos at once

     - Alternatively, you can run `make <demoname>` to make a specific demo. Try out `make 00a_quad` as an example

1. Run any of the demos in the directory, like `./00a_quad` and see if something appears on screen
