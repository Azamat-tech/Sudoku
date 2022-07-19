#pragma once

#include <iostream>
#include <SDL.h>
#undef main

#include "constant.hpp"

using namespace std;

class View {
	public:
		View();
	private:
		SDL_Renderer* _renderer;
		SDL_Window* _window;

		void CHECKFORERROR(bool, string);
};
