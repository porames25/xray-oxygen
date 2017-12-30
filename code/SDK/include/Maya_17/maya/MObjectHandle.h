#ifndef _MObjectHandle
#define _MObjectHandle
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
// ****************************************************************************
//
// CLASS:    MObjectHandle
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MObject.h>

// CLASS DECLARATION (MObjectHandle)

//! \ingroup OpenMaya
//! \brief Generic Class for validating MObjects.
/*!
  MObjectHandle is a wrapper class for the MObject class. An MObjectHandle
  will provide a user with added information on the validity of an MObject.
  Each MObjectHandle that is created registers an entry into a table to
  maintain state tracking of the MObject that the handle was created for.
  This will help users track when an MObject is invalid and should be
  re-retrieved.
*/
class OPENMAYA_EXPORT MObjectHandle
{
public:
	MObjectHandle();
	MObjectHandle( const MObject& object );
	MObjectHandle( const MObjectHandle &handle );
	~MObjectHandle();
	MObject			object() const;
	const MObject & objectRef() const;
	unsigned int	hashCode() const;
	bool			isValid() const;
	bool			isAlive() const;

	bool			operator==(const MObject &object) const;
	bool			operator==(const MObjectHandle &object) const;
	bool			operator!=(const MObject &object) const;
	bool			operator!=(const MObjectHandle &object) const;

	MObjectHandle & operator=(const MObject &object );
	MObjectHandle & operator=(const MObjectHandle &other );

    static unsigned int	objectHashCode(const MObject&);
private:

	// Internal object registration methods
	void			registerObject();
	void			deregisterObject();

	// Internal destructor callback
	static void		registerDestroyedCallback();
	static void		deregisterDestroyedCallback();
	static bool		fIsCallbackInitialized;
	static void		destroyedCallback(void*);

	MObject			fObject;
	bool			fIsAlive;
	bool			fIsDependNode;
	static int		fHandleCount;
};

#endif /* __cplusplus */
#endif /* _MObjectHandle */

