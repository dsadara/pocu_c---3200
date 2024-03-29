#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();
		Vehicle(const Vehicle& other);
		virtual unsigned int GetMaxSpeed() const = 0;
		virtual char GetVehicleType() const = 0;
		virtual bool IsTrailerConnected() const = 0;
		void operator=(const Vehicle& rhs);
		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetPassengersWeightSum() const;
	private:
		unsigned int mMaxPassengersCount;
		const Person** mPeople;
		unsigned int mCurrIndexOfPerson;
	};
}