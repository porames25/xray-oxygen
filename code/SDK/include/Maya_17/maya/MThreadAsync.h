#ifndef _MThreadAsync
#define _MThreadAsync
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================
//+
//
// CLASS:    MThreadAsync
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MTypes.h>

#ifdef _WIN32
typedef long MThreadRetVal;
#else
typedef void * MThreadRetVal;
#endif

class MThreadRootTask;

//! \brief Pointer to a function to be executed within threads.
/*!
 \param[in] data Pointer to user-defined supplied when the thread task was created.

 \return Result of the function call.
*/
typedef MThreadRetVal (*MThreadFunc)(void *data);

//! \brief Pointer to a callback function to be executed within threads.
/*!
 \param[in] data Pointer to user-defined data supplied when the thread task was created.
*/
typedef void (*MThreadAsyncCallbackFunc)(void *data);

// ****************************************************************************
// CLASS DECLARATION (MThreadAsync)

//! \ingroup OpenMaya
//! \brief Methods for creating threads. 
/*!
 MThreadAsync class. Allows creation of asynchronous threads.
*/
class OPENMAYA_EXPORT MThreadAsync
{
public:
	static MStatus init();

	static MStatus createTask(MThreadFunc func, void* data, MThreadAsyncCallbackFunc afunc, MThreadRootTask* root);

	static void release();

	static const char* 	className();

private:
	MThreadAsync() {};
	MThreadAsync(const MThreadAsync&) {}; // disallow this
	~MThreadAsync() {};
};

#endif /* __cplusplus */
#endif /* _MThreadAsync */
