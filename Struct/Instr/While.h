#pragma once
#include "Instr.h"
class While :
	public Instr
{
public:
	/* ---- Constructors / Destructor ---- */
	While(Expr* e,Block* b);
	~While();

	/* ------------- Methods ------------- */

private:

	/* ------------ Attributs ------------ */
	Block* child;
};

