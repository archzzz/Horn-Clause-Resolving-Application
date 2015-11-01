﻿#include "stdafx.h"
#include "DeductiveDatabase.h"
#include "HeadNode.h"
#include "BodyNode.h"
#include "PredicateNode.h"

DeductiveDatabase::DeductiveDatabase(SymbolTable& symbol_table) :
    symbol_table_(symbol_table), hornclause_buffer_ptr_(nullptr)
{}

void DeductiveDatabase::AddHornclauseEntry(const HornclauseDatabaseEntry& entry) {
    hornclause_entries_.push_back(entry);
}

void DeductiveDatabase::OnPreVisit(HornclauseNode*) {
    hornclause_buffer_ptr_ = new HornclauseDatabaseEntry();
}

void DeductiveDatabase::OnPostVisit(HornclauseNode*) {
    AddHornclauseEntry(*hornclause_buffer_ptr_);
}

void DeductiveDatabase::OnPreVisit(HeadNode*) {
    predicate_buffer_.clear();
}

void DeductiveDatabase::OnPostVisit(HeadNode*) {
    hornclause_buffer_ptr_->head = predicate_buffer_;
}

void DeductiveDatabase::OnPreVisit(BodyNode*) {
    predicate_buffer_.clear();
}

void DeductiveDatabase::OnPostVisit(BodyNode*) {
    hornclause_buffer_ptr_->body = predicate_buffer_;
}

void DeductiveDatabase::OnVisit(PredicateNode* node) {
    predicate_buffer_.push_back(symbol_table_.FindPredicateEntryByNode(*node));
}

void DeductiveDatabase::Display(std::ostream& os, const unsigned& offset, const unsigned& num_entries) const {
    size_t min_num = offset + num_entries < size() ? offset + num_entries : size();
    for (size_t i = offset; i < min_num; ++i)
        os << i + 1 << Encode(":") << hornclause_entries_[i] << std::endl;
}

size_t DeductiveDatabase::size() const {
    return hornclause_entries_.size();
}

std::ostream& operator<<(std::ostream& os, const HornclauseDatabaseEntry& entry) {
    os << Encode("(") << *entry.head[0];
    if (!entry.body.empty()) {
        os << Encode("(");
        for (PredicateEntry* predicate_ptr : entry.body)
            os << *predicate_ptr;
        os << Encode(")");
    }
    os << ")";
    return os;
}