// no client should be forced depend on methods it does not use

#include <iostream>
#include <vector>

using namespace std;

class Document;

/* 
Doing it in wrong way. Not all client needs all these three interaces. Hence need to segregate them to indivisual interface.
*/

//class IMachine
//{
//	public:
//		virtual void print(vector<Document*> docs) = 0;
//		virtual void scan(vector<Document*> docs) = 0;
//		virtual void fax(vector<Document*> docs) = 0;
//};
//
//class ConcreteMachine : public IMachine
//{
//	public:
//		virtual void print(vector<Document*> docs)
//		{
//
//		}
//
//		virtual void scan(vector<Document*> docs)
//		{
//
//		}
//
//		virtual void fax(vector<Document*> docs)
//		{
//
//		}
//};

// Doing it in correct way

class IPrinter
{
	public:
		virtual void print(vector<Document*> docs) = 0;
};

class IScanner
{
	public:
		virtual void scan(vector<Document*> docs) = 0;
};

class IFax
{
	public:
		virtual void fax(vector<Document*> docs) = 0;
};

class IMachine : public IPrinter, public IScanner
{
};

class Printer : public IPrinter
{
	public:
		virtual void print(vector<Document*> docs)
		{

		}
};


class Machine : public IMachine
{
	public:
		Machine(IPrinter& printer, IScanner& scanner) : printer(printer), scanner(scanner)
		{

		}

		void print(vector<Document*> docs)
		{
			printer.print(docs);
		}

		void scan(vector<Document*> docs)
		{
			scanner.scan(docs);
		}

	private:
		IPrinter& printer;
		IScanner& scanner;


};


