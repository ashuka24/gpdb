//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2013 EMC Corp.
//
//	@filename:
//		CStatsPredArrayCmp.h
//
//	@doc:
//		ArrayCmp filter on statistics
//---------------------------------------------------------------------------
#ifndef GPNAUCRATES_CStatsPredArrayCmp_H
#define GPNAUCRATES_CStatsPredArrayCmp_H

#include "gpos/base.h"
#include "naucrates/md/IMDType.h"
#include "naucrates/statistics/CStatsPred.h"

// fwd declarations
namespace gpopt
{
	class CColRef;
}

namespace gpnaucrates
{
	using namespace gpos;
	using namespace gpmd;
	using namespace gpopt;

	class CStatsPredArrayCmp : public CStatsPred
	{
		private:

			// private copy ctor
			CStatsPredArrayCmp(const CStatsPredArrayCmp &);

			// private assignment operator
			CStatsPredArrayCmp& operator=(CStatsPredArrayCmp &);

			// comparison type
			CStatsPred::EStatsCmpType m_stats_cmp_type;

		public:

			// ctor
			CStatsPredArrayCmp
				(
				ULONG colid,
				CStatsPred::EStatsCmpType stats_cmp_type
				);

			// dtor
			virtual
			~CStatsPredArrayCmp()
			{
			}

			// comparison types for stats computation
			virtual
			CStatsPred::EStatsCmpType GetCmpType() const
			{
				return m_stats_cmp_type;
			}

			// filter type id
			virtual
			EStatsPredType GetPredStatsType() const
			{
				return CStatsPred::EsptArrayCmp;
			}

			// conversion function
			static
			CStatsPredArrayCmp *ConvertPredStats
				(
				CStatsPred *pred_stats
				)
			{
				GPOS_ASSERT(NULL != pred_stats);
				GPOS_ASSERT(CStatsPred::EsptArrayCmp == pred_stats->GetPredStatsType());

				return dynamic_cast<CStatsPredArrayCmp*>(pred_stats);
			}

	}; // class CStatsPredArrayCmp

}

#endif // !GPNAUCRATES_CStatsPredArrayCmp_H

// EOF
