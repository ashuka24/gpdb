//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2013 EMC Corp.
//
//	@filename:
//		CStatsPredArrayCmp.cpp
//
//	@doc:
//		Implementation of statistics for ArrayCmp filter
//---------------------------------------------------------------------------

#include "naucrates/statistics/CStatsPredArrayCmp.h"
#include "naucrates/md/CMDIdGPDB.h"

#include "gpopt/base/CColRef.h"
#include "gpopt/base/CColRefTable.h"

using namespace gpnaucrates;
using namespace gpopt;
using namespace gpmd;


// Ctor
CStatsPredArrayCmp::CStatsPredArrayCmp
	(
	ULONG colid,
	CStatsPred::EStatsCmpType stats_cmp_type
	)
	:
	CStatsPred(colid),
	m_stats_cmp_type(stats_cmp_type)
{
}

// EOF

