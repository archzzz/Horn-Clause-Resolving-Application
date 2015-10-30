﻿// TokenComparator.h -- This file implements a TokenComparator struct used to compare between two Token.
// Created by Anqi Zhang, Yu Xiao
//
#include "stdafx.h"
#include "TokenComparator.h"

bool TokenComparator::operator()(const Token& lhs, const Token& rhs) const {
    return lhs.label < rhs.label; // compare the Tokens label.
}