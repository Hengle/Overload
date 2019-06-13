/**
* @project: Overload
* @author: Overload Tech.
* @restrictions: This software may not be resold, redistributed or otherwise conveyed to a third party.
*/

#pragma once

#include <OvMaths/FVector2.h>

#include "OvUI/Internal/TextureID.h"
#include "OvUI/Widgets/AWidget.h"

namespace OvUI::Widgets::Visual
{
	/**
	* Simple widget that display an image
	*/
	class API_OVUI Image : public AWidget
	{
	public:
		/**
		* Constructor
		* @param p_textureID
		* @parma p_size
		*/
		Image(uint32_t p_textureID, const OvMaths::FVector2& p_size);

	protected:
		void _Draw_Impl() override;

	public:
		Internal::TextureID textureID;
		OvMaths::FVector2 size;
	};
}