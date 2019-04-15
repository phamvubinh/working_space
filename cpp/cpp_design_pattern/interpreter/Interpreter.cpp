#include <iostream>

#include <map>

using namespace std;

class Context
{
public:
	void set(const string & var, const bool value)
	{
		vars.insert(pair<string, bool>(var, value));
	}

	bool get(const string &exp)
	{
		return vars[exp];
	}
private:
	map<string, bool> vars;
};


class AbstractExpression
{
public:
	virtual ~AbstractExpression() {}
	virtual bool interpret(Context * const)
	{
		return false;
	}
};

class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const string & val) : value(val) {}
	~TerminalExpression() {}

	bool interpret(Context * const context)
	{
		return context->get(value);
	}

private:
	string value;
};

class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression * left, AbstractExpression *right) :
		lop(left), rop(right){}

	~NonterminalExpression()
	{
		delete lop;
		delete rop;
	}

	bool interpret(Context *const context)
	{
		return lop->interpret(context) && rop->interpret(context);
	}

private:
	AbstractExpression *lop;
	AbstractExpression *rop;
};

int main(int argc, char const *argv[])
{
	AbstractExpression *A = new TerminalExpression("A");
	AbstractExpression *B = new TerminalExpression("B");

	AbstractExpression*exp = new NonterminalExpression(A, B);

	Context context;

	context.set("A", 1);
	context.set("B", 1);

	cout << context.get("A") << " AND " << context.get("B");
	cout << " = " << exp->interpret(&context) << endl;

	delete exp;
	return 0;
}