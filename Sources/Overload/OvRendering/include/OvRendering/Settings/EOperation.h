/**
* @project: Overload
* @author: Overload Tech.
* @restrictions: This software may not be resold, redistributed or otherwise conveyed to a third party.
*/

#pragma once

#include "OvRendering/API/Export.h"

namespace OvRendering::Settings
{
	/**
	* OpenGL operation enum wrapper
	*/
	enum class EOperation
	{
		KEEP			= 0x1E00,
		ZERO			= 0,
		REPLACE			= 0x1E01,
		INCREMENT		= 0x1E02,
		INCREMENT_WRAP	= 0x8507,
		DECREMENT		= 0x1E03,
		DECREMENT_WRAP	= 0x8508,
		INVERT			= 0x150A
	};
}