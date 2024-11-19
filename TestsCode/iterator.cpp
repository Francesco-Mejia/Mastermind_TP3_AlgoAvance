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
	TEST_CLASS(Iterator_EN){
		public :

			// Test qui doit compiler SANS �TRE MODIFI�

			TEST_METHOD(IteratorShouldCompile){
				LinkedList<Book> l;
	Book *b1 = new Book(1);
	Node<Book> *node = new Node<Book>();
	node->setContent(b1);
	Iterator<Book> iter(node);
	Iterator<Book> iter1;
	Iterator<Book> iter2;

	iter1 = l.begin();
	iter2 = l.end();

	// IterAccess est une classe amie (friend) � Iterator
	// Elle a acc�s � ses attributs priv�s pour insecter le noeud sur lequel l'it�rateur est positionn�
	// Ceci va vous servir dans vos tests
	IterAccess<Book> ia(iter1);
	ia.getCurrentNode();
	iter1 = l.begin();
	iter1 = l.end();
	++iter1;
	if (iter1 == iter2 || iter1 != iter2)
	{
	}
	Book *test = &iter;
	Assert::IsTrue(true);
}

// Test du ++
TEST_METHOD(Iterator_TestIncrementOperateurListeDeuxNoeud)
{
	LinkedList<Book> l;
	Book *j1 = new Book(1);
	Book *j2 = new Book(2);
	l.add(j1);
	l.add(j2);
	Iterator<Book> iter = l.begin();
	++iter;
	IterAccess<Book> ia(iter);
	Assert::IsTrue(ia.getCurrentNode()->getContent() == j2);
	delete j1;
	delete j2;
}

// Tester autres sc�narios de ++ :
//    Sur liste vide
TEST_METHOD(Iterator_IncrementOnEmptyList)
{
	LinkedList<Book> list;
	Iterator<Book> iter = list.begin();
	++iter;
	Assert::IsTrue(iter == list.end());
}
//   Plusieurs en s�quence sur liste pleine
TEST_METHOD(Iterator_MultipleIncrementsOnFullList)
{
	LinkedList<Book> list;
	Book *b1 = new Book(1);
	Book *b2 = new Book(2);
	Book *b3 = new Book(3);
	list.add(b1);
	list.add(b2);
	list.add(b3);

	Iterator<Book> iter = list.begin();
	Assert::IsTrue(&iter == b1);
	++iter;
	Assert::IsTrue(&iter == b2);
	++iter;
	Assert::IsTrue(&iter == b3);
	++iter;
	Assert::IsTrue(iter == list.end());

	delete b1;
	delete b2;
	delete b3;
}

TEST_METHOD(Iterator_IncrementAtEndOfList)
{
	LinkedList<Book> list;
	Book *b1 = new Book(1);
	list.add(b1);

	Iterator<Book> iter = list.begin();
	++iter;
	Assert::IsTrue(iter == list.end());
	++iter;
	Assert::IsTrue(iter == list.end());

	delete b1;
}

// Tester tous les autres op�rateurs de l'it�rateur et ses cas limites !
//  Test de l'op�rateur ==
TEST_METHOD(Iterator_EqualityOperator)
{
	LinkedList<Book> list;
	Book *b1 = new Book(1);
	list.add(b1);

	Iterator<Book> iter1 = list.begin();
	Iterator<Book> iter2 = list.begin();
	Assert::IsTrue(iter1 == iter2);

	++iter2;
	Assert::IsFalse(iter1 == iter2);

	delete b1;
}

// Test de l'op�rateur !=
TEST_METHOD(Iterator_InequalityOperator)
{
	LinkedList<Book> list;
	Book *b1 = new Book(1);
	list.add(b1);

	Iterator<Book> iter1 = list.begin();
	Iterator<Book> iter2 = list.end();
	Assert::IsTrue(iter1 != iter2);

	++iter1;
	Assert::IsFalse(iter1 != iter2);

	delete b1;
}

// Test de l'op�rateur & (d�r�f�rencement)
TEST_METHOD(Iterator_DereferenceOperator)
{
	LinkedList<Book> list;
	Book *b1 = new Book(1);
	list.add(b1);

	Iterator<Book> iter = list.begin();
	Assert::IsTrue(&iter == b1);

	iter = list.end();
	Assert::IsNull(&iter);

	delete b1;
}

// Test des cas limites
TEST_METHOD(Iterator_EdgeCases)
{
	LinkedList<Book> list;

	// Test sur liste vide
	Assert::IsTrue(list.begin() == list.end());

	// Test apr�s avoir ajout� et supprim� un �l�ment
	Book *b1 = new Book(1);
	list.add(b1);
	list.remove(b1);
	Assert::IsTrue(list.begin() == list.end());

	// Test avec un seul �l�ment
	list.add(b1);
	Iterator<Book> iter = list.begin();
	Assert::IsTrue(&iter == b1);
	++iter;
	Assert::IsTrue(iter == list.end());

	delete b1;
}
}
;
}
