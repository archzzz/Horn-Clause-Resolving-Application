// Visitor.h : Delare Visitor class that allows user to visit every node of the horn clause tree.
// Created by Anqi Zhang (439754), and Yu Xiao (439734)
//
#ifndef VISITOR_H
#define VISITOR_H
//
//class Visitor
//
//
class Visitor
{
public:

	virtual ~Visitor(){}

    virtual void OnPreVisit(struct BaseNode*) {}

    virtual void OnPreVisit(struct RootNode*) {}

    virtual void OnPreVisit(struct HornclauseNode*) {}

    virtual void OnPreVisit(struct HeadNode*) {}

    virtual void OnPreVisit(struct BodyNode*) {}

    virtual void OnPreVisit(struct PredicateNode*) {}

    virtual void OnPreVisit(struct SymbolNode*) {}

    virtual void OnPreVisit(struct NameNode*) {}

    virtual void OnPrevisit(struct UnknownNode*) {}
	
    virtual void OnVisit(struct BaseNode*) {}

    virtual void OnVisit(struct RootNode*) {}

    virtual void OnVisit(struct HornclauseNode*) {}

    virtual void OnVisit(struct HeadNode*) {}

    virtual void OnVisit(struct BodyNode*) {}

    virtual void OnVisit(struct PredicateNode*) {}

    virtual void OnVisit(struct SymbolNode*) {}

    virtual void OnVisit(struct NameNode*) {}

    virtual void OnVisit(struct UnknownNode*) {}

    virtual void OnPostVisit(struct BaseNode*) {}

    virtual void OnPostVisit(struct RootNode*) {}

    virtual void OnPostVisit(struct HornclauseNode*) {}

    virtual void OnPostVisit(struct HeadNode*) {}

    virtual void OnPostVisit(struct BodyNode*) {}

    virtual void OnPostVisit(struct PredicateNode*) {}

    virtual void OnPostVisit(struct SymbolNode*) {}

    virtual void OnPostVisit(struct NameNode*) {}

    virtual void OnPostVisit(struct UnknownNode*) {}

};
#endif