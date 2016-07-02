/***********************************************************************
Filename   : rvarchdefs.h
Description: definitions used by architechture configuration headers
************************************************************************
        Copyright (c) 2001 RADVISION Inc. and RADVISION Ltd.
************************************************************************
NOTICE:
This document contains information that is confidential and proprietary
to RADVISION Inc. and RADVISION Ltd.. No part of this document may be
reproduced in any form whatsoever without written prior approval by
RADVISION Inc. or RADVISION Ltd..

RADVISION Inc. and RADVISION Ltd. reserve the right to revise this
publication and make changes without obligation to notify any person of
such revisions or changes.
***********************************************************************/
#ifndef RV_ARCHDEFS_H
#define RV_ARCHDEFS_H

/* Note: Adding additional parameters requires changing the makefiles */
/* too since these definitions are set in rvbuildconfig.h, which is */
/* generated by the makefiles. */

/* CPU Endian Configuration. Some CPUs can be either. */
#define RV_ARCH_BIG_ENDIAN 0
#define RV_ARCH_LITTLE_ENDIAN 1

/* CPU Bit Architectures */
#define RV_ARCH_BITS_32 0
#define RV_ARCH_BITS_64 1

#endif /* RV_ARCHDEFS_H */
