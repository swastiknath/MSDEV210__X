#include <iostream>
#include<forward_list>
#include<string>
#include<list>
#include<vector>

using namespace std;

// Algorithm 1: Finding First Instance in the Container
template<class InputIterator, typename valueType>
InputIterator findFirstInstance(InputIterator iterBegin, InputIterator iterEnd, const valueType& findEle) {
	while (iterBegin != iterEnd && *iterBegin != findEle) {
		++iterBegin;
	}
	return iterBegin;
}

// Algorithm 2: Merging Two Sorted Containers:

template<class InputIterator, class OutputIterator>
OutputIterator mergeSortedContainers(InputIterator lhsBegin,
	InputIterator lhsEnd, InputIterator rhsBegin, InputIterator rhsEnd, OutputIterator result) {
	while (lhsBegin != lhsEnd && rhsBegin != rhsEnd) {
		if (*lhsBegin <= *rhsBegin) {
			*result = *lhsBegin;
			++lhsBegin;
		}
		else {
			*result = *rhsBegin;
			++rhsBegin;
		}
		++result;
	}

	// Copying the remaining elements:
	while (lhsBegin != lhsEnd) {
		*result = *lhsBegin;
		++lhsBegin;
		++result;
	}
	while (rhsBegin != rhsEnd) {
		*result = *rhsBegin;
		++rhsBegin;
		++result;
	}
	return result;

}

// Algorithm 3: Finding Elemnets in a container using Foreward Iterator:

template<class ForewardIterator, typename ElementType>
void findAndReplace(ForewardIterator iterBegin, ForewardIterator iterEnd, const ElementType& oldEle, const ElementType& newEle) {
	while (iterBegin != iterEnd) {
		if (*iterBegin == oldEle) {
			*iterBegin = newEle;
		}
		++iterBegin;
	}
}

// Algorithm 4: Bidirectional Iterator : Reverse Copy:

template<class BidirectionalIterator, class OutputIterator>
OutputIterator reverseCopy(BidirectionalIterator iterBegin, 
	BidirectionalIterator iterEnd, OutputIterator result) {
	while (iterBegin != iterEnd) {
		*result++ = *--iterEnd;
	}
	return result;
}

template<class RandomAccessIterator>
void Randomise(RandomAccessIterator iterBegin, RandomAccessIterator iterEnd) {
	while (iterBegin < iterEnd) {
		std::iter_swap(iterBegin, iterBegin + rand() % (iterEnd - iterBegin));
		++iterBegin;
	}
}

int main()
{
	forward_list<int> firstList = { 34, 77, 16, 2 };
	forward_list<int> secondList = { 35, 76, 18, 2 };

	list<int> List = { 34, 77, 16, 2, 35, 76, 18, 2 };
	vector<int> resultsList(8);

	firstList.sort();
	secondList.sort();

	cout << "findfirstinstance of 16 in firstList and 76 in secondlist is: " 
		<< *findFirstInstance(firstList.begin(), firstList.end(), 16) 
		<< " "
		<< *findFirstInstance(secondList.begin(), secondList.end(), 76) 
		<< endl;

	cout << "Merge and Sort: "
		<< *mergeSortedContainers(firstList.begin(), firstList.end(), secondList.begin(), secondList.end(), resultsList.begin()) << endl;

	for (vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++) {
		cout << *it << endl;
	}

	cout << "find and replace : " <<endl;
	findAndReplace(secondList.begin(), secondList.end(), 76, 10006);
	for (forward_list<int>::iterator it = secondList.begin(); it != secondList.end(); it++) {
		cout << *it << endl;
	}

	cout << "reverse copy: " << endl;
	resultsList.empty();
	resultsList.resize(List.size());

	reverseCopy(List.begin(), List.end(), resultsList.begin());
	
	for (vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++) {
		cout << *it << endl;
	}

	// Randomizing Examples:
	cout << "Calling Randomize : " << endl;
	List.sort();
	vector<int> temp(List.begin(), List.end());

	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
		cout << *it << endl;
	}

	Randomise(temp.begin(), temp.end());
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
		cout << *it << endl;
	}
}
