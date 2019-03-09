#pragma once
#include <list>
#include <string>
#include <fstream>

using std::list;
using std::string;
using std::ofstream;

class DataBase
{
	public:
		class Purchase
		{
		public:
			class Date
			{
				friend class Purchase;
			public:
				Date(string);

			private:
				string mDateString;
				long long mDateValue;
			};

			Purchase(Date, int, int);

			string getDate() { return mDate.mDateString; }
			long long getDateProductID() { return mDateProductID; }
			long long getDateCostumerID() { return mDateCostumerID; }


			bool cmpDateProduct(const Purchase&) const;			// Compares two objects in terms of "mDateProductID"
			bool cmpDateCostumer(const Purchase&) const;		// Compares two objects in terms of "mDateCostumerID"

		private:
			Date mDate;
			long long mDateProductID;            // Holds (Date * 1000 + productID)
			long long mDateCostumerID;           // Holds (Date * 10000 + costumerID)
		};

		void addPurchase(string);
		void writeSummary(ofstream&);

	private:
		list<Purchase> mPurchaseList;
		string mPurchaseSummary;
};
	
	