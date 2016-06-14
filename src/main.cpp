#include "Application2D.h"

#include "Matrix3.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>
#include <thread>
int main() {
	
	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	return 0;
}