# Introduction to Parallel Programming Technologies

Parallel programming is a way to make computers faster

1. Multithreading
   1. threads
   1. Note: threads have huge problems (race conditions, deadlock, overhead)
   1. Intel hyperthreading
1. SIMD (Single Instruction, Multiple Data)
   1. Vectorization
   1. Intel: SSE, AVX, AVX2, AVX512 (only AMD?)
   1. ARM: Neon
1. [ISPC](https://ispc.github.io)
1. [CUDA](https://developer.nvidia.com/cuda-downloads)
   1. [Google Cloud will let you use NVIDIA if you register!](https://cloud.google.com/gpu)
1. OpenMP (Automatic generation of threading with shared memory)
1. MPI (Message Massing Interface)
   1. Run programs on many computers in parallel
   1. Computers communicate by sending messages to each other over a backbone
   1. Message latency can be an issue
   1. Most supercomputers run massive numbers of CPUs splitting jobs with MPI. They may also use NVIDIA cores on each one
   1. [top500](https://www.top500.org/system/180047/)

For all these technologies (excepto MPI), it turns out they are usually memory bound

1. Threading with C++ threads (a wrapper on the OS)
1. openmp
1. avx
