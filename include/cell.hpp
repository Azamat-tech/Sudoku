#pragma once

using namespace std;
#include <iostream>
#include <SDL.h>

#include "button.hpp"

class Cell : public Button {
public:
	Cell();

	/* CELL RELATED */
	// setters 
	void set_number(const int);
	void set_solution(const int);
	void set_editable(const bool);

	// method for non editable square (they have number as solution and not editable)
	void set_noneditable_square(const int);
	void unset();
	
	//getters
	int get_number() const;
	int get_solution() const;
	bool get_editable() const;

	//valid number
	bool check() const;
private:
	/* CELL RELATED*/
	bool isEditable;
	
	int number;
	int solution;

	friend ostream& operator<<(std::ostream& strm, const Cell& a);
};