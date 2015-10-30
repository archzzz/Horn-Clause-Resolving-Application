// predicate_st.h -- Declares a predicate class used in symbol table
// Created by Anqi Zhang, Yu Xiao
//
#ifndef PREDICATE_ST_H
#define PREDICATE_ST_H

#include <memory>
#include <vector>
#include "Label.h"

//
// struct PredicateST
// This struct is an interface connecting symbol table and Token tree.
//
struct PredicateST {
	// Stores name of predicate.
	Label name;

	// Stores symbols of predicate.
	std::vector<Token *> symbols;

	//
	// Contructor
	// Takes a Label token and stores as name of predicate.
	//
	PredicateST(std::shared_ptr<Label>& n);

	~PredicateST();

	//
	// clone_symbols()
	// Clone symbols vector from the Token tree.
	//
	void clone_symbols(std::vector<std::shared_ptr<Token>>& other_symbols);

	//
	// formatted output
	// toString function, print this predicate information (name and symbols).
	//
	friend std::ostream& operator<<(std::ostream& os, PredicateST const& p);
};

#endif