#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCurrPointIndex(0)
	{
		mPoints = new Point const* [10];
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCurrPointIndex(0)
	{
		mPoints = new Point const* [10];

		// Point 깊은 복사
		for (size_t i = 0; i < other.mCurrPointIndex; i++)
		{
			AddPoint(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
		}
	}

	PolyLine::~PolyLine()
	{
		DeletePoints();
		delete[] mPoints;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCurrPointIndex >= 10)
		{
			return false;
		}

		mPoints[mCurrPointIndex] = new Point(x, y);
		mCurrPointIndex++;
		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCurrPointIndex >= 10 || point == nullptr)
		{
			return false;
		}
		mPoints[mCurrPointIndex] = point;
		mCurrPointIndex++;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCurrPointIndex)
		{
			return false;
		}

		delete mPoints[i];

		for (size_t j = i; j < mCurrPointIndex - 1; j++)
		{
			mPoints[j] = mPoints[j + 1];
		}

		mCurrPointIndex--;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCurrPointIndex < 1)
		{
			return false;
		}

		float minX = mPoints[0]->GetX();
		float minY = mPoints[0]->GetY();
		float maxX = mPoints[0]->GetX();
		float maxY = mPoints[0]->GetY();

		// find min x, y max x, y by one pass
		float currX;
		float currY;
		for (size_t i = 0; i < mCurrPointIndex; i++)
		{
			currX = mPoints[i]->GetX();
			currY = mPoints[i]->GetY();
			if (minX > currX)
			{
				minX = currX;
			}
			if (maxX < currX)
			{
				maxX = currX;
			}
			if (minY > currY)
			{
				minY = currY;
			}
			if (maxY < currY)
			{
				maxY = currY;
			}
		}

		outMin->SetX(minX);
		outMin->SetY(minY);
		outMax->SetX(maxX);
		outMax->SetY(maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mCurrPointIndex)
		{
			return nullptr;
		}

		return mPoints[i];
	}

	void PolyLine::operator=(const PolyLine& other)
	{
		const Point* tmp[10] = { nullptr, };
		size_t otherCurrPointIndex = other.mCurrPointIndex;
		size_t prevCurrPointIndex = mCurrPointIndex;
		mCurrPointIndex = 0;

		// 나 자신 얕은 복사 
		for (size_t i = 0; i < prevCurrPointIndex; i++)
		{
			tmp[i] = mPoints[i];
		}


		// 대입
		for (size_t i = 0; i < otherCurrPointIndex; i++)
		{
			AddPoint(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
		}

		// 이전 mPoints 메모리 해제
		for (size_t i = 0; i < prevCurrPointIndex; i++)
		{
			delete tmp[i];
		}

	}

	void PolyLine::DeletePoints()
	{
		for (size_t i = 0; i < mCurrPointIndex; i++)
		{
			delete mPoints[i];
			//mPoints[i] = nullptr;
		}

	}
}