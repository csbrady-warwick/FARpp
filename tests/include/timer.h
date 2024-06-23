#ifndef TIMER_H
#define TIMER_H
#include <chrono>

struct timer{

  std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
  std::string name;

  void begin(std::string name = "unnamed"){ this->name = name; start = std::chrono::high_resolution_clock::now();}
  float end(){
		float dt = end_silent();
    std::cout << "Time taken by " << name << " is " << dt  << " seconds\n";
		return dt;
  }
	float end_silent(){
		stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		return (float)duration.count()/1.0e6;
	}
};

#endif
