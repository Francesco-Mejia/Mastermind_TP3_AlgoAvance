#include "stdafx.h"
#include "CppUnitTest.h"
#include <LinkedList.h>
#include "Book.h"
#include <Node.h>
#include "Iterator.h"
#include "IterAccess.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTest
{
	TEST_CLASS(Iterator_EN)
	{
	public:

		//Test qui doit compiler SANS �TRE MODIFI�
		
		TEST_METHOD(IteratorShouldCompile)
		{
			LinkedList<Book> l;
			Book* b1 = new Book(1);
			Node<Book> * node = new Node<Book>();
			node->setContent(b1);
			Iterator<Book> iter(node);
			Iterator<Book> iter1;
			Iterator<Book> iter2;

			iter1 = l.begin();
			iter2 = l.end();

			//IterAccess est une classe amie (friend) � Iterator
			//Elle a acc�s � ses attributs priv�s pour insecter le noeud sur lequel l'it�rateur est positionn�
			//Ceci va vous servir dans vos tests
			IterAccess<Book> ia(iter1);
			ia.getCurrentNode();
			iter1 = l.begin();
			iter1 = l.end();
			++iter1;
			if (iter1 == iter2 || iter1 != iter2)
			{
			}
			Book* test = &iter;
			Assert::IsTrue(true);
		}
		

		//Test du ++
		TEST_METHOD(Iterator_TestIncrementOperateurListeDeuxNoeud)
		{
			LinkedList<Book> l;
			Book* j1 = new Book(1);
			Book* j2 = new Book(2);
			l.add(j1);
			l.add(j2);
			Iterator<Book> iter = l.begin();
			++iter;
			IterAccess<Book> ia(iter);
			Assert::IsTrue(ia.getCurrentNode()->getContent() == j2);
			delete j1;
			delete j2;
		}
		

			
		//Tester autres sc�narios de ++ :
		//   Sur liste vide
		//   Plusieurs en s�quence sur liste pleine
		//   Fin de liste
		
		//Tester tous les autres op�rateurs de l'it�rateur et ses cas limites !		
	};
}

