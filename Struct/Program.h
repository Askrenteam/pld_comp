#pragma once

#include <vector>
#include <map>
#include "Function.h"
#include "GlobalVar.h"
#include "IR.h"

class Program
{
public:
	/* ---- Constructors / Destructor ---- */
	Program();
	~Program();

	/* ------------- Methods ------------- */
	void addGlobalVar(GlobalVar* gv);
	void addFunction(Function* f);
	void print();
	void buildIR(CFG* cfg);
	static string getTabs(int tabs);

private:

	/* ------------ Attributs ------------ */
	std::vector<Function*> functions;
	std::vector<GlobalVar*> globalVars;

};

