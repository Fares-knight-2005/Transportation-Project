#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "DataStructures.h"

class Database
{
    public:


		static DoubleLinkedList <string> Split(string s, string delim)
		{
			string Word = "";

			DoubleLinkedList <string> Words;

			short pos = s.find(delim);

			while (pos != string::npos)
			{
				Word = s.substr(0, pos);
				s.erase(0, pos + delim.length());

				if (Word != "")
					Words.addLast(Word);

				pos = s.find(delim);
			}

			if (s != "")
				Words.addLast(s);

			return Words;
		}



		static string JoinString(string* ArrString, string Delim)
		{
			string Results = "";

			for (int i = 0; i < ArrString->length; i++)
			{
				Results += Delim + ArrString[i];
			}

			return Results.substr(Delim.length(), Results.length() - Delim.length());
		}

};

#endif // DATABASE_H
