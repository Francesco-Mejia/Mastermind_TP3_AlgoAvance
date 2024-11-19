#pragma once
#include "Combination.h"
#include "Color.h"
#include <LinkedList.h>

const int NB_POSSIBLE_COMBINATIONS = 4096;
const int NB_POSSIBLE_COLORS = 8;
const int NB_COLORS_PER_COMBINATION = 4;
const int VERDICT_CORRECT_POSITION = 1;
const int VERDICT_CORRECT_COLOR_WRONG_POSITION = 2;
const int VERDICT_WRONG_COLOR = 3;

class Mastermind
{
public:
  
    Mastermind(LinkedList<Combination>* _list);
    ~Mastermind();

    int getNbElements() const;
    Combination* getElement(int _index) const;

    int cleanList(Combination* _ref, short* _tabVerdicts);

private:

	bool isPossibleCombination(Combination* _toValidate, Combination* _ref, short* _tabVerdicts);
    Combination* tabCombinations[NB_POSSIBLE_COMBINATIONS];
    LinkedList<Combination>* list;
    void generateAllCombinations();
};
