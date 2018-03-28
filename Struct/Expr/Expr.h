#pragma once
#include "../Instr/Instr.h"

class IRInstr;
class BasicBlock;
class Expr
{
public:
	/* ---- Constructors / Destructor ---- */
	Expr();
	virtual ~Expr();

	/* ------------- Methods ------------- */
	virtual void print() = 0;

    virtual void buildIR(CFG *cfg) = 0;

    /* ------------ Attributs ------------ */
};

