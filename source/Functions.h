//
// DESCRIPTION FUNCTONS:  
// QC-COMPLEMENTOS++
//
//  Created by Solange Becerra on 27-10-14.
//  
//

#ifndef _QC_FUNCTIONS_
#define _QC_FUNCTIONS_

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include "QCDate.h"
#include "qcBasis.h"

using namespace std;

bool IsBasis(std::string basis);
qcBasis stringToEnumDayCountConvention(std::string sBasis);
double yearFraction(QCDate startDate, QCDate endDate, qcBasis basis);
int yearFracActualActual(QCDate startDate, QCDate endDate);
double roundingValue(double number);
#endif