#include "Mastermind.h"


Mastermind::Mastermind(LinkedList<Combination>* _list)
{
	//TODO: Compl�ter
}

Mastermind::~Mastermind()
{
	//TODO: Compl�ter
}


int Mastermind::getNbElements() const
{
	//TODO: Compl�ter
	return 0;
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combination* Mastermind::getElement(int index) const
{
	//TODO: Compl�ter
	return NULL;
}

bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _tried, short* _tabVerdicts)
{
	//A COMPLETER
	//V�rifiez si la combinaison toValidate doit �tre gard�e ou non de la liste, en fonction d'une combinaison essay�e et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs pr�sentes dans toValidate, 3 verdicts possibles doivent �tre pris en consid�ration pour �l�miner ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).

	//Voici un �bauche d'algorithme qui devrait vous aider � compl�ter cette m�thode:
	//Pour chacune des couleurs de la combinaison toValidate, v�rifiez:
	
	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs � valider n'a pas la couleur � la m�me place que 
	//la combinaison essay�e, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs � valider n'a pas la couleur � un autre emplacement que
	//celui de la combinaison essay�e, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs � valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.

	
	bool keepCombination = true;
	
	//TODO: Compl�ter l'algorithme ici
	
	return keepCombination;
}

int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//�pure la liste de combinaisons de couleurs en fonction de la combinaison re�ue et des 4 verdicts (valeurs 1 � 3).
	//Pour chacune des combinaisons de la liste, v�rifier si elle doit �tre retir�e ou non de liste.
	//Le nombre de combinaisons supprim�es doit �tre retourn�.

	//Cette fonction appelle isPossibleCombination pour savoir si la combinaison inspect�e est � garder ou non

	//TODO: Compl�ter

	return 0;
}
