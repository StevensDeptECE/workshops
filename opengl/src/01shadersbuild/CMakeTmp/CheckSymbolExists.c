/* */
#include <stdlib.h>

int main(int argc, char** argv)
{
  (void)argv;
#ifndef strtod_l
  return ((int*)(&strtod_l))[argc];
#else
  (void)argc;
  return 0;
#endif
}
