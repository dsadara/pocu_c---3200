#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include <cassert>
#include <cmath>

using namespace assignment3;

void SpecTestCase();
void StudTestCase();

int main()
{
	SpecTestCase();

	// ============SmartStack==================

	// test Push(), Pop(), GetMin(), GetMax(), Peek()
	SmartStack<int> s;
	SmartStack<int>* sPtr = new SmartStack<int>();

	s.Push(6); // [ 6 ]
	assert(s.Peek() == 6);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 6);

	s.Push(5); // [ 6, 5 ]
	assert(s.Peek() == 5);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 5);

	s.Push(-2); // [ 6, 5, -2 ]
	assert(s.Peek() == -2);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == -2);

	s.Push(9);	// [ 6, 5 , -2, 9 ]
	assert(s.Peek() == 9);
	assert(s.GetMax() == 9);
	assert(s.GetMin() == -2);

	s.Pop();	// [ 6, 5 , -2 ]
	assert(s.Peek() == -2);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == -2);

	s.Pop();	// [ 6, 5 ]
	assert(s.Peek() == 5);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 5);

	s.Pop();	// [ 6 ]
	assert(s.Peek() == 6);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 6);

	// test SmartStack Copy Constructor, Assignment Operator

	sPtr->Push(6);
	sPtr->Push(4);
	sPtr->Push(2);
	sPtr->Push(6);

	SmartStack<int> s2(*sPtr);
	SmartStack<int> s2_1;
	s2_1 = *sPtr;

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());


	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	//assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	//assert(s2_1.Peek() == sPtr->Peek());

	delete sPtr;

	// test GetSum(). GetCount(), GetAverage()

	SmartStack<int> s3;
	s3.Push(6);
	s3.Push(5);
	s3.Push(-2);
	
	assert(s3.GetCount() == 3u);
	assert(s3.GetSum() == 9);
	assert(s3.GetAverage() == 3.0);

	//s3.Pop();

	//assert(s3.GetCount() == 2u);
	//assert(s3.GetSum() == 11);
	//assert(s3.GetAverage() == (11.0/2.0));

	//s3.Pop();

	//assert(s3.GetCount() == 1u);
	//assert(s3.GetSum() == 6);
	//assert(s3.GetAverage() == (6.0/1.0));

	//s3.Pop();

	//assert(s3.GetCount() == 0u);
	//assert(s3.GetSum() == 0);
	//assert(s3.GetAverage() == 0.0);

	// test GetVariance(), GetStandardDeviation()

	double diff = s3.GetVariance() - 12.667;
	assert(fabs(diff) < 0.01);
	assert(fabs(s3.GetStandardDeviation() - 3.559) < 0.01);

	// ============SmartQueue=================

	// Enqueue()

	// Peek()

	// Dequeue()

	// constructor, copy constructor, assignment operator

	SmartQueue<int> q;
	SmartQueue<int>* qPtr = new SmartQueue<int>();


}

void SpecTestCase()
{
	const double EPSILON = 0.0009765625;

	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(std::abs(ss.GetMin() - (-5.9f)) <= EPSILON);
	//assert(ss.GetMin() == -5.9f);			WTF..
	assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);

}
void StudTestCase()
{
	
}
