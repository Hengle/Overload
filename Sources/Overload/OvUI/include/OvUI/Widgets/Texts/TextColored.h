/**
* @project: Overload
* @author: Overload Tech.
* @restrictions: This software may not be resold, redistributed or otherwise conveyed to a third party.
*/

#pragma once

#include "OvUI/Widgets/Texts/Text.h"
#include "OvUI/Types/Color.h"

namespace OvUI::Widgets::Texts
{
	/**
	* Widget to display text on a panel that can be colored
	*/
	class API_OVUI TextColored : public Text
	{
	public:
		/**
		* Constructor
		* @param p_content
		* @param p_color
		*/
		TextColored(const std::string& p_content = "", const Types::Color& p_color = Types::Color(1.0f, 1.0f, 1.0f, 1.0f));

	public:
		Types::Color color;

	protected:
		virtual void _Draw_Impl() override;
	};
}