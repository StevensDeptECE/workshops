# Intro to CUDA

[CUDA programming manual](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html)

[Download CUDA](https://developer.nvidia.com/cuda-downloads)

[Google cloud can do NVIDIA but you have to request it](https://cloud.google.com/nvidia)

* Runs only on NVIDIA
* large memory bandwidth (probably 12x PC)
* very large number of CPUS
  * 1050   2GB      640 cores     128-bit        112GB/s
  * 2080   8GB      2944 cores    256-bit        448GB/s
  * 3090   24 GB    10496 cores   384-bit        936.19 GB/s
  * 4090   24 GB    16384 cores   384 bit        

* Newer GPUs also contain tensor cores (machine learning)
* Newer GPUs also contain RT (ray tracing)

* groups of 32 threads: warp
* threads are allocated in warps (you cannot assign less than 32)