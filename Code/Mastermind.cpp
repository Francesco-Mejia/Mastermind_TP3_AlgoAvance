#include "Mastermind.h"
#include "Iterator.h"

// Constructeur : Initialise le Mastermind avec une liste de combinaisons
Mastermind::Mastermind(LinkedList<Combination>* _list) : list(_list)
{
	// Cette appelle de m�thhode g�n�re toutes les combinaisons possibles et les ajoute � la liste
	generateAllCombinations();
}

// Destructeur : Lib�re la m�moire allou�e pour toutes les combinaisons
Mastermind::~Mastermind()
{
	// Boucle qui parcours le tableau de combinaisons et supprime chaque �l�ment
	for (int i = 0; i < NB_POSSIBLE_COMBINATIONS; i++)
	{
		delete tabCombinations[i];
	}
}

// M�thode qui retourne le nombre d'�l�ments dans la liste de combinaisons
int Mastermind::getNbElements() const
{
	int count = 0; // compteur
	// Boucle qui parcours la liste avec l'it�rateur et compte les �l�ments
	for (Iterator<Combination> iter = list->begin(); iter != list->end(); ++iter)
	{
		count++;
	}
	return count;
}

/// <summary>
/// Retourne un �l�ment de la liste en position index
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position index</returns>
Combination* Mastermind::getElement(int index) const
{
	// V�rification si l'index est valide
	if (index < 0 || index >= getNbElements())
	{
		return nullptr;
	}

	// Boucle qui parcours la liste jusqu'� l'index sp�cifi�
	Iterator<Combination> iter = list->begin();
	for (int i = 0; i < index; i++)
	{
		++iter;
	}
	// Retourne l'�l�ment � l'index sp�cifi�
	return iter.operator&();
}

// M�thode qui v�rifie si une combinaison est possible selon les verdicts donn�s
bool Mastermind::isPossibleCombination(Combination* _toValidate, Combination* _ref, short* _tabVerdicts)
{
	bool keepCombination = true;
	// Bouble qui v�rifie chaque couleur de la combinaison
	for (int i = 0; i < NB_COLORS_PER_COMBINATION; i++)
	{
		Color refColor = _ref->getColor(i);
		Color validateColor = _toValidate->getColor(i);

		// Switch/Case qui traite chaque verdict
		switch (_tabVerdicts[i]) 
		{
		case VERDICT_CORRECT_POSITION: // Bonne couleur, bonne place
			if (validateColor != refColor) 
			{
				keepCombination = false;
			}
			break;
		case VERDICT_CORRECT_COLOR_WRONG_POSITION: // Bonne couleur, mauvaise place
			if (validateColor == refColor) 
			{
				keepCombination = false;
			}
			else 
			{
				// Boucle qui v�rifie si la couleur est pr�sente dans une autre place dans la combinaison
				bool colorFound = false;
				for (int j = 0; j < NB_COLORS_PER_COMBINATION; j++)
				{
					if (j != i && _toValidate->getColor(j) == refColor) 
					{
						colorFound = true;
						break;
					}
				}
				if (!colorFound) 
				{
					keepCombination = false;
				}
			}
			break;
		case VERDICT_WRONG_COLOR: // Mauvaise couleur
			// Boucle qui v�rifie si la couleur est pr�sente dans la combinaison
			for (int j = 0; j < NB_COLORS_PER_COMBINATION; j++)
			{
				if (_toValidate->getColor(j) == refColor) 
				{
					keepCombination = false;
					break;
				}
			}
			break;
		}

		// Si la combinaison est invalide on arr�te la v�rification
		if (!keepCombination) 
		{
			break;
		}
	}
	return keepCombination;
}

// M�thode quiu nettoie la liste en supprimant les combinaisons impossibles
int Mastermind::cleanList(Combination* _ref, short* _tabVerdicts)
{
	int removed = 0; // Compteur du nombre de combinaisons supprim�es
	Iterator<Combination> iter = list->begin();
	while (iter != list->end()) 
	{
		// On v�rifie si la combinaison est possible
		if (!isPossibleCombination(iter.operator&(), _ref, _tabVerdicts)) 
		{
			Combination* toRemove = iter.operator&();
			++iter;
			// On supprime la combinaison si elle n'est pas possible
			if (list->remove(toRemove)) 
			{
				removed++;
			}
		}
		else 
		{
			++iter;
		}
	}
	return removed; // Retourne le nombre de combinaisons supprim�es
}

// M�thode qui g�n�re toutes les combinaisons possibles et les ajoute � la liste
void Mastermind::generateAllCombinations()
{
	// Parcourt toutes les combinaisons possibles de 4 couleurs (4 boucles imbriqu�s)
	for (int i = 1; i <= NB_POSSIBLE_COLORS; i++)
	{
		for (int j = 1; j <= NB_POSSIBLE_COLORS; j++)
		{
			for (int k = 1; k <= NB_POSSIBLE_COLORS; k++)
			{
				for (int l = 1; l <= NB_POSSIBLE_COLORS; l++)
				{
					// On va cr�er une nouvelle combinaison
					Combination* combination = new Combination(Color(i), Color(j), Color(k), Color(l));
					// On ajoute la combinaison au tableau et � la liste
					tabCombinations[getNbElements()] = combination;
					list->add(combination);
				}
			}
		}
	}
}