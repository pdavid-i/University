#include "tester.h"
#include <assert.h>

void Tester::test_hash_table()
{
	int rezult;
	HashTable table;
	assert (table.countElements() == 0);
	std::string element = "FirstElement";
	table.add(element);
	assert(table.search(element) == 1);
	table.add("second element");
	assert(table.countElements() == 2);
	rezult = table.add("second element");
	assert(rezult == 1);
	rezult = table.remove("random");
	assert(rezult == 0);
	table.remove("second element");
	assert(table.countElements() == 2);
}

void Tester::test_bag()
{
	int rezult;
       	Bag bag;
        assert (bag.countElements() == 0);
        std::string element = "FirstElement";
        bag.add(element);
        assert(bag.search(element) == 1);
        bag.add("second element");
        assert(bag.countElements() == 2);
        rezult = bag.add("second element");
        assert(rezult == 1);
        rezult = bag.remove("xOSADDASKOA");
        assert(rezult == 0);
        bag.remove("second element");
        assert(bag.countElements() == 2);
	
}

void Tester::test_iterator()
{
	Bag bag;
	bag.add("FirstElem");
	bag.add("SecondElem");
	bag.add("ThirdElem");
	bag.getContainer().getNextIndex(99);	
	Bag* pointer = &bag;
	BagIterator iterator(pointer);
	assert(iterator.isValid() == 1);
	iterator.next();
	std::string aux = iterator.getCurrent();
	assert(aux == "FirstElem" || aux == "SecondElem" || aux == "ThirdElem");
	iterator.next();
	assert(iterator.isValid() == 1);
	iterator.next();
	iterator.next();
	assert(iterator.isValid() == 0);
	BagIterator iter;
	assert(iter.isValid() == 0);
	iter.next();
	assert(iter.isValid() == 0);
}


void Tester::run()
{
	test_hash_table();
	test_bag();
	test_iterator();
}
