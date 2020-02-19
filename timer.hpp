#ifndef TIMER
#define TIMER  

#include <sys/time.h>

class timer {
public:
  void SetTimer();
  timeval GetTimer();
private:
  timeval t_;

};

#endif
