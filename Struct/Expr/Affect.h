#pragma once
#include "Expr.h"
#include "../Var.h"

class Affect :
	public Expr
{
public:
	/* ---- Constructors / Destructor ---- */
	Affect(Var *var, Expr *expr);
	~Affect();

	/* ------------- Methods ------------- */
	void print();
	string buildIR(CFG* cfg);
private:

	/* ------------ Attributs ------------ */
	Var* var;
	Expr* expr;
};

