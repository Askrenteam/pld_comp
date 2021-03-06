#include <iostream>
#include "ExprUni.h"
#include "../IR.h"
#include "../../Tools/PrintTool.h"


ExprUni::ExprUni(Expr* expr, ExprUniType::ExprUniType type, Block *block)
        : Expr(), expr(expr), type(type)
{
    this->parentBlock = block;
}


ExprUni::~ExprUni()
{
}

void ExprUni::print(int tabs)
{
    string stab = PrintTool::getTabs(tabs);
    std::cout<< stab <<"Unary Expression :"<<endl;
    cout << stab <<"Type :"<<getType(type)<<std::endl;
    expr->print(tabs+1);
}

string ExprUni::buildIR(CFG *cfg, bool isComparedToZero) {
    vector<string> params;
    string val = expr->buildIR(cfg);
    params.push_back(val);
    switch(type){
        // nb : pas de diff entre post et pre
        case ExprUniType::NO:
            params.push_back(val);
            params.push_back("0");
            cfg->current_bb->add_IRInstr(IRInstr::cmp_eq, params,isComparedToZero);
            break;
        case ExprUniType::PREINCR:
            params.push_back(val);
            params.push_back(to_string(1));
            cfg->current_bb->add_IRInstr(IRInstr::add, params,isComparedToZero);
            break;
        case ExprUniType::POSTINCR:
            params.push_back(val);
            params.push_back(to_string(1));
            cfg->current_bb->add_IRInstr(IRInstr::add, params,isComparedToZero);
            break;
        case ExprUniType::POSTDECR:
            params.push_back(val);
            params.push_back(to_string(1));
            cfg->current_bb->add_IRInstr(IRInstr::sub, params,isComparedToZero);
            break;
        case ExprUniType::PREDECR:
            params.push_back(val);
            params.push_back(to_string(1));
            cfg->current_bb->add_IRInstr(IRInstr::sub, params,isComparedToZero);
            break;
        case ExprUniType::INV:
            params.push_back(to_string(0));
            params.push_back(val);
            cfg->current_bb->add_IRInstr(IRInstr::sub, params,isComparedToZero);
            break;
        default:
            cfg->current_bb->add_IRInstr(IRInstr::unk, params,isComparedToZero);
            break;
    }
    return val;
}


string ExprUni::getType(int type) {
    switch(type){
        case ExprUniType::PREDECR:
            return "--(pre)";
        case ExprUniType::INV:
            return "-";
        case ExprUniType::POSTDECR:
            return "--(post)";
        case ExprUniType::POSTINCR:
            return "++(post)";
        case ExprUniType::PREINCR:
            return "++(pre)";
        case ExprUniType::NO:
            return "!";
    }
    return "unk";
}