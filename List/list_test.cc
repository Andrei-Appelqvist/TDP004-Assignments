// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include <iostream>
#include "catch.hpp"
#include "lista.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" )
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}

// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.

TEST_CASE( "Insert an item in an empty list" )
{
    Sorted_List l{};

    l.insert(6);

    REQUIRE( l.is_empty() == false );
    REQUIRE( l.size() == 1 );

}

SCENARIO( "Empty lists" )
{
    GIVEN( "An empty list" )
    {
	Sorted_List l{};

	REQUIRE( l.is_empty() );
	REQUIRE( l.size() == 0 );

	WHEN( "an item is inserted" )
	{
	    l.insert(2);

	    THEN( "the size increase and the item is first in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 1);
		REQUIRE( l.get_first()->get_val() == 2 );
	    }
	}

	WHEN( "an item is removed" )
	{
    l.insert(2);
    l.remove(2);

	    THEN( "the list is still empty" )
	    {
        REQUIRE( l.is_empty()  );
     		REQUIRE( l.size() == 0 );
	    }
	}
	WHEN( "the list is copied to a new list" )
	{

	    Sorted_List t{l};

	    THEN( "the new list is also empty" )
	    {
		   REQUIRE(t.is_empty());
	    }
	}

	WHEN( "the list is copied to an existing non-empty list" )
	{
      Sorted_List n{};
      n = l;
	    // copy (assign) your empty list to the existing

	    THEN( "the existing list is also empty" )
	    {
        REQUIRE(n.is_empty());
        REQUIRE(n.size() == 0 );
		// add your REQUIRE statements
  }
	}
}
}

SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {
      Sorted_List list1{};
      list1.insert(5);
	// create the given scenario
	WHEN( "a smaller item is inserted" )
	{
    list1.insert(3);
	    THEN( "Item placed before initial item" )
	    {
        REQUIRE(list1.get_first()->get_val() == 3);
      }
	}
	WHEN( "a larger item is inserted" )
	{
    list1.insert(7);
	    THEN( "Item is placed after initial item" )
	    {
        REQUIRE(list1.get_first()->get_val() == 5);
	    }
	}
	WHEN( "an item is removed" )
	{
	    THEN( "/* describe what will happen */" )
	    {
        list1.remove(5);
        REQUIRE(list1.is_empty());
	    }
	}
	WHEN( "the list is copied to a new list" )
	{

    Sorted_List kek{list1};
	    THEN( "/* describe what will happen */" )
	    {
        REQUIRE(kek.get_first()->get_val() == 5);
	    }
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
    Sorted_List kek{};
    kek = list1;
	    THEN( "/* describe what will happen */" )
	    {
        REQUIRE(kek.get_first()->get_val() == 5);
	    }
	}
}
}

SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {
      Sorted_List t{};
      t.insert(5);
      t.insert(2);
      t.insert(6);
      t.insert(4);
      t.insert(8);

	// create the given scenario and all THEN statements
	// and all REQUIRE statements

	WHEN( "an item smaller than all other is inserted" )
	{
    t.insert(1);
    REQUIRE(t.get_first()->get_val() == 1);
	}
	WHEN( "an item larger than all other is inserted" )
	{
    t.insert(12);
    REQUIRE(t.get_first()->get_next()->get_next()->get_next()->get_next()->
            get_next()->get_val() == 12);
	}
	WHEN( "an item smaller than all but one item is inserted" )
	{
    t.insert(3);
    REQUIRE(t.get_first()->get_next()->get_val() == 3);
	}
	WHEN( "an item larger than all but one item is inserted" )
	{
    t.insert(7);
      REQUIRE(t.get_first()->get_next()->get_next()->get_next()->get_next()->
              get_val() == 7);
	}
	WHEN( "an item is removed" )
	{
    t.remove(4);
    REQUIRE(t.size() == 4);
	}
	WHEN( "all items are removed" )
	{
    t.remove(2);
    t.remove(4);
    t.remove(5);
    t.remove(8);
    t.remove(6);
    REQUIRE(t.is_empty());
  }
	WHEN( "the list is copied to a new list" )
	{
    Sorted_List t2{t};
    REQUIRE(t2.size() == 5);
    REQUIRE(t2.get_first()->get_val() == 2);
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
    Sorted_List kek{};
    kek.insert(1);
    kek.insert(2);
    kek.insert(6);
    kek = t;
    REQUIRE(kek.size() == 5);
    REQUIRE(kek.get_first()->get_val() == 2);
	}
    }
}

SCENARIO( "Lists can be copied" )
{

    GIVEN( "A list with five items in it, and a new copy of that list" )
    {
      Sorted_List t{};
      t.insert(5);
      t.insert(2);
      t.insert(6);
      t.insert(4);
      t.insert(8);
      Sorted_List t2{t};

	WHEN( "the original list is changed" )
	{
    t.remove(4);
	    THEN( "the copy remain unmodified" )
	    {
        REQUIRE(t2.size() == 5);
	    }
	}

	WHEN( "the copied list is changed" )
	{
    t2.remove(5);
	    THEN( "the original remain unmodified" )
	    {
        REQUIRE(t.size() == 5);
	    }
	}
    }
}

SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
      Sorted_List t{};
	// create the given list with 1000 random items
	std::random_device rd;
	std::uniform_int_distribution<int> uniform(1,1000);

	for (int i{0}; i < 1000; ++i)
	{
	    int random { uniform(rd) }; // generate a random number
      t.insert(random);
	    // insert into list
	}

	WHEN( "the list have 1000 random numbers inserted" )
	{
	    // THEN the list have 2000 items in correct order
	    // (assumes unique inserts or duplicates allowed)
      for (int i{0}; i < 1000; ++i)
      {
          int random { uniform(rd) }; // generate a random number
          t.insert(random);
          // insert into list
      }
      REQUIRE(t.size() == 2000);
	}
/*
	WHEN( "the list have 2000 random numbers removed" )
	{
	    // THEN the list is empty
	    // (assumes successful removes)
      for (int i{0}; i < 1000; ++i)
      {
          int random { uniform(rd) }; // generate a random number
          t.remove(random);
          // insert into list
      }
	}*/
    }
}

Sorted_List trigger_move(Sorted_List l)
{
    // do some (any) modification to list
    l.insert(1);
    l.insert(2);
    l.insert(3);
    return l;
}


SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {

	Sorted_List given{};
  given.insert(5);
  given.insert(2);
  given.insert(6);
  given.insert(4);
  given.insert(8);
	// insert 5 items

	WHEN( "the list is passed to trigger_move()" )
	{

	    Sorted_List l{ trigger_move(given) };

	    THEN( "the given list remain and the result have the change" )
	    {/*
void Sorted_List::insert(int ins_val){
  if(is_empty()){
    first = new Node{ins_val, nullptr};
  }
  else{
    Sorted_List::Node* current = first;
    while(current->get_next() != nullptr){
      current = current->Node::get_next();
  }
    Sorted_List::Node* new_node = new Node{ins_val, nullptr};
    current->Node::change_next(new_node);
}
}*/
        REQUIRE(l.size() == 8);
        REQUIRE(l.get_first()->get_val() == 1);
	    }
	}
    }
}
#if 0

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert):
void use_const_list(Sorted_List const& l)
{
    // perform every operation that do not modify the list here
    return l;
}

#endif
